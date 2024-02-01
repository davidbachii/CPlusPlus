#ifndef NODOPILA_HPP
#define NODOPILA_HPP

#include "Paciente.hpp"
#include <iostream>

using namespace std;
class NodoPila
{
public:
    NodoPila(Paciente* p, NodoPila* sig = NULL);
    ~NodoPila();

private:
    Paciente* pa;
    NodoPila* siguiente;
    friend class Pila;
};

typedef NodoPila* pnodoPila;
#endif // NODOPILA_HPP