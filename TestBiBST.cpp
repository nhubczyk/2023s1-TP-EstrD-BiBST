#include <iostream>
using namespace std;
#include <iomanip>
#include "TiposBasicos.h"
#include "BiBST.h"
#include "TableroInfinito.h"

int main() {
    BiBST nodo = new BBNode;
    int coordenadaX = 2;
    int coordenadaY = 2;
    nodo->kx = coordenadaX;
    nodo->ky = coordenadaY;

    PrintBB(findBBNode(nodo, 2, 2));  
}