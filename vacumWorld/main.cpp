#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Environment{
public:
    bool isdirtyA;
    bool isdirtyB;
    bool agentLocation;


    Environment(bool _isdirtyA = true, bool _isdirtyB = true, bool _agentLocation = true) {
        this->isdirtyA = _isdirtyA;
        this->isdirtyB = _isdirtyB;
        this->agentLocation = _agentLocation;
    }

    bool getdirtyA(){
        return this->isdirtyA;
    }

    bool getdirtyB(){
        return this->isdirtyB;
    }

    bool getAgentLocation(){
        return this->agentLocation;
    }
    void setAgentLocation(bool location){
        this->agentLocation = location;
    }
    void setdirtyA(bool dirtyA){
        this->isdirtyA = dirtyA;
    }
    void setdirtyB(bool dirtyB){
        this->isdirtyB = dirtyB;
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
    bool getLocation(){
        return this->location;
    }
    bool getIsDirty(){
        return this->isDirty;
    }

};

class Action{
    string name;

public:
    Action(string _name = ""){
        this->name = _name;

    }
    string getName(){
        return this->name;
    }
};

class Agent{

    Perception perception;
    vector<Action> actions;

public:
    Agent(){}

    vector<Action> getActions(){
        return this->actions;
    }
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

        perceptions.push_back(_perception);

        map<Perception*,Action*>::iterator it;
        for (it = table.begin(); it != table.end(); it++) {
            if((it->first->getLocation()== _perception.getLocation()) && (it->first->getIsDirty() == _perception.getIsDirty())){
                return *(it->second);
            }

        }
        return Action("Erro");

    }
};

int main(){


    TableDriveAgent agent;
    Action action;

    int n;
    bool location,dirtyA, dirtyB;
    bool isDirty;

    cout << "number of times the agent should act" << endl;
    cin >> n;
    cout << "Location, dirtyA, dirtyB" << endl;
    cin >> location >> dirtyA >> dirtyB;

    Environment environment(location,dirtyA,dirtyB);
    agent.setTable();


    for(int i = 0; i < n; i++){
        cout << "Location: " << environment.getAgentLocation() << " isDurtyA: " << environment.getdirtyA()
             << " isDurtyB: " << environment.getdirtyB() << endl;

        environment.getAgentLocation() ? isDirty = environment.getdirtyA() : isDirty = environment.getdirtyB();
        action = agent.selectAction(Perception(environment.getAgentLocation(), isDirty));

        cout << "Action: " << action.getName() << endl;

        if(action.getName() == "Aspirar"){
            environment.getAgentLocation() ? environment.setdirtyA(0) : environment.setdirtyB(0);
        }
        if(action.getName() == "Esquerda"){
            environment.setAgentLocation(1);
        }
        if(action.getName() == "Direita"){
            environment.setAgentLocation(0);
        }
    }


}
