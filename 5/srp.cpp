// ===============
// bad design
// ===============

class product{
    int price;
    string name;
    product(int p,string n){
        price=p;
        name=n;
    }
};
class shoppingCart{
    private:
    vector<product*> productList;
    public:
    void addProduct(product* p){
        productList.push_back(p);
    }
    vector<product*> getProducts(){
        return productList;
    }
    int calculateTotal(){
        int ans=0;
        for(auto it:productList){
            ans=ans+it->price;
        }
        return ans;
    }
    void printInvoice(){
        cout<<"Printing Invoice...";
    }
    void saveToDb(){
        cout<<"Saving to DB";
    }
};

// ===========
// good design
// ===========

class product{
    int price;
    string name;
    product(int p,string n){
        price=p;
        name=n;
    }
};
class shoppingCart{
    private:
    vector<product*> productList;
    public:
    void addProduct(product* p){
        productList.push_back(p);
    }
    vector<product*> getProducts(){
        return productList;
    }
    int calculateTotal(){
        int ans=0;
        for(auto it:productList){
            ans=ans+it->price;
        }
        return ans;
    }
};
class invoicePrinter{
    private:
    shoppingCart* sc;
    public:
    invoicePrinter(shopingCart* sc){
        this->sc=sc;
    }
    void printInvoice(){
        cout<<"Printing Invoice"
    }
};
class dbStorage{
    private:
    shopping* sc;
    public:
    dbStorage(shopingCart* sc){
        this->sc=sc;
    }
    void saveToDb(){
        cout<<"Saving to DB";
    }
};