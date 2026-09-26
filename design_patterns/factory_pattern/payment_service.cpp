#include <stdio.h>
#include<iostream>

using namespace std;

enum class PaymentTypes {
    UPI,
    Card,
    NetBanking
};

class Payment{
public:
   virtual void pay() = 0;
   virtual ~ Payment(){}
};

class UPI: public Payment {
public:
    void pay() {
        cout << "Paid using UPI";
    }
};

class Card: public Payment {
public:
    void pay() {
        cout << "Paid using Card";
    }
};

class NetBanking: public Payment {
public:
    void pay() {
        cout << "Paid using Net Banking";
    }
};

class PaymentFactory {
    public: 
        Payment *createPayment(PaymentTypes method){
            if(method == PaymentTypes:: UPI){
                return new UPI();
            }else if(method == PaymentTypes:: Card){
                return new Card();
            }else {
                return new NetBanking();
            }
        }
};


int main(){
    PaymentFactory doPayment;
    Payment *p = doPayment.createPayment(PaymentTypes::NetBanking);
    p->pay();
    p = doPayment.createPayment(PaymentTypes::Card);
    p->pay();
    delete p;
    return 0;
}