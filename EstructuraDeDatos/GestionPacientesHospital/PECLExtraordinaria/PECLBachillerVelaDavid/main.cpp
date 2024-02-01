#include <Controlador.hpp>
#include <iostream>
#include <windows.h> // sólo windows. Comentar para otro SO
#define _WIN32_WINNT 0x500

using namespace std;

int main(int argc, char** argv)

{

    Controlador controlador;

    char opcion;

    do {

        ShowWindow(GetConsoleWindow(),
            SW_MAXIMIZE); // sólo windows. Comentar para otro SO

        cout << "\n\t--------------------------------------------------------------"
                "--------\n";
        cout << "\tPacientes en la pila -> " << controlador.PacientesPila()
             << "\n\tPacientes en las colas:\n \t\tSala A-> " << controlador.PacientesColaApendicitis() << "\tSala B-> "
             << controlador.PacientesColaHernias()

             << " \n\tPacientes en las listas:\n \t\tQuirofano Apendicitis-> "
             << controlador.pacientesListaApendicitis()

             << "\tQuirofano hernias-> " << controlador.pacientesListaHernias()

             << "\n\tPacientes en el arbol -> " << controlador.PacientesArbol() << "\n";

        cout << "\t----------------------------------------------------------------"
                "------\n\n";

        cout << "\tA. Generar 10 pacientes de forma aleatoria y almacenarlos en el "
                "Arbol.\n";

        cout << "\tB. Mostrar los pacientes que hay en el arbol en postorden \n";

        cout << "\tC. Buscar en el ABB y mostrar los siguientes 4 pacientes, mayor y menos ID, mayor y menos nHab. \n";

        cout << "\tD. Contar el numero de pacientes almacenados en el ABB cuyos "
                "IDs son pares.\n";

        cout << "\tE. Mostrar los pacientes que se encuentran almacenados en un "
                "nodo hoja.\n";

        cout << "\tF. eliminar un paciente indicado por su ID (que se pide desde "
                "consola). Mostrar el arbol "
                "antes y despues de la eliminacion de dicho paciente.\n";

        cout << "\tG. Esta opcion extraera los pacientes del arbol en preorden y "
                "los almacenara en su "
                " correspondiente cola..\n";

        cout << "\tH. Esta opcion mostrara todos los pacientes almacenados en la cola de apendicitis. \n ";

        cout << "\tI.  Esta opcion mostrara todos los pacientes almacenados en la cola de hernias. \n ";

        cout << "\tJ. Esta opcion borrara todos los pacientes almacenados en las colas.\n";

        cout << "\tK. Esta opcion extraera los pacientes de la cola y los almacenara en las listas ordenados de "
                "menor a mayor por numero de habitacion. \n ";

        cout << "\tL. Esta opcion mostrara los pacientes que hay en la Lista Apendicitis.\n";

        cout << "\tM. Esta opcion mostrara los pacientes que hay en la Lista Hernias.\n";

        cout << "\tN. Esta opcion buscara en las listas y mostrara los siguientes 2 pacientes, mayor y menor nHab. \n";
        
        cout << "\tO. Esta opcion transfiere los pacientes de las listas a la pila. \n";
        
        cout << "\tP. Esta opciOn muestra los pacientes de la Pila. \n";
        
        cout << "\tQ. Reiniciar el programa a su estado inicia \n";

        cout << "\tR. Salir.\n\n";

        cout << "\tIndique la opcion deseada: ";

        cin >> opcion;

        opcion = toupper(opcion);

        // system("clear"); para MAC

        system("cls"); // sólo windows. Comentar para otro SO

        switch(opcion) {

        case 'A':

            controlador.generar10pacientes();
            controlador.crearYdibujarArbol();

            break;

        case 'B':

            controlador.mostrarPostOrden();

            break;

        case 'C':

            controlador.mostrarMyoresMenoresArb();

            break;

        case 'D':

            controlador.IDsPares();

            break;

        case 'E':

            controlador.mostrarPacientesHoja();

            break;

        case 'F':

            controlador.eliminarPacienteId();

            break;

        case 'G':

            controlador.eliminarArbolPreorden();

            break;

        case 'H':

            controlador.mostrarPacienteColassApendicitis();

            break;

        case 'I':

            controlador.mostrarPacientesColasHernias();

            break;

        case 'J':

            controlador.vaciarColas();

            break;

        case 'K':

            controlador.enlistarPacientesMenorMayor();

            break;

        case 'L':

            controlador.mostrarPacientesListasApendicitis();

            break;

        case 'M':

            controlador.mostrarPacientesListasHernias();

            break;

        case 'N':

            controlador.mostrarMayoresMenoresListas();

            break;

        case 'O':

            controlador.apilarPacientes();

            break;

        case 'P':

            controlador.mostrarPacientesPila();

            break;

        case 'Q':

            controlador.reiniciarPrograma();

            break;

        case 'R':

            cout << "Saliendo del programa...\n";

            break;

        default:

            cout << "Opcion incorrecta!\n\n";

            break;
        }

    } while(opcion != 'S');

    return 0;
}
