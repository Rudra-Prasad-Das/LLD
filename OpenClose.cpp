#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class Color {red, green , blue};
enum class Size  {small, medium, large};

class Product{
    public:
    string name;
    Color color;
    Size size;
    Product(string name , Color color, Size size){
        this->name = name;
        this->color = color;
        this->size = size;
    }
};

class ProductFilter{
    public:
    vector<Product*> byColor(vector<Product*> items, Color color){
        vector<Product*> results;
        for(auto& item : items){
            if(item->color == color){ 
                results.push_back(item);
            }
        }
        return results;
    }
};

int main(){
    Product apple("Apple", Color::green, Size::small);
    Product tree("Banyan", Color::green, Size::large);
    Product house("House", Color::blue, Size::large);

    vector<Product*> items {&apple, &tree, &house};
    ProductFilter pf;

    auto greenItems = pf.byColor(items, Color::green);
    string itemSize;
    for(auto greenItem : greenItems){  
        if(greenItem->size == Size::large){
            itemSize = "large";
        } 
        else if (greenItem->size == Size::medium){
            itemSize = "medium";
        }
        else{
            itemSize = "small";
        }
        cout << greenItem->name << " " << itemSize <<endl; //fix
        /**
         * @brief cout << greenItem->name << " " << greenItem->color <<endl; is an error
         * Reason : Color is an enum and cout does not know how to print greenItem->color
         */
    }




    return 0;
}

/**
 * @brief How to compile and run cpp code in terminal
 * g++ <filename>.cpp -o <filename>.exe
 * <filename>.exe
 */