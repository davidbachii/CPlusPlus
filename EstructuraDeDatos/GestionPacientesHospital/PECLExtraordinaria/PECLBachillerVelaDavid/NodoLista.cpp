#include "NodoLista.hpp"

NodoLista::NodoLista(Paciente* p, NodoLista* sig, NodoLista* ant)
{
    pa = p;
    siguiente = sig;
    anterior = ant;
}

NodoLista::~NodoLista()
{
}
