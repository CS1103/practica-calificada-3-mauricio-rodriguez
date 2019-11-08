#include "subasta.h"
int main() {
    subasta *subasta1;
    subasta1 = new subasta("bid_example.txt");
    subasta1->leerDatos();
    subasta1->descalificar();
    return 0;
}