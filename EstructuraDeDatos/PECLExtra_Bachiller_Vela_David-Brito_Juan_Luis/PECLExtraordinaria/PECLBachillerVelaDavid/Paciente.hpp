#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>

using namespace std;
class Paciente {
public:
  Paciente();
  void mostrarPacientePila();
  void mostrarInformacionPaciente();
  void setHabitacion(int n);
  void setId(int id);
  bool getApendicitis();
  char getDNI();
  int getHabitacion();
  int getId();
  ~Paciente();

private:
  int nHabitacion;
  bool apendicitis;
  int ID;
  char DNI[10];

  void generarDNI();
};

#endif // PACIENTE_HPP
