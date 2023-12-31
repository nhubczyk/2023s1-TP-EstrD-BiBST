#include <iostream>
#include <algorithm>
#include "BiBST.h"
using namespace std;


//==========================================================================
// Invariante de representación
//==========================================================================
/* INV.REP.
   * En cada nodo del arbol BiBST existen un par de claves, formando una coordenada.
   * La raiz del arbol BiBST posee un array de 4 subarboles que se representan con un
     cuadrante.
   * Cada nodo del arbol BiBST representa una celda del tablero mendiante sus coordena
     das.
   * Cada nodo del arbol representa mediante un arreglo la cantidad de bolitas de 
     cada color a insertar en la celda.
   * Cada par de claves no pueden repetirse en distintos nodos.
*/

//==========================================================================
// Implementación
//==========================================================================

BBNode* findBBNode(BBNode* nodo, int x, int y) { 
    if (nodo->kx == x && nodo->ky == y) {
      return nodo; 
    }
    else if (x > nodo->kx && y > nodo->ky) {
      return findBBNode(nodo->hijo[NE], x, y);
    }
    else if (x > nodo->kx && y <= nodo->ky) {
      return findBBNode(nodo->hijo[SE], x, y);
    }
    else if (x <= nodo->kx && y > nodo->ky) {
      return findBBNode(nodo->hijo[NO], x, y);
    }
    else if (x <= nodo->kx && y <= nodo->ky) {
      return findBBNode(nodo->hijo[SO], x, y);
    }
    else {
      return NULL;
    } 
}

BBNode* insertBBNode(BBNode* nodo, int x, int y) { 
    if (nodo == NULL) {
        BBNode* node = new BBNode;
        node->kx=x;
        node->ky=y;
        return node; 
    }
    else {
      BBNode * nodoAnterior;
      while(nodo != NULL) {
        nodoAnterior = nodo;
        if (nodo->kx == x && nodo->ky == y) {
          return nodo;
        }
        else if (x > nodo->kx && y > nodo->ky) {
          nodo = nodo->hijo[NE];
        }
        else if (x > nodo->kx && y <= nodo->ky) {
          nodo = nodo->hijo[SE];
        }
        else if (x <= nodo->kx && y > nodo->ky) {
          nodo = nodo->hijo[NO];
        }
        else if (x <= nodo->kx && y <= nodo->ky) {
          nodo = nodo->hijo[SO];
        }
      }
      BBNode* nodoNuevo = new BBNode;
      nodoNuevo->kx=x;
      nodoNuevo->ky=y;
      if (x > nodoAnterior->kx && y > nodoAnterior->ky) {
        nodoAnterior->hijo[NE] = nodoNuevo;
        return nodoAnterior->hijo[NE];
      }
      else if (x > nodoAnterior->kx && y <= nodoAnterior->ky) {
        nodoAnterior->hijo[SE] = nodoNuevo;
        return nodoAnterior->hijo[SE];
      }
      else if (x <= nodoAnterior->kx && y > nodoAnterior->ky) {
        nodoAnterior->hijo[NO] = nodoNuevo;
        return nodoAnterior->hijo[NO];
      }
      else if (x <= nodoAnterior->kx && y <= nodoAnterior->ky) {
        nodoAnterior->hijo[SO] = nodoNuevo;
        return nodoAnterior->hijo[SO];
      }
    }
}

void LiberarBiBST(BiBST t) { 
  if (t != NULL) {
    LiberarBiBST(t->hijo[NE, SE, NO, SO]);
    delete t;
  }
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

