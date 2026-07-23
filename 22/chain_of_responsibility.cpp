#include <bits/stdc++.h>
using namespace std;
class MoneyHandler{
    private:
    MoneyHandler* nextHandler;
    public:
    MoneyHandler(){
        this->nextHandler=nullptr;
    }
    void setNextHandler(MoneyHandler* next){
        nextHandler=next;
    }
    virtual void dispence()=0;
};
class ThousandHandler:public MoneyHandler{
    public:
    ThousandHandler(){

    }
    void dispence(){

    }
};
class HundreadHandler:public MoneyHandler{
    public:
    void dispence(){
        
    }
};
int main(){
    MoneyHandler* thousand=new ThousandHandler();
    MoneyHandler* hundread=new HundreadHandler();
    thousand->setNextHandler(hundread);
    
}