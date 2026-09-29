#include <iostream>
using namespace std;

class Payment
{
public:
    virtual void pay(double amount) = 0;
    virtual ~Payment() {}
};

class Refund
{
public:
    virtual void refund(double amount) = 0;
    virtual ~Refund() {}
};

class StripePayment : public Payment
{
public:
    void pay(double amount) override
    {
        cout << "Stripe: Processing payment of ₹"
             << amount << endl;
    }
};

class StripeRefund : public Refund
{
public:
    void refund(double amount) override
    {
        cout << "Stripe: Processing refund of ₹"
             << amount << endl;
    }
};

class PaypalPayment : public Payment
{
public:
    void pay(double amount) override
    {
        cout << "PayPal: Processing payment of ₹"
             << amount << endl;
    }
};

class PaypalRefund : public Refund
{
public:
    void refund(double amount) override
    {
        cout << "PayPal: Processing refund of ₹"
             << amount << endl;
    }
};

class PaymentFactory
{
public:
    virtual Payment* createPayment() = 0;
    virtual Refund* createRefund() = 0;

    virtual ~PaymentFactory() {}
};

// ======================================================
// 6. CONCRETE FACTORY: Stripe
// ======================================================

class StripeFactory : public PaymentFactory
{
public:
    Payment* createPayment() override
    {
        return new StripePayment();
    }

    Refund* createRefund() override
    {
        return new StripeRefund();
    }
};

class PaypalFactory : public PaymentFactory
{
public:
    Payment* createPayment() override
    {
        return new PaypalPayment();
    }

    Refund* createRefund() override
    {
        return new PaypalRefund();
    }
};

int main()
{
    PaymentFactory* factory = new StripeFactory();

    Payment* payment = factory->createPayment();
    Refund* refund = factory->createRefund();

    payment->pay(5000);
    refund->refund(2000);

    delete payment;
    delete refund;
    delete factory;

    factory = new PaypalFactory();

    payment = factory->createPayment();
    refund = factory->createRefund();

    payment->pay(5000);
    refund->refund(2000);

    delete payment;
    delete refund;
    delete factory;

    return 0;
}