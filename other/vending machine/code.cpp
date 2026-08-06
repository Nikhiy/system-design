#include <bits/stdc++.h>
using namespace std;
class VendingMachine;
class Product{
    private:
    int id;
    int price;
    public:
    Product(int i,int p){
        id=i;
        price=p;
    }
};
class Rack{
    private:
    int Rid;
    Product* product;
    int quantity;
    public:
    Rack(int id){
        Rid=id;
    }
    void AddProduct(Product* p){
        product=p;
    }
    void addQuantity(int n){
        quantity+=n;
    }
};
class Inventory{
    private:
    map<int,Rack*> racks;
    public:
    void AddRack(int rid,Rack* r){
        racks[rid]=r;
    }
    Rack* getRack(int rid){
        return racks[rid];
    }
};
class State{
    private:
    VendingMachine* vm;
    public:
    State(VendingMachine* m){
        vm=m;
    }
    virtual void insertMoney(int n)=0;
    virtual void selectProduct(int n)=0;
};
class NoMoneyState:public State{
    public:
    NoMoneyState(VendingMachine* m): State(m){}
    void insertMoney(int amount) override {
        // logic
    }
    void selectProduct(int rack) override {
        // logic
    }
};
class MoneyState:public State{
    public:
    MoneyState(VendingMachine* m): State(m){}
    void insertMoney(int amount) override {
        // logic
    }
    void selectProduct(int rack) override {
        // logic
    }
};
class DispenceState:public State{
    public:
    DispenceState(VendingMachine* m): State(m){}
    void insertMoney(int amount) override {
        // logic
    }
    void selectProduct(int rack) override {
        // logic
    }
};
class VendingMachine{
private:
    Inventory* inventory;
    State* state;
    int currentAmount;
public:
    VendingMachine(Inventory* inv){
        inventory = inv;
        currentAmount = 0;
        state = new NoMoneyState(this);
    }
    void setState(State* s){
        state = s;
    }
    State* getState(){
        return state;
    }
    Inventory* getInventory(){
        return inventory;
    }
    void addMoney(int amount){
        currentAmount += amount;
    }
    int getMoney(){
        return currentAmount;
    }
    void resetMoney(){
        currentAmount = 0;
    }
    void insertMoney(int amount){
        state->insertMoney(amount);
    }
    void selectProduct(int rackId){
        state->selectProduct(rackId);
    }
};
int main(){
    Inventory* inv = new Inventory();
    Rack* r1 = new Rack(1);
    Rack* r2 = new Rack(2);
    Product* coke = new Product(101,40);
    Product* chips = new Product(102,20);
    r1->AddProduct(coke);
    r1->addQuantity(10);
    r2->AddProduct(chips);
    r2->addQuantity(5);
    inv->AddRack(1,r1);
    inv->AddRack(2,r2);
    VendingMachine vm(inv);
    vm.insertMoney(50);
    vm.selectProduct(1);
    return 0;
}