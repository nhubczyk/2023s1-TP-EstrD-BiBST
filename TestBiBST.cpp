#include <iostream>
using namespace std;
#include <iomanip>
#include "TiposBasicos.h"
#include "BiBST.h"
#include "TableroInfinito.h"

int main() {
    BiBST nodo = new BBNode;
    nodo->kx = 3;
    nodo->ky = 4;
    
    insertBBNode(nodo, 2, 4);

    PrintBB(nodo);
}