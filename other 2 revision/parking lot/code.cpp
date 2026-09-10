#include <bits/stdc++.h>
using namespace std;
enum class SpotType{
    COMPACT,
    LARGE,
    BIKE,
    ACCESSIBLE
};
class Spot{
    public:
    int id;
    bool isFull;
    SpotType st;
    Spot(int i,SpotType s){
        isFull=false;
        id=i;
        st=s;
    }
};
class Ticket{
    public:
    int price;
    bool isPaid;
    string startTime;
    string endTime;
    Ticket(){
        price=0;
        isPaid=false;
        startTime="";//set it to present time
        endTime="";
    }
};
class Vehicle{
    public:
    int vid;
    Ticket* ticket;
    Spot* spot;
    Vehicle(int i,Ticket* t,Spot* s){
        spot=s;
        vid=i;
        ticket=t;
    }
};
class Car:public Vehicle{
    Car(){

    }
};
class Truck:public Vehicle{
    Truck(){
        
    }
};
class Vans:public Vehicle{
    Vans(){
        
    }
};
class Bike:public Vehicle{
    Bike(){
        
    }
};
class ParkingLot{
    public:
    vector<int> parkingspots;
    ParkingLot(){

    }
    void addSpot(Spot* s){
        parkingspots.push_back(s);
    }
};
class DisplayBoard{
    public:
    ParkingLot* pl;
    bool DisplayFull(){

    }
};
class Entry{
    public:
    Entry(){

    }
    void issueTicket(){

    }
};
class Exit{
    public:
    int amount;

}