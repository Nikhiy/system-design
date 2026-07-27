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
class FlatDiscountStrategy : public DiscountStrategy {
private:
    double amount;
public:
    FlatDiscountStrategy(double amt) {
        amount = amt;
    }
    double calculate(double baseAmount) override {
        return min(amount, baseAmount);
    }
};
class PercentageDiscountStrategy : public DiscountStrategy {
private:
    double percent;
public:
    PercentageDiscountStrategy(double pct) {
        percent = pct;
    }
    double calculate(double baseAmount) override {
        return (percent / 100.0) * baseAmount;
    }
};
class PercentageWithCapStrategy : public DiscountStrategy {
private:
    double percent;
    double cap;
public:
    PercentageWithCapStrategy(double pct, double capVal) {
        percent = pct;
        cap = capVal;
    }
    double calculate(double baseAmount) override {
        double disc = (percent / 100.0) * baseAmount;
        if (disc > cap) {
            return cap;
        }
        return disc;
    }
};
enum StrategyType {
    FLAT,
    PERCENT,
    PERCENT_WITH_CAP
};
class DiscountStrategyManager{
    private:
    static DiscountStrategyManager* instance;
    DiscountStrategyManager() {}
    public:
    static DiscountStrategyManager* getInstance() {
        if (!instance) {
            instance = new DiscountStrategyManager();
        }
        return instance;
    }
    DiscountStrategy* getStrategy(StrategyType type, double param1, double param2 = 0.0) const {
        if (type == StrategyType::FLAT) {
            return new FlatDiscountStrategy(param1);
        }
        if (type == StrategyType::PERCENT) {
            return new PercentageDiscountStrategy(param1);
        }
        if (type == StrategyType::PERCENT_WITH_CAP) {
            return new PercentageWithCapStrategy(param1, param2);
        }
        return nullptr;
    }
};
DiscountStrategyManager* DiscountStrategyManager::instance = nullptr;
class Coupon{
    private:
    Coupon* next;
    public:
    Coupon(){
        next=nullptr;
    }
    Coupon* getNext(){
        return next;
    }
    void setNext(Coupon* n){
        next=n;
    }
    virtual bool isApplicable(Cart* cart) = 0;
    virtual double getDiscount(Cart* cart) = 0;
    virtual bool isCombinable() {
        return true;
    }
    virtual string name() = 0
    void applyDiscount(Cart* c){
        if(isApplicable(Cart* cart)){
            double discount=getDiscount(cart);
            cart->applyDiscount(discount);
            if(!isCombinable) return;
            if(next) next->applyDiscount(cart);
        }
    }
};
class SeasonalOffer : public Coupon {
private:
    double percent;
    string category;
    DiscountStrategy* strat;
public:
    SeasonalOffer(double pct, string cat) {
        percent = pct;
        category = cat;
        strat = DiscountStrategyManager::getInstance()->getStrategy(StrategyType::PERCENT, percent);
    }
    ~SeasonalOffer() {
        delete strat;
    }
    bool isApplicable(Cart* cart) override {
        for (CartItem* item : cart->getItems()) {
            if (item->getProduct()->getCategory() == category) {
                return true;
            }
        }
        return false;
    }
    double getDiscount(Cart* cart) override {
        double subtotal = 0.0;
        for (CartItem* item : cart->getItems()) {
            if (item->getProduct()->getCategory() == category) {
                subtotal += item->itemTotal();
            }
        }
        return strat->calculate(subtotal);
    }
    bool isCombinable() override {
        return true;
    }
    string name() override {
        return "Seasonal Offer " + to_string((int)percent) + " % off " + category;
    }
};
class LoyaltyDiscount : public Coupon {
private:
    double percent;
    DiscountStrategy* strat;
public:
    LoyaltyDiscount(double pct) {
        percent = pct;
        strat = DiscountStrategyManager::getInstance()->getStrategy(StrategyType::PERCENT, percent);
    }
    ~LoyaltyDiscount() {
        delete strat;
    }
    bool isApplicable(Cart* cart) override {
        return cart->isLoyaltyMember();
    }
    double getDiscount(Cart* cart) override {
        return strat->calculate(cart->getCurrentTotal());
    }
    string name() override {
        return "Loyalty Discount " + to_string((int)percent) + "% off";
    }
};
class BulkPurchaseDiscount : public Coupon {
private:
    double threshold;
    double flatOff;
    DiscountStrategy* strat;
public:
    BulkPurchaseDiscount(double thr, double off) {
        threshold = thr;
        flatOff = off;
        strat = DiscountStrategyManager::getInstance()->getStrategy(StrategyType::FLAT, flatOff);
    }
    ~BulkPurchaseDiscount() {
        delete strat;
    }
    bool isApplicable(Cart* cart) override {
        return cart->getOriginalTotal() >= threshold;
    }
    double getDiscount(Cart* cart) override {
        return strat->calculate(cart->getCurrentTotal());
    }
    string name() override {
        return "Bulk Purchase Rs " + to_string((int)flatOff) + " off over "
             + to_string((int)threshold);
    }
};
class BankingCoupon : public Coupon {
private:
    string bank;
    double minSpend;
    double percent;
    double offCap;
    DiscountStrategy* strat;
public:
    BankingCoupon(const string& b, double ms, double percent, double offCap) {
        bank = b;
        minSpend = ms;
        this->percent = percent;
        this->offCap = percent;
        strat = DiscountStrategyManager::getInstance()->getStrategy(StrategyType::PERCENT_WITH_CAP, percent, offCap);
    }
    ~BankingCoupon() {
        delete strat;
    }
    bool isApplicable(Cart* cart) override {
        return cart->getPaymentBank() == bank
            && cart->getOriginalTotal() >= minSpend;
    }
    double getDiscount(Cart* cart) override {
        return strat->calculate(cart->getCurrentTotal());
    }
    string name() override {
        return bank + " Bank Rs " + to_string((int)percent) + " off upto " + to_string((int) offCap);
    }
};
