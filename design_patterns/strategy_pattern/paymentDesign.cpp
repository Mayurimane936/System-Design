#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class PayNow {
    public:
    virtual void pay() = 0;
    virtual ~PayNow() {};
};

class UpiPayment : public PayNow {
    public:
    void pay() {
        cout << "Paying using UPI" << endl;
    }
};

class CardPayment : public PayNow {
    public:
    void pay() {
        cout << "Paying using card" << endl;
    }
};

class NetBankingPayment : public PayNow {
    public:
    void pay() {
        cout << "Paying using net banking" << endl;
    }
};

class Payment {
    private:
    PayNow *payStrategy;

    public: 
    Payment (PayNow *p) {
        this->payStrategy = p;
    }

    void pay() {
        payStrategy->pay();
    }
};


int main () {
    Payment *payment1 = new Payment(new UpiPayment());
    Payment *payment2 = new Payment(new CardPayment());
    Payment *payment3 = new Payment(new NetBankingPayment());

    payment1->pay();
    payment2->pay();
    payment3->pay();

    return 0;
}