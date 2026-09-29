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


class TextBox : public UI
{
public:
    void createElement() override
    {
        cout << "Creating TextBox" << endl;
    }
};

class WindowsTextBox : public TextBox
{
public:
    void createElement() override
    {
        cout << "Creating Windows TextBox" << endl;
    }
};


class MacTextBox : public TextBox
{
public:
    void createElement() override
    {
        cout << "Creating Mac MacTextBox" << endl;
    }
};


class UIFactory
{
public:
    virtual Button *createButton() = 0;
    virtual CheckBox *createCheckBox() = 0;
    virtual TextBox *createTextBox() = 0;

    virtual ~UIFactory() {}
};

class WindowsFactory : public UIFactory
{
public:
    Button *createButton() override
    {
        return new WindowsButton();
    }

    CheckBox *createCheckBox() override
    {
        return new WindowsCheckBox();
    }
    TextBox *createTextBox() override{
        return new WindowsTextBox();
    }
};

// ---------------- MAC FACTORY ----------------

class MacFactory : public UIFactory
{
public:
    Button *createButton() override
    {
        return new MacButton();
    }

    CheckBox *createCheckBox() override
    {
        return new MacCheckBox();
    }

    TextBox *createTextBox() override{
        return new MacTextBox();
    }
};

int main()
{
    UIFactory *uI = new MacFactory();

    UI *button = uI->createButton();
    button->createElement();

    UI *checkBox = uI->createCheckBox();
    checkBox->createElement();

    UI *textBox = uI->createTextBox();
    textBox->createElement();

    delete button;
    delete checkBox;
    delete uI;

    uI = new WindowsFactory();

    UI *windowsButton = uI->createButton();
    windowsButton->createElement();

    UI *windowsCheckBox = uI->createCheckBox();
    windowsCheckBox->createElement();

    UI *windowsTextBox = uI->createTextBox();
    windowsTextBox->createElement();

    delete windowsButton;
    delete windowsCheckBox;
    delete textBox;
    delete uI;

    return 0;
}