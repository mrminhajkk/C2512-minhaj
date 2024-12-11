#include <iostream>
using namespace std;

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
            if (_top >= _size) { 
                cout << "Error: Stack Overflow" << endl;
            } else {
                arr[_top] = data;
                _top++;
            }
        }

        
        void pop() {
            if (_top <= 0) { 
                cout << "Error: Stack Underflow" << endl;
            } else {
                _top--;
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
    stack.push(17.0);
    stack.top(); // element at the top is 11.0
    stack.pop(); // Popped: 11.0
    stack.top(); // element at the top is 12.0
    stack.pop(); // Popped: 12.0
    stack.top(); // element at the top is 10.0
    stack.pop(); // Popped: 10.0
    stack.top(); // Error: Stack is empty

    return 0;
}