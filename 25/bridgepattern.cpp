#include <bits/stdc++.h>
using namespace std;
class Engine{
    public:
    virtual void Start()=0;
    virtual string getType()=0;
};
class Petrol:public Engine{
    public:
    Petrol(){}
    void Start(){
        cout<<"Starting petrol engine";
    }
    string getType(){
        return "Petrol";
    }
};
class Deisel:public Engine{
    public:
    Deisel(){}
    void Start(){
        cout<<"Starting Deisel engine";
    }
    string getType(){
        return "Diesel";
    }
};
class Car{
    protected:
    Engine* engine;
    public:
    Car(Engine* e){
        engine=e;
    }
    virtual void Drive()=0;
};
class Honda:public Car{
    public:
    Honda(Engine* e) :Car(e){}
    void Drive(){
        cout<<"Driving Honda with "<<engine->getType()<<" engine \n";
    }
};
class Toyota:public Car{
    public:
    Toyota(Engine* e) :Car(e){}
    void Drive(){
        cout<<"Driving Toyota with "<<engine->getType()<<" engine \n";
    }
};
int main(){
    Engine* p=new Petrol();
    Engine* d=new Deisel();
    Car* honda=new Honda(p);
    Car* hondad=new Honda(d);
    honda->Drive();
    hondad->Drive();
    return 0;
}