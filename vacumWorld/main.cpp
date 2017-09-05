#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Enviromment{
    bool isDurtyA;
    bool isDurtyB;
    bool agentLocation;

public:
    Enviromment(bool _isDurtyA = true, bool _isDurtyB = true, bool _agentLocation = true) {
        this->isDurtyA = _isDurtyA;
        this->isDurtyB = _isDurtyB;
        this->agentLocation = _agentLocation;
    }

};

class Perception{
    bool location;
    bool isDirty;

public:
    Perception(bool _location = true, bool _isDirty = true){
        this->location = _location;
        this->isDirty = _isDirty;
    }
};

class Action{
    string name;
public:
    Action(string _name = ""){
        this->name = _name;

    }
};

class Agent{
    Perception perception;
    vector<Action> actions;

public:
    Agent() {}
};



class TableDriveAgent : Agent{
    vector<Perception> perceptions;
    map<Perception*,Action*> table;
public:
    TableDriveAgent(){}

    void setTable(){
        this->table.insert(make_pair(new Perception(true,false), new Action("Direita")));
        this->table.insert(make_pair(new Perception(true,true), new Action("Aspirar")));
        this->table.insert(make_pair(new Perception(false,false), new Action("Esquerda")));
        this->table.insert(make_pair(new Perception(false,true), new Action("Aspirar")));
    }
};

int main(){
    cout << "Hello World!" << endl;
    return 0;
}
