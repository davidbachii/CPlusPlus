#ifndef ARBOL_HPP
#define ARBOL_HPP
#include "Cola.hpp"
#include "Lista.hpp"
#include "NodoArbol.hpp"
#include "Paciente.hpp"
#include <vector>
using namespace std;
class Arbol
{
public:
    Arbol();
    void insertar(Paciente* p);
    void dibujar();
    int getLongitud();
    void mostrarPostOrdenArbol();
    void eliminarPreordeArbol();
    void mostrarMenoresMayoresArbol();
    int nPares();
    void mostrarHojas();
    void eliminarPorId(int nHab);
    Paciente* extraerCola();
   // Paciente* eliminarPorIdx(int nhab);
    Cola getCola();
    ~Arbol();

private:
    pnodoAbb raiz;
    pnodoAbb insertar(pnodoAbb, Paciente* p);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos, char linkChar);
    int altura(pnodoAbb p);
    void postOrden(pnodoAbb ab);
    void eliminarPreornden(pnodoAbb ab);
    pnodoAbb maximo(pnodoAbb ab);
    pnodoAbb minimo(pnodoAbb ab);
    int nPares(pnodoAbb ab);
    void mostrarHojas(pnodoAbb ab);
    pnodoAbb borrarNodo(pnodoAbb ab);
    pnodoAbb eliminarId(int nHab, pnodoAbb ab);
    int ContarNodos(pnodoAbb ab);
    int num_nodos;
     Cola cola;
   
};

#endif // ARBOL_HPP
