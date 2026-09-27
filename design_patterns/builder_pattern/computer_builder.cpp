#include <iostream>
#include <string>
using namespace std;

class Computer
{
public:
    string CPU = "";
    int RAM = 0;
    string Storage = "";
    bool WiFi = false;
    string GPU = "";
    bool Bluetooth = false;
    bool WebCam = false;

    void display()
    {
        cout << "CPU: " << CPU << endl;
        cout << "RAM: " << RAM << " GB" << endl;
        cout << "Storage: " << Storage << endl;
        cout << "WiFi: " << WiFi << endl;
        cout << "GPU: " << GPU << endl;
        cout << "Bluetooth: " << Bluetooth << endl;
        cout << "Webcam: " << WebCam << endl;
    }
};


// =======================
// Builder
// =======================

class ComputerBuilder
{
private:
    Computer computer;

public:

    ComputerBuilder& setCPU(string CPU)
    {
        computer.CPU = CPU;
        return *this;
    }

    ComputerBuilder& setRAM(int RAM)
    {
        if (RAM <= 0)
        {
            cerr << "Error: RAM must be greater than 0!" << endl;
            return *this;
        }

        computer.RAM = RAM;
        return *this;
    }

    ComputerBuilder& setStorage(string Storage)
    {
        computer.Storage = Storage;
        return *this;
    }

    ComputerBuilder& setGPU(string GPU)
    {
        computer.GPU = GPU;
        return *this;
    }

    ComputerBuilder& enableWiFi()
    {
        computer.WiFi = true;
        return *this;
    }

    ComputerBuilder& enableBluetooth()
    {
        computer.Bluetooth = true;
        return *this;
    }

    ComputerBuilder& enableWebcam()
    {
        computer.WebCam = true;
        return *this;
    }

    Computer build()
    {
        // Save the current configuration
        Computer result = computer;

        // Reset builder for next Computer
        computer = Computer();

        return result;
    }
};


// =======================
// Director
// =======================

class ComputerDirector
{
public:

    Computer buildGamingComputer(ComputerBuilder& builder)
    {
        return builder
            .setCPU("Intel i9")
            .setRAM(64)
            .setStorage("2TB SSD")
            .setGPU("RTX")
            .enableWiFi()
            .enableBluetooth()
            .enableWebcam()
            .build();
    }

    Computer buildOfficeComputer(ComputerBuilder& builder)
    {
        return builder
            .setCPU("Intel i5")
            .setRAM(16)
            .setStorage("512GB SSD")
            .enableWiFi()
            .build();
    }
};


// =======================
// Main
// =======================

int main()
{
    ComputerBuilder builder;

    // --------------------------------
    // Build Computer 1 manually
    // --------------------------------

    Computer computer1 = builder
        .setCPU("Intel i7")
        .setRAM(32)
        .setStorage("1TB SSD")
        .enableWiFi()
        .setGPU("XYZ")
        .build();

    cout << "Computer 1" << endl;
    cout << "----------------" << endl;

    computer1.display();


    // --------------------------------
    // Build Computer 2 manually
    // --------------------------------

    Computer computer2 = builder
        .setCPU("Intel i8")
        .setRAM(64)
        .enableBluetooth()
        .enableWebcam()
        .build();

    cout << "\nComputer 2" << endl;
    cout << "----------------" << endl;

    computer2.display();


    // --------------------------------
    // Using Director
    // --------------------------------

    ComputerDirector director;

    Computer gamingPC =
        director.buildGamingComputer(builder);

    cout << "\nGaming Computer" << endl;
    cout << "----------------" << endl;

    gamingPC.display();


    Computer officePC =
        director.buildOfficeComputer(builder);

    cout << "\nOffice Computer" << endl;
    cout << "----------------" << endl;

    officePC.display();


    return 0;
}