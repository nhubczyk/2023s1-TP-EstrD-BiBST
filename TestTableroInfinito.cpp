#include <iostream>
using namespace std;
#include <iomanip>
#include "TiposBasicos.h"
#include "BiBST.h"
#include "TableroInfinito.h"

int main() {
    TableroInfinito nuevoTablero; 
    nuevoTablero = TInfInicial();

    PonerNTInf(nuevoTablero, AZUL, 3);
    SacarNTInf(nuevoTablero, AZUL, 1);
    LiberarTInf(nuevoTablero);

    PrintRepTInf(nuevoTablero);
}