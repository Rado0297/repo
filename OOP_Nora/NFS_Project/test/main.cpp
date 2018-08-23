#include <iostream>
#include <cstring>
#include <assert.h>

using namespace std;

class Employee
{
    virtual bool execute() const = 0;
    virtual double successRate() const = 0;
};

class Worker : public Employee
{
protected:
    char* name;
    char** tasks;
    int allTasks;
    int doneTasks;

    void copy(const Worker& w1)
    {
        name = new char[strlen(w1.name) + 1];
        assert(name != nullptr);
        strcpy(name, w1.name);

        allTasks = w1.allTasks;
        doneTasks = w1.doneTasks;

        tasks = new char*[allTasks];
        assert(tasks != nullptr);
        for (size_t i = 0; i < allTasks; i++) {
            tasks[i] = new char[strlen(w1.tasks[i]) + 1];
            assert(tasks[i] != nullptr);
            strcpy(tasks[i], w1.tasks[i]);
        }
    }

    void erase()
    {
        delete name;
        for (size_t i = 0; i < allTasks; i++) {
            delete tasks[i];
        }

        delete[] tasks;
    }

public:
    Worker()
    {
        name = new char[strlen("Worker") + 1];
        assert(name != nullptr);
        strcpy(name, "Worker");
        allTasks = 0;
        doneTasks = 0;

        tasks = new char*[3];
        assert(tasks != nullptr);
        for (size_t i = 0; i < 3; i++) {
            tasks[i] = new char[3];
            assert(tasks[i] != nullptr);
        }

        strcpy(tasks[0], "12");
        strcpy(tasks[1], "12");
        strcpy(tasks[2], "12");
    }

    Worker(const char* _name, char** _tasks, int _allTasks)
    {
        name = new char[strlen(_name) + 1];
        assert(name != nullptr);
        strcpy(name, _name);

        allTasks = _allTasks;
        doneTasks = allTasks - 1;

        tasks = new char*[allTasks];
        assert(tasks != nullptr);
        for (size_t i = 0; i < allTasks; i++) {
            tasks[i] = new char[strlen(_tasks[i]) + 1];
            assert(tasks[i] != nullptr);
            strcpy(tasks[i], _tasks[i]);
        }
    }

    Worker(const Worker& w1)
    {
        copy(w1);
    }

    Worker& operator=(const Worker& w1)
    {
        if (this != &w1) {
            erase();
            copy(w1);
        }

        return *this;
    }

    ~Worker()
    {
        erase();
    }

    const char* getName() const
    {
        return name;
    }

    void getTask(const char* newTask)
    {
        //
    }

    double successRate() const
    {
        return (doneTasks / allTasks);
    }

    bool execute() const
    {
        for (size_t i = 0; i < allTasks; i++) {
            if (i == doneTasks) {
                return false;
            }

            return true;
        }
    }

    const void printWorker() const
    {
        cout << "Name: " << name << endl
            << "All tasks:" << allTasks << endl
            << "Done tasks: " << doneTasks << endl
            << "Success rate: " << successRate() << endl;

        for (size_t i = 0; i < allTasks; i++) {
            cout << "Task name: " << tasks[i] << endl
                << "Task status: " << execute() << endl;
        }
    }
};

class Expert : public Worker
{
public:
    Expert() : Worker(){}
    Expert(const char* _name, char** _tasks, int _allTasks) : Worker(_name, _tasks, _allTasks){}
    Expert(const Expert& e1) : Worker(e1){}
    Expert& operator=(const Expert& e1)
    {
        Worker::operator=(e1);
    }
    ~Expert(){}

    double successRate() const
    {
        return (doneTasks / allTasks);
    }

    bool execute() const
    {
        for (size_t i = 0; i < allTasks; i++) {
            return true;
        }
    }

    const void printExpert() const
    {
        printWorker();
    }
};

template <typename T>
class Manager
{
private:
    T* employees;
    int employeesCount;
    char* name;
    char** tasks;
    int allTasks;

    void erase()
    {
        delete name;

        delete[] employees;

        for (size_t i = 0; i < allTasks; i++) {
            delete tasks[i];
        }

        delete[] tasks;
    }

public:
    Manager()
    {
        name = new char[strlen("Manager") + 1];
        assert(name != nullptr);
        strcpy(name, "Manager");
        allTasks = 0;

        tasks = new char*[3];
        assert(tasks != nullptr);
        for (size_t i = 0; i < 3; i++) {
            tasks[i] = new char[3];
            assert(tasks[i] != nullptr);
        }

        strcpy(tasks[0], "13");
        strcpy(tasks[1], "13");
        strcpy(tasks[2], "13");
    }

    Manager(const char* _name, T* _empl, int count, char** _tasks, int _allTasks)
    {
        name = new char[strlen(_name) + 1];
        assert(name != nullptr);
        strcpy(name, _name);
        employeesCount = count;

        employees = new T[employeesCount];
        assert(employees != nullptr);

        for (size_t i = 0; i < employeesCount; i++) {
            employees[i] = _empl[i];
        }

        for (size_t i = 0; i < allTasks; i++) {
            tasks[i] = new char[strlen(_tasks[i]) + 1];
            assert(tasks[i] != nullptr);
            strcpy(tasks[i], _tasks[i]);
        }
    }

    Manager(const Manager& m1)
    {
        /* code */
    }

    Manager& operator=(const Manager& m1)
    {
        if (this != &m1) {
            /* code */
        }

        return *this;
    }

    ~Manager()
    {
        erase();
    }

    void addEmployee(const char* _name, char** _tasks, int _allTasks)
    {
        T newEmp(_name, tasks, _allTasks);
        T* tempList = new T[employeesCount];
        assert(tempList != nullptr);

        for (size_t i = 0; i < employeesCount; i++) {
            tempList[i] = employees[i];
        }

        delete employees;
        employeesCount++;
        employees = new T[employeesCount];
        assert(employees != nullptr);

        for (size_t i = 0; i < employeesCount; i++) {
            if (i == employeesCount - 2) {
                employees[i] = tempList[i];
            }
            else if (i == employeesCount - 1)
            {
                employees[i] = newEmp;
            }
        }
    }

    void removeEmployee(char* employeeName)
    {
        T* temp = new T[employeesCount - 1];
        assert(temp != nullptr);

        int j = 0;
        for (size_t i = 0; i < employeesCount; i++) {
            if (strcmp(employeeName, employees[i].getName()) != 0) {
                temp[j] = employees[i];
                j++;
            }
        }

        delete temp;
    }
};

int main() {
    char** test;
    test = new char*[3];
    assert(test != nullptr);
    for (size_t i = 0; i < 3; i++) {
        test[i] = new char[3];
        assert(test[i] != nullptr);
    }

    strcpy(test[0], "12");
    strcpy(test[1], "12");
    strcpy(test[2], "12");

    for (size_t i = 0; i < 3; i++) {
        cout << test[i] << endl;
    }

    Expert w1("Ti", test, 3);
    w1.printWorker();

    Expert w2;
    w2 = w1;
    w2.printWorker();

    Expert w3(w2);
    w3.printExpert();


    for (size_t i = 0; i < 3; i++) {
        delete test[i];
    }

    delete[] test;

    return 0;
}
