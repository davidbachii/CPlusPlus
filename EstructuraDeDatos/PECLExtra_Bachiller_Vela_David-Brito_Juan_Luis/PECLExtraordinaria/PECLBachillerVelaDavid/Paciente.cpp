#include "Paciente.hpp"

Paciente::Paciente() {
  generarDNI();
  this->apendicitis = rand()%2;//1-->Apendicitis 0-->Hernias
  this->ID = -1;
  this->nHabitacion = -1;
}

void Paciente::generarDNI() {

  char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
  int numDNI = 0, aux = 1E7;
  for (int i = 0; i < 8; i++) {
    int num = rand() % 10;
    this->DNI[i] = '0' + num;
    numDNI = numDNI + num * aux;
    aux /= 10;
  }
  this->DNI[8] = letras[numDNI % 23];
  this->DNI[9] = '\0';
}



void Paciente::mostrarInformacionPaciente() {
  if (apendicitis == 1) {
    cout << "El paciente cuyo DNI es " << this->DNI
         << " tiene apendicitis, su ID es: " << this->ID
         << " y su habitacion asignada es: " << this->nHabitacion << endl;
  } else {
    cout << "El paciente cuyo DNI es " << this->DNI
         << " tiene hernias, su ID es: " << this->ID
         << " y su habitacion asignada es: " << this->nHabitacion << endl;
  }
}

void Paciente::setHabitacion(int n) { this->nHabitacion = n; }

void Paciente::setId(int n) { this->ID = n; }

bool Paciente::getApendicitis() { return this->apendicitis; }

int Paciente::getHabitacion() { return this->nHabitacion; }

int Paciente::getId() { return this->ID; }

Paciente::~Paciente() {}
