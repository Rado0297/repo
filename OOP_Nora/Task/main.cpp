#include <iostream>

using namespace std;

class Task
{
public:
    virtual bool isDone() const = 0;
    virtual void progress() = 0;
    virtual double progressInfo() = 0;
    virtual void restartTask() = 0;
    virtual void print() = 0;
};

class SimpleTask : public Task
{
private:
    char* sName;
    int countOfSteps;
    bool status;

public:
    //Big 4

    //virtual functions
    virtual bool isDone() const
    {
        return status;
    }

    virtual void progress()
    {}

    virtual double progressInfo() = 0;
    virtual void restartTask() = 0;
    virtual void print() = 0;
};

class RepeateTask
{
private:
    SimpleTask sTask;
    int repeate;

public:

};

int main() {



    return 0;
}
