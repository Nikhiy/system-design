#include<bits/stdc++.h>
using namespace std;
class ICharacter{
    public:
    virtual string getAbilities()=0;
};
class mario: public ICharacter{
    public:
    string getAbilities(){
        return "Mario";
    }
};
class Decorator:public ICharacter{
    protected:
    ICharacter* c;
    public:
    Decorator(ICharacter* c){
        this->c=c;
    }
};
class heighUp:public Decorator{
    public:
    ICharacter* c;
    heighUp(ICharacter* c){
        this->c=c;
    }
    string getAbilities(){
        return c->getAbilities()+"Height up";
    }
};
class GunPowerUp : public CharacterDecorator {
    public:
    GunPowerUp(Character* c) : CharacterDecorator(c) { }
    string getAbilities(){
        return character->getAbilities() + " with Gun";
    }
};
