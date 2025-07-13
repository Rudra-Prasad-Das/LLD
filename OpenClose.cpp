#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Journal{
    public:
    string title;
    vector<string> entries;
   
    Journal(const string &title){
        this->title = title;
    }

    void add(const string& entry){
        static int count = 0 ;
        entries.push_back("Entry no" + to_string(count) + ":" + entry);
        count++;
    }

    void display(){
        for(auto entry : entries){
            cout<<entry<<"\n";
        }
    }

};
int main(){
    Journal obj("Add the name of the diary");

    obj.add("Today is Sunday");
    obj.add("Today is Monday");
    obj.display();

    return 0;
}

/**
 * @brief How to compile and run cpp code in terminal
 * g++ <filename>.cpp -o <filename>.exe
 * <filename>.exe
 */