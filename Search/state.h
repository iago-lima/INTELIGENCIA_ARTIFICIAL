#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class State{
    int state;
  public:
    State(){}
    State(int _state){
        state = _state;
    }

    int getState(){
        return state;
    }
    void setState(int value){
        state = value;
    }
};

#endif // STATE_H
