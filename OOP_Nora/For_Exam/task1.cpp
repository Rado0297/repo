#include <iostream>
#include <cstring>
#include <assert.h>

using namespace std;

class Movie
{
protected:
    char* name;
    int year;

public:
    Movie()
    {
        name = new char[5];
        assert(name != nullptr);
        strcpy(name, "NULL");

        year = 0;
    }

    Movie(const char* n, const int y)
    {
        name = new char[strlen(n) + 1];
        assert(name != nullptr);
        strcpy(name, n);

        year = y;
    }

    Movie(const Movie& m1)
    {
        name = new char[strlen(m1.name) + 1];
        assert(name != nullptr);
        strcpy(name, m1.name);

        year = m1.year;
    }

    Movie& operator=(const Movie& m1)
    {
        if (this != &m1) {
            name = new char[strlen(m1.name) + 1];
            assert(name != nullptr);
            strcpy(name, m1.name);

            year = m1.year;
        }

        return *this;
    }

    ~Movie()
    {
        delete name;
    }

    //Setters

    //Getters
    const char* getName() const
    {
        return name;
    }

    const int getYear() const
    {
        return year;
    }

    friend ostream& operator<<(ostream& out, const Movie m1);
};

ostream& operator<<(ostream& out, const Movie m1)
{
    out << "Movie: " << m1.name << endl
        << "Year: " << m1.year << endl;

    return out;
}

class Criminal : public Movie
{
protected:
    int countOfVictims;

public:
    Criminal() : Movie()
    {
        countOfVictims = 0;
    }

    Criminal(const char* n, const int y, const int cov) : Movie(n, y)
    {
        countOfVictims = cov;
    }

    Criminal(const Criminal& c1) : Movie(c1)
    {
        countOfVictims = c1.countOfVictims;
    }

    Criminal& operator=(const Criminal& c1)
    {
        if (this != nullptr) {
            Movie::operator=(c1);
            countOfVictims = c1.countOfVictims;
        }

        return *this;
    }

    const int getCOV() const
    {
        return countOfVictims;
    }

    friend ostream& operator<<(ostream& out, const Criminal& c1);
};

ostream& operator<<(ostream& out, const Criminal& c1)
{
    out << "Criminal movie: " << c1.name << endl
        << "Year: " << c1.year << endl
        << "Count of victims: " << c1.countOfVictims << endl;
}

class Animation : public Movie
{
protected:
    char* animName;

public:
    Animation() : Movie()
    {
        animName = new char[5];
        assert(animName != nullptr);
        strcpy(animName, "Null");
    }

    Animation(const char* n, const int y, const char* anim) : Movie(n, y)
    {
        animName = new char[strlen(anim) + 1];
        assert(animName != nullptr);
        strcpy(animName, anim);
    }

    Animation(const Animation& a1) : Movie(a1)
    {
        animName = new char[strlen(a1.animName) + 1];
        assert(animName != nullptr);
        strcpy(animName, a1.animName);
    }

    Animation& operator=(const Animation& a1)
    {
        if (this != &a1) {
            Movie::operator=(a1);
            animName = new char[strlen(a1.animName) + 1];
            assert(animName != nullptr);
            strcpy(animName, a1.animName);
        }

        return *this;
    }

    ~Animation()
    {
        delete animName;
    }

    void setAnimatorName(const char* n)
    {
        delete animName;
        animName = new char[strlen(n) + 1];
        assert(animName != nullptr);
        strcpy(animName, n);
    }

    const char* getAnimatorName() const
    {
        return animName;
    }

    friend ostream& operator<<(ostream& out, const Animation& a1);
};

ostream& operator<<(ostream& out, const Animation& a1)
{
    out << "Animation movie: " << a1.name << endl
        << "Year: " << a1.year << endl
        << "Animator's name: " << a1.animName << endl;

    return out;
}

class AnimCrim : public Criminal, public Animation
{
public:
    AnimCrim() : Criminal(), Animation(){}

    AnimCrim(const char* n, const int y, const int cov, const char* anim) : Criminal(n, y, cov), Animation(n, y, anim){}

    AnimCrim(const AnimCrim& am1) : Criminal(am1), Animation(am1){}

    AnimCrim& operator=(const AnimCrim& am1)
    {
        Criminal::operator=(am1);
        Animation::operator=(am1);
    }

    friend ostream& operator<<(ostream& out, const AnimCrim& ac);
};

ostream& operator<<(ostream& out, const AnimCrim& ac)
{
    out << "AnimCrim name: " << ac.Criminal::getName() << endl
        << "AnimCrim year: " << ac.Criminal::getYear() << endl
        << "Cout of victims: " << ac.Criminal::getCOV() << endl
        << "Main animator: " << ac.Animation::getAnimatorName() << endl;
}

int main() {
    Movie m1;
    Movie m2("John Wick", 2017);

    cout << m1 << endl << m2 << endl;

    Criminal c1("John Cena", 2012, 1);
    Criminal c2;

    cout << c1 << endl << c2 << endl;

    Criminal c3, c4(c1);
    c3 = c1;

    cout << c3 << endl << c4 << endl;

    Animation a1;
    Animation a2("Indepedence day", 2016, "Radoslav");

    cout << a1 << endl << a2 << endl;

    AnimCrim am1;
    AnimCrim am2("Titanic", 2101, 12, "Rado");

    cout << am1 << endl << am2 << endl;

    AnimCrim ac(am2);
    cout << ac << endl;

    AnimCrim amc;

    cout << amc << endl;

    amc = ac;

    cout << amc << endl;

    return 0;
}
