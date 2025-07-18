#include<iostream>
#include<vector>

using namespace std;
class Document{
    public:
    Document(){

    }
};
class IMachine{
    virtual void print(Document& doc) = 0;
    virtual void scan(Document& doc) = 0;
    virtual void fax(Document& doc) = 0;
};

class MFP:public IMachine{
    void print(Document& doc){

    }
    void scan(Document& doc){

    }

    void fax(Document& doc){

    }
};

class Scanner:public IMachine{
    void print(Document& doc){
        // throw some Exception 
        // or let them be empty
        // Sending the client wrong message is giving a wrong API
    }
    void scan(Document& doc){
        // Only functionality required
    }

    void fax(Document& doc){

    }
};
int main(){
    //client code
    return 0;
}
