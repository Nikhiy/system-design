

//==========================
//check last fo reserve flow
//==============================
#include<bits/stdc++.h>
using namespace std;
enum  class BookStatus{
    BOROW,
    RESERVE,
    DUE
};
class Book{
    public:
    int ISBN;
    string title;
    string author;
    string subject;
    string publishDate;
};
class BookItem{
    public:
    Book* book;
    bool borrowed;
    BookStatus s;
    double price;
    string BorrowDate;
    string DueDate;
};
class Rack{
    public:
    int id;
    vector<BookItem*> list;
};
class Catalog{
    public:
    vector<BookItem*> list;
};
class Search{
    public:
    Catalog* c;
    Book* SearchByName(string& s){}
    Book* SearchByID(string& s){}
    Book* SearchByAuthor(string& s){}
};
class User{
    public:
    int id;
    string email;
    string password;
    Search* search;
    User(string& e,string& p){
        email=e;
        password=p;
    }
    BookItem* SearchWithName(string s){
        search->SearchByName(s);
    }
    BookItem* SearchWithID(string s){
        search->SearchByID(s);
    }
    BookItem* SearchWithAuthor(string s){
        search->SearchByAuthor(s);
    }
};
class UserCard{
    public:
    User* user;
    int id;
    UserCard(User* u){
        user=u;
    }
    bool isActive(){}
    void Activate(){}
};
class Member:public User{
    public:
    Member(string& e,string& p):User(e,p){}
    bool BorrowBook(int BookID){}
    bool ReturnBook(int BookID){}
    void CheckOut(int BookId){}
    bool ReserveBookItem(){}
    int getTotalBooks(){}
    bool CheckForFine(){}
};
class Librarian:public User{
    public:
    vector<Member*> members;
    void AddBook(){}
    bool LendBook(){}
    void RemoveBook(){}
    void AddMember(){}
};
class NotificationSystem{
    public:
    virtual void Notify(User* u)=0;
};
class SMSNotification:public NotificationSystem{
    public:
    void Notify(User* user){

    }
} ;
class EmailNotification:public NotificationSystem{
    public:
    void Notify(User* user){

    }
} ;
class BookReservation{
    User* user;
    BookItem* book;
    int ReserveId;
    bool ReserveStatus;
    BookReservation(User* u,BookItem* b){
        user=u;
        book=b;
    }
};
class ReserveSystem{
    public:
    NotificationSystem* n;
    void NotifyUser(User* u){}
    bool ReserveBook(User* u,BookItem* b){}
    void setNotification(NotificationSystem* noti){
        n=noti;
    }
    BookReservation* GetReservation(BookItem* b){}
};
class BookLending{
    User* user;
    BookItem* book;
    int LendId;
    bool Status;
    BookLending(User* u,BookItem* b){
        user=u;
        book=b;
    }
};
class LendingSystem{
    public:
    NotificationSystem* n;
    void NotifyUser(User* u){}
    bool LendBookItem(User* u,BookItem* b){}
    BookLending* Getlending(BookItem* b){}
};
class LibrarySyatem{
    public:
    vector<BookItem*> books;
    vector<Librarian*> librariens;
    Catalog* c;
    void AddPerson(Librarian* l){}
    void remove(Librarian* l){}
};

//================
//main code generated
//=================
int main() {

    // Create book
    Book* book = new Book();
    book->ISBN = 101;
    book->title = "Clean Code";

    // Physical copy
    BookItem* item = new BookItem();
    item->book = book;
    item->s = BookStatus::DUE;

    // Catalog
    Catalog* catalog = new Catalog();
    catalog->list.push_back(item);

    // Search
    Search* search = new Search();
    search->c = catalog;

    // Member
    string email = "nikhil@gmail.com";
    string pass = "123";

    Member* member = new Member(email, pass);
    member->search = search;

    // Notification
    NotificationSystem* notification =
        new EmailNotification();

    // Reservation Service
    ReserveSystem service;
    service.setNotification(notification);

    // Member searches
    BookItem* result =
        member->SearchWithName("Clean Code");

    // Member reserves
    service.ReserveBook(member, result);

    return 0;
}

//===============
//RESERVATION FLOW
//===============
// bool ReservationService::reserveBook(
//     Member* member,
//     BookItem* item)
// {
//     // already reserved?
//     if(repository->findByBook(item))
//         return false;

//     BookReservation* reservation =
//         new BookReservation(member,item);

//     repository->save(reservation);

//     notification->Notify(member);

//     return true;
// }