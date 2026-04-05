#include <bits/stdc++.h>
using namespace std;


    class car {
        public:
        virtual void startEngine() = 0;
    };
    class sportsCar:public car{
        public:
        string company;
        string model;
        bool engineStatus;
        sportsCar(string c,string m){
            company=c;
            model=m;
            engineStatus=false;
        }
        void startEngine(){
            engineStatus=true;
            cout<<"Engine started for "<<company<<" "<<model<<endl;
        }
    };

    int main(){
        car* myCar=new sportsCar("Ferrari","488 Spider");
        myCar->startEngine();
        delete myCar;
        return 0;
    }
