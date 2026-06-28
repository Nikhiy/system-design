// ==========
// bad design
// ==========
#include<bits/stdc++.h>
using namespace std;
class DocumentEditor{
private:
    vector<string> documentElements;
    string renderedDocument;
public:
    void addText(string s){
        documentElements.push_back(s);
    }
    void addImage(string s){
        documentElements.push_back(s);
    }
    string renderDocument(){
        return "This is business logic";
    }
    void saveToDB(){
        cout<<"Saving to DB";
    }
}

// =============
// better design
// =============

class documentElement{
    public:
    virtual string render()=0;
};
class textElement:public documentElement{
    private:
    string text;
    public:
    textElement(string s){
        text=s;
    }
    string render(){
        return text;
    }
};
class imageElement:public documentElement{
    private:
    string text;
    public:
    imageElement(string s){
        text=s;
    }
    string render(){
        return text;
    }
};
class document{
    private:
    vector<documentElement*> elements;
    public:
    void addElement(documentElement* dl){
        elements.push_back(dl);
    }
    string render(){
        string ans;
        for(auto it:elements){
            ans+=it->render();
        }
        return ans;
    }
};
class persistence{
    public:
    virtual void save(string s)=0;
};

class saveToDB:public persistence{
    public:
    void save(string s){
        cout<<"Saving to DB";
    }
};
class saveToFile:public persistence{
    public:
    void save(string s){
        cout<<"Saving to DB";
    }
};
class documentEditor{
    private:
    document* doc;
    persistence* p;
    string renderedDocument;
    public:
    documentEditor(document* doc,persistence* p){
        this->doc=doc;
        this->p=p;
    }
    void addText(string s){
        doc->addElement(new textElement(s));
    }
    void addImage(string s){
        doc->addElement(new imageElement(s));
    }
    string render(){
        if(renderedDocument.empty()){
            renderedDocument=doc->render();
        }
        return renderedDocument;
    }
    void save(){
        p->save(renderedDocument);
    }
};
