#include <iostream>
#include <string>

using namespace std;

class UI
{
public:
    virtual void createElement() = 0;
    virtual ~UI() {}
};


class Button : public UI
{
public:
    void createElement() override
    {
        cout << "Creating Button" << endl;
    }
};


class WindowsButton : public Button
{
public:
    void createElement() override
    {
        cout << "Creating Windows Button" << endl;
    }
};


class MacButton : public Button
{
public:
    void createElement() override
    {
        cout << "Creating Mac Button" << endl;
    }
};


class CheckBox : public UI
{
public:
    void createElement() override
    {
        cout << "Creating CheckBox" << endl;
    }
};


class WindowsCheckBox : public CheckBox
{
public:
    void createElement() override
    {
        cout << "Creating Windows CheckBox" << endl;
    }
};


class MacCheckBox : public CheckBox
{
public:
    void createElement() override
    {
        cout << "Creating Mac CheckBox" << endl;
    }
};



class UIFactory
{
public:
    virtual Button* createButton() = 0;
    virtual CheckBox* createCheckBox() = 0;

    virtual ~UIFactory() {}
};



class WindowsFactory : public UIFactory
{
public:
    Button* createButton() override
    {
        return new WindowsButton();
    }

    CheckBox* createCheckBox() override
    {
        return new WindowsCheckBox();
    }
};


// ---------------- MAC FACTORY ----------------

class MacFactory : public UIFactory
{
public:
    Button* createButton() override
    {
        return new MacButton();
    }

    CheckBox* createCheckBox() override
    {
        return new MacCheckBox();
    }
};

int main()
{
    UIFactory* uI = new MacFactory();

    UI* button = uI->createButton();
    button->createElement();

    UI* checkBox = uI->createCheckBox();
    checkBox->createElement();


    delete button;
    delete checkBox;
    delete uI;


    uI = new WindowsFactory();

    UI* windowsButton = uI->createButton();
    windowsButton->createElement();

    UI* windowsCheckBox = uI->createCheckBox();
    windowsCheckBox->createElement();


    delete windowsButton;
    delete windowsCheckBox;
    delete uI;

    return 0;
}