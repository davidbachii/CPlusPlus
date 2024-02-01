#include "NodoPila.hpp"

NodoPila::NodoPila(Paciente* p, NodoPila* sig)
{
   pa = p;
   siguiente = sig;
}
NodoPila::~NodoPila()
{
}