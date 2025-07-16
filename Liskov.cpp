/**
 * Liskov Principle
 *  Base classes should be directly replacable with Subclasses without change in the functionality
 */

#include<iostream>
using namespace std;

class Rectangle{
    protected:
    int height;
    int width;
    public:
    Rectangle(int width ,int height) : width(width), height(height) {}
    virtual void setHeight(int height){
        Rectangle::height = height;
    }
    virtual void setWidth(int width){
        Rectangle::width = width;
    }
    int getHeight(){
        return height;
    }
    int getWidth(){
        return width;
    }
    int area(){
        return height*width;
    }
    
};
class Square : public Rectangle{
    public:
    Square(int size) : Rectangle(size, size) {}

    void setHeight(int height){
        this->width = this->height = height;
    }

    void setWidth(int width){
        this->width = this->height = width;
    }

};
/**
 * @brief Violation of the Liskov Principle
 * It states that any function is taking any object of the Base class then it should be replacable by the Derived class without any problem
 * @param r 
 */
void process(Rectangle &r){
    int w = r.getWidth();
    r.setHeight(10);
    cout<<"Expected area : "<<(w*10)<<" Processed area : "<<r.area()<<endl;
}
int main(){
    Rectangle r(3,4);
    process(r);
    Square sq(5);
    process(sq);
    return 0;
}