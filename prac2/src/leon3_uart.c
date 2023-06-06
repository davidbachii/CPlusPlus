#include "leon3_uart.h"


//Estructura de datos que permite acceder a los registros de la //UART de LEON3

struct UART_regs
{
	/** \brief UART Data Register */
	volatile uint32_t Data; /* 0x80000100 */
	/** \brief UART Status Register */
	volatile uint32_t Status; /* 0x80000104 */
	/** \brief UART Control Register */
	volatile uint32_t Ctrl; /* 0x80000108 */
	/** \brief UART Scaler Register */
	volatile uint32_t Scaler; /* 0x8000010C */
};


struct UART_regs * const pLEON3_UART_REGS= 0x80000100;

//! LEON3 UART A Transmit FIFO is FULL
#define LEON3_UART_TFF (pLEON3_UART_REGS->Status & (1 << 9))
//! LEON3 UART A Transmit FIFO is EMPTY
#define LEON3_UART_TFE (pLEON3_UART_REGS->Status & (1 << 2))


#define leon3_UART_TF_IS_FULL() (LEON3_UART_TFF != 0)


int8_t leon3_putchar(char c)
{
	uint32_t write_timeout=0;
	while(leon3_UART_TF_IS_FULL()&&(write_timeout < 0xAAAAA))
	{
		write_timeout++;
	} //Espera mientras la cola de transmisión esté llena
	if(write_timeout < 0xAAAAA){
		pLEON3_UART_REGS -> Data = c;
		//COMPLETAR. Escribir el carácter en el registro Data
	}
	return (write_timeout == 0xAAAAA);
}

int8_t leon3_uart_tx_fifo_is_empty(){
	//COMPLETAR ↓
	int8_t result;
	if (LEON3_UART_TFE != 0){
		return 1;
	}
	else{
		return 0;
	}
}
