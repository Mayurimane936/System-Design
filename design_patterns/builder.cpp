#include<stdio.h>
#include<iostream>

using namespace std;

class HotDog {
    string bun;
    string sausage;
    string sauce;
    public:
        HotDog* setBun() {
            this->bun = true;
            return this;
            
        }
        HotDog* setSausage() {
            this->sausage = true;
            return this;
        }
        HotDog* setSauce() {
            this->sauce = true;
            return this;
        }
        void show() {
            cout << "HotDog with " << bun << " bun, " << sausage << " sausage, and " << sauce << " sauce." << endl;
        }
};


int main (){
    HotDog* hotDog = new HotDog();
    cout<<" hotDog value"<<hotDog<<endl; // address 
    hotDog->setBun()->setSausage()->setSauce();
    hotDog->show();
}