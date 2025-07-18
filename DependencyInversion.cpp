#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

// A. High level modules should not depend on the low level modules
//    Both should depend on abstractions
// B. Abstractions should not depend on details
//    Details should depend on abstractions

//Abstractions ! What are they ? --> Interfaces or Base classes

enum class Relation{
    PARENT,
    CHILD,
    SIBLING
};
class Person{
    public:
    string name;
};
class Relationship{  //low-level module
    public:
    vector<tuple<Person, Relation, Person>> relations;
    void addParentAndChild(const Person& parent, const Person& child){
        relations.push_back({parent,Relation::PARENT,child});
        relations.push_back({child,Relation::CHILD,parent});
    }
};

class Research{  // High level module
    public:
    Research(Relationship& rel){  //Direct dependency on the low-level Module
        auto& relations = rel.relations;
        for(auto& tup : relations){
            const Person& first = get<0>(tup);
            Relation relation = get<1>(tup);
            const Person& second = get<2>(tup);
            if(first.name == "Mom" && relation == Relation::PARENT){
                cout<<"Mom has a child called "<<second.name<<endl;
            }
        } 
    }
};
int main(){
    Person son, mom, daughter;
    son.name = "Son";
    mom.name = "Mom";
    daughter.name = "Daughter";
    Relationship rel;
    rel.addParentAndChild(mom,son);
    rel.addParentAndChild(mom,daughter);
    Research _res(rel);
    return 0;
}