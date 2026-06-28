#include<bits/stdc++.h>
using namespace std;
class talkableRobot{
    public:
    virtual void talk()=0;
};
class walkableRobot{
    public:
    virtual void walk()=0;
};
class flyableRobot{
    public:
    virtual void fly()=0;
};
class normalWalk:public walk{
    public:
    void walk(){
        cout<<"walking..";
    }
};
class noWalk:public walk{
    public:
    void walk(){
        cout<<"cant walk..";
    }
};
class normaltalk:public talk{
    public:
    void talk(){
        cout<<"talking..";
    }
};
class notalk:public talk{
    public:
    void talk(){
        cout<<"cant talk..";
    }
};
class normalfly:public fly{
    public:
    void fly(){
        cout<<"flying..";
    }
};
class nofly:public fly{
    public:
    void fly(){
        cout<<"cant fly..";
    }
};

class robot{
    protected:
    walkableRobot* walkrobot;
    talkableRobot* talkrobot;
    flyableRobot* flyrobot;
    public:
    robot(walkableRobot* w,talkableRobot* t,flyableRobot* f){
        walkrobot=w;
        talkrobot=t;
        flyrobot=f;
    }
    void walk(){
        walkrobot->walk();
    }
    void talk(){
        talkrobot->talk();
    }
    void fly(){
        flyrobot->fly();
    }
    virtual void projection()=0;
};
class companionRobot:public robot{
    companionRobot(walkableRobot* w,talkableRobot* t,flyableRobot* f):robot(w,t,f){}
    void projection(){
        cout<<"Companion projection";
    }
};

int main(){
    robot* robot1=new companionRobot(new walkableRobot(),new notalk(),new nofly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    return 0;
}