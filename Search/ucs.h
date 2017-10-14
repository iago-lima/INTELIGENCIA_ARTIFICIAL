#ifndef CUSTO_H
#define CUSTO_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include "enum.h"
#include "graph.h"
#include "state.h"
#include "node.h"
#include <algorithm>

using namespace std;

class Comp{
    bool reverse;
public:
    Comp(const bool& reverse = false);

    bool operator() (Node& lhs, Node& rhs);
};


//Uniform cost search.
class UniformCostSearch{
public:
    UniformCostSearch();

    vector<Node> UCS(State _origin, State _destiny, Graph graph);
};


#endif // CUSTO_H
