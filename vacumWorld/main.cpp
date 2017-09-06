#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Enviromment{
public:
    bool isDurtyA;
    bool isDurtyB;
    bool agentLocation;


    Enviromment(bool _isDurtyA = true, bool _isDurtyB = true, bool _agentLocation = true) {
        this->isDurtyA = _isDurtyA;
        this->isDurtyB = _isDurtyB;
        this->agentLocation = _agentLocation;
    }

};

class Perception{
public:
    bool location;
    bool isDirty;

    Perception(bool _location = true, bool _isDirty = true){
        this->location = _location;
        this->isDirty = _isDirty;
    }
};

class Action{
public:
    string name;

    Action(string _name = ""){
        this->name = _name;

    }
};

class Agent{
public:
    Perception perception;
    vector<Action> actions;

    Agent() {}
};



class TableDriveAgent : Agent{
public:
    vector<Perception> perceptions;
    map<Perception*,Action*> table;

    TableDriveAgent(){}

    void setTable(){
        this->table.insert(make_pair(new Perception(true,false), new Action("Direita")));
        this->table.insert(make_pair(new Perception(true,true), new Action("Aspirar")));
        this->table.insert(make_pair(new Perception(false,false), new Action("Esquerda")));
        this->table.insert(make_pair(new Perception(false,true), new Action("Aspirar")));
    }

    Action selectAction(Perception _perception){

        perceptions.push_back(perception);

        map<Perception*,Action*>::iterator it;
        for (it = table.begin(); it != table.end(); it++) {
            if((it->first->location == _perception.location) && (it->first->isDirty == _perception.isDirty)){
                return *(it->second);
            }

        }
        return Action("Erro");

    }
};

int main(){
    TableDriveAgent agent;
    agent.setTable();

    Perception a(true,true);
    Perception b(false,false);

    Action _return;
    _return = agent.selectAction(a);
    cout << _return.name << endl;

    _return = agent.selectAction(b);
    cout << _return.name << endl;


}
