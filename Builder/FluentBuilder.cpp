#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

class HTMLElement{
    friend class HTMLBuilder;
    string name, text;
    vector<HTMLElement> elements;
    const size_t indent_size = 2;
    HTMLElement() {}

    HTMLElement(const string& name, const string& text) : name(name), text(text) {}
    public:
    string str(int indent = 0){
        ostringstream oss;
        string i(indent_size*indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if(text.size() > 0){
            oss<< string(indent_size*(indent+1),' ') <<text<<endl;
        }

        for(auto& e : elements){
            oss << e.str(indent+1);
        }

        oss << i << "</" << name << ">" << endl;
        return oss.str();

    }

};
class HTMLBuilder{
    public:
    HTMLElement root;
    HTMLBuilder(string root_name){
        root.name = root_name;
    }
    HTMLBuilder& addChild(string child_name, string child_text){
        HTMLElement e(child_name,child_text);
        root.elements.push_back(e);
        return *this;
    }
    string str() {
        return root.str();
    }
};
int main(){

    HTMLBuilder builder("ul");
    builder.addChild("li", "hello").addChild("li","World").addChild("li","Namaste Sabko");

    cout<<builder.str()<<endl;

    
    
    return 0;
}