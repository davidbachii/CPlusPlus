#include <public/ccavoidobstacles_iface_v1.h>

// ***********************************************************************

// class EDROOM_CTX_Top_0

// ***********************************************************************



	// CONSTRUCTORS***********************************************

CCAvoidObstacles::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(CCAvoidObstacles &act,
	 TEDROOMByte & EDROOMpVarVObsDetected ):

	EDROOMcomponent(act),
	Msg(EDROOMcomponent.Msg),
	MsgBack(EDROOMcomponent.MsgBack),
	AvoidObstaclesSysCtrl(EDROOMcomponent.AvoidObstaclesSysCtrl),
	SensorIRQ(EDROOMcomponent.SensorIRQ),
	VObsDetected(EDROOMpVarVObsDetected)
{
}

CCAvoidObstacles::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(EDROOM_CTX_Top_0 &context):

	EDROOMcomponent(context.EDROOMcomponent),
	Msg(context.Msg),
	MsgBack(context.MsgBack),
	AvoidObstaclesSysCtrl(context.AvoidObstaclesSysCtrl),
	SensorIRQ(context.SensorIRQ),
	VObsDetected(context.VObsDetected)
{

}

	// EDROOMSearchContextTrans********************************************

bool CCAvoidObstacles::EDROOM_CTX_Top_0::EDROOMSearchContextTrans(
			TEDROOMTransId &edroomCurrentTrans)
			{

	bool edroomValidMsg=false; 

	 switch(Msg->signal)
	{

		 case ( EDROOMSignalDestroy ): 

			 edroomValidMsg=true;
			 edroomCurrentTrans.distanceToContext = 0 ;
			 edroomCurrentTrans.localId = -1 ;
			 break;

	}

	return(edroomValidMsg);

}

	// User-defined Functions   ****************************

void	CCAvoidObstacles::EDROOM_CTX_Top_0::FConfigOK()

{

io_ctrl_obst_detection_start_up();
SensorIRQ.InstallHandler();
   //Reply synchronous communication
   Msg->reply(SConfigOK); 
}



void	CCAvoidObstacles::EDROOM_CTX_Top_0::FHandleIRQ()

{
   //Handle Msg->data
  TEDROOMByte & varEDROOMIRQsignal = *(TEDROOMByte *)Msg->data;
	
		// Data access
	
 
	VObsDetected=varEDROOMIRQsignal;

}



void	CCAvoidObstacles::EDROOM_CTX_Top_0::FHandleObstacle()

{

io_ctrl_detect_obstacle(VObsDetected);
 
actuators_halt();
   //Send message 
   AvoidObstaclesSysCtrl.send(SObstacleDetected); 
}



	//********************************** Pools *************************************



// ***********************************************************************

// class EDROOM_SUB_Top_0

// ***********************************************************************



	// CONSTRUCTOR*************************************************

CCAvoidObstacles::EDROOM_SUB_Top_0::EDROOM_SUB_Top_0 (CCAvoidObstacles&act):
		EDROOM_CTX_Top_0(act,
			VObsDetected)
{

}

	//***************************** EDROOMBehaviour ********************************

void CCAvoidObstacles::EDROOM_SUB_Top_0::EDROOMBehaviour()
{

	TEDROOMTransId edroomCurrentTrans;

	//Behaviour starts from Init State

	edroomCurrentTrans = EDROOMIArrival();

	do
	{

		//Take next transition

		switch(edroomCurrentTrans.localId)
		{

			//Next Transition is Init
			case (Init):
				//Next State is Idle
				edroomNextState = Idle;
				break;
			//Next Transition is Config
			case (Config):
				//Reply Synchronous Message 
				FConfigOK();
				//Next State is Idle
				edroomNextState = Idle;
				break;
			//Next Transition is Start
			case (Start):
				//Next State is Ready
				edroomNextState = Ready;
				break;
			//Next Transition is HandleObstacle
			case (HandleObstacle):
				//Msg->Data Handling 
				FHandleIRQ();
				//Send Asynchronous Message 
				FHandleObstacle();
				//Next State is Ready
				edroomNextState = Ready;
				break;
		}

		//Entry into the Next State 
		switch(edroomNextState)
		{

				//Go to the state I
			case (I):
				//Arrival to state I
				edroomCurrentTrans=EDROOMIArrival();
				break;

				//Go to the state Idle
			case (Idle):
				//Arrival to state Idle
				edroomCurrentTrans=EDROOMIdleArrival();
				break;

				//Go to the state Ready
			case (Ready):
				//Arrival to state Ready
				edroomCurrentTrans=EDROOMReadyArrival();
				break;

		}

		edroomCurrentState=edroomNextState;

	}while(Msg->signal != EDROOMSignalDestroy);

}



	// Context Init**********************************************

void CCAvoidObstacles::EDROOM_SUB_Top_0::EDROOMInit()
{

edroomCurrentState=I;

}



//	 ***********************************************************************

//	 SubState I

//	 ***********************************************************************



TEDROOMTransId CCAvoidObstacles::EDROOM_SUB_Top_0::EDROOMIArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	//Next transition is  Init
	edroomCurrentTrans.localId = Init;
	edroomCurrentTrans.distanceToContext = 0;
	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  Idle

	// ***********************************************************************



TEDROOMTransId CCAvoidObstacles::EDROOM_SUB_Top_0::EDROOMIdleArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (SConfigAO): 

				 if (*Msg->GetPInterface() == AvoidObstaclesSysCtrl)
				{

					//Next transition is  Config
					edroomCurrentTrans.localId= Config;
					edroomCurrentTrans.distanceToContext = 0;
					edroomValidMsg=true;
				 }

				break;

			case (SStart): 

				 if (*Msg->GetPInterface() == AvoidObstaclesSysCtrl)
				{

					//Next transition is  Start
					edroomCurrentTrans.localId= Start;
					edroomCurrentTrans.distanceToContext = 0;
					edroomValidMsg=true;
				 }

				break;

		};

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  Ready

	// ***********************************************************************



TEDROOMTransId CCAvoidObstacles::EDROOM_SUB_Top_0::EDROOMReadyArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (EDROOMIRQsignal): 

				 if (*Msg->GetPInterface() == SensorIRQ)
				{

					//Next transition is  HandleObstacle
					edroomCurrentTrans.localId= HandleObstacle;
					edroomCurrentTrans.distanceToContext = 0;
					edroomValidMsg=true;
				 }

				break;

		};

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}



