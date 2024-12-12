#include <iostream>
#include <stdexcept>  
#include <vector>  // Include vector library
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
    vector<T> arr;     // Use a vector instead of a raw array
    int _top;          // Variable to keep track of the top index
    static const int _size = 3; 

public:
    C2512Stack() : _top(-1) {  
        // No need for dynamic allocation, vector will handle it.
    }

    void push(T data) {
        try {
            if (_top >= _size - 1) {  // Check if stack is full
                throw StackOverflowException(); 
            } else {
                _top++;  // Increment the top index
                if (_top < arr.size()) {
                    arr[_top] = data;  // Overwrite if space exists
                } else {
                    arr.push_back(data);  // Otherwise, add a new element
                }
            }
        }
        catch (const StackOverflowException& e) {
            cout << e.what() << endl;  
        }
    }

    void pop() {
        try {
            if (_top < 0) {  // Check if stack is empty
                throw StackUnderflowException(); 
            } else {
                cout << "Popped: " << arr[_top] << endl;  // Print the popped item
                _top--;  // Decrement the top index
            }
        }
        catch (const StackUnderflowException& e) {
            cout << e.what() << endl; 
        }
    }

    void top() {
        if (_top < 0) { 
            cout << "Error: Stack is empty" << endl;
        } else {
            cout << "Top: " << arr[_top] << endl;  // Display the top element
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

    // Create stack for long type
    C2512Stack<long> lStack;
    cout << "\n\nStack for long datatype:\n" << endl;
    
    lStack.push(2L);
    lStack.push(4L);
    lStack.push(6L);

    lStack.top();  // Top: 6
    lStack.pop();  // Popped: 6
    lStack.top();  // Top: 4
    lStack.pop();  // Popped: 4
    lStack.top();  // Top: 2
    lStack.pop();  // Popped: 2
    lStack.pop();  // Error: Stack Underflow
    lStack.top();   // Error: Stack is empty

    return 0;
}






























// #include <iostream>
// #include <stdexcept>  
// #include <vector>  // Include vector library
// using namespace std;

// class StackOverflowException : public exception {
// public:
//     const char* what() const noexcept override {
//         return "Error: Stack Overflow";
//     }
// };

// class StackUnderflowException : public exception {
// public:
//     const char* what() const noexcept override {
//         return "Error: Stack Underflow";
//     }
// };

// template <typename T>
// class C2512Stack {
// private:
//     vector<T> arr;     // Use a vector instead of a raw array
//     static const int _size = 3; 

// public:
//     C2512Stack() {  
//         // No need for dynamic allocation, vector will handle it.
//     }

//     void push(T data) {
//         try {
//             if (arr.size() >= _size) { 
//                 throw StackOverflowException(); 
//             } else {
//                 arr.push_back(data);  // Push data onto the stack (vector)
//             }
//         }
//         catch (const StackOverflowException& e) {
//             cout << e.what() << endl;  
//         }
//     }

//     void pop() {
//         try {
//             if (arr.empty()) { 
//                 throw StackUnderflowException(); 
//             } else {
//                 cout << "Popped: " << arr.back() << endl;  // Print the popped item
//                 arr.pop_back();  // Remove the top element from the stack
//             }
//         }
//         catch (const StackUnderflowException& e) {
//             cout << e.what() << endl; 
//         }
//     }

//     void top() {
//         if (arr.empty()) { 
//             cout << "Error: Stack is empty" << endl;
//         } else {
//             cout << "Top: " << arr.back() << endl;  // Display the top element
//         }
//     }
// };

// int main() {
//     // Create stack for double type 
//     cout << "Stack for double datatype:\n" << endl;
//     C2512Stack<double> stack;

//     stack.push(10.0);
//     stack.push(12.0);
//     stack.push(11.0);
    
//     // Trying to push another element this will cause overflow exception
//     stack.push(17.0);  

//     stack.top();  // Top: 11.0
//     stack.pop();  // Popped: 11.0
//     stack.top();  // Top: 12.0
//     stack.pop();  // Popped: 12.0
//     stack.top();  // Top: 10.0
//     stack.pop();  // Popped: 10.0
//     stack.pop();  // Error: Stack Underflow
//     stack.top();  // Error: Stack is empty

//     // Create stack for int type
//     cout << "\n\nStack for int datatype:\n" << endl;
//     C2512Stack<int> intStack;

//     intStack.push(1);
//     intStack.push(2);
//     intStack.push(3);

//     // Trying to push another element this will cause overflow exception
//     intStack.push(4); 

//     intStack.top();  // Top: 3
//     intStack.pop();  // Popped: 3
//     intStack.top();  // Top: 2
//     intStack.pop();  // Popped: 2
//     intStack.top();  // Top: 1
//     intStack.pop();  // Popped: 1
//     intStack.pop();  // Error: Stack Underflow
//     intStack.top();  // Error: Stack is empty

//     // Create stack for long type
//     C2512Stack<long> lStack;
//     cout << "\n\nStack for long datatype:\n" << endl;
    
//     lStack.push(2L);
//     lStack.push(4L);
//     lStack.push(6L);

//     lStack.top();  // Top: 6
//     lStack.pop();  // Popped: 6
//     lStack.top();  // Top: 4
//     lStack.pop();  // Popped: 4
//     lStack.top();  // Top: 2
//     lStack.pop();  // Popped: 2
//     lStack.pop();  // Error: Stack Underflow
//     lStack.top();   // Error: Stack is empty

//     return 0;
// }
