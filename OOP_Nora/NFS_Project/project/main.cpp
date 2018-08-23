#include "libs.hpp"

#include "car.hpp"
#include "racer.hpp"
#include "shop.hpp"
#include "race.hpp"

int main() {
    //Car** classA(); //the most powerful
    //Car classB(); //less powerful
    //Car classC(); //slow ugly bitches

    //NormalCar c(1000, 13, 10);
    // c.printCar();

    // Car c1(c);
    // c1.printCar();

    // Car c3;
    // c3 = c;
    // c3.printCar();



    // nc.printCar();
    // nc1.printCar();
    // nc3.printCar();

    //Racer rb;
    //rb.printRacer();

    // if (CON <= 0 && CONiC <= 0) {
    //     cout << "Error: You have entered invalid values for count of Normal and Nitro car! Racer must have at least one car!\n";
    // }
    //
    // else
    // {
    //
    // }


    // HumanRacer r(3, 4, 3, 3, list, list2);
    // r.earnXP(10);
    // //r.printRacer();
    //
    // r.buyNormalCar(c);
    // r.buyNitroCar(nt);
    //
    // HumanRacer r1(r);
    // //r1 = r;
    // NormalCar* list3;
    // list3 = new NormalCar[3];
    // for (size_t i = 0; i < 3; i++) {
    //     list3[i] = r1.getNormalCar(i);
    // }
    //
    // for (size_t i = 0; i < 3; i++) {
    //     list3[i].upgradeCar();
    // }
    //
    // r1.setNormalCarList(list3, 3);

    //r1.printHumanRacer();
    //Racer r1(1, 1, 3, 3);
    // r1.printRacer();

    // std::cout << "------------------ Unit Tests ------------------\n";
    // test1();
    // std::cout << "------------------------------------------------\n";
    // test2();
    // std::cout << "------------------------------------------------\n";
    // test3();
    // std::cout << "------------------------------------------------\n";
    // test4();
    // std::cout << "------------------------------------------------\n";
    // test5();
    // std::cout << "------------------------------------------------\n";
    // test6();
    // std::cout << "------------------------------------------------\n";
    // test7();
    // std::cout << "--------------------- End ----------------------\n";

    NormalCar nc("Lamborghini", 122, 2, 4);
    // NormalCar nc1("Ferrari", 452, 7, 5);
    // NormalCar nc3("Ford Mustang", 300, 7, 7);
    // //
    // NormalCar list[3];
    // list[0] = nc;
    // list[1] = nc1;
    // list[2] = nc3;
    //
    // NitroCar list2[3], nt("Volkswagen", 167, 3, 3);
    // list2[0] = nt;
    // list2[1] = nt;
    // list2[2] = nt;

    // Showroom<NormalCar> ncars(list, 3);
    // Showroom<NitroCar> nitcars(list2, 3);
    //
    // Showroom<NitroCar> shop1(list2, 3);
    // shop1.printShowroom();
    // shop1.sellCar(2);
    // shop1.printShowroom();

    //HumanRacer h;
    // Car c;
    // NormalCar nc;
    // NitroCar nt;
    // Racer r;
    // ComputerRacer pc;
    // HumanRacer hm;
    // Showroom<NormalCar> ss;
    // Showroom<NitroCar> ss1;
    // Race race;

    // ComputerRacer pc1[3];
    // ComputerRacer p("COMPUTER", 100, 10, 3, 3, list, list2);
    // HumanRacer hs[3];
    // HumanRacer h("Rado", 100, 10, 3, 3, list, list2);
    // hs[0] = h;
    // pc1[0] = p;
    // Race race1(pc1, hs, 3, 3);
    //race1.compete(hs[0]);

    // For rounds
    // bool playing = 1;
    // while (playing) {
    //     cout << "1. Race with someone\n"
    //         << "2. Buy car\n"
    //         << "3. Exit\n";
    //
    //     int choise;
    //     cin >> choise;
    //
    //     switch (choise) {
    //         case 1: race1.compete(hs[0]); break;
    //         case 2:
    //             ncars.printShowroom();
    //             nitcars.printShowroom();
    //             cout << "Your choise will be number of the line of the car\n";
    //             int cho;
    //             cin >> cho;
    //             //to be continue..
    //             break;
    //         case 3: playing = 0; break;
    //         default: cout << "Error: Invalid comand!\n"; break;
    //     }
    // }

    return 0;
}
