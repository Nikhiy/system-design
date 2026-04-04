#include <bits/stdc++.h>
using namespace std;

class DepositOnlyAccount{
    public:
    virtual void deposit(double amount)=0;
};

class withdrawablelAccount:public DepositOnlyAccount{
    public:
    virtual void withdraw(double amount)=0;
};

class savingsAccount:public withdrawablelAccount{
    public:
    double amount;
    savingsAccount(){
        amount=0;
    }
    void deposit(double amount){
        this->amount+=amount;
    }
    void withdraw(double amount){
        if(this->amount>=amount){
            this->amount-=amount;
        }
        else{
            cout<<"Insufficient balance"<<endl;
        }
    }
};

class currentAccount:public withdrawablelAccount{
    public:
    double amount;
    currentAccount(){
        amount=0;
    }
    void deposit(double amount){
        this->amount+=amount;
    }
    void withdraw(double amount){
        if(this->amount>=amount){
            this->amount-=amount;
        }
        else{
            cout<<"Insufficient balance"<<endl;
        }
    }
};

class fixedDepositAccount:public DepositOnlyAccount{
    public:
    double amount;
    fixedDepositAccount(){
        amount=0;
    }
    void deposit(double amount){
        this->amount+=amount;
    }
};

int main(){
    return 0;
}