#include <iostream>
#include <string>
using namespace std;




class Plant {
protected:
    double height;
    int age;

public:
    Plant(double h, int a) : height(h), age(a) {
        cout << "Plant Constructor: Height = " << height << ", Age = " << age << endl;
    }

    virtual ~Plant() {  
        cout << "Plant Destructor" << endl;
    }

    void grow() {
        cout << "The plant is growing. Height: " << height << ", Age: " << age << endl;
    }
};





class Flower : public Plant {
protected:
    string color;

public:
    Flower(double h, int a, const string& c) : Plant(h, a), color(c) {
        cout << "Flower Constructor: Color = " << color << ", Height = " << height << ", Age = " << age << endl;
    }

    ~Flower() {
        cout << "Flower Destructor" << endl;
    }

    void bloom() {
        cout << "The " << color << " flower is blooming!" << endl;
    }
};





int main() {
    cout << "Static Object: \n";
    Plant staticPlant(10, 5);        
    Flower staticFlower(20, 10, "Red"); 


    staticPlant.grow();  
    staticFlower.grow(); 
    staticFlower.bloom(); 

    cout << "\nDynamic Object: \n";
    Plant* dynamicPlant = new Plant(15, 7);   
    Flower* dynamicFlower = new Flower(30, 14, "Yellow");


    dynamicPlant->grow();   
    dynamicFlower->grow();  
    dynamicFlower->bloom(); 

    delete dynamicPlant;
    delete dynamicFlower;

    return 0;
}
