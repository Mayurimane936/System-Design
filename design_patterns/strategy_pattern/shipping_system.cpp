// An e-commerce website needs to calculate shipping charges.

// There are three shipping methods:

// Standard Shipping → ₹50
// Express Shipping  → ₹150
// Same Day Shipping → ₹300

// Create a Strategy Pattern.
#include <iostream>
using namespace std;

// Strategy
class Shipping {
public:
    virtual double calculateShipping(double amount) = 0;
    virtual ~Shipping() {}
};

// Concrete Strategy 1
class Standard : public Shipping {
private:
    int std = 50;

public:
    double calculateShipping(double amount) override {
        return std;
    }
};

// Concrete Strategy 2
class Express : public Shipping {
private:
    int exp = 150;

public:
    double calculateShipping(double amount) override {
        return exp;
    }
};

// Concrete Strategy 3
class SameDay : public Shipping {
private:
    int same = 300;

public:
    double calculateShipping(double amount) override {
        return same;
    }
};

// Context
class Ship {
public:
    Shipping* sh = nullptr;

    void chooseShipping(Shipping* sh) {
        delete this->sh;
        this->sh = sh;
    }

    void showCharges(double amount) {
        double shippingCharge = sh->calculateShipping(amount);

        cout << "Product Price: " << amount << endl;
        cout << "Shipping Charge: " << shippingCharge << endl;
        cout << "Final Price: " << amount + shippingCharge << endl;
        cout << "-------------------" << endl;
    }

    ~Ship() {
        delete sh;
    }
};

int main() {

//     Strategy decides HOW to calculate shipping.
// Context decides what to do with that result.

    Ship product;

    product.chooseShipping(new Standard());
    product.showCharges(4000);

    product.chooseShipping(new Express());
    product.showCharges(4000);

    product.chooseShipping(new SameDay());
    product.showCharges(4000);

    return 0;
}