#include <bits/stdc++.h>
using namespace std;
enum class ResponseStatus{
    PENDING,
    ACCEPTED,
    DECLINE
};
class Room{
    public:
    int id;
    int capacity;
    bool isBooked;
    Room(int i,int c){
        id=i;
        capacity=c;
        isBooked=false;
    }
};
class RoomManager{
    public:
    vector<Room*> rooms;
    void bookRoom(Room* room,string start,string end){

    }
    void AddRoom(Room* room){

    }
};
class Organizer{
    public:
    MeetingController* control;
    void AddUser(Meeting* meeting,User* user){

    }
    void DeleteUser(Meeting* meeting,User* user){

    }
};
class Meeting{
    public:
    int id;
    Room* room;
    Organizer* owner;
}