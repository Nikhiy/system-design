// ========
// bad design
// ===========
#include<bits/stdc++.h>
using namespace std;
class account{
    public:
    virtual void deposit(int num)=0;
    virtual void withdraw(int num)=0;
};
class savingAccount:public account{
    private:
    int balance;
    savingAccount(){
        balance=0;
    }
    void deposit(int num){
        balance+=num;
        cout<<"updated";
    }
    void withdraw(int num){
        if(balance>=num){
            balance-=num;
            cout<<"updated";
        }
        else{
            cout<<"error";
        }
    }
};
class currentAccount:public account{
    private:
    int balance;
    currentAccount(){
        balance=0;
    }
    void deposit(int num){
        balance+=num;
        cout<<"updated";
    }
    void withdraw(int num){
        if(balance>=num){
            balance-=num;
            cout<<"updated";
        }
        else{
            cout<<"error";
        }
    }
};
class FDAccount:public account{
    private:
    int balance;
    FDAccount(){
        balance=0;
    }
    void deposit(int num){
        balance+=num;
        cout<<"updated";
    }
    void withdraw(int num){
        cout<<"error";
    }
};

// =============
// good design
// =============

class nonWithdrawAcc{
    public:
    virtual void deposit(int num)=0;
};
class withdrawAcc:nonWithdrawAcc{
    public:
    virtual void withdraw(int num)=0;
};
class FDAcc:public nonWithdrawAcc{
    private:
    int balance=0;
    public:
    FDAcc(){
        balance=0;
    }
    void deposit(int num){
        balance+=num;
        cout<<"DONE";
    }
};
class currentAcc:public withdrawAcc{
    private:
    int balance;
    public:
    currentAcc(){
        balance=0;
    }
    void deposit(int num){
        balance+=num;
        cout<<"DONE";
    }
    void withdraw(int num){
        if(balance>=num){
            balance-=num;
            cout<<"updated";
        }
        else{
            cout<<"error";
        }
    }
};
class savingAcc:public withdrawAcc{
    private:
    int balance;
    public:
    savingAcc(){
        balance=0;
    }
    void deposit(int num){
        balance+=num;
        cout<<"DONE";
    }
    void withdraw(int num){
        if(balance>=num){
            balance-=num;
            cout<<"updated";
        }
        else{
            cout<<"error";
        }
    }
};