//
// Created by mauri on 11/7/2019.
//

#ifndef PC3_SUBASTA_H
#define PC3_SUBASTA_H

#include "headers.h"
class subasta {
private:
map<string,pair<string,int>> mapa;
fstream archivoR;
string nombrearchivo;
string dato;
stringstream datos;
ifstream archivo;
public:
    void leerDatos();
    subasta(const string &nombrearchivo);
    void generarArchivo();
    int getMayor();
    float getPromedio();
    int getMenor();
    void descalificar();
};


#endif //PC3_SUBASTA_H
