#include "Arbol.hpp"

Arbol::Arbol()
{
    // Creamos el paciente ficticio con el Id 50 e inicializamos el resto de valores del constructor
    Paciente* aux = new Paciente();
    aux->setId(50);
    raiz = new NodoArbol(aux);
    num_nodos = 0;
    this->cola = Cola();
}
// Metodo privado insertar
pnodoAbb Arbol::insertar(pnodoAbb abb, Paciente* p)
{
    if(!abb) { // Si no hay, se crea
        abb = new NodoArbol(p);
    } else {

        if(p->getId() <= abb->paciente->getId()) { // Si el id es menor al id de la raiz en este caso 50, se inserta el
                                                   // paciente en el arbol por la izquierda
            if(!(abb->izq)) {                      // Si no hay un nodo por la izquierda lo crea
                abb->izq = new NodoArbol(p);
                this->num_nodos++;
            } else { // Una vez creado ya lo inserta
                abb->izq = insertar(abb->izq, p);
            }

        } else { // Si el id es mayor al id de la raiz en este caso 50, se inserta el paciente en el arbol por la
                 // derecha
            if(!(abb->der)) { // Si no hay un nodo por la derecha lo crea
                abb->der = new NodoArbol(p);
                this->num_nodos++;
            } else { // Una vez creado lo inserta
                abb->der = insertar(abb->der, p);
            }
        }
    }

    return abb;
}
// Metodo publico insertar
void Arbol::insertar(Paciente* p)
{
    insertar(raiz, p);
}
// Metodo privado de dibujar dado por la profesora
void Arbol::dibujarNodo(vector<string>& output,
    vector<string>& linkAbove,
    pnodoAbb nodo,
    int nivel,
    int p,
    char linkChar)
{

    if(!nodo)
        return;
    int h = output.size();
    string SP = " ";
    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());
    if(nodo->izq) {
        int numeroQueQuieroImprimirEnElArbol = nodo->izq->paciente->getId();
        string izqdato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }
    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    int numeroQueQuieroImprimirEnElArbol = nodo->paciente->getId();
    string nododato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
    output[nivel] += nododato;
    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;
    if(nodo->der)
        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}
// Metodo privado altura
int Arbol::altura(pnodoAbb abb)
{
    if(abb) {                         // Minetras haya nodo
        if(abb->izq == nullptr) {     // Si la rama izquierda es vacia
            if(abb->der == nullptr) { // Y tambien la derecha
                return 0;             // Arbol vacio
            } else {
                return 1 +
                    altura(
                        abb->der); // Suma uno a la altura y recorre el arbol recursivamente con la rama de la derecha
            }

        } else {
            if(abb->der == nullptr) { // Si solo esta vacia la rama de la derecha
                return 1 +
                    altura(
                        abb->izq); // Suma uno a la altura y recorre el arbol recursivamente por la rama de la izquierda

            } else { // En el caso de que ambas ramas no esten vacias
                return 1 + max(altura(abb->izq), altura(abb->der));
            }
        }

    } else { // Si no hay nodo retorna 0
        return 0;
    }
}
// Metodo publico dibujar
void Arbol::dibujar()
{
    int h = altura(raiz) + 1;
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');
    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }
    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}
