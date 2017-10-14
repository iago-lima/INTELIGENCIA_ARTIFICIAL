#ifndef NODE_H
#define NODE_H

#include "state.h"
#include "action.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node{
    State state;
    float custoDeCaminho;
    Action action;
public:
    Node * pai;
    Node(){}
    Node(State _state, Node* _pai, Action _action, float _custo){
        state = _state;
        pai = _pai;
        action = _action;
        custoDeCaminho = _custo;
    }

    State getStateNode(){
        return state;
    }

    void setState(State value){
        state = value;
    }

    float getCustoDeCaminho(){
        return custoDeCaminho;
    }

    void setCustoDeCaminho(float value){
        custoDeCaminho = value;
    }

    Action getAction(){
        return action;
    }

    void setAction(Action value){
        action = value;
    }

    Node& getPai(){
        return *pai;
    }

    void setPai(Node *value){
        pai = value;
    }

    bool operator==(Node& _node){
        return this->custoDeCaminho == _node.getCustoDeCaminho();
    }

    struct OrdenarPorCusto{
        bool operator()(Node& lhs, Node& rhs){
            return lhs.getCustoDeCaminho() > rhs.getCustoDeCaminho();
        }
    };

};


#endif // NODE_H
