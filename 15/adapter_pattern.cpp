#include<bits/stdc++.h>
using namespace std;
class IReport{
    public:
    virtual string getJsonData(string& data)=0;
};
class xmlDataProvider{
    public:
    string getXmlData(string data){
        return data;
    }
};
class XmlDataProviderAdapter:public IReport{
    private:
    xmlDataProvider* prov;
    public:
    XmlDataProviderAdapter(xmlDataProvider* p){
        prov=p;
    }
    string getJsonData(string& data){
        string xml=prov->getXmlData(data);
        //========================
        //converting xml to json logic
        //========================
        return xml;//the converted json data
    }
};
class client{
    public:
    void getReport(IReport* report,string& rawdata){
        cout<<"json data"<<report->getJsonData(rawdata);
    }
};
int main(){
    xmlDataProvider* prev=new xmlDataProvider();
    IReport* adapter= new XmlDataProviderAdapter(prev);
    string data="nikhil";
    client* c=new client();
    c->getReport(adapter,data);
    return 0;
}