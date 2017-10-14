#ifndef CUSTO_H
#define CUSTO_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include "enum.h"
#include "grafo.h"
#include "state.h"
#include "node.h"
#include <algorithm>

using namespace std;

class Comp{
    bool reverse;
public:
    Comp(const bool& reverse = false){
        this->reverse = reverse;
    }

    bool operator() (Node& lhs, Node& rhs){
        if(reverse) return (lhs.getCustoDeCaminho() > rhs.getCustoDeCaminho());
        else return (lhs.getCustoDeCaminho() < rhs.getCustoDeCaminho());
    }
};


//Busca de custo uniforme.
class UniformCostSearch{
public:
    UniformCostSearch(){}

    vector<Node> BFS(State _origem, State _destino, Grafo grafo){

        std::string CityName[] = {"ORADEA", "ZERIND", "ARAD", "TIMISOARA", "LUGOJ",
                                  "MEHADIA", "DROBETA","SIBIU", "RVILCEA", "CRAIOVA",
                                  "FAGARAS", "PITESTI", "BUCHAREST", "GIURGIU", "URZICENI",
                                  "VASLUI", "IASI", "NEAMT", "HIRSOVA", "EFORIE", "TAM_MAPA"
                                 };

        //Inicializando no raiz do grafo
        Node noInit;
        noInit.setAction(Action(_origem, _destino));
        noInit.setCustoDeCaminho(0);
        noInit.setPai(nullptr);
        noInit.setState(State(_origem.getState()));
        //Finalizando no raiz do grafo

        priority_queue<Node,vector<Node>,Node::OrdenarPorCusto> borda;
        vector<Node> resp;

        borda.push(noInit);

        bool viewed[TAM_MAPA];
        for(int i = 0; i <  TAM_MAPA; i++){
            viewed[i] = false;
        }

        while(true){
            if(borda.empty())
                throw string("Falha pois borda está vazia!\n");

            noInit = borda.top();

            if(noInit.getStateNode().getState() == _destino.getState()){
                resp.push_back(noInit);
                return resp;
            }

            borda.pop();
            int linha = noInit.getStateNode().getState();
            if(!viewed[linha]){
                cout << "Visitando " << CityName[linha] << "..." << endl;
                resp.push_back(noInit);
                viewed[linha] = true;
            }


            for(int j = 0; j < TAM_MAPA; j++){
                if(grafo.getPeso(linha,j)){
                    Node newNo = Node(State(j),&noInit,Action(linha,j),noInit.getCustoDeCaminho() + grafo.getPeso(linha,j));
                    if(!viewed[newNo.getStateNode().getState()]){
                        borda.push(newNo);
                    }
                }
            }
        }
    }
};


#endif // CUSTO_H
