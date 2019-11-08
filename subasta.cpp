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
    /*for (auto it=mapa.begin();it!=mapa.end();it++)
        cout<<it->first<<"/"<<it->second.first<<"/"<<it->second.second<<endl;*/
    archivo.close();
}

subasta::subasta(const string &nombrearchivo) : nombrearchivo(nombrearchivo) {}

void subasta::generarArchivo() {
    // ahhh me falto tiempo
    archivoR.open("resultado.txt",ios::out);
    string a;
    for (auto it=mapa.begin();it!=mapa.end();it++){
        if (it->first==it->second.first){
            archivoR<<it->first<<" "<<getMayor(it->first)<<" "<<getPromedio(it->first)<<getMenor(it->first)<<endl;
            a= it->first;
                    }
    }
}

int subasta::getMayor(const string &value) {
    vector<int>vec;
    for (auto it=mapa.begin();it!=mapa.end();it++){
        if (it->second.first==value)
            vec.push_back(it->second.second);
    }
    int max=0;
    for (auto i=begin(vec);i<begin(vec);i++)
        if (max<*i)
            max=*i;
    return max;
}

float subasta::getPromedio(const string &value) {
    vector<int>vec;
    for (auto it=mapa.begin();it!=mapa.end();it++){
        if (it->second.first==value)
            vec.push_back(it->second.second);
    }
    int sum=0;
    for (auto i=begin(vec);i<begin(vec);i++)
            sum+=*i;
    return sum/vec.size();
}

int subasta::getMenor(const string &value) {
    vector<int>vec;
    for (auto it=mapa.begin();it!=mapa.end();it++){
        if (it->second.first==value)
            vec.push_back(it->second.second);
    }
    int min=vec[0];
    for (auto i=begin(vec);i<begin(vec);i++)
        if (min>*i)
            min=*i;
    return min;
}

void subasta::descalificar() {
    string a;
    string b;
    // no llegue a encontar forma de elimnar a los repetidos :c
for (auto it=mapa.begin();it!=mapa.end();it++){
    a=it->first.substr(0,it->first.find(' '));
    for (auto it2=it++;it2!=mapa.end();it2++){
        b=it2->first.substr(0,it2->first.find(' '));
        if (a==b){
            mapa.erase(it);
            mapa.erase(it2);
        }
    }
}
    for (auto it=mapa.begin();it!=mapa.end();it++)
        cout<<it->first<<"/"<<it->second.first<<"/"<<it->second.second<<endl;

}

