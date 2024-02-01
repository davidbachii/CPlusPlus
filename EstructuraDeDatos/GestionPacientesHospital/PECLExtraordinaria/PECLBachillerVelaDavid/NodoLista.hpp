#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include <iostream>

#include "Paciente.hpp"

using namespace std;

class NodoLista
{
public:
    NodoLista(Paciente* p, NodoLista* sig = NULL, NodoLista* ant = NULL);
    ~NodoLista();

private:
    Paciente* pa;
    NodoLista* siguiente;
    NodoLista* anterior;
    friend class Lista;
};

typedef NodoLista* pnodoLista;

#endif // NODOLISTA_HPP
