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

public:

    Knight(string name, int health)
    {
        this->name = name;
        this->health = health;
    }

    Character* clone() override
    {
        return new Knight(*this);
    }

    void display() override
    {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
    }
};

int main()
{
    Knight* original = new Knight("Arthur", 100);

    Knight* copy =
        dynamic_cast<Knight*>(original->clone());

    original->display();

    cout << "\nCopied Character\n";

    copy->display();

    delete original;
    delete copy;

    return 0;
}