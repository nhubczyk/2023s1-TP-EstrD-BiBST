#include <iostream>
#include <iomanip>
#include <algorithm>
#include "TiposBasicos.h"
#include "TableroInfinito.h"
#include "BiBST.h"
#include "BiBST.cpp"
using namespace std;

//==========================================================================
// Implementación de TableroInfinito
//==========================================================================
struct TableroInfinitoHeader {
  BiBST celda;
  BiBST celdaOrigen;
}; 

typedef TableroInfinitoHeader* TableroInfinito;
/* INV.REP.:
    * El cabezal dentro del tablero se representa mediante una coordenada 
      (x,y).
    * Cada celda dentro del tablero se representa mediante un nodo del arbol
      BiBST.
    * Cada celda del tablero puede contener como maximo hasta 4 bolitas de
      4 colores posibles.
*/

//--------------------------------------------------------------------------
TableroInfinito TInfInicial(){
  TableroInfinitoHeader* tablero = new TableroInfinitoHeader;
  BiBST celda = new BBNode;
  celda->kx=0;
  celda->ky=0;
  tablero->celda = celda;
  tablero->celdaOrigen = celda;
  return tablero;
}

//--------------------------------------------------------------------------
void PonerNTInf(TableroInfinito t, Color color, int n){
  // PRECOND: el color es válido
  t->celda->bolitas[color] += n;
}

//--------------------------------------------------------------------------
void SacarNTInf(TableroInfinito t, Color color, int n){
  // PRECOND:
  //  * el color es válido
  //  * hay al menos n bolitas en la celda actual en t
  if (t->celda->bolitas[color] >= n) {
    t->celda->bolitas[color] -= n;
  }else {
    BOOM("No existen la cantidad de bolitas n dadas");
  }
}

//--------------------------------------------------------------------------
void MoverNTInf(TableroInfinito t, Dir dir, int n){
  // PRECOND: la dirección dada es válida
  if (dir == NORTE) {
    t->celda->ky = t->celda->ky + n;
  }
  else if (dir == SUR) {
    t->celda->ky = t->celda->ky - n;
  }
  else if (dir == OESTE) {
    t->celda->kx = t->celda->kx - n;
  }
  else if (dir == ESTE) {
    t->celda->kx = t->celda->kx + n;
  }
}

//--------------------------------------------------------------------------
int nroBolitasTInf(TableroInfinito t, Color color) {
  // PRECOND: el color es válido
  return (t->celda->bolitas[color]);
}

//--------------------------------------------------------------------------
void LiberarTInf(TableroInfinito t){
  LiberarBiBST(t->celda);
  delete t;
}

//==========================================================================
// Impresión para verificaciones
//==========================================================================
void PrintRepTInf(TableroInfinito t) {
  cout << "Celda:" << t->celda->kx << t->celda->ky << endl;
  PrintBB(t->celda);
  // PISTA: utilizar PrintBB de BiBST
}
