#include <iostream>
using namespace std;
#include <iomanip>
#include "TiposBasicos.h"
#include "BiBST.h"
#include "TableroInfinito.h"

int main() {
    BiBST nodo = new BBNode;
    nodo->kx = 1;
    nodo->ky = 0;
    
    insertBBNode(nodo, 3, 0);
    insertBBNode(nodo, 4, 0);
    insertBBNode(nodo, 5, 0);
    insertBBNode(nodo, 8, 0);
    insertBBNode(nodo, 4, 1);


    PrintBB(nodo);
}