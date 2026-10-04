#include <iostream>
using namespace std;

class Character
{
public:
    virtual Character* clone() = 0;
    virtual void display() = 0;

    virtual ~Character() {}
};

class Knight : public Character
{
private:
    string name;
    int health;
    string weapon;

public:

    Knight(string name, int health, string weapon)
    {
        this->name = name;
        this->health = health;
        this->weapon = weapon;
    }

    Character* clone() override
    {
        return new Knight(*this);
    }

    void display() override
    {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Weapon: " << weapon << endl;

    }
};

class Archer : public Character
{
private:
    string name;
    int health;
    string weapon;
    int Range;

public:

    Archer(string name, int health, string weapon, int range)
    {
        this->name = name;
        this->health = health;
        this->weapon = weapon;
        this->Range = range;
    }

    Character* clone() override
    {
        return new Archer(*this);
    }

    void display() override
    {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Weapon: " << weapon << endl;
        cout<< "Range:" <<Range <<endl;

    }
};

int main()
{
    Knight* original = new Knight("Arthur", 100, "sword");

    Knight* copy =
        dynamic_cast<Knight*>(original->clone());
    
    original->display();
    copy->display();


    Archer* org = new Archer("Mayuri", 90, "sword", 5000);
    Archer *cp = dynamic_cast<Archer*>(org->clone());
    org->display();
    cp->display();

    delete original;
    delete copy;
    delete org;
    delete cp;

    return 0;
}