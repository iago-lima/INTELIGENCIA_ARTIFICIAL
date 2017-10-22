#include <iostream>
#include <vector>

using namespace std;

class Action{
    string name;
public:
    Action(string name){
        this->name = name;
    }

    string getName(){
        return this->name;
    }

};

class Perception {
    bool location;
    bool isDirty;

public:
    Perception(bool location = false, bool isDirty = true){
        this->isDirty = isDirty;
        this->location = location;
    }

    bool getIsDirty(){
        return this->isDirty;
    }

    bool getLocation(){
        return this->location;
    }

    void setIsDirty(bool value){
        this->isDirty = value;
    }

    void setLocation(bool value){
        this->location = value;
    }

};

class Agent{
protected:
    Perception perception;
    vector<Action> actions;

public:
    Agent(){}

    void setPerception(Perception perception){
        this->perception = perception;
    }

    Perception getPerception(){
        return this->perception;
    }
};

class Environment {
    bool isDirtyA, isDirtyB, agentLocation;
public:
    Environment(bool isDirtyA, bool isDirtyB, bool agentLocation){
        this->isDirtyA = isDirtyA;
        this->isDirtyB = isDirtyB;
        this->agentLocation = agentLocation;
    }

    Perception getPerception(){
        return Perception(agentLocation, agentLocation ? isDirtyA : isDirtyB);
    }

    void updateEnvironment(Perception p){
        p.getLocation() ? isDirtyA = p.getIsDirty() : isDirtyB = p.getIsDirty();
        this->agentLocation = p.getLocation();
    }

    bool isDirty(){
        return this->isDirtyA | this->isDirtyB;
    }

    bool getIsDirtyA() const{
        return isDirtyA;
    }

    void setIsDirtyA(bool value){
        this->isDirtyA = value;
    }

    bool getIsDirtyB() const{
        return isDirtyB;
    }

    void setIsDirtyb(bool value){
        this->isDirtyB = value;
    }

    bool getAgentLocation() const{
        return this->agentLocation;
    }
    void setAgentLocation(bool value){
        this->agentLocation = value;
    }
};

class SimpleRefrexAgent : Agent {
private:

public:
    Action selectAction(Perception perception1){

        this->perception = perception1;

        if(perception.getIsDirty()){
            this->actions.push_back(Action("Aspirar"));
            this->perception.setIsDirty(false);
            return Action("Aspirar");
        }
        else if(perception.getLocation()){
            this->actions.push_back(Action("Direita"));
            this->perception.setLocation(false);
            return Action("Direita");
        }
        else if(!perception.getLocation()){
            this->actions.push_back(Action("Esquerda"));
            this->perception.setLocation(true);
            return Action("Esquerda");
        }
    }

    void setPerception(Perception perception){
        this->perception = perception;
    }

    Perception getPerception(){
        return this->perception;
    }
};

int main()
{    
    Environment ambiente(true,true,true);
    SimpleRefrexAgent s;

    int i;
    cout << "Digite a quantidade de interações: ";
    cin >> i;

    while(i > 0){

        s.setPerception(ambiente.getPerception());

        cout << "Sala: ";
        cout << (ambiente.getAgentLocation() ? "A" : "B") << endl;

        cout << "Suja: ";
        cout << (ambiente.getAgentLocation() ? (ambiente.getIsDirtyA() ? "Sim" : "Não") : (ambiente.getIsDirtyB() ? "Sim" : "Não")) << endl;
        cout << s.selectAction(s.getPerception()).getName() << endl << endl;

        ambiente.updateEnvironment(s.getPerception());

        i--;
    }

}
