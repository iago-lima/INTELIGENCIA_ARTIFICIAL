#ifndef DFS_H
#define DFS_H

#include <iostream>
#include <vector>
#include <string>
#include <stack> // Pilha para Busca por profundidade (DFS)
#include "enum.h"
#include "grafo.h"
#include "state.h"
#include "node.h"

using namespace std;
//Busca em profundidade.
class Deep_Search{
public:
    Deep_Search(){}

    vector<Node> DFS(State _origem, State _destino, Grafo grafo){
        //int numVertices = 20; // Número de vertices

        //Inicializando no raiz do grafo
        Node noInit;
        noInit.setAction(Action(_origem, _destino));
        noInit.setCustoDeCaminho(0);
        noInit.setPai(nullptr);
        noInit.setState(State(_origem.getState()));
        //Finalizando no raiz do grafo

        stack<Node> borda;
        vector<Node> resp;

        //Verificando se o estado inicial é o destido
        if(noInit.getStateNode().getState() == _destino.getState()){
            return resp;
        }
        //fim_verif_

        //Se não for add na borda
        borda.push(noInit);

        //Declarando explorados
        bool viewed[TAM_MAPA];
        for(int i = 0; i <  TAM_MAPA; i++){
            viewed[i] = false;
        }
        //fim_dec_expl

        while (true) {
            //Verificando se borda está vazia
            if(borda.empty()){
                throw string("Falha pois borda está vazia!\n");
            }
            //fim_Verif_

            //Pegando o que esta da borda
            noInit = borda.top();

            //Tirando da borda e setando que foi explorado
            borda.pop();
            int localAtual = noInit.getStateNode().getState();
            if(!viewed[localAtual]){
                cout << "Visitando " << localAtual << "..." << endl;
                resp.push_back(noInit);
                viewed[localAtual] = true;
            }
            //fim_Tirando

            int COLUNA;
            for(COLUNA = 0; COLUNA < TAM_MAPA; COLUNA++){
                if(grafo.getPeso(localAtual, COLUNA)){
                    Node newNo = Node(State(COLUNA), &noInit, Action(localAtual, COLUNA), 0);
                    if(!viewed[newNo.getStateNode().getState()]){
                        if((newNo.getStateNode().getState()) == _destino.getState()){
                            return resp;
                        }
                        borda.push(newNo);
                    }
                }
            }
        }
    }
};

#endif // DFS_H
