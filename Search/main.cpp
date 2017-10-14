#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "grafo.h"
#include "dfs.h"
#include "bfs.h"
#include "custouniforme.h"
//#include <utility> // Pra usar o make pair
using namespace std;

void InitGrafo(Grafo& grafo){
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
            grafo.addPonto(i, j, 0);

    grafo.addPonto(ORADEA, ZERIND, 71);
    grafo.addPonto(ORADEA, SIBIU, 151);
    grafo.addPonto(ZERIND, ARAD, 75);
    grafo.addPonto(ARAD, SIBIU, 140);
    grafo.addPonto(ARAD, TIMISOARA, 118);
    grafo.addPonto(TIMISOARA, LUGOJ, 111);
    grafo.addPonto(LUGOJ, MEHADIA, 70);
    grafo.addPonto(MEHADIA, DROBETA, 75);
    grafo.addPonto(DROBETA, CRAIOVA, 120);
    grafo.addPonto(SIBIU, FAGARAS, 99);
    grafo.addPonto(SIBIU, RVILCEA, 80);
    grafo.addPonto(RVILCEA, PITESTI, 97);
    grafo.addPonto(RVILCEA, CRAIOVA, 146);
    grafo.addPonto(CRAIOVA, PITESTI, 138);
    grafo.addPonto(FAGARAS, BUCHAREST, 211);
    grafo.addPonto(PITESTI, BUCHAREST, 101);
    grafo.addPonto(BUCHAREST, GIURGIU, 90);
    grafo.addPonto(BUCHAREST, URZICENI, 85);
    grafo.addPonto(URZICENI, HIRSOVA, 98);
    grafo.addPonto(URZICENI, VASLUI, 142);
    grafo.addPonto(HIRSOVA, EFORIE, 86);
    grafo.addPonto(VASLUI, IASI, 92);
    grafo.addPonto(IASI, NEAMT, 87);
}

int main(){

    Grafo grafo;
    InitGrafo(grafo);
    Deep_Search dfs;
    Breadth_Search bfs;
    UniformCostSearch custo;
    vector<Node> solucao;
    clock_t start, end;
    int c = 0;

    std::string CityName[] = {"ORADEA", "ZERIND", "ARAD", "TIMISOARA", "LUGOJ",
                               "MEHADIA", "DROBETA","SIBIU", "RVILCEA", "CRAIOVA",
                               "FAGARAS", "PITESTI", "BUCHAREST", "GIURGIU", "URZICENI",
                               "VASLUI", "IASI", "NEAMT", "HIRSOVA", "EFORIE", "TAM_MAPA"
                                };

    while(true){                

        try{
        cout << " 1 - Busca em Profundidade     \n"
                " 2 - Busca em Largura          \n"
                " 3 - Busca por custo uniforme  \n"
             << endl << "(opção): ";

            cin >> c;

            if(c == 1){
                cout << "Busca em profundidade:" << endl;
                start = clock();
                solucao = dfs.DFS(State(ARAD), State(BUCHAREST), grafo);
                end = clock();
                float time = (((end - start) * 1000.0) / CLOCKS_PER_SEC);
                cout << "Solução: " << "[ ";
                for(auto elemento : solucao){
                    cout << CityName[elemento.getStateNode().getState()] << " ";
                }
                cout << "]" << endl << "Tempo de execução: " << time << endl << endl;
            }

            if(c == 2){
                cout << "Busca em largura:" << endl;
                start = clock();
                solucao = bfs.BFS(State(ARAD), State(BUCHAREST), grafo);
                end = clock();
                float time = (((end - start) * 1000.0) / CLOCKS_PER_SEC);
                cout << "Solução: " << "[ ";
                for(auto elemento : solucao){
                    cout << CityName[elemento.getStateNode().getState()] << " ";
                }
                cout << "]" << endl << "Tempo de execução: " << time << endl << endl;
            }

            if(c == 3){
                cout << "Busca em largura:" << endl;
                start = clock();
                solucao = custo.BFS(State(ARAD), State(BUCHAREST), grafo);
                end = clock();
                float time = (((end - start) * 1000.0) / CLOCKS_PER_SEC);
                cout << "Solução: " << "[ ";
                for(auto elemento : solucao){
                    cout << CityName[elemento.getStateNode().getState()] << " ";
                }
                cout << "]" << endl << "Tempo de execução: " << time << endl << endl;
            }

        }catch(string e){
                cout << e << endl;
        }
    }





    return 0;
}




