#include <stdint.h>
#include <iostream>

using namespace std;

class Notification {
public:
    virtual void send() = 0;

    virtual ~Notification() {
        cout << "Notification destructor called" << endl;
    }
};

class SMS : public Notification {
public:
    void send() override {
        cout << "sending notification via SMS" << endl;
    }

    ~SMS() {
        cout << "SMS destructor called" << endl;
    }
};

class Email : public Notification {
public:
    void send() override {
        cout << "sending notification via Email" << endl;
    }

    ~Email() {
        cout << "Email destructor called" << endl;
    }
};

class Whatsapp : public Notification {
public:
    void send() override {
        cout << "sending notification via Whatsapp" << endl;
    }

    ~Whatsapp() {
        cout << "Whatsapp destructor called" << endl;
    }
};

class NotificationCreator {
public:
    virtual Notification* createNotification() = 0;

    virtual ~NotificationCreator() {
        cout << "NotificationCreator destructor called" << endl;
    }
};

class CreateSMSNotification : public NotificationCreator {
public:
    Notification* createNotification() override {
        return new SMS();
    }

    ~CreateSMSNotification() {
        cout << "CreateSMSNotification destructor called" << endl;
    }
};

class CreateEmailNotification : public NotificationCreator {
public:
    Notification* createNotification() override {
        return new Email();
    }

    ~CreateEmailNotification() {
        cout << "CreateEmailNotification destructor called" << endl;
    }
};

class CreateWhatsappNotification : public NotificationCreator {
public:
    Notification* createNotification() override {
        return new Whatsapp();
    }

    ~CreateWhatsappNotification() {
        cout << "CreateWhatsappNotification destructor called" << endl;
    }
};

int main() {

    NotificationCreator* notificationCreator =
        new CreateEmailNotification();

    Notification* notification =
        notificationCreator->createNotification();

    notification->send();

    cout << "\n--- Deleting notification ---" << endl;

    delete notification;

    cout << "\n--- Deleting notification creator ---" << endl;

    delete notificationCreator;

    return 0;
}

