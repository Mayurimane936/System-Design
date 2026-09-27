#include <stdio.h>
#include <iostream>

using namespace std;

class Config
{
private:
    string val = "";
    Config()
    {
        cout << "Object got created babyyyy" << endl;
    }

    Config(const Config &) = delete;
    Config &operator=(const Config &) = delete;

public:
    static Config &getInstance()
    {
        static Config instance;
        return instance;
    }
    void setValue(string val)
    {
        this->val = val;
        cout << "we have set the val " << val << endl;
    };

    void display()
    {
        cout << "val " << val << endl;
    }
};

int main()
{
    Config &conf = Config::getInstance();
    Config &conff = Config::getInstance();

    conf.setValue("hello");
    conff.display();
    return 0;
}