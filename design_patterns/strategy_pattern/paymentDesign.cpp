#include<stdio.h>
#include<iostream>

using namespace std;

//abstract class
class PaymentMethod {
    public: 
    virtual void pay (int amount) = 0;
    virtual ~PaymentMethod() {};
};


class UPIPayment : public PaymentMethod{
    public: 
    void pay (int amount) override{
        cout<<"Paid  ₹" <<amount << " using UPI"<<endl;
    }
};

class CardPayment : public PaymentMethod{
    public: 
    void pay (int amount) override{
        cout<<"Paid  ₹" <<amount << " using CardPayment"<<endl;
    }
};

class NetBanking : public PaymentMethod{
    public: 
    void pay (int amount) override{
        cout<<"Paid  ₹" <<amount << " using NetBanking"<<endl;
    }
};


class Strategy {
    PaymentMethod* method = nullptr;
    public:
        void callStrategy (PaymentMethod* paymentType){
            this->method = paymentType;
        }

        void executeStrategy(int amount){
            method->pay(amount);
        }
        ~Strategy() {
            delete method;
        }
};

int main() {
    Strategy PaymentStrategy;
    PaymentStrategy.callStrategy(new CardPayment());
    PaymentStrategy.executeStrategy(2000);
    return 0;
}

