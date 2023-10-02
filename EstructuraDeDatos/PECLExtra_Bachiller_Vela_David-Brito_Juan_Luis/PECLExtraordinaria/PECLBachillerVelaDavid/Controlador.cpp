#include "Controlador.hpp"

Controlador::Controlador()
{
    this->Arb = Arbol();
    this->colaA = Cola();
    this->colaH = Cola();
    this->listaA = Lista();
    this->listaH = Lista();
    this->pila = Pila();
    this->contadorA = 0;    // Contador de apendicitis
    this->contadorH = 0;    // Contador de hernias
    this->arrID[49] = {};   // Creamos un array con 49 valores
    this->arrNHab[99] = {}; // Creamos un array con 99 valores
    for(int i = 0; i < 50; i++) {
        arrID[i] = i + 1; // Asignamos valores a cada posicion del array Id apendicitis
    }
    for(int k = 0; k < 100; k++) {
        arrNHab[k] = k + 101; // Asignamos valores a cada posicion del array Id hernias
    }

    random_shuffle(arrID, arrID + 49);     // Reordena el array de IDs aleatoriamente
    random_shuffle(arrNHab, arrNHab + 99); // Reordena el array de de Nhabs aleatoriamnete
}
// Opcion A
void Controlador::generar10pacientes()
{
    if(totalPacientes() < 50) {
        for(int i = 0; i < 10; i++) {

            Paciente* p = new Paciente();
            if(p->getApendicitis() == 1) {

                p->setId(arrID[contadorA]);           // Le establezco al paciente la primera posicion del array de ID
                p->setHabitacion(arrNHab[contadorA]); // Le establezco al paciente la primera posicion del array de Nhab
                this->Arb.insertar(p);                // Lo inserto en el arbol
                this->contadorA++;

            } else {
                p->setId(arrID[contadorH] + 50);            // Le sumo 50 ya que el id de hernias va de de 51 a 99
                p->setHabitacion(arrNHab[contadorH] + 100); // Lo mismo con el nHab
                this->Arb.insertar(p);                      // Lo inserto en el arbol
                this->contadorH++;
            }
        }
    } else {
        cout << "Espacio completo" << endl;
    }
}
// Opcion A
void Controlador::crearYdibujarArbol()
{
    this->Arb.dibujar();
}
// Opción B
void Controlador::mostrarPostOrden()
{
    this->Arb.mostrarPostOrdenArbol();
}
// Opcion C
void Controlador::mostrarMyoresMenoresArb()
{
    this->Arb.mostrarMenoresMayoresArbol();
}
// Opcion D
void Controlador::IDsPares()
{
    cout << "El numero de Pacientes cuyo ID es par es: " << this->Arb.nPares() << endl;
}
// Opcion E
void Controlador::mostrarPacientesHoja()
{
    this->Arb.mostrarHojas();
}
// Opcion F
void Controlador::eliminarPacienteId()
{
    int nHab;
    this->Arb.dibujar();
    cout << "Escoja el paciente que quiere eliminar por su numero de habitacion: " << endl;
    cin >> nHab;
    this->Arb.eliminarPorId(nHab);
    this->Arb.dibujar();
}
// Opcion G
void Controlador::eliminarArbolPreorden()
{

    // lo primero que hacemos es recorrer el arbol en preorden para obtener los pacientes y
    // añadirlo a la cola auxiliar
    this->Arb.eliminarPreordeArbol();
    // Posteriormente vaciaremos el arbol
    for(int i = 0; i < contadorA; i++) {
        this->Arb.eliminarPorId(arrID[i]);
    }
    for(int i = 0; i < contadorA + contadorH; i++) {
        this->Arb.eliminarPorId(arrID[i] + 50);
    }
    Paciente* aux;
    // Mientras que la longitud de la cola auxiliar sea mayor que 0 va estar extrayendo pacientes
    // y añadiendolos a su cola de apendicitis o hernias
    while(this->Arb.getCola().getLongitud() > 0) {
        aux = this->Arb.extraerCola();

        if(aux->getApendicitis() == 1) {

            this->colaA.insertar(aux);

        } else {

            this->colaH.insertar(aux);
        }
    }
}
// Opcion H
void Controlador::mostrarPacienteColassApendicitis()
{
    this->colaA.mostrar();
}
// Opcion I
void Controlador::mostrarPacientesColasHernias()
{
    this->colaH.mostrar();
}
// Opcion J
void Controlador::vaciarColas()
{
    while(this->colaA.getLongitud() > 0) {
        this->colaA.eliminar();
    }
    while(this->colaH.getLongitud() > 0) {
        this->colaH.eliminar();
    }
}
// Opcion K
void Controlador::enlistarPacientesMenorMayor()
{
    Paciente* aux;
    while(colaA.getLongitud() > 0) {
        aux = colaA.eliminar();
        this->listaA.insertarOrdenado(aux);
    }
    while(colaH.getLongitud() > 0) {
        aux = colaH.eliminar();
        this->listaH.insertarOrdenado(aux);
    }
}
// Opcion L
void Controlador::mostrarPacientesListasApendicitis()
{
    this->listaA.mostrar();
}
// Opcion M
void Controlador::mostrarPacientesListasHernias()
{
    this->listaH.mostrar();
}
// Opcion N
void Controlador::mostrarMayoresMenoresListas()
{
    cout << "Lista Apendicitis" << endl;
    this->listaA.mostrarMenorMayorLista();
    cout << "Lista Hernias" << endl;
    this->listaH.mostrarMenorMayorLista();
}

// Opcion O
void Controlador::apilarPacientes()
{

    while(listaA.getLognitud() > 0) {
        this->pila.insertar(listaA.eliminarPrimero());
    }
    while(listaH.getLognitud() > 0) {
        this->pila.insertar(listaH.eliminarPrimero());
    }
}
void Controlador::mostrarPacientesPila()
{
    this->pila.mostrar();
}
void Controlador::vaciarLista()
{
    while(listaA.getLognitud() > 0) {
        listaA.vaciarLista();
    }
    while(listaH.getLognitud() > 0) {
        listaH.vaciarLista();
    }
}
void Controlador::vaciarPila()
{
    while(pila.getLongitud() > 0) {
        this->pila.extraer();
    }
}

void Controlador::reiniciarPrograma()
{
    for(int i = 0; i < contadorA; i++) {
        this->Arb.eliminarPorId(arrID[i]);
    }
    for(int i = 0; i < contadorA + contadorH; i++) {
        this->Arb.eliminarPorId(arrID[i] + 50);
    }
    vaciarColas();
    vaciarLista();
    vaciarPila();
}

int Controlador::PacientesArbol()
{
    return this->Arb.getLongitud();
}
int Controlador::PacientesColaApendicitis()
{
    return this->colaA.getLongitud();
}
int Controlador::PacientesColaHernias()
{
    return this->colaH.getLongitud();
}
int Controlador::pacientesListaApendicitis()
{
    return this->listaA.getLognitud();
}
int Controlador::pacientesListaHernias()
{
    return this->listaH.getLognitud();
}
int Controlador::PacientesPila()
{
    return this->pila.getLongitud();
}
int Controlador::totalPacientes()
{
    return PacientesArbol() + PacientesColaApendicitis() + PacientesColaHernias() + pacientesListaApendicitis() +
        pacientesListaHernias() + PacientesPila();
}

Controlador::~Controlador()
{
}
