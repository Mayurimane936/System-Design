#include <iostream>
using namespace std;

class Database
{
private:

    Database()
    {
        cout << "Database created" << endl;
    }

    // Prevent copying
    Database(const Database&) = delete;

    // Prevent assignment
    Database& operator=(const Database&) = delete;

public:
    static Database& getInstance()
    {
        
        static Database instance;
        return instance;
    }
};

int main()
{
    Database& db1 = Database::getInstance();
    Database& db2 = Database::getInstance();

    // Database d3 = Database::getInstance();

    cout << &db1 << endl;
    cout << &db2 << endl;

    return 0;
}