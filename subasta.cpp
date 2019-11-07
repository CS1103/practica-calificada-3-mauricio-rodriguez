//
// Created by mauri on 11/7/2019.
//

#include "subasta.h"

void subasta::leerDatos() {
    archivo.open(nombrearchivo,ios::in);
    string type;
    while (!archivo.eof()) {
        getline(archivo, dato);
        string temp;
        string temp2;
        if (isupper(dato[0])){
            type=dato;
            mapa[dato]=make_pair(type ,0);
        }
        else {
            temp=dato.substr(0,dato.find(' '));
            temp2= dato.substr(dato.find(' ')+1,dato.size());
            mapa[dato]=make_pair(type,stoi(temp2));
        }
    }
    archivo.close();
}

subasta::subasta(const string &nombrearchivo) : nombrearchivo(nombrearchivo) {}

void subasta::generarArchivo() {
    archivoR.open("resultado.txt");

}

int subasta::getMayor() {
    return 0;
}

float subasta::getPromedio() {
    return 0;
}

int subasta::getMenor() {
    return 0;
}

void subasta::descalificar() {
    for (auto it=mapa.begin();it!=mapa.end();it++){

    }
}

