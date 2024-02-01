#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include "Paciente.hpp"
class NodoArbol
{
public:
    NodoArbol(Paciente* p);
    ~NodoArbol();
private:    
    Paciente* paciente; 
    NodoArbol* izq;
    NodoArbol* der;
    
    friend class Arbol;

};
typedef NodoArbol* pnodoAbb;

#endif // NODOARBOL_HPP
