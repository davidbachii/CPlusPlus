#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP


#include <iostream>
#include "Paciente.hpp"


using namespace std;

class NodoCola

{

public:

   NodoCola(Paciente* p, NodoCola* sig = NULL);
   ~NodoCola();
private:

   Paciente* pa;
   NodoCola* siguiente;
   friend class Cola;
};

typedef NodoCola* pnodoCola;


#endif // NODOCOLA_HPP