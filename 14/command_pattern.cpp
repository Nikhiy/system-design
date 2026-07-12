#include<bits/stdc++.h>
using namespace std;
class ICommand{
    public:
    virtual void execute()=0;
    virtual void undo()=0;
};
class Light {
public:
    void on()  { 
        cout << "Light is ON" << endl; 
    }
    void off() { 
        cout << "Light is OFF" << endl;
    }
};

class Fan {
public:
    void on()  { 
        cout << "Fan is ON" << endl; 
    }
    void off() { 
        cout << "Fan is OFF" << endl; 
    }
};
class lightCommand:public ICommand{
    private:
    Light* light;
    lightCommand(Light* l){
        light=l;
    }
    void execute(){
        light->on();
    }
    void undo(){
        light->off();
    }
};
class fanCommand:public ICommand{
    private:
    Fan* fan;
    fanCommand(Fan* f){
        fan=f;
    }
    void execute(){
        fan->on();
    }
    void undo(){
        fan->off();
    }
};
class Remote{
    private:
    static const int numButtons = 4;
    ICommand* buttons[numButtons];
    bool buttonPressed[numButtons];
    public:
    Remote(){
        for(int i=0;i<numButtons;i++){
            buttonPressed[i]=false;
            buttons[i]=nullptr;
        }
    }
    void setCommand(int idx, ICommand* cmd) {
        if (idx >= 0 && idx < numButtons) {
            if (buttons[idx] != nullptr)
                delete buttons[idx];
            buttons[idx] = cmd;
            buttonPressed[idx] = false;
        }
    }
    void pressButton(int idx) {
        if (idx >= 0 && idx < numButtons && buttons[idx] != nullptr) {
            if (buttonPressed[idx] == false) {
                buttons[idx]->execute();
            } else {
                buttons[idx]->undo();
            }
            buttonPressed[idx] = !buttonPressed[idx];
        } else {
            cout << "No command assigned at button " << idx << endl;
        }
    }
};