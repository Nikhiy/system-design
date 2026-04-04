#include <bits/stdc++.h>
using namespace std;
//bad design----------------
class product{
    public:
    string name;
    int price;

    product(string name, int price){
        this->name = name;
        this->price = price;
    }
};

class shopping_cart{
    private:
    vector<product> products;
    public:
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
    void printInvoice(){
        cout<<"Invoice: "<<endl;
        for(auto it:products){
            cout<<it.name<<" "<<it.price<<endl;
        }
        cout<<"Total: "<<calculateTotal()<<endl;
    }
    void saveToDb(){
        cout<<"Saving to database..."<<endl;
    }
};

//------------------

//--------good design-----------

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
    int calculateTotal(){
        int ans=0;
        for(auto it:products){
            ans+=it.price;
        }
        return ans;
    }
};

class printInvoice{
    public:
    shoppingCart* cart;
    printInvoice(shoppingCart *cart){
        this->cart = cart;
    }
    void printInvoiceList(){
        cout<<"Invoice: "<<endl;
        for(auto it:cart->products){
            cout<<it.name<<" "<<it.price<<endl;
        }
        cout<<"Total: "<<cart->calculateTotal()<<endl;
    }
};

class savevToDb{
    public:
    shoppingCart* cart;
    savevToDb(shoppingCart *cart){
        this->cart = cart;
    }
    void saveToDb(){
        cout<<"Saving to database..."<<endl;
    }
};

//-----------------

int main(){
    return 0;
}