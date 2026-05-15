//=========================================
//Bad design since all are in one class
//=========================================
#inclde<bits/stdc++.h>
using namespace std;

class DocumentEditor{
    private:
    vector<string> documentElements;
    string renderedDocument;
    public:
    void addText(stirng& text){
        documentElements.push_back(text);
    }
    void addImage(string & image){
        documentElements.push_back(image);
    }
    string renderDocument(){
        if(!renderedDocument.empty()) continue;
        string result;
            for (auto element : documentElements) {
                if (element.size() > 4 && (element.substr(element.size() - 4) == ".jpg" ||
                 element.substr(element.size() - 4) == ".png")) {
                    result += "[Image: " + element + "]" + "\n";
                } else {
                    result += element + "\n";
                }
            }
            renderedDocument = result;
        return renderedDocument;
    }

};
int main(){
    return 0;
}


//============================
//Good design
//============================
