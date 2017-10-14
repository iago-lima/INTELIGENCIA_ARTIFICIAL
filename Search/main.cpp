#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "graph.h"
#include "dfs.h"
#include "bfs.h"
#include "ucs.h"
#include "inputcmd.h"
//#include <utility> // Pra usar o make pair
using namespace std;

void InitGrafo(Graph& grafo){
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
            grafo.addPoint(i, j, 0);

    grafo.addPoint(ORADEA, ZERIND, 71);
    grafo.addPoint(ORADEA, SIBIU, 151);
    grafo.addPoint(ZERIND, ARAD, 75);
    grafo.addPoint(ARAD, SIBIU, 140);
    grafo.addPoint(ARAD, TIMISOARA, 118);
    grafo.addPoint(TIMISOARA, LUGOJ, 111);
    grafo.addPoint(LUGOJ, MEHADIA, 70);
    grafo.addPoint(MEHADIA, DROBETA, 75);
    grafo.addPoint(DROBETA, CRAIOVA, 120);
    grafo.addPoint(SIBIU, FAGARAS, 99);
    grafo.addPoint(SIBIU, RVILCEA, 80);
    grafo.addPoint(RVILCEA, PITESTI, 97);
    grafo.addPoint(RVILCEA, CRAIOVA, 146);
    grafo.addPoint(CRAIOVA, PITESTI, 138);
    grafo.addPoint(FAGARAS, BUCHAREST, 211);
    grafo.addPoint(PITESTI, BUCHAREST, 101);
    grafo.addPoint(BUCHAREST, GIURGIU, 90);
    grafo.addPoint(BUCHAREST, URZICENI, 85);
    grafo.addPoint(URZICENI, HIRSOVA, 98);
    grafo.addPoint(URZICENI, VASLUI, 142);
    grafo.addPoint(HIRSOVA, EFORIE, 86);
    grafo.addPoint(VASLUI, IASI, 92);
    grafo.addPoint(IASI, NEAMT, 87);
}

int main(){

    Graph graph;
    InitGrafo(graph);
    Deep_Search dfs;
    Width_Search bfs;
    UniformCostSearch custo;
    vector<Node> solution;
    clock_t start, end;
    int c = 0;
    int _originInt;
    int _destinyInt;
    string _origin;
    string _destiny;
    State origin;
    State destiny;

    std::string CityName[] = {"ORADEA", "ZERIND", "ARAD", "TIMISOARA", "LUGOJ",
                               "MEHADIA", "DROBETA","SIBIU", "RVILCEA", "CRAIOVA",
                               "FAGARAS", "PITESTI", "BUCHAREST", "GIURGIU", "URZICENI",
                               "VASLUI", "IASI", "NEAMT", "HIRSOVA", "EFORIE", "TAM_MAPA"
                                };

    while(true){                

        try{
        cout << "Options \n"
                " 1 - Search in Deep \n"
                " 2 - Search in Width \n"
                " 3 - Uniform Cost Search \n"
             << endl << "(option): ";

            cin >> c;

            cout << "Enter the origin: " << endl;
            cin >> _origin;

            cout << "Enter the destiny: " << endl;
            cin >> _destiny;

            _originInt = inputCMD(_origin);
            _destinyInt = inputCMD(_destiny);

            origin = State(_originInt);
            destiny = State(_destinyInt);

            cout << "Enter the origin" << endl;


            if(c == 1){
                cout << "Search in Deep:" << endl;
                start = clock();
                solution = dfs.DFS(origin,destiny, graph);
                end = clock();
                float time = (((end - start) * 1000.0) / CLOCKS_PER_SEC);
                cout << "Solution: " << "[ ";
                for(auto element : solution){
                    cout << CityName[element.getStateNode().getState()] << " ";
                }
                cout << "]" << endl << "Runtime: " << time << "ms" << endl << endl;
            }

            if(c == 2){
                cout << "Search in Width:" << endl;
                start = clock();
                solution = bfs.BFS(origin, destiny, graph);
                end = clock();
                float time = (((end - start) * 1000.0) / CLOCKS_PER_SEC);
                cout << "Solution: " << "[ ";
                for(auto element : solution){
                    cout << CityName[element.getStateNode().getState()] << " ";
                }
                cout << "]" << endl << "Runtime: " << time << "ms" << endl << endl;
            }

            if(c == 3){
                cout << "Uniform Cost Search:" << endl;
                start = clock();
                solution = custo.UCS(origin, destiny, graph);
                end = clock();
                float time = (((end - start) * 1000.0) / CLOCKS_PER_SEC);
                cout << "Solution: " << "[ ";
                for(auto element : solution){
                    cout << CityName[element.getStateNode().getState()] << " ";
                }
                cout << "]" << endl << "Runtime: " << time << "ms"
                                                              "" << endl << endl;
            }

        }catch(string e){
                cout << e << endl;
        }
    }





    return 0;
}




