#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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

class PersistenceManager {
public:
    static void save(const Journal& j, const string& filename) {
        ofstream ofs(filename);
        for (auto& entry : j.entries) {
            ofs << entry << endl;
        }
    }
};

int main(){
    Journal obj("Enter the name of the diary");

    obj.add("Today is Sunday");
    obj.add("Today is Monday");
    obj.display();

    PersistenceManager::save(obj, "diary.txt");

    return 0;
}

/**
 * @brief Single Responsibility Pattern --> A class should only one reason to change.
 * The Persistence (save) must be separated from the journal activity (add , display)
 */