#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Burger {
    public:
    virtual void prepare() = 0;
    virtual ~Burger() {};
};

class BasicBurger : public Burger {
    public :
    void prepare() override {
        cout<<"preparing basic burger with patty and bun" << endl;
    }
};

class StandardBurger : public Burger {
    public:
    void prepare() override {
        cout<<"preparing standard burger with patty, bun, lettuce and tomato" << endl;
    }
};

class PremiumBurger : public Burger {
    public: 
    void prepare() override {
        cout<<"preparing premium burger with patty, bun, lettuce, tomato, cheese and bacon" << endl;
    }
};

class HealthybasicBurger : public Burger {
    public:
    void prepare() override {
        cout<<"preparing healthy basic burger with patty, bun and lettuce" << endl;
    }
};

class HealthyStandardBurger : public Burger {
    public:
    void prepare() override {
        cout<<"preparing healthy standard burger with patty, bun, lettuce and tomato" << endl;
    }
};

class HealthyPremiumBurger : public Burger {
    public:
    void prepare() override {
        cout<<"preparing healthy premium burger with patty, bun, lettuce, tomato and cheese" << endl;
    }
};

class BurgerFactory {
    public :
    virtual Burger* createBurger(string type) = 0;
    virtual ~BurgerFactory() {};
};

class SinghBurger : public BurgerFactory {
    public:
    Burger *createBurger (string type) override {
        if(type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new PremiumBurger();
        } else {
            cout<<"Invalid burger type" << endl;
            return nullptr;
        }
    }
};

class HealthyBurgerFactory : public BurgerFactory {
    public:
    Burger *createBurger (string type) override {
        if(type == "basic") {
            return new HealthybasicBurger();
        } else if (type == "standard") {
            return new HealthyStandardBurger();
        } else if (type == "premium") {
            return new HealthyPremiumBurger();
        } else {
            cout<<"Invalid burger type" << endl;
            return nullptr;
        }
    }
};

int main () {
    string type = "premium";
    BurgerFactory *factory = new SinghBurger();
    Burger *burger = factory->createBurger(type);
    burger->prepare();

    BurgerFactory *healthyFactory = new HealthyBurgerFactory();
    Burger *healthyBurger = healthyFactory->createBurger(type);
    healthyBurger->prepare();
}