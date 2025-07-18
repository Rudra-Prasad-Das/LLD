#include<iostream>
#include<vector>

using namespace std;
class Document{
    public:
    Document(){

    }
};
//Segregation of Interfaces
class IPrinter{
    virtual void print(Document& doc) = 0;
};

class IScanner{
    virtual void print(Document& doc) = 0;
};

class IFax{
    virtual void fax(Document& doc) = 0;
};

class MFP:public IPrinter, public IScanner, public IFax {
    void print(Document& doc){

    }
    void scan(Document& doc){

    }

    void fax(Document& doc){

    }
};

class Scanner:public IScanner{
    void scan(Document& doc){
        // Only functionality required
    }
};
int main(){
    //client code
    return 0;
}
