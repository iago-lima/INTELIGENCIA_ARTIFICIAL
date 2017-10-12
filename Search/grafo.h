#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <string>
#include "enum.h"
using namespace std;

class Grafo{
    int grafo[20][20];
  public:
    Grafo(){}

    void addPonto(int _linha, int _coluna, int _peso){
        grafo[_linha][_coluna] = _peso;
    }
    int getPeso(int _linha, int _coluna){
        if(grafo[_linha][_coluna]){
            return grafo[_linha][_coluna];
        }else if (grafo[_coluna][_linha]) {
            return grafo[_coluna][_linha];
        }
        return 0;
    }
};


#endif // GRAFO_H
