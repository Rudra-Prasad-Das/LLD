#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

int main(){
    auto text = "hello";
    string output;
    output+="<p>";
    output+=text;
    output+="<p>";

    cout<<output<<"\n";


    string words[] = {"hello","world"};
    ostringstream oss;

    oss<< "<ul>";
    for(auto word : words){
        oss<<" <li> " << words << "</li>";
    }
    oss<<"/ul>";
    cout<<oss.str() << endl;

    return 0;
}