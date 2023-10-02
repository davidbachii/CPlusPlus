#include "Pila.hpp"

Pila::Pila()
{
    ultimo = NULL;
    longitud = 0;
}
//Metodo publico para insertar un paciente en la pila
void Pila::insertar(Paciente* p)
{
    pnodoPila nuevo; 
    nuevo = new NodoPila(p, ultimo);
    ultimo = nuevo;
    longitud++;
}
Paciente* Pila::extraer()
{
    pnodoPila nodo;
    Paciente* p;
    if(!ultimo)
        return NULL;
    nodo = ultimo;
    ultimo = nodo->siguiente;
    p = nodo->pa;
    longitud--;
    delete nodo;
    return p;
}

void Pila::mostrar()
{
    pnodoPila aux = ultimo; //Se crea un nodo auxiliar se le pasa el ultimo nodo y se muestra informacionde dicho nodo
    cout << "\tEl contenido de la pila es: \n";
    while(aux) {
        aux->pa->mostrarInformacionPaciente();
        aux = aux->siguiente; //Se pasa al siguiente
    }
    cout << endl;
}

int Pila::getLongitud()
{
    return this->longitud;
}
Pila::~Pila() //Es un método de la clase que se usa para destruir objetos del tipo de la clase, no tiene parámetros de entrada ni valor de retorno
{
    pnodoPila aux;
    while(ultimo) {
        aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
    }
}