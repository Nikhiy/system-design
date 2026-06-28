#include<bits/stdc++.h>
using namespace std;
// =========
// bad version(thread unsafe)
// ===========
class singleton{
    private:
    static singleton* instance;
    singleton(){
        cout<<"private constructor";
    }
    public:
    singleton* getInstance(){
        if(instance==nullptr){
            instance=new singleton();
        }
        return instance;
    }
};
singleton* Singleton::instance=nullptr;
int main(){
    singleton* s1=new getInstance();
    return 0;
}

// ===========
// thread safe version
// ===========
class singleton{
    private:
    static singleton* instance;
    static mutex mtx;
    public:
    static singleton* getInstance(){
        lock_guard<mutex> lock(mtx);
        if(instance==nullptr){
            return new singleton();
        }
        return instance
    }
};
singleton* sing::instance=nullptr;
mutex singleton::mtx;
