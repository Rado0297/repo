#include "libs.hpp"
#include "ticket.hpp"

class Feeling
{
protected:
    char name[100];
    int percent;

public:
    Feeling()
    {
        strcpy(name, "Default");
        percent = 0;
    }

    Feeling(const char* _name, const int _percent)
    {
        strcpy(name, _name);
        percent = _percent;
    }

    Feeling(const Feeling& f1)
    {
        strcpy(name, f1.name);
        percent = f1.percent;
    }

    Feeling& operator=(const Feeling& f1)
    {
        if (this != nullptr) {
            strcpy(name, f1.name);
            percent = f1.percent;
        }

        return *this;
    }

    const void print() const
    {
        cout << "Feeling's name: " << name << endl
            << "Percents: " << percent << endl;
    }
};

class Love : public Feeling
{
public:
    Love() : Feeling() {}
    Love(const int _percent) : Feeling("love", _percent) {}
    Love(const Love& l1) : Feeling(l1) {}
    Love& operator=(const Love& l1)
    {
        Feeling::operator=(l1);
    }

    const void printEmoji() const
    {
        cout << "<3\n";
    }
};

class Sadness : public Feeling
{
public:
    Sadness() : Feeling() {}
    Sadness(const int _percent) : Feeling("sadness", _percent) {}
    Sadness(const Sadness& s1) : Feeling(s1) {}
    Sadness& operator=(const Sadness& s1)
    {
        Feeling::operator=(s1);
    }

    const void printEmoji() const
    {
        cout << ":(\n";
    }
};

class Proud : public Feeling
{
public:
    Proud() : Feeling() {}
    Proud(const int _percent) : Feeling("proud", _percent) {}
    Proud(const Proud& p1) : Feeling(p1) {}
    Proud& operator=(const Proud& p1)
    {
        Feeling::operator=(p1);
    }

    const void printEmoji() const
    {
        cout << "(flag)\n";
    }
};

template <typename T>
class Spectator
{
private:
    Ticket<T>* t1;

public:
    Spectator();
    Spectator(const Ticket<T>& tt)
    {
        t1 = tt;
    }
};

class LivePerformance
{
private:
    char performer[100];
};

int main() {



    return 0;
}
