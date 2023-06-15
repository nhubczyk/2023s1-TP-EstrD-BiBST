#include <iostream>
#include <algorithm>
#include "BiBST.h"
using namespace std;


//==========================================================================
// Invariante de representación
//==========================================================================
/* INV.REP.
   * En (NodeT (kx, ky) ti td):
        * todos los elementos de ti son menores que el par de claves (kx, ky).
        * todos los elementos de td son mayores que el par de claves (kx, ky).
        * El arbol debe tener 4 nodos hijos desde la raiz, cada uno de los 
          cuales va a representar un cuadrante, siendo:
            * x > kx && y > ky expresa al cuadrante NE.
            * > kx && y <= ky expresa al cuadrante SE.
            * x <= kx && y > ky expresa al cuadrante NO.
            * x <= kx && y <= ky expresa al cuadrante SO
        * ti y td cumplen el invariante de BiBST.
*/

//==========================================================================
// Implementación
//==========================================================================
BBNode* findBBNode(BBNode* nodo, int x, int y) { 
  return NULL; // REEMPLAZAR
}

BBNode* insertBBNode(BBNode* nodo, int x, int y) { 
  return NULL; // REEMPLAZAR
}

void LiberarBiBST(BiBST t) { 
  // COMPLETAR
}

//==========================================================================
// Impresión para verificaciones
//==========================================================================
void PrintBBNode(BBNode* t, int tab) {
  if (t == NULL) { return; }
  INDENT(tab)
  cout << "  (" << t->kx << "," << t->ky << "): ";
  PRINTCOLORN(AZUL , t->bolitas[AZUL ]); 
  cout << ", "; PRINTCOLORN(NEGRO, t->bolitas[NEGRO]); 
  cout << ", "; PRINTCOLORN(ROJO , t->bolitas[ROJO ]); 
  cout << ", "; PRINTCOLORN(VERDE, t->bolitas[VERDE]); 
  cout << endl;
  PrintBBNode(t->hijo[NE], ++tab);
  PrintBBNode(t->hijo[SE], tab);
  PrintBBNode(t->hijo[NO], tab);
  PrintBBNode(t->hijo[SO], tab);
}

void PrintBB(BiBST t) {
  cout << "BiBST:" << endl;
  PrintBBNode(t, 0);
}

