#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP
#include "Arbol.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Paciente.hpp"
#include "Pila.hpp"
#include <algorithm>
using namespace std;

class Controlador
{
public:
    Controlador();
    ~Controlador();
    // Arbol
    void generar10pacientes();
    void crearYdibujarArbol();
    int PacientesArbol();
    void mostrarPostOrden();
    void mostrarMyoresMenoresArb();
    void IDsPares();
    void mostrarPacientesHoja();
    void eliminarPacienteId();
    void eliminarArbolPreorden();
    // Colas
    void mostrarPacienteColassApendicitis();
    void mostrarPacientesColasHernias();
    int PacientesColaApendicitis();
    int PacientesColaHernias();
    void vaciarColas();
    // Listas
    void enlistarPacientesMenorMayor();
    int pacientesListaApendicitis();
    int pacientesListaHernias();
    void mostrarPacientesListasApendicitis();
    void mostrarPacientesListasHernias();
    void mostrarMayoresMenoresListas();
    void vaciarLista();
    //Pila
    void apilarPacientes();
    void mostrarPacientesPila();
    int PacientesPila();
    void vaciarPila();
    //Extra
    void reiniciarPrograma();
private:
    Arbol Arb;
    Cola colaA;
    Cola colaH;
    Lista listaA;
    Lista listaH;
    Pila pila;
    int arrID[50];
    int arrNHab[100];
    int contadorA;
    int contadorH;

    int totalPacientes();
};

#endif // CONTROLADOR_HPP