// Metodo publcio que invoca al metodo pueblico para recorrer el arboo en postorden
void Arbol::mostrarPostOrdenArbol()
{
    postOrden(raiz);
}
// Metodo privado para mostrar el arbol en postorden
void Arbol::postOrden(pnodoAbb abb)
{
    if(abb != nullptr) {                 // Mientras que el nodo no este vacio
        postOrden(abb->izq);             // Primero recorremos el arbol por la izquierda
        postOrden(abb->der);             // Luego por la derecha
        if(abb->paciente->getId() != 50) // Se comprueba que no se incluya el nodo ficticio creado en el constructor
            abb->paciente->mostrarInformacionPaciente(); // Se muestra la raiz
    }
}
// Metodo publico que invoca al metodo eliminar el arbol en preorden
void Arbol::eliminarPreordeArbol()
{
    eliminarPreornden(raiz);
}
// Método privado para eliminar el arbol en preorden
void Arbol::eliminarPreornden(pnodoAbb abb)
{
    
    // En este caso para poder eliminar el arbol y poder pasarlo a la cola la idea va a ser pasar los pacientes
    // recorridos en preorden a una cola auxiliar inicializada en el constructor y como atributo privado, y luego de esa
    // cola auxiliar pasarlos a sus pertinentes colas, tanto de apendicitis como de hernias
    if(abb != nullptr) {
        if(abb->paciente->getId() != 50)        // Mientras que no sea el paciente ficticio
            this->cola.insertar(abb->paciente); // Insertamos la raiz en la cola

        eliminarPreornden(abb->izq); // despues recorremos el arbol por la izquierda
        eliminarPreornden(abb->der); // por ultimo por la derecha
    }
}
Paciente* Arbol::extraerCola()
{
    Paciente* aux;
    aux = cola.eliminar();
    return aux;
}
// Metodo privado que te devuelve un nodo
pnodoAbb Arbol::maximo(pnodoAbb abb)
{
    if(abb->der == nullptr) { // Si la rama de la derecha esta vacia retorna ese mismo nodo
        return abb;
    } else {                     // Si hay rama de la derecha
        return maximo(abb->der); // Recorre recursivamente el arbol por la rama de la derecha retornando el ultimo nodo
                                 // mas a la derecha que en este caso tendra el maximo id
    }
}
// Método privado que te devuelve un nodo, en este caso el de mas a la izquierda del arbol, siendo el minimo
pnodoAbb Arbol::minimo(pnodoAbb abb)
{
    if(abb->izq == nullptr) { // Si no hay rama por la izquierda te retorna el nodo el propio nodo
        return abb;
    } else {                     // Si hay rama de la izquierda
        return minimo(abb->izq); // Recorre recursivamente el arbol por la rama de la izquierda retornando el ultimo
                                 // nodo mas a la izquierda que en este caso tendra el minimo id
    }
}
// Metodo publico para mostrar los Pacientes con mayor y menor id
void Arbol::mostrarMenoresMayoresArbol()
{
    cout << "\tApendicitis Menor ID: " << endl, minimo(raiz->izq)->paciente->mostrarInformacionPaciente();
    cout << "\tApendicitis Mayor ID: " << endl, maximo(raiz->izq)->paciente->mostrarInformacionPaciente();
    cout << "\tHernias Menor ID: " << endl, minimo(raiz->der)->paciente->mostrarInformacionPaciente();
    cout << "\tHernias Mayor ID: " << endl, maximo(raiz->der)->paciente->mostrarInformacionPaciente();
}
// Metodo publico que te retorna la longitud del arbol
int Arbol::getLongitud()
{
    return this->num_nodos;
}
// Metodo publico que que invoca al metodo privado para saber el numero de pares
int Arbol::nPares()
{
    return nPares(raiz);
}
// Metodo privado para saber el numero de pacientes con id par
int Arbol::nPares(pnodoAbb abb)
{
    if(abb != nullptr) { // Mientras qhe el nodo no sea vacio
        if(abb->paciente->getId() % 2 == 0 and
            abb->paciente->getId() !=
                50) // Mientras que el resto de la division entera entre dos sea 0 y el id sea diferente al
            // nodo ficticio tenemos un paciente con los atributos correctos
            return 1 + nPares(abb->izq) + nPares(abb->der); // Sumamos uno y se recorre el arbol por la izquierda y por
                                                            // la derecha sumando uno en el caso
        // de que los atributos cumplan las caracteristicas impuestas en la condicion
        else // Si no se cumple la condicion impuesta recorro el arbol por la izquierda y por la derecha
            return nPares(abb->izq) + nPares(abb->der);
    } else { // En el caso de que el nodo este vacio devuelvo 0
        return 0;
    }
}
// Metodo publico de mostrar hojas que invoca el metodo privado
void Arbol::mostrarHojas()
{
    mostrarHojas(raiz);
}
// Metodo privado para mostrar hojas
void Arbol::mostrarHojas(pnodoAbb abb)
{
    if(abb != nullptr) {        // Si el nodo no esta vacio
        mostrarHojas(abb->izq); // Recorremos recursivamente el nodo por la izquierda
        if(abb->paciente->getId() != 50 and abb->der == nullptr and
            abb->izq == nullptr) // Si no tiene rama izquierda ni derecha y no es el paciente ficticio
            abb->paciente->mostrarInformacionPaciente(); // Mostramos la informacion de ese paciente
        mostrarHojas(abb->der);                          // Despues recorremos el arbol por la derecha
    }
}
// Metodo privado para eliminar un paciente dado su id
pnodoAbb Arbol::eliminarId(int nId, pnodoAbb abb)
{
    if(abb) {
        if(nId == abb->paciente->getId() and
            nId != 50) { // Si el id introducido coincide con el del paciente y es diferente al del nodo fictico
            abb = borrarNodo(abb);             // Borramos el nodo
        } else {                               // En el caso de que no coincida el id
            if(nId < abb->paciente->getId()) { // Si es menor el id introducido al del paciente se recorre el arbol
                                               // recursivamente por la izquierda
                abb->izq = eliminarId(nId, abb->izq);
            } else {
                if(nId > abb->paciente->getId()) { // Si es mayor el id introducido al del paciente se recorre le arbol
                                                   // recursivamente por la derecha
                    abb->der = eliminarId(nId, abb->der);
                }
            }
        }
    }

    return abb;
}
// Metodo publico para eliminar id que invoca al metodo privado eliminarId y al de Contarndos
void Arbol::eliminarPorId(int nHab)
{
    eliminarId(nHab, raiz); // Invocamos el metodo creado anteriormente

    if(num_nodos != 0)
        num_nodos--;
}
/*Paciente* Arbol::eliminarPorIdx(int nHab)
{
    Paciente* p;
    p = eliminarId(nHab, raiz)->paciente; // Invocamos el metodo creado anteriormente
    if(num_nodos != 0) {
        num_nodos--;
    }

    return p;
}
*/
// Metodo privado para borrar nodo
pnodoAbb Arbol::borrarNodo(pnodoAbb abb)
{
    pnodoAbb aux;
    Paciente* e;
    if(abb->izq == nullptr) {
        aux = abb->der;
        abb->der = nullptr;
        delete abb;
    } else {
        if(abb->der == nullptr) {
            aux = abb->izq;
            abb->izq = nullptr;
            delete abb;
        } else {
            e = maximo(abb->izq)->paciente;
            abb->paciente = e;
            abb->izq = eliminarId(e->getId(), abb->izq);
            aux = abb;
        }
    }
    return aux;
}

Cola Arbol::getCola()
{
    return this->cola;
}

Arbol::~Arbol()
{
}
