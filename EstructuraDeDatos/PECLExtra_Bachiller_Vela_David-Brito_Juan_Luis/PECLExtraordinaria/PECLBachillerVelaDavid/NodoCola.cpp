#include "NodoCola.hpp"

NodoCola::NodoCola(Paciente *p, NodoCola *sig) {
  pa = p;
  siguiente = sig;
}

NodoCola::~NodoCola() {}
