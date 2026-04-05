#include <bits/stdc++.h>
using namespace std;

class twoD{
    public:
    virtual void area()=0;
};

class threeD{
    public:
    virtual void area()=0;
    virtual void volume()=0;
};

class square:public twoD{
    public:
    int side;
    square(int side){
        this->side=side;
    }
    void area(){
        cout<<side*side<<endl;
    }
};

class cubeoid:public threeD{
    public:
    int length,breadth,height;
    cubeoid(int length,int breadth,int height){
        this->length=length;
        this->breadth=breadth;
        this->height=height;
    }
    void area(){
        cout<<2*(length*breadth+breadth*height+length*height)<<endl;
    }
    void volume(){
        cout<<length*breadth*height<<endl;
    }
};

int main(){
    return 0;
}