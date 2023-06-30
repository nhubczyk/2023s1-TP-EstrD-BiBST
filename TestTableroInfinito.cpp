#include <iostream>
using namespace std;
#include <iomanip>
#include "TiposBasicos.h"
#include "BiBST.h"
#include "TableroInfinito.h"

int main() {
    TableroInfinito nuevoTablero; 
    nuevoTablero = TInfInicial();

    cout << "El nro de bolitas es (0):" << nroBolitasTInf(nuevoTablero, ROJO) << endl;
    MoverNTInf(nuevoTablero, NORTE, 2);
    PonerNTInf(nuevoTablero, AZUL, 4);
    MoverNTInf(nuevoTablero, SUR, 1);
    cout << "El nro de bolitas es (0):" << nroBolitasTInf(nuevoTablero, AZUL) << endl;
    PonerNTInf(nuevoTablero, ROJO, 1);
    cout << "El nro de bolitas es (1):" << nroBolitasTInf(nuevoTablero, ROJO) << endl;
    MoverNTInf(nuevoTablero, NORTE, 1);
    cout << "El nro de bolitas es (4):" << nroBolitasTInf(nuevoTablero, AZUL) << endl;
    SacarNTInf(nuevoTablero, AZUL, 1);
    cout << "El nro de bolitas es ():" << nroBolitasTInf(nuevoTablero, AZUL) << endl;

    PrintRepTInf(nuevoTablero);
}