// ==========
// bad design
// ==========
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
class dbStorage{
    private:
    shopping* sc;
    public:
    dbStorage(shopingCart* sc){
        this->sc=sc;
    }
    void saveToSQL(){
        cout<<"Saving to SQL";
    }
    void saveToMongo(){
        cout<<"Saving to mongoDB";
    }
};

// ==========
// good design
// ==========

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
class persistence{
    private:
    shoppingCart* cart;
    public:
    virtual void save(shoppingCart* cart)=0;
};
class saveToSql:public persistence{
    public:
    void save(shoppingCart* cart){
        cout<<"Saving to sql";
    }
};
class saveToMongo:public persistence{
    public:
    void save(shoppingCart* cart){
        cout<<"Saving to MongoDB";
    }
};