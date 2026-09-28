#include <iostream>
#include <vector>

using namespace std;

//push model
// Observer
class Observer
{
public:
    virtual void update(double temperature) = 0;

    virtual ~Observer() {}
};

// Concrete Observer 1
class MobileApp : public Observer
{
public:
    void update(double temperature) override
    {
        cout << "Mobile notification: Temperature is "
             << temperature << "°C" << endl;
    }
};

// Concrete Observer 2
class TVDisplay : public Observer
{
public:
    void update(double temperature) override
    {
        cout << "TV Display: Current temperature is "
             << temperature << "°C" << endl;
    }
};

// Concrete Observer 3
class AlertSystem : public Observer
{
public:
    void update(double temperature) override
    {
        cout << "Alert: Temperature reached "
             << temperature << "°C" << endl;
    }
};

// Subject
class WeatherStation
{
private:
    vector<Observer*> observers;
    double temperature = 0;

public:

    // Add observer
    void addObserver(Observer* observer)
    {
        observers.push_back(observer);
    }

    // Remove observer
    void removeObserver(Observer* observer)
    {
        for (int i = 0; i < observers.size(); i++)
        {
            if (observers[i] == observer)
            {
                observers.erase(observers.begin() + i);
                return;
            }
        }
    }

    // Notify all observers
    void notifyObservers()
    {
        for (int i = 0; i < observers.size(); i++)
        {
            observers[i]->update(temperature);
        }
    }

    // Change temperature
    void setTemperature(double temperature)
    {
        this->temperature = temperature;

        cout << "\nTemperature updated to "
             << temperature << "°C" << endl;

        notifyObservers();
    }
};


int main()
{
    // Subject
    WeatherStation weatherStation;

    // Observers
    MobileApp mobile;
    TVDisplay tv;
    AlertSystem alert;

    // Register observers
    weatherStation.addObserver(&mobile);
    weatherStation.addObserver(&tv);
    weatherStation.addObserver(&alert);

    // Temperature changes
    weatherStation.setTemperature(30);

    // Remove TV from notification list
    cout << "\nRemoving TV Display...\n";

    weatherStation.removeObserver(&tv);

    // Temperature changes again
    weatherStation.setTemperature(35);

    return 0;
}