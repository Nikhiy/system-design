#include <bits/stdc++.h>
using namespace std;
enum class CarState{
    MOVINGUP,
    MOVINGDOWN,
    IDLE,
    EMERGENCY,
    MAINTENANCE
};
class Button{
    public:
    bool isPressed;
    Button(){
        isPressed=false;
    }
    void PressButton(){
        isPressed=!isPressed;
    }
};
class UpButton:public Button{
    public:
    UpButton(){

    }
};
class DownButton:public Button{
    public:
    DownButton(){

    }
};
class FloorButton:public Button{
    public:
    FloorButton(){

    }
};
class OpenButton:public Button{
    public:
    OpenButton(){

    }
};
class EmergencyButton:public Button{
    public:
    EmergencyButton(){

    }
};
class CloseButton:public Button{
    public:
    CloseButton(){

    }
};
class Display{
    public:
    Direciton dir;
    int floorNumber;
    Display(){
        floorNumber=0;
    }
    void DisplayDetails(){

    }
};
class DashBoard{
    public:
    DashBoard(){

    }
};
class FloorDashBoard:public DashBoard{
    public:
    Display* floorDisplay;
    UpButton* up;
    DownButton* down;
    FloorDashBoard(Display* s,UpButton* w,DownButton* d){
        floorDisplay=f;
        up=u;
        down=d;
    }
};
class CarDashBoard:public DashBoard{
    public:
    Display* CarDisplay;
    vector<FloorButton*> floors;
    Open* open;
    Close* close;
    EmergencyButton* eb;
    CarDashBoard(){

    }
    
};
class Central{
    public:
    vector<Car*> cars;
    Central(){

    }
    void addCar(Car* c){
        cars.push_back(c);
    }
    Car* getbestCar(Floor* f,Direciton dir){

    }
};
class Floor{
    public:
    int floorNmuber;
    FloorDashBoard* fd;
    Central* central;
    Floor(int f,FloorDashBoard* f,Central* c){

    }
    void pressButton(Direciton dir){

    }
};
class AlertService{
    public:
    send Alert(){

    }
};
class Car{
    public:
    int id;
    int load;
    Floor* floor;
    Door* door;
    CarState state;
    AlertService* alert;
    Car(int i,Floor* f,Door* d,CarState s,AlertService* a){
        id=i;
        floor=f;
        door=d;
        state=s;
        alert=a;
        load=0;
    }
    int calculateLoad(){

    }

};