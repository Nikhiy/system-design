#include <bits/stdc++.h>
using namespace std;
enum CardType{
    NORMAL,
    ACE
};
enum class WinType{
    NORMALWIN,
    BLACKJACK,
    PUSH
};
class Card{
    public:
    int id;
    CardType type;
    int value;
    bool faceUp;
    Card(int i,CardType c,int v,bool f){
        id=i;
        type=c;
        value=v;
        faceUp=f;
    }
    void reveal(){
        faceUp = true;
    }
};
class Deck{
    public:
    vector<Card*> cards;
    Deck(){
        //add cards of each type
    }
};
class Shoe{
    public:
    vector<Deck*> decks;
    void addDeck(Deck* d){
        decks.push_back(d);
    }
    Card* drawCard(){
        //gets random card from present decks
    }
};
class Hand{
    public:
    vector<Card*> presentcards;
    int value;
    void addCard(Card* card){
        presentcards.push_back(card);
    }
    int getValue(){
        int ans=0;
        for(auto it:presentcards){
            ans+=it->value;
        }
        return ans;
    }
};
class User{
    public:
    Hand* hand;
    User(Hand* h){
        hand=h;
    }
    void stand(){

    }
};
class Dealer:public User{
    public:
    Dealer(Hand* h):User(h){}
    void reavelCard(){}
};
class Player:public User{
    public:
    int amount=0;
    Player(Hand* h):User(h){}
    void placeBets(int n){
        amount=n;
    }
};
class Payment{
    public:
    bool initiatePayment(User* u,int n){
        //logic for payment
    }
};
class Round{
    public:
    vector<Player*> players;
    Dealer* dealer;
    Payment* payment;
    Shoe* shoe;
    WinType wt;
    int winnerAmount=0;
    Round(Dealer* d,Payment* p,Shoe* s){
        dealer=d;
        payment=p;
        shoe=s;
    }
    void addPlayers(Player* p){
        players.push_back(p);
    }
    void distributeCards(){
        //logic to distribute cards
    }
    Player* getWinner(){

    }
    void CheckWinType(Player* p){
        //assing wt
    }
    void startPayment(Player* p,int n){
        payment->initiatePayment(p,n);
    }
    void hit(Player* p){
        Card* card = shoe->drawCard();
        p->hand->addCard(card);
    }
    void startGame(){
        for(auto it:players){
            it->placeBets(100);
        }
        distributeCards();
        for(auto it:players){
            hit(it);
        }
        Player* winner=getWinner();
        CheckWinType(winner);
        //assing winner amount based on wintype
        startPayment(winner,winnerAmount);
    }
};
class Game{
    public:
    int id;
    vector<Round*> rounds;
    Shoe* shoe;
    Game(Shoe* s,int i){
        id=i;
        shoe=s;
    }
    void addRound(Round* r){
        rounds.push_back(r);
    }
    void playGame(){
        for(auto it:rounds){
            it->startGame();
        }
    }
};