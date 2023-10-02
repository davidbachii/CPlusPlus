#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"

class Lista
{
public:
    Lista();
    ~Lista();
    void insertarOrdenado(Paciente* p);
    Paciente* menorID();
    Paciente* Primero();
    Paciente* Ultimo();
    Paciente* eliminarPrimero();
    void mostrar();
    void vaciarLista();
    int getLognitud();
    void mostrarMenorMayorLista();

private:
    pnodoLista primero, ultimo;
    int longitud;
};

#endif // LISTA_HPP
