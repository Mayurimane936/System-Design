#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Burger {
    public: 
    virtual void prepare() = 0;
    virtual ~Burger() {};
};

//different type of burgers
class BasicBurger : public Burger {
    public:
    void prepare() override {
        cout<<"Preparing basic burger" << endl;
    }
};

class StandardBurger : public Burger{
    public:
    void prepare() override {
        cout<<"Preparing standard burger" << endl;
    }
};

class PremiumBurger : public Burger {
    public:
    void prepare() override {
        cout<<"Preparing premium burger" << endl;
    }
};

class BurgerFactory {
    public: 
    Burger *createBurger (string type){
        if(type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new PremiumBurger();
        } else {
            return nullptr;
            cout<<"Invalid burger type" << endl;
        }
    }
};

int main () {
    string type = "standard";
    BurgerFactory *factory = new BurgerFactory();
    Burger *burger = factory->createBurger(type);
    burger->prepare();
}