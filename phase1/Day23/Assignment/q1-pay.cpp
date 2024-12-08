#include <iostream>
#include <string>
using namespace std;


class PaymentMethod {
protected:
    string paymentType;

public:
    PaymentMethod(const string& type) : paymentType(type) {
        cout << "PaymentMethod Constructor: " << paymentType << endl;
    }

    virtual ~PaymentMethod() {
        cout << "PaymentMethod Destructor: " << paymentType << endl;
    }

    void processPayment() {
        cout << "Processing payment using " << paymentType << " method." << endl;
    }
};




class CreditCard : virtual public PaymentMethod {
protected:
    string cardNumber;

public:
    CreditCard(const string& type, const string& card) : PaymentMethod(type), cardNumber(card) {
        cout << "CreditCard Constructor: Card number " << cardNumber << endl;
    }

    virtual ~CreditCard() {
        cout << "CreditCard Destructor: Card number " << cardNumber << endl;
    }

    void authorize() {
        cout << "Authorizing payment with card number: " << cardNumber << endl;
    }
};






class DigitalWallet : virtual public PaymentMethod {
protected:
    string walletID;

public:
    DigitalWallet(const string& type, const string& wallet) : PaymentMethod(type), walletID(wallet) {
        cout << "DigitalWallet Constructor: Wallet ID " << walletID << endl;
    }

    virtual ~DigitalWallet() {
        cout << "DigitalWallet Destructor: Wallet ID " << walletID << endl;
    }

    void authenticate() {
        cout << "Authenticating wallet ID: " << walletID << endl;
    }
};







class HybridPayment : public CreditCard, public DigitalWallet {
protected:
    double discount;

public:
    HybridPayment(const string& type, const string& card, const string& wallet, double disc)
        : PaymentMethod(type), CreditCard(type, card), DigitalWallet(type, wallet), discount(disc) {
        cout << "HybridPayment Constructor: Discount " << discount << "%" << endl;
    }

    ~HybridPayment() {
        cout << "HybridPayment Destructor: Discount " << discount << "%" << endl;
    }

    void splitPayment() {
        cout << "Splitting payment with a discount of " << discount << "%" << endl;
    }
};

int main() {
    cout << "Static Object: \n";
    HybridPayment staticObj("Hybrid", "1234", "Wallet1001", 9.0);

    staticObj.processPayment();  
    staticObj.authorize();       
    staticObj.authenticate();    
    staticObj.splitPayment();    

    cout << "\nDynamic Object: \n";
    HybridPayment* dynamicObj = new HybridPayment("NetBanking", "5678", "Wallet1002", 29.0);

    dynamicObj->processPayment();  
    dynamicObj->authorize();       
    dynamicObj->authenticate();    
    dynamicObj->splitPayment();    

    delete dynamicObj;

    return 0;
}
