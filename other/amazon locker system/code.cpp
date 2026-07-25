#include<bits/stdc++.h>
using namespace std;
enum class LockerSize{
    EXTRA_SMALL,
    SMALL,
    MEDIUM,
    LARGE,
    EXTRA_LARGE,
    DOUBLE_EXTRA LARGE
};
enum class LockerStatus{
    FILLED,
    EMPTY
};
class Locker;
class Package;
class Order;
class Location;
class Customer;
class CodeGeneratorService{
    public:
    string GenerateCode(){
        return "";
    }
};
class DeliveryService{
    public:
    void AssignLocker(Location* l,Package* p){
        //assign locker
        string c=NotifyCustomer(o);
        Locker* lock=l->FindLocker(p);
        lock->GetPackage(Package);
    }
    string NotifyCustomer(Order* o){
        CodeGeneratorService CGS;
        return CGS->GenerateCode();
    }
};
class RefundService{
    public:
    void StartRefund(Package* p){}
};
class ReturnService{
    public:
    void AssignLockerReturn(Package* p,Location* l){
        for(auto it:l->lockers){
            if(it->package==nullptr && it->LockerSize>=p->packagesize){
                it->GetPackage(p);
                string c=NotifyCustomerReturn(o);
                it->code=c;
            }
        }
    }
    string NotifyCustomerReturn(Order* o){
        CodeGeneratorService CGS;
        return CGS->GenerateCode();
    }
    void SendRefund(Package* p){
        RefundService rs;
        rs->StartRefund(p)
    }
};
class Locker{
    public:
    LockerSize size;
    Package* package;
    LockerStatus status;
    string code;
    Locker(LockerSize s){
        package=nullptr;
        status=EMPTY;
        size=s;
        code="";
    }
    void GetPackage(Package* p){
        package=p;

    }
    bool CheckCode(string code){

    }
    void RemovePackage(){
        package=nullptr;
    }
};
class DeliveryAgent{
    public:
    void DeliverPackage(){}
    void PickUpReturn(){}
};
class Location{
    public:
    vector<Locker*> lockers;
    string OpenTime;
    string CLoseTime;
    Location(string s,string c){
        OpenTime=s;
        CLoseTime=c;
    }
    void AddLocker(Locker* l){
        lockers.push_back(l);
    }
    Locker* FindLocker(Package* p){}
};
class Customer{
    public:
    int cid;
    Location* location;
    void SetLocation(Location* l){
        location=l;
    }
    void CreateOrder(Order* o){

    }
    void TakeOrder(string code){

    }
    void RequestReturn(Package* p,Location* l){

    }
};
class Item{
    Public:
    int id;
    int size;
    Item(int i,int s){
        id=i;
        size=s;
    }
};
class Order{
    Public:
    vector<Item*> items;
    int OrderSize;
    Customer* customer;
    Order(Customer* c){
        OrderSize=0;
        customer=c;
    }
    void addItem(Item* item){
        items.push_back(item);
        OrderSize+=item->size;
    }
};
class Package{
    public:
    LockerSize packagesize;
    Order* order;
    Customer* c;
    Package(Order* o){
        order=o;
        //logic to assign a lockersize according to ordersize
        c=order->customer;
        packagesize=SMALL;
    }
};
int main(){
    Location* location=new Location("9am","9pm");
    location->AddLocker(new Locker(LockerSize::SMALL));
    location->AddLocker(new Locker(LockerSize::MEDIUM));
    location->AddLocker(new Locker(LockerSize::LARGE));
    Customer* customer=new Customer();
    customer->SetLocation(location);
    Order* order=new Order(customer);
    order->addItem(new Item(1,2));
    order->addItem(new Item(2,3));
    Package* package=new Package(order);
    DeliveryService service;
    service->AssignLocker(location,package);
    string otp="qwerty";
    Locker* locker=location->FindLocker(package);
    if(locker->CheckCode(otp)){
        locker->RemovePackage();
    }
    else{
        cout<<"Wrong pin";
    }
    ReturnService rs;
    customer->RequestReturn(package,location);
    rs->AssignLockerReturn(package,location);
    rs->NotifyCustomerReturn();
    stirng returnOtp="gjk";
    locker = location->FindLocker(package);
    if(locker->CheckCode(returnOtp))
    {
        locker->GetPackage(package);
    }
    locker->RemovePackage();
    rs->SendRefund();
    return 0;
}