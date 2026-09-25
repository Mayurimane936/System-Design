// Question 3 — Discount Calculator

// An e-commerce application has different discount strategies:

// Regular Customer → 5% discount
// Premium Customer → 20% discount
// VIP Customer → 30% discount

#include <stdio.h>
#include <iostream>

using namespace std;

class Discount
{
protected:
    int regularDiscount = 5;
    int premiumDiscount = 20;
    int VIPDiscount = 30;

public:
    virtual void calculateDiscount(double amount) = 0;
    virtual ~Discount() {}
};

class Regular : public Discount
{
public:
    void calculateDiscount(double amount)
    {
        int discountAmount = (amount / 100) * regularDiscount;
        cout << "As you are our regular customer you got " << discountAmount << " discount, pay " << amount - discountAmount << endl;
    }
};

class Premium : public Discount
{
public:
    void calculateDiscount(double amount)
    {
        int discountAmount = (amount / 100) * premiumDiscount;
        cout << "As you are our premium customer you got " << discountAmount << " discount, pay " << amount - discountAmount << endl;
    }
};

class VIP : public Discount
{
public:
    void calculateDiscount(double amount)
    {
        int discountAmount = (amount / 100) * VIPDiscount;
        cout << "As you are our VIP customer you got " << discountAmount << " discount, pay " << amount - discountAmount << endl;
    }
};

class discountStrategy
{
public:
    Discount *dis = nullptr;
    void chooseDiscount(Discount *dis)
    {
        delete this->dis;
        this->dis = dis;
    }

    void getDiscount(double amount)
    {
        dis->calculateDiscount(amount);
    }

    ~discountStrategy()
    {
        delete dis;
    }
};

int main()
{
    discountStrategy discount;
    discount.chooseDiscount(new Regular());
    discount.getDiscount(5000);
    discount.chooseDiscount(new Premium());
    discount.getDiscount(5000);
    discount.chooseDiscount(new VIP());
    discount.getDiscount(5000);
    return 0;
}