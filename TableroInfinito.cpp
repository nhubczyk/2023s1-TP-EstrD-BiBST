#include <iostream>
#include <iomanip>
#include <algorithm>
#include "TiposBasicos.h"
#include "TableroInfinito.h"
#include "BiBST.h"
using namespace std;

//==========================================================================
// Implementación de TableroInfinito
//==========================================================================

struct TableroInfinitoHeader {
  int x;
  int y;
  BiBST celdas;
};


typedef TableroInfinitoHeader* TableroInfinito;
/* INV.REP.:
    * Cada celda dentro del tablero se representa mediante un nodo del arbol
      BiBST.
*/

//--------------------------------------------------------------------------
TableroInfinito TInfInicial(){
  TableroInfinitoHeader* tablero = new TableroInfinitoHeader;
  tablero->x=0;
  tablero->y=0;
  tablero->celdas = EMPTYBB;

  return tablero;
}


//--------------------------------------------------------------------------
void PonerNTInf(TableroInfinito t, Color color, int n){
  // PRECOND: el color es válido
  BBNode* nodo;
  nodo = insertBBNode(t->celdas, t->x, t->y);
  nodo->bolitas[color] += n;
  if (t->celdas == EMPTYBB) {
    t->celdas = nodo;
  }
}

//--------------------------------------------------------------------------
void SacarNTInf(TableroInfinito t, Color color, int n){
  // PRECOND:
  //  * el color es válido
  //  * hay al menos n bolitas en la celda actual en t
  BBNode* celdaActual;
  celdaActual = findBBNode(t->celdas, t->x, t->y);
  if (celdaActual != NULL && celdaActual->bolitas[color] >= n) {
    celdaActual->bolitas[color] -= n;
  }else {
    BOOM("No existen la cantidad de bolitas n dadas");
  }
}

//--------------------------------------------------------------------------
void MoverNTInf(TableroInfinito t, Dir dir, int n){
  // PRECOND: la dirección dada es válida
  if (dir == NORTE) {
    t->y += n;
  }
  else if (dir == SUR) {
    t->y -= n;
  }
  else if (dir == OESTE) {
    t->x -= n;
  }
  else if (dir == ESTE) {
    t->x += n;
  }
}

//--------------------------------------------------------------------------
int nroBolitasTInf(TableroInfinito t, Color color) {
  // PRECOND: el color es válido
  BBNode* celdaActual;
  celdaActual = findBBNode(t->celdas, t->x, t->y);
  if (celdaActual != NULL) {
    return (celdaActual->bolitas[color]);
  }
  else {
    return 0; // La celda esta vacia.     
  }
}

//--------------------------------------------------------------------------
void LiberarTInf(TableroInfinito t){
  LiberarBiBST(t->celdas);
  delete t;
}

//==========================================================================
// Impresión para verificaciones
//==========================================================================
void PrintRepTInf(TableroInfinito t) {
  cout << "Coordenada: (" << t->x << ", " << t->y << ")" << endl;
  PrintBB(t->celdas);
  // PISTA: utilizar PrintBB de BiBST
}
