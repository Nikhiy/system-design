#include <bits/stdc++.h>
using namespace std;
class Movie{
    public:
    string name;
    string language;
    string genre;
    string releaseDate;
    Movie(string n,string l,string g,string r){
        name=n;
        language=l;
        genre=g;
        releaseDate=r;
    }
};
class Seat{
    public:
    int id;
    bool isBooked;
    Seat(int i){
        id=i;
        isBooked=false;
    }
    bool DisplaySeatStatus(){
        return isBooked==false;
    }
};
class Silver:public Seat{
    public:
    int price;
    Silver(int p){
        price=p;
    }
};
class Platinum:public Seat{
    public:
    int price;
    Platinum(int p){
        price=p;
    }
};
class Gold:public Seat{
    public:
    int price;
    Gold(int p){
        price=p;
    }
};
class Show{
    public:
    Movie* movie;
    string startTime;
    string endTime;
    vector<Seat*> seats;
    Show(Movie* m,string s,string e){
        movie=m;
        startTime=s;
        endTime=e;
    }
    void addSeat(Seat* s){
        seats.push_back(s);
    }
};
class Hall{
    public:
    vector<Show*> shows;
    Hall(){

    }
    void addShow(Show* s){
        shows.push_back(s);
    }
};
class Cinema{
    public:
    vector<Hall*> halls;
    Cinema(){

    }
    void addHall(Hall* s){
        halls.push_back(s);
    }
};
class Notification{
    public:
    void notifyUsers(){
        //logic to notify
    }
};
class System{
    public:
    vector<Cinema*> cinemas;
    Notification* notification;
    System(Notification* n){
        notification=n;
    }
    void addCinema(Cinema* c){
        cinemas.push_back(c);
    }
    Show* GetShowsForMovie(string s){

    }
    //have to think about notification to add or not
    void Notify(){
        notification->notifyUsers();
    }
};
class Booking{
    public:
    Show* s;
    int bid;
    vector<Seat*> seats;
    Booking(int i,Show* show,vector<Seat*> se){
        seats=se;
        bid=i;
        s=show;
    }
};
class MovieBooking{
    public:
    vecotr<Booking*> bookinglist;
    void addBooking(Booking* b){
        bookinglist.push_back(b);
    }
};
class BookingService{
    public:
    Notification* notification;
    BookingService(Notification* n){
        notification=n;
    }
    void StartBooking(vector<Seat*> seats,Show* show){

    }
};
class Payment{
    public:
    void startPayment(double m){

    }
};
class Cash:publuic Payment{
    public:
    Cash(){}
};
class Card:publuic Payment{
    public:
    Card(){}
};
class User{
    public:
    System* system;
    User(System*s){
        system=s;
    }
};
class Admin: public User{
    public:
    Admin(){
        
    }
    void AddShow(show* s){}
    void DeleteShow(show* s){}
    void UpdateShow(Show* s){}
    void UpdateMovies(Movie* m){}
    void AddMovie(Movie* m){}
    void DeleteMovie(Movie* m){}
    void Notify(){
        system->notifyUsers();
    }
};
class Customer:public User{
    public:
    Show* pshow;
    BookingService* bs;
    vector<Seat*> selectedseats;
    Card* card;
    double amount;
    Customer(BookingService* b,Card* c){
        bs=b;
        card=c;
        amount=0;
    }
    SelectShow(string s){
        pshow=system->GetShowsForMovie(s);
    }
    SelectSeat(Seat* s){
        for(auto it:pshow->seats){
            //check for unused seats and book it;
            //add amoount here itself 
        }
    }
    void intiateBooking(){
        card->startPayment(amount);
        bs->StartBooking(selectedseats,pshow);
    }
};
class TicketAgent:public User{
    public:
    Show* pshow;
    BookingService* bs;
    vector<Seat*> selectedseats;
    Card* card;
    Cash* cash
    double amount;
    TicketAgent(BookingService* s,Card* c,Cash* ca){
        bs=b;
        amount=0;
        cash=ca;
        card=c;
    }
    SelectShow(string s){}
    intiateBooking(){}
    SelectSeat(Seat* s){}
};
