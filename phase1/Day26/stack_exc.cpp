#include <iostream>
#include <stdexcept>  
using namespace std;


class StackOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Stack Overflow";
    }
};


class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Stack Underflow";
    }
};

class C2512Stack {
    private:
        static const int _size = 3;  
        double arr[_size];           
        int _top;

    public:
    
        C2512Stack() {
            _top = 0; 
        }

       
        void push(double data) {
            try {
                if (_top >= _size) { 
                    throw StackOverflowException(); 
                } else {
                    arr[_top] = data;
                    _top++;
                }
            }
            catch (const StackOverflowException& e) {
                cout << e.what() << endl;  
            }
        }

        
        void pop() {
            try {
                if (_top <= 0) { 
                    throw StackUnderflowException();  
                } else {
                    _top--;
                }
            }
            catch (const StackUnderflowException& e) {
                cout << e.what() << endl;  
            }
        }

        
        void top() {
            if (_top <= 0) { 
                cout << "Error: Stack is empty" << endl;
            } else {
                cout << "Top: " << arr[_top - 1] << endl; 
            }
        }
};


int main() {
    C2512Stack stack;

 
    stack.push(10.0);
    stack.push(12.0);
    stack.push(11.0);
    
    // try to add another element but it will throw exception that is stack overflow
    stack.push(17.0); 

   
    stack.top();  //top element is 11.0
    stack.pop();  // Popped: 11.0
    stack.top();  //top element is 12.0
    stack.pop();  // Popped: 12.0
    stack.top();  //top element is 10.0
    stack.pop();  // Popped: 10.0
    stack.pop();
    // Trying to pop when stack is empty this will throw  underflow exception
    stack.top();  

    return 0;
}