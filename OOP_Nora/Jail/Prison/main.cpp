#include "libs.hpp"

#include "person.hpp"
#include "guard.hpp"
#include "prisoner.hpp"
#include "gang.hpp"
#include "jail.hpp"

int main() {
    Prisoner p("Sam", 4);
    Gang g1("gang1");
    p.setGang(&g1);

    Jail jail;
    jail.acceptPrisoner(p);
    jail.iterateDays(400);

    cout << p;

    Prisoner p2 = p;
    cout << p2;

    Prisoner p3("ahgd", 5);
    p3 = p;
    cout << p3;

    Guard guard("James");
    jail.hireGuard(guard);

    jail.prisonBreak(p);

    return 0;
}
