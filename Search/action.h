#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <vector>
#include <string>
#include "state.h"
using namespace std;

class Action{
    State origem;
    State destino;
public:
    Action(){}
    Action(State _origem, State _destino){
        origem = _origem;
        destino = _destino;
    }
    State getOrigem(){
        return origem;
    }
    void setOrigem(State value){
        origem = value;
    }
    State getDestino(){
        return destino;
    }
    void setDestino(State value){
        destino = value;
    }
};

#endif // ACTION_H
