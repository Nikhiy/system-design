#include <bits/stdc++.h>
using namespace std;

class product{
    public:
    string name;
    int price;
    product(string name, int price){
        this->name = name;
        this->price = price;
    }
};

class shoppingCart{
    public:
    vector<product> products;
    void addProduct(product P){
        products.push_back(P);
    }
    vector<product> getProducts(){
        return products;
    }
    double calculateTotal(){
        double ans=0;
        for(auto it:products){
            ans+=it.price;
        }
        return ans;
    }
};

class invoice{
    public:
    shoppingCart cart;
    invoice(shoppingCart cart){
        this->cart = cart;
    }
    void printInvoice(){
        cout<<"Invoice: "<<endl;
        for(auto it:cart.getProducts()){
            cout<<it.name<<" "<<it.price<<endl;
        }
        cout<<"Total: "<<cart.calculateTotal()<<endl;
    }
};

class persistence{
    public:
    shoppingCart cart;
    virtual void saveToDb(shoppingCart cart){
        cout<<"Saving to database..."<<endl;
    }
};

class persisenceToMongoDb:public persistence{
    public:
    void saveToDb(shoppingCart cart){
        cout<<"Saving to MongoDB..."<<endl;
    }
};

class persisenceToMySql:public persistence{
    public:
    void saveToDb(shoppingCart cart){
        cout<<"Saving to MySQL..."<<endl;
    }
};

int main(){
    return 0;
}