#include<bits/stdc++.h>
using namespace std;
class Button{
    public:
    bool isPressed;
    virtual void press()=0;
    virtual void undo()=0;
};
class CarButton:public Button{
    public:
    int floor;
    CarButton(){
        isPressed=false;
    }
    void press(){
        isPressed=true;
    }
    void undo(){
        isPressed=false;
    }
    int getFloor(int n){
        floor=n;
        return floor;
    }
};
class FloorButton:public Button{
    public:
    FloorButton(){
        isPressed=false;
    }
    void press(){
        isPressed=true;
    }
    void undo(){
        isPressed=false;
    }
};
class EmergencyButton:public Button{
    public:
    EmergencyButton(){
        isPressed=false;
    }
    void press(){
        isPressed=true;
    }
    void undo(){
        isPressed=false;
    }
};
class DoorButton:public Button{
    public:
    DoorButton(){
        isPressed=false;
    }
    void press(){
        isPressed=true;
    }
    void undo(){
        isPressed=false;
    }
};
class Panel{
    Panel(){}
};
class CarPanel:public Panel{
    public:
    vector<CarButton*> buttons;
    DoorButton* opem;
    DoorButton* close;
    EmergencyButton* e;
    void enterEmergency(){

    }
    void exitEmergency(){

    }
};
class FloorPanel:public Panel{
    public:
    FloorButton* down;
    FloorButton* up;
    void PressUp(){}
    void PressDown(){}
};
class Display{
    public:
    int floor;
    Direction d;
    virtual void getFloor(int f)=0;
    virtual void getDirection(Direction dir)=0;
    virtual void displayDetails()=0;
};
class CarDisplay:public Display{
    public:
    int load;
    void getLoad(int l){}
    void displayDetails(){}
    void getFloor(int f){}
    void getDirection(Direction dir){}
};
class FloorDisplay:public Display{
    public:
    bool maitanence;
    void getMaintenace(bool m){}
    void showMaintanceStatus(){}
    void displayDetails(){}
    void getFloor(int f){}
    void getDirection(Direction dir){}
};
class Floor{
    public:
    int FloorNumber;
    vector<FloorDisplay*> displays;
    FloorPanel* panel;
    void showDetails(){}
};
class Door{
    public:
    bool isOpen;
    void OpenDoor(){}
    void CloseDoor(){}
};
class Request{
    public:
    int startFloor;
    int endFloor;
    Direction dir;
    Request(int s,int e,Direction d){}
};
class IMovementStrategy{
    public:
    vector<Car*> cars;
    virtual Car* move(Request* r)=0;
}
class normalStrategy:public IMovementStrategy{
    public:
    Car* move(Request* r){
        return nullptr;
    }
};
class Controller{
    public:
    IMovementStrategy* st;
    Controller(IMovementStrategy* s){
        st=s;
    }
    void assignCar(Request* r){
        Car* c=st->move(r);
        c->addRequest(r);
        c->MoveLogic();
    }
};
class Car{
    public:
    int id;
    int floor;
    int load;
    bool emergency;
    CarPanel* panel;
    CarDisplay* Display;
    Door* door;
    queue<Request* r> q;
    Car(CarPanel* p,CarDisplay& d,Door* do){}
    void getId(int i){}
    void getFloor(int f){}
    void getDoor(Door* d){}
    void startEmergency(){}
    void stopEmergency(){}
    void showDisplay(){}
    void MoveLogic(int f){}
    void addRequest(Request* r){}
};
class Building{
    public:
    vector<Floor*> floors;
    vector<Car*> cars;
};
class ElevatorSystem{
    public:
    Building* house;
    ElevatorSystem(Building* b){
        house=b;
    }
};


int main(){

    //-------------------------------
    // Create Floor Panels
    //-------------------------------

    FloorButton* up1 = new FloorButton();
    FloorButton* down1 = new FloorButton();

    FloorPanel* fp1 =
        new FloorPanel(up1, down1);

    FloorDisplay* fd1 =
        new FloorDisplay();

    Floor* floor0 =
        new Floor(0, fp1);

    floor0->displays.push_back(fd1);

    //-------------------------------
    // Elevator Car
    //-------------------------------

    DoorButton* open =
        new DoorButton();

    DoorButton* close =
        new DoorButton();

    EmergencyButton* emergency =
        new EmergencyButton();

    CarPanel* cp =
        new CarPanel(open, close, emergency);

    CarDisplay* cd =
        new CarDisplay();

    Door* door =
        new Door();

    Car* car1 =
        new Car(1, cp, cd, door);

    //-------------------------------
    // Building
    //-------------------------------

    vector<Floor*> floors = {floor0};
    vector<Car*> cars = {car1};

    Building* building =
        new Building(floors, cars);

    ElevatorSystem system(building);

    //-------------------------------
    // Strategy
    //-------------------------------

    IMovementStrategy* strategy =
        new normalStrategy();

    Controller controller(strategy);

    //-------------------------------
    // Passenger presses UP
    //-------------------------------

    up1->press();

    Request* request =
        new Request(0,5,Direction::UP);

    controller.assignCar(request);

}