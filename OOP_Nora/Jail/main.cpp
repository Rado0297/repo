#include "libs.hpp"

#include "person.hpp"
#include "guard.hpp"
#include "prisoner.hpp"
#include "gang.hpp"
#include "jail.hpp"

int main() {
    Prisoner p("Jack Rapist", 12.3, "Avengers");
    cout << p;

    cin >> p;
    cout << p;

    Prisoner p1("J. R. Townkin", 12.3, "Lord of the FMI");
    cout << p1;

    p += p1;

    cout << "------------- Result --------------\n";
    cout << p;
    cout << p1;






    // Guard g;
    // cin >> g;
    // cout << g;

    //
    //
    // Gang gangs[5];
    //
    // for (size_t i = 0; i < 5; i++) {
    //     cin >> gangs[i];
    // }
    //
    // for (size_t i = 0; i < 5; i++) {
    //     cout << gangs[i];
    // }
    //
    //
    //
    // Prisoner p2("Freddy Cruger", 123.3);
    // cout << p2;
    //
    // Prisoner p3("John Snow", 13.2);
    // cout << p3;
    // p3 += p2;
    // cout << p3;
    //
    // Jail j1;
    // j1.hireGuard(g);
    // j1.acceptPrisoner(p2);
    // j1.acceptPrisoner(p3);
    // j1.joinGang(p2.getName(), p3.getName());
    // j1.print();


    // Gang gg("Dis");
    // cout << gg;
    //
    // cin >> gg;
    //
    // cout << gg;

    return 0;
}
