#include <bits/stdc++.h>
using namespace std;
class Product{
    public:
    string name;
    string category;
    double price;
    Product(string n,string c,double p){
        name=n;
        category=c;
        price=p;
    }
    string getName() {
        return name;
    }
    string getCategory() {
        return category;
    }
    double getPrice() {
        return price;
    }
};
class CartItem{
    public:
    Product* product;
    int quantity;
    CartItem(Product* p,int q){
        product=p;
        quantity=q;
    }
    double itemTotal() {
        return product->getPrice() * quantity;
    }
    const Product* getProduct() {
        return product;
    }
};
class Cart{
    public:
    vector<CartItem*> items;
    double originalTotal;
    double currentTotal;
    bool loyaltyMember;
    string paymentBank;
    Cart() {
        originalTotal = 0.0;
        currentTotal = 0.0;
        loyaltyMember = false;
        paymentBank = "";
    }
    void addProduct(Product* prod, int qty = 1) {
        CartItem* item = new CartItem(prod, qty);
        items.push_back(item);
        originalTotal += item->itemTotal();
        currentTotal  += item->itemTotal();
    }
    double getOriginalTotal() {
        return originalTotal;
    }
    double getCurrentTotal() {
        return currentTotal;
    }
    void applyDiscount(double d) {
        currentTotal -= d;
        if (currentTotal < 0) {
            currentTotal = 0;
        }
    }
    void setLoyaltyMember(bool member) {
        loyaltyMember = member;
    }
    bool isLoyaltyMember() {
        return loyaltyMember;
    }
    void setPaymentBank(string bank) {
        paymentBank = bank;
    }
    string getPaymentBank() {
        return paymentBank;
    }
    vector<CartItem*> getItems() {
        return items;
    }
};
class DiscountStrategy{
    public:
    virtual double Calculate(double baseAmount)=0; 
};
class FlatDiscount:public DiscountStrategy{
    
}