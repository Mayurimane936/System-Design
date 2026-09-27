#include<stdio.h>
#include<iostream>

using namespace std;

class Logger {
    public: 
        virtual void logging(string msg) = 0;
        virtual ~Logger(){}
};

class FileLogger : public Logger{
    public:
        void logging(string msg) override{
            cout<<"logging with FileLogger "<<msg<<endl;
        }
};

class ConsoleLogger : public Logger{
    public:
        void logging(string msg) override{
            cout<<"logging with ConsoleLogger "<<msg<<endl;
        }
};

class DatabaseLogger : public Logger{
    public:
        void logging(string msg) override{
            cout<<"logging with DatabaseLogger "<<msg<<endl;
        }
};

class LoggerCreator{
    public: 
        virtual Logger *CreateLogger() = 0;
        virtual ~LoggerCreator(){}
};

class ConsoleLoggerCreator : public LoggerCreator{
    Logger *CreateLogger () override {
        return new ConsoleLogger();
    }
};

class DatabaseLoggerCreator : public LoggerCreator{
    Logger *CreateLogger () override {
        return new DatabaseLogger();
    }
};

class FileLoggerCreator : public LoggerCreator{
    Logger *CreateLogger () override {
        return new FileLogger();
    }
};

int main(){
    LoggerCreator *createFileLogger = new FileLoggerCreator();
    Logger *fileLogger = createFileLogger->CreateLogger();
    string msg = "Hello Mayuri";
    fileLogger->logging(msg);

    LoggerCreator* createDatabaseLogger = new DatabaseLoggerCreator();
    Logger *DatabaseLogger = createDatabaseLogger->CreateLogger();
    string msgg = "Hello Mayuri";
    DatabaseLogger->logging(msgg);

    delete fileLogger;
    delete createFileLogger;

    delete DatabaseLogger;
    delete createDatabaseLogger;
    return 0;
}
