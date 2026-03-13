#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Burger {
    public: 
    virtual void preapre() = 0;
    virtual ~Burger() {};
};

// different type of burgers
class BasicBurger : public Burger {
    public:
    void preapre() override {
        cout<<"Preparing basic burger" << endl;
    }
};

class StandardBurger : public Burger {
    public:
    void preapre() override {
        cout<<"Preparing standard burger" << endl;
    }
};

class PremiumBurger : public Burger {
    public:
    void preapre() override {
        cout<<"Preparing premium burger" << endl;
    }
};

class HealthyBasicBurger : public Burger {
    public:
    void preapre() override {
        cout<<"Preparing healthy basic burger" << endl;
    }
};

class HealthyStandardBurger : public Burger {
    public:
    void preapre() override {
        cout<<"Preparing healthy standard burger" << endl;
    }
};

class HealthyPremiumBurger : public Burger {
    public:
    void preapre() override {
        cout<<"Preparing healthy premium burger" << endl;
    }
};

class GarlicBread {
    public:
    virtual void prepare() = 0;
    virtual ~GarlicBread() {};
};

// different type of garlic bread
class BasicGarlicBread : public GarlicBread {
    public:
    void prepare() override {
        cout<<"Preparing basic garlic bread" << endl;
    }
};

class StandardGarlicBread : public GarlicBread {
    public:
    void prepare() override {
        cout<<"Preparing standard garlic bread" << endl;
    }
};

class PremiumGarlicBread : public GarlicBread {
    public:
    void prepare() override {
        cout<<"Preparing premium garlic bread" << endl;
    }
};

class HealthyBasicGarlicBread : public GarlicBread {
    public:
    void prepare() override {
        cout<<"Preparing healthy basic garlic bread" << endl;
    }
};

class HealthyStandardGarlicBread : public GarlicBread {
    public:
    void prepare() override {
        cout<<"Preparing healthy standard garlic bread" << endl;
    }
};

class HealthyPremiumGarlicBread : public GarlicBread {
    public:
    void prepare() override {
        cout<<"Preparing healthy premium garlic bread" << endl;
    }
};

class FoodFactory {
    public:
    virtual Burger* createBurger(string type) = 0;
    virtual GarlicBread* createGarlicBread(string type) = 0;
    virtual ~FoodFactory() {};
};

class SinghFoodFactory: public FoodFactory {
    public: 
    Burger* createBurger(string type) override {
        if (type == "basic") {
            return new HealthyBasicBurger();
        } else if (type == "standard") {
            return new HealthyStandardBurger();
        } else if (type == "premium") {
            return new HealthyPremiumBurger();
        } else {
            cout<<"Invalid burger type" << endl;
            return nullptr;
        }
    }
    GarlicBread* createGarlicBread(string type) override {
        if (type == "basic") {
            return new HealthyBasicGarlicBread();
        } else if (type == "standard") {
            return new HealthyStandardGarlicBread();
        } else if (type == "premium") {
            return new HealthyPremiumGarlicBread();
        } else {
            cout<<"Invalid garlic bread type" << endl;
            return nullptr;
        }
    }
};

class KingFoodFactory : public FoodFactory {
    public:
    Burger* createBurger(string type) override {
        if (type == "basic") {
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
    GarlicBread* createGarlicBread(string type) override {
        if (type == "basic") {
            return new BasicGarlicBread();
        } else if (type == "standard") {
            return new StandardGarlicBread();
        } else if (type == "premium") {
            return new PremiumGarlicBread();
        } else {
            cout<<"Invalid garlic bread type" << endl;
            return nullptr;
        }
    }
};


int main () {
    string type = "standard";
    FoodFactory *factory1 = new SinghFoodFactory();
    Burger * burger1 = factory1->createBurger(type);
    burger1->preapre();

    GarlicBread *garlicBread1 = factory1->createGarlicBread(type);
    garlicBread1->prepare();

    FoodFactory *factory2 = new KingFoodFactory();
    Burger * burger2 = factory2->createBurger(type);
    burger2->preapre();

    GarlicBread *garlicBread2 = factory2->createGarlicBread(type);
    garlicBread2->prepare();

     return 0;
}