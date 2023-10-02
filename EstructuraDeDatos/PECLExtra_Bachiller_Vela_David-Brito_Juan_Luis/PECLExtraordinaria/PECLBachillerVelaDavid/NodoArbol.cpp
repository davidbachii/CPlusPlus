#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Paciente* p)
{
    this->paciente = p;
    this->der = nullptr;
    this->izq = nullptr;
}

NodoArbol::~NodoArbol()
{
}

