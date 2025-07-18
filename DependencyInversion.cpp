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
class Relationship{
    public:
    vector<tuple<Person, Relation, Person>> relations;
    void addParentAndChild(const Person& parent, const Person& child){
        relations.push_back({parent,Relation::PARENT,child});
        relations.push_back({child,Relation::CHILD,parent});
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
    return 0;
}