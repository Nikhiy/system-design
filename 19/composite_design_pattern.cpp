#include<bits/stdc++.h>
using namespace std;
class IFileSystem{
    public:
    virtual void ls(int ind=0)=0;
    virtual void openAll(int ind=0)=0;
    virtual int getSize()=0;
    virtual IFileSystem* cd(string& name)=0;
    virtual string getName()=0;
    virtual bool isFile()=0;
};
class File:IFileSystem{
    private:
    int siz;
    string name;
    File(int s,string& n){
        siz=s;
        name=n;
    }
    bool isFile(){
        return true;
    }
    string getName(){
        return name;
    }
    void ls(int ind=0){
        cout<<string(ind,' ')<<name<<endl;
        return;
    }
    void openAll(int ind=0){
        cout<<string(ind,' ')<<name<<endl;
        return;
    }
    int getSize(){
        return siz;
    }
    IFileSystem* cd(string& name){
        return nullptr;
    }
};
class Folder:IFileSystem{
    private:
    string name;
    vector<IFileSystem*> list;
    public:
    Folder(string n){
        name=n;
    }
    bool isFile(){
        return false;
    }
    string getName(){
        return name;
    }
    void ls(){
        for(auto it:list){
            it->getName();
        }
        return ;
    }
    void openAll(){
        for(auto it:list){
            it->openAll();
        }
    }
    int getSize(){
        int siz=0;
        for(auto it:list){
            siz+=it->getSize();
        }
        return siz;
    }
    IFileSystem* cd(string& name){
        for(auto it:list){
            if(it->getName()==name) return it;
        }
        return nullptr;
    }
};