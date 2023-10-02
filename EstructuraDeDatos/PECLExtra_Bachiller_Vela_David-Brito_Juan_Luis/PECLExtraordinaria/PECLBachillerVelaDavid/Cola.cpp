#include "Cola.hpp"

Cola::Cola() {
  primero = NULL;
  ultimo = NULL;
  longitud = 0;
}
void Cola::insertar(Paciente *p)

{
  pnodoCola nuevo;
  nuevo = new NodoCola(p); //Se crea un nuevo nodo con ese paciente
  if (ultimo)
    ultimo->siguiente = nuevo; //Si es el ultimo se pasa al siguiente nodo 
  ultimo = nuevo; 
  if (!primero) 
    primero = nuevo;
  longitud++;
}

void Cola::mostrar()

{
  pnodoCola aux = primero; //Se crea un nodo auxiliar se le pasa el primer nodo y se muestra informacionde dicho nodo
  while (aux) {
    aux->pa->mostrarInformacionPaciente();
    aux = aux->siguiente; //Se pasa al siguiente nodo
  }
  cout << endl;
}
Paciente *Cola::eliminar() {
  pnodoCola nodo;
  Paciente *p;
  nodo = primero;
  if (!nodo)
    return 0;
  primero = nodo->siguiente;
  p = nodo->pa;
  delete nodo;
  if (!primero)
    ultimo = NULL;
  longitud--;
  return p;
}


int Cola::getLongitud() { return this->longitud; }


Cola::~Cola() {}
