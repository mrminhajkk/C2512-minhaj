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

template <typename T>
class C2512Stack {
private:
    T* arr;        
    int _top;
    static const int _size = 3; 

public:
   
    C2512Stack() {  
        arr = new T[_size];  
        _top = 0; 
    }

   
    ~C2512Stack() {
        delete[] arr;  
    }

    
    void push(T data) {
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
    // Create stack for double type 
    cout << "Stack for double datatype:\n" << endl;
    C2512Stack<double> stack;

   
    stack.push(10.0);
    stack.push(12.0);
    stack.push(11.0);
    
    // Trying to push another element this will cause overflow exception
    stack.push(17.0);  

   
    stack.top();  // Top: 11.0
    stack.pop();  // Popped: 11.0
    stack.top();  // Top: 12.0
    stack.pop();  // Popped: 12.0
    stack.top();  // Top: 10.0
    stack.pop();  // Popped: 10.0
    stack.pop();  // Error: Stack Underflow
    stack.top();  // Error: Stack is empty

    // Create stack for int type
     cout << "\n\nStack for int datatype:\n" << endl;
    C2512Stack<int> intStack;
   
   
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    // Trying to push another element this will cause overflow exception
    intStack.push(4); 

    
    intStack.top();  // Top: 3
    intStack.pop();  // Popped: 3
    intStack.top();  // Top: 2
    intStack.pop();  // Popped: 2
    intStack.top();  // Top: 1
    intStack.pop();  // Popped: 1
    intStack.pop();  // Error: Stack Underflow
    intStack.top();  // Error: Stack is empty

     C2512Stack<long> lStack;
      cout << "\n\nStack for long datatype:\n" << endl;
     
     lStack.push(2L);
     lStack.push(4L);
     lStack.push(6L);
     
    lStack.top();  // Top: 3
    lStack.pop();  // Popped: 3
    lStack.top();  // Top: 2
    lStack.pop();  // Popped: 2
    lStack.top();  // Top: 1
    lStack.pop();  // Popped: 1
    lStack.pop();  // Error: Stack Underflow
    lStack.top();
     
    

    return 0;
}
