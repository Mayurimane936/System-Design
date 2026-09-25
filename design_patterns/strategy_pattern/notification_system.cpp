// Now let's test whether you understand the pattern rather than just the payment example.

// Problem 2: Notification System

// Imagine an application that can send notifications through:

// Email
// SMS
// WhatsApp

// Create a Strategy Pattern implementation.

#include<stdio.h>
#include<iostream>
using namespace std;

class NotificationMethod {
    public:
        virtual void sendNotification(string msg) = 0;
        virtual ~ NotificationMethod() {};
};

class Email : public NotificationMethod{
    public: 
        void sendNotification (string msg) override {
            cout<< msg<<endl;
        }
};

class SMS : public NotificationMethod{
    public: 
        void sendNotification (string msg) override {
            cout<< msg<<endl;
        }
};

class WhatsApp : public NotificationMethod{
    public: 
        void sendNotification (string msg) override {
            cout<< msg<<endl;
        }
};

class sendNotification {
    public:
        NotificationMethod *notification = nullptr;
        void create( NotificationMethod *notification) {
            delete this->notification; //memory leak each time it overrides object.
            this->notification = notification;
        }

        void send(string msg){
            notification->sendNotification(msg);
        }

        ~sendNotification() {
            delete notification;
        }
};

int main(){
    sendNotification notify;
    notify.create(new WhatsApp());
    notify.send("Hello Mayuri from whatsapp");
    notify.create(new Email());
    notify.send("Hello Mayuri from Email");
    notify.create(new SMS());
    notify.send("Hello Mayuri from SMS");
    return 0;
}