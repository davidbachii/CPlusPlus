#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"
class Cola {
public:
  Cola();
  ~Cola();
  void insertar(Paciente *p);
  Paciente *eliminar();
  void mostrar();
  int getLongitud();
  

private:
  pnodoCola primero, ultimo;
  int longitud;
};

#endif // COLA_HPP
