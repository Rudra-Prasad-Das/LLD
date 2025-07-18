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

// Add an abstraction to interact with the low level code
class RelationshipBrowser{
    public:
    virtual vector<Person> findAllChildren(const string &name) = 0;
};
class Relationship:public RelationshipBrowser{  //low-level module
    vector<tuple<Person, Relation, Person>> relations;  //Change in logic of the low level code
    public:
    void addParentAndChild(const Person& parent, const Person& child){
        relations.push_back({parent,Relation::PARENT,child});
        relations.push_back({child,Relation::CHILD,parent});
    }
    vector<Person> findAllChildren(const string& name){
        vector<Person> child;
        for(auto &tup : relations){
           const Person& first = get<0>(tup);
           Relation relation = get<1>(tup);
           const Person& second = get<2>(tup); 
           if(first.name == name && relation == Relation::PARENT){
            child.push_back(second);
           }
        }
        return child;
    }
};
class Research{  // High level module
    public:
    Research(RelationshipBrowser& browser){
        for (auto &child : browser.findAllChildren("Mom")){
            cout<<"Mom has child with name "<<child.name<<endl;
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
    Research _res(rel);  // No change in the client code even when the low level code was changed
    return 0;
}