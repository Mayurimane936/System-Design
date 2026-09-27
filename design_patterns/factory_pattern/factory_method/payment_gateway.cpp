#include<stdio.h>
#include<iostream>

using namespace std;

class Payment {
    public: 
        virtual void doPayment(double amount) = 0;
        virtual ~Payment(){};
};

class StripePayment: public Payment{
    public:
        void doPayment(double amount){
            cout<<"paying "<<amount<<" via StripePayment"<<endl;
        }
};

class RazorpayPayment: public Payment{
    public:
        void doPayment(double amount){
            cout<<"paying "<<amount<<" via RazorpayPayment"<<endl;
        }
};

class PayPalPayment: public Payment{
    public:
        void doPayment(double amount){
            cout<<"paying "<<amount<<" via PayPalPayment"<<endl;
        }
};

class PaymentCreator{
    public: 
        virtual Payment *createPayment() = 0;
        virtual ~PaymentCreator(){};
};

class StripeCreator: public PaymentCreator{
    public: 
       Payment* createPayment() override {
            return new StripePayment();
       }
};

class RazorpayCreator: public PaymentCreator{
    public: 
       Payment* createPayment() override {
            return new RazorpayPayment();
       }
};

class PayPalCreator: public PaymentCreator{
    public: 
       Payment* createPayment() override {
            return new PayPalPayment();
       }
};

int main(){
    PaymentCreator *createPayment = new StripeCreator();
    Payment *stripePayment = createPayment->createPayment();
    stripePayment->doPayment(5000);

    PaymentCreator *createPaymentt = new PayPalCreator();
    Payment *paypalPayment = createPaymentt->createPayment();
    paypalPayment->doPayment(300);

    delete createPayment;
    delete stripePayment;

    delete createPaymentt;
    delete paypalPayment;
    return 0;
}