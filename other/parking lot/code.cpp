#include<bits/stdc++.h>
using namespace std;
//---------
// enum
// ticketStatus
// SpotType
//---------
enum class SpotType{
    HANDICAPPED,
    COMPACT,
    LARGE,
    MOTORBIKE,
    ELECTRIC
};
enum class ticketStatus{
    ACTIVE,
    PAID,
    LOST
};
class Vehicle{
    public:
    string licenceNumber;
    virtual void assignTicket()=0;
};
class bike:public Vehicle{
    public:
    bike(string& num){
        licenceNumber=num;
    }
    void assignTicket(){
        //assign ticket
    }
};
class car:public Vehicle{
    public:
    car(string& num){
        licenceNumber=num;
    }
    void assignTicket(){
        //assign ticket
    }
};
class van:public Vehicle{
    public:
    van(string& num){
        licenceNumber=num;
    }
    void assignTicket(){
        //assign ticket
    }
};
class truck:public Vehicle{
    public:
    truck(string& num){
        licenceNumber=num;
    }
    void assignTicket(){
        //assign ticket
    }
};
class electric:public Vehicle{
    public:
    string licenceNumber;
    electric(string& num){
        licenceNumber=num;
    }
    void assignTicket(){
        //assign ticket
    }
};
class Payment{
    public:
    virtual void startPayment(double amount)=0;
};
class CashPayment:public Payment{
    public:
    void startPayment(double a){
        //cash payment
    }
};
class CardPayment:public Payment{
    public:
    void startPayment(double a){
        //Card payment
    }
};
class IParkingSpot{
    public:
    Vehicle* vehicle;
    bool isFree;
    int id;
    virtual void assignVehicle(Vehicle* v)=0;
    virtual void removeVehicle()=0;
};
class BikeSpot:public IParkingSpot{
    public:
    BikeSpot(int i){
        id=i;
    }
    void assignVehicle(Vehicle* v){
        vehicle=v;
    }
    void removeVehicle(){
        vehicle=nullptr;
    }
};
class CompactSpot:public IParkingSpot{
    public:
    CompactSpot(int i){
        id=i;
    }
    void assignVehicle(Vehicle* v){
        vehicle=v;
    }
    void removeVehicle(){
        vehicle=nullptr;
    }
};
class LargeSpot:public IParkingSpot{
    public:
    LargeSpot(int i){
        id=i;
    }
    void assignVehicle(Vehicle* v){
        vehicle=v;
    }
    void removeVehicle(){
        vehicle=nullptr;
    }
};
class HandicapedSpot:public IParkingSpot{
    public:
    HandicapedSpot(int i){
        id=i;
    }
    void assignVehicle(Vehicle* v){
        vehicle=v;
    }
    void removeVehicle(){
        vehicle=nullptr;
    }
};
class ElectricSpot:public IParkingSpot{
    private:
    Payment* p;
    public:
    ElectricSpot(int i){
        id=i;
    }
    void assignVehicle(Vehicle* v){
        vehicle=v;
    }
    void removeVehicle(){
        vehicle=nullptr;
    }
    void chargePayment(Payment* payment,double amount){
        p=payment;
        p->startPayment(amount);
    }
};
class DisplayBoard{
    public:
    int id;
    void showFreeSpots(){
        //logic to show free spots
    }
};
class ParkingFloor{
    public:
    int floorNumber;
    vector<IParkingSpot*> spots;
    vector<DisplayBoard*> boards;
    vector<Entry*> inlist;
    vector<Exit*> outlist;
    void addDisplayBoard(){

    }
    void addParkingspot(SpotType s){

    }
    void addEntry(){

    }
    void addExit(){

    }
};
//Singleton
class ParkingLot{
    public:
    int id;
    void addFloor(){

    }
    bool isFull(){
        return false;
    }
};
class CustomerInfoPortal{
    public:
    int id;
    ParkingTicket* p;
    void getParkingTicket(ParkingTicket* ticket){
        p=ticket;
    }
    void finishPayment(Payment* p){
        p->payment(p.amount);
    }
};
class Entry{
    public:
    int id;
    void giveTicket(){

    }
};
class Exit{
    public:
    int id;
    Payment* p;
    void validateTicket(){

    }
    void startPaymentExit(Payment* payment,double amount){
        p=payment;
        p->payment(amount);
    }
};
class PaymentStrategy{
    public:
    virtual double calculate(string& starttime,string& endime,Vehicle* v)=0;
};
class strategy1:public PaymentStrategy{
    public:
    double claculate(string& s,string& e,Vehicle* vehicle){
        //calculate total
        return 0;
    }
};
class ParkingTicket{
    public:
    int Ticketid;
    string startTime;
    string EndTime;
    Vehicle* c;
    Payment* p;
    PaymentStrategy* s;
    double amount;
    ticketStatus status;
    Entry* in;
    Exit* out;
    ParkingTicket(PaymentStrategy* ps){
        ps=s;
    }
    void calculateTotal(string& s,string& e,Vehicle* vehicle){
        amount=s->calculate(s,e,vehicle);
    }
};
class Account{
    protected:
    string username;
    string password;
};
class Admin:public Account{
    private:
    ParkingLot* p;
    public:
    Admin(ParkingLot* lot){
        p=lot;
    }
    void addparkingfloor(){
        p->addFloor();
    }
};
class ParkingAttendant:public Account{
    private:
    ParkingTicket* p;
    public:
    void getTicket(ParkingTicket* ticket){
        p=ticket;
    }
};