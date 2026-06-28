#include<bits/stdc++.h>
using namespace std;

// ============
// simple factory
// ============
class burger{
    public:
    virtual void create()=0;
};
class basicBurger:public burger{
    public:
    void create(){
        cout<<"Creating a basic burger";
    }
};
class standardBurger:public burger{
    public:
    void create(){
        cout<<"Creating a standard burger";
    }
};
class premiumBurger:public burger{
    public:
    void create(){
        cout<<"Creating a premium burger";
    }
};
class burgerFactory{
    public:
    burger* createBurger(string& s){
        if(s=="basic"){
            return new basicBurger();
        }
        else if(s=="standard"){
            return new standardBurger();
        }
        else{
            return new premiumBurger();
        }
    } 
};

// ==========
// factory method
// ===========

class burger{
    public:
    virtual void create()=0;
};
class basicBurger:public burger{
    public:
    void create(){
        cout<<"Creating a basic burger";
    }
};
class standardBurger:public burger{
    public:
    void create(){
        cout<<"Creating a standard burger";
    }
};
class basicWheatBurger:public burger{
    public:
    void create(){
        cout<<"Creating a basic wheat burger";
    }
};
class standardWheatBurger:public burger{
    public:
    void create(){
        cout<<"Creating a standard wheat burger";
    }
};
class factory{
    public:
    virtual void create()=0;
};
class singhBurger:public factory{
    public:
    burger* create(string& s){
        if(s=="basic"){
            return new basicBurger();
        }
        else if(s=="standard"){
            return new standardBurger();
        }
    }
};
class kingBurger:public factory{
    public:
    burger* create(string& s){
        if(s=="basic"){
            return new basicWheatBurger();
        }
        else if(s=="standard"){
            return new standardWheatBurger();
        }
    }
};
//==================
// abstract factory method
//==================

class burger{
    public:
    virtual void create()=0;
};
class basicBurger:public burger{
    public:
    void create(){
        cout<<"Creating a basic burger";
    }
};
class standardBurger:public burger{
    public:
    void create(){
        cout<<"Creating a standard burger";
    }
};
class basicWheatBurger:public burger{
    public:
    void create(){
        cout<<"Creating a basic wheat burger";
    }
};
class standardWheatBurger:public burger{
    public:
    void create(){
        cout<<"Creating a standard wheat burger";
    }
};
class Bread{
    public:
    virtual void create()=0;
};
class basicBread:public Bread{
    public:
    void create(){
        cout<<"Creating a basic Bread";
    }
};
class standardBread:public Bread{
    public:
    void create(){
        cout<<"Creating a standard Bread";
    }
};
class basicWheatBread:public Bread{
    public:
    void create(){
        cout<<"Creating a basic wheat Bread";
    }
};
class standardWheatBread:public Bread{
    public:
    void create(){
        cout<<"Creating a standard wheat Bread";
    }
};
class mealFactory{
    public:
    virtual void createBurger()=0;
    virtual void createBread()=0;
};
class kingBurger{
    public:
    burger* create(string* s){
        
    }
}