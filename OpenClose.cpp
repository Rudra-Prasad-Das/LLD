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
   // Make a different function for a different filter
    vector<Product*> bySize(vector<Product*> items, Size size){
        vector<Product*> results;
        for(auto& item : items){
            if(item->size == size){ 
                results.push_back(item);
            }
        }
        return results;
    }

    vector<Product*> bySizeAndColor(vector<Product*> items, Size size, Color color){
        vector<Product*> results;
        for(auto& item : items){
            if(item->size == size && item->color == color){ 
                results.push_back(item);
            }
        }
        return results;
    }
    
};
template<typename T> 
class Specification {
public:
    virtual bool isSatisfied(T* item) = 0;
};

template<typename T> 
class Filter {
public:
    virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
};

class BetterFilter : public Filter<Product> {
public:
    vector<Product*> filter(vector<Product*> items, Specification<Product>& spec) override {
        vector<Product*> result;
        for (auto& item : items) {
            if (spec.isSatisfied(item)) {
                result.push_back(item);
            }
        }
        return result;
    }
};
class ColorSpecification : public Specification<Product>
{
    public:
    Color color;
    ColorSpecification(Color color) : color(color) {}

    bool isSatisfied(Product* item){
        return item->color == color;
    }

};

class SizeSpecification : public Specification<Product>
{
    public:
    Size size;
    SizeSpecification(Size size) : size(size) {}

    bool isSatisfied(Product* item){
        return item->size == size;
    }
};

template<typename T>
class AndSpecification : public Specification<T>{
    public:
    Specification<T>& first;
    Specification<T>& second;

    AndSpecification(Specification<T> &first,Specification<T> &second) : first(first),second(second) {}

    bool isSatisfied(T* item){
        return first.isSatisfied(item) and second.isSatisfied(item);
    }


};

int main(){
    Product apple("Apple", Color::green, Size::small);
    Product tree("Banyan", Color::green, Size::large);
    Product house("House", Color::blue, Size::large);

    vector<Product*> items {&apple, &tree, &house};
    
    BetterFilter bf;
    ColorSpecification green(Color::green);
    /**
        for(auto item : bf.filter(items, green)){
            cout<<item->name<<endl;
        }
    */
    
    SizeSpecification small(Size::small);

    AndSpecification<Product> greenAndSmall(green,small);

    for(auto item : bf.filter(items, greenAndSmall)){
            cout<<item->name<<endl;
        }

        /**
         * @brief cout << greenItem->name << " " << greenItem->color <<endl; is an error
         * Reason : Color is an enum and cout does not know how to print greenItem->color
         */
    
    return 0;
}

/**
 * @brief Open Close Principle --> System should be open to extension and closed for modifications
 * g++ <filename>.cpp -o <filename>.exe
 * <filename>.exe
 */