#include "Lista.hpp"

using namespace std;

Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

int Lista::getLognitud() // Devuelve la longitud de la lista
{
    return longitud;
}

Paciente* Lista::Primero() // Devuelve el primer paciente de la lista
{
    return primero->pa;
}
Paciente* Lista::Ultimo() // Devuelve el ultimo paciente de la lista
{

    return ultimo->pa;
}

void Lista::mostrarMenorMayorLista()
{

    cout << "\t Mayor nHab: " << endl, Primero()->mostrarInformacionPaciente();
    cout << "\t Menor nHab: " << endl, Ultimo()->mostrarInformacionPaciente();
}

void Lista::insertarOrdenado(Paciente* p) // Inserta ordenadamente los paciente en la lista(menor mayor)
{
    pnodoLista aux;
    pnodoLista nuevo;
    nuevo = new NodoLista(p);
    if(!primero) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        if(p->getHabitacion() > primero->pa->getHabitacion()) {
            nuevo->siguiente = primero;
            primero->anterior = nuevo;
            primero = nuevo;
        } else if(p->getHabitacion() < ultimo->pa->getHabitacion()) {
            nuevo->anterior = ultimo;
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        } else {
            aux = primero;
            while((aux) and (p->getHabitacion() < aux->pa->getHabitacion())) {
                aux = aux->siguiente;
            }
            if(!aux) {
                ultimo->siguiente = nuevo;
                nuevo->anterior = ultimo;
                ultimo = nuevo;
            } else {
                nuevo->siguiente = aux;
                aux->anterior->siguiente = nuevo;
                nuevo->anterior = aux->anterior;
                aux->anterior = nuevo;
            }
        }
    }
    longitud++;
}

Paciente* Lista::eliminarPrimero() // Devuelve y elimina el primer elemento
{
    Paciente* p;
    pnodoLista aux;
    aux = primero;
    primero = primero->siguiente;
    if(!aux)
        return 0;
    p = aux->pa;
    delete aux;
    if(!primero)
        ultimo = NULL;
    longitud--;
    return p;
}

void Lista::mostrar() // Muestra todos los elementos de la lista recorriendola
{
    pnodoLista aux = primero;
    while(aux) {
        aux->pa->mostrarInformacionPaciente();
        aux = aux->siguiente;
    }
    cout << endl;
}

void Lista::vaciarLista() // Vacia la lista utilizando la funcion resto hasta que el primero sea NULL
{
    while(primero) {
        eliminarPrimero();
    }
    longitud = 0;
}

Lista::~Lista() // Es un método de la clase que se usa para destruir objetos del tipo de la clase, no tiene parámetros
                // de entrada ni valor de retorno
{
    while(primero) {
        eliminarPrimero();
    }
    longitud = 0;
}
