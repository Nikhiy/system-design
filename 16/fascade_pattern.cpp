#include<bits/stdc++.h>
using namespace std;
class powerSupply{
    public:
    void start(){
        cout<<"Starting power supply";
    }
};
class CPU{
    public:
    void start(){
        cout<<"Starting CPU";
    }
};
class Memory{
    public:
    void start(){
        cout<<"Starting Memory";
    }
};
class hardDrive{
    public:
    void start(){
        cout<<"Starting hard drive";
    }
};
class computerFascade{
    private:
    powerSupply* ps;
    CPU* cpu;
    Memory* memo;
    hardDrive* hd;
    public:
    computerFascade(powerSupply* p,CPU* c,Memory* m,hardDrive* h){
        ps=p;
        cpu=c;
        memo=m;
        hd=h;
    }
    void startComputer(){
        ps->start();
        cpu->start();
        memo->start();
        hd->start();
    }
};
class client{
    private:
    computerFascade* cf;
    public:
    client(computerFascade* c){
        cf=c;
    }
    void startComputer(){
        cf->startComputer();
    }
};
int main(){
    powerSupply* ps=new powerSupply();
    CPU* cpu=new CPU();
    Memory* memo=new Memory();
    hardDrive* hd=new hardDrive();
    computerFascade* cf=new computerFascade(ps,cpu,memp,hd);
    client* c=new client(cf);
    c->startComputer();
    return 0;
}