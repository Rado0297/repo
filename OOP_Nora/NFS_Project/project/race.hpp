#include "libs.hpp"

#ifndef RACE_HPP
#define RACE_HPP

class Race
{
private:
    int hracers;
    int pcracers;
    ComputerRacer* pcs;
    HumanRacer* humans;

public:
    Race()
    {
        hracers = 1;
        pcracers = 1;

        pcs = new ComputerRacer[pcracers];
        assert(pcs != nullptr);
        ComputerRacer pc;
        pcs[0] = pc;

        humans = new HumanRacer[hracers];
        assert(humans != nullptr);
        HumanRacer p1;
        humans[0] = p1;
    }

    Race(ComputerRacer* list1, HumanRacer* list2, int _pcracers, int _hracers)
    {
        pcracers = _pcracers;
        hracers = _hracers;

        pcs = new ComputerRacer[pcracers];
        assert(pcs != nullptr);
        for (size_t i = 0; i < pcracers; i++) {
            pcs[i] = list1[i];
        }

        humans = new HumanRacer[hracers];
        assert(humans != nullptr);
        for (size_t i = 0; i < hracers; i++) {
            humans[i] = list2[i];
        }
    }

    ~Race()
    {
        delete[] pcs;
        delete[] humans;
    }

    void compete(HumanRacer& player)
    {
        //num is variable vor number of player that we choose to race with
        srand(time(NULL));
        // int randPC = rand() % pcracers;
        // int randHuman = rand() % hracers;
        //
        //
        double x = 0,
                y = 0,
                z = 0,
                res = 0,
                coef1 = 0,
                coef2 = 0;

        cout << "Enter 1 to lists all computer racers and choose an opponent\n"
            << "Enter 2 to list all human racers and choose an opponent\n";

        int oppType, pcNum, pcCarT, humCarT, humNum, carNum;
        cin >> oppType;

        //Human vs PC
        if (oppType == 1) {
            cout << "List of computer racers:\n";
            for (size_t i = 0; i < pcracers; i++) {
                cout << i + 1 << "." << pcs[i].getName()
                    << ", exp: " << pcs[i].getXP()
                    << ", count of races: " << pcs[i].getCountOfRaces() << endl << endl;
            }

            cin >> pcNum; //current num of opp

            cout << "Select type of your car.\n"
                << "Enter 1 for normal car\n"
                << "Enter 2 for nitro car\n";

            cin >> humCarT;

            if (humCarT == 1) {
                for (size_t i = 0; i < player.getCountOfNormalCars(); i++) {
                    cout << i + 1 << ". " << player.getNormalCar(i).getBrand()
                        << ", HP: " << player.getNormalCar(i).getHP() << endl;
                }

                cin >> carNum; //current num of

                x = player.getXP();
                y = player.getNormalCar(carNum - 1).getHP();
                z = rand() % 20;
                res = ((x + y) * (100.0 + z)) / 100.0;

                player.setCoef(res);
                coef1 = player.getCoef();

                pcCarT = rand() % 2 + 1;

                //rand() % (pcs[pcNum - 1].getCountOfNormalCars() - 1)

                if (pcCarT == 1) {
                    x = pcs[pcNum - 1].getXP();
                    int index = pcs[pcNum - 1].getCountOfNormalCars() - 1;
                    y = pcs[pcNum - 1].getNormalCar(rand() % index).getHP();
                    z = rand() % 20;
                    res = ((x + y) * (100.0 + z)) / 100.0;

                    pcs[pcNum - 1].setCoef(res);
                    coef2 = pcs[pcNum - 1].getCoef();
                }
                else if (pcCarT == 2) {
                    x = pcs[pcNum - 1].getXP();
                    int index = pcs[pcNum - 1].getCountOfNitroCars() - 1;
                    y = pcs[pcNum - 1].getNitroCar(rand() % index).getHP();
                    z = rand() % 20;
                    res = ((x + y) * (100.0 + z)) / 100.0;

                    pcs[pcNum - 1].setCoef(res);
                    coef2 = pcs[pcNum - 1].getCoef();
                }

                if (coef1 > coef2) {
                    cout << player.getName() << ", you wins!\n";
                }
                else if (coef1 < coef2) {
                    cout << pcs[pcNum - 1].getName() << " wins!\n";
                }
                else {
                    cout << "Players finished at the same time!\n";
                }
            }

            else if (humCarT == 2) {
                for (size_t i = 0; i < player.getCountOfNitroCars(); i++) {
                    cout << i + 1 << ". " << player.getNitroCar(i).getBrand()
                        << ", HP: " << player.getNitroCar(i).getHP() << endl;
                }

                cin >> carNum; //current num of

                x = player.getXP();
                y = player.getNitroCar(carNum - 1).getHP();
                z = rand() % 20;
                res = ((x + y) * (100.0 + z)) / 100.0;

                player.setCoef(res);
                coef1 = player.getCoef();

                pcCarT = rand() % 2 + 1;

                //rand() % (pcs[pcNum - 1].getCountOfNormalCars() - 1)

                if (pcCarT == 1) {
                     x = pcs[pcNum - 1].getXP();
                     int index = pcs[pcNum - 1].getCountOfNormalCars() - 1;
                     y = pcs[pcNum - 1].getNormalCar(rand() % index).getHP();
                     z = rand() % 20;
                     res = ((x + y) * (100.0 + z)) / 100.0;

                     pcs[pcNum - 1].setCoef(res);
                     coef2 = pcs[pcNum - 1].getCoef();
                }
                else if (pcCarT == 2) {
                    x = pcs[pcNum - 1].getXP();
                    int index = pcs[pcNum - 1].getCountOfNitroCars() - 1;
                    y = pcs[pcNum - 1].getNitroCar(rand() % index).getHP();
                    z = rand() % 20;
                    res = ((x + y) * (100.0 + z)) / 100.0;

                    pcs[pcNum - 1].setCoef(res);
                    coef2 = pcs[pcNum - 1].getCoef();
                }

                if (coef1 > coef2) {
                    cout << player.getName() << ", you wins!\n";
                }
                else if (coef1 < coef2) {
                    cout << pcs[pcNum - 1].getName() << " wins!\n";
                }
                else {
                    cout << "Players finished at the same time!\n";
                }
            }
        }


















        //Human vs Human
        else if (oppType == 2) {
            cout << "List of human racers:\n";
            for (size_t i = 0; i < hracers; i++) {
                cout << i + 1 << "." << humans[i].getName()
                    << ", exp: " << humans[i].getXP()
                    << ", count of races: " << humans[i].getCountOfRaces() << endl << endl;
            }

            cin >> humNum; //current num of opp

            cout << "Select type of your car.\n"
                << "Enter 1 for normal car\n"
                << "Enter 2 for nitro car\n";


            cin >> humCarT;

            if (humCarT == 1) {
                for (size_t i = 0; i < player.getCountOfNormalCars(); i++) {
                    cout << i + 1 << ". " << player.getNormalCar(i).getBrand()
                        << ", HP: " << player.getNormalCar(i).getHP() << endl;
                }

                cin >> carNum; //current num of

                x = player.getXP();
                y = player.getNormalCar(carNum - 1).getHP();
                z = rand() % 20;
                res = ((x + y) * (100.0 + z)) / 100.0;

                player.setCoef(res);
                coef1 = player.getCoef();

                cout << "Opponent must select a car\n"
                    << "Enter 1 for normal car\n"
                    << "Enter 2 for nitro car\n";

                int oppCarT;
                cin >> oppCarT;

                if (oppCarT == 1) {
                    cout << "Select car (for opponent)\n";
                    int ind = humNum - 1;
                    for (size_t i = 0; i < humans[ind].getCountOfNormalCars(); i++) {
                        cout << i + 1 << ". " << humans[ind].getNormalCar(i).getBrand()
                            << ", HP: " << humans[ind].getNormalCar(i).getHP() << endl;
                    }

                    // int carNumOp;
                    // cin >> carNumOp;

                    // double res1, x1, y1, z1;
                    // x1 = humans[ind].getXP();
                    // int jj = carNumOp - 1;
                    // y1 = humans[ind].getNormalCar(jj).getHP();
                    // z1 = rand() % 20;
                    // res1 = ((x + y) * (100.0 + z)) / 100.0;
                    //
                    // humans[ind].setCoef(res);
                    // coef2 = humans[ind].getCoef();
                }

                // else if (oppCarT == 2) {
                //     cout << "Select car (for opponent)\n";
                //     for (size_t i = 0; i < humans[humNum - 1].getCountOfNitroCars(); i++) {
                //         cout << i + 1 << ". " << humans[humNum - 1].getNitroCar(i).getBrand()
                //             << ", HP: " << humans[humNum - 1].getNitroCar(i).getHP() << endl;
                //     }
                //
                //     cin >> carNum;
                //
                //     x = humans[humNum - 1].getXP();
                //     y = humans[humNum - 1].getNitroCar(carNum - 1).getHP();
                //     z = rand() % 20;
                //     res = ((x + y) * (100.0 + z)) / 100.0;
                //
                //     humans[humNum - 1].setCoef(res);
                //     coef2 = humans[humNum - 1].getCoef();
                // }
                //
                // if (coef1 > coef2) {
                //     cout << player.getName() << ", you wins!\n";
                // }
                // else if (coef1 < coef2) {
                //     cout << humans[humNum - 1].getName() << " wins!\n";
                // }
                // else {
                //     cout << "Players finished at the same time!\n";
                // }
            }
            else if (humCarT == 2) {
                cout << "Here !!!\n";

                for (size_t i = 0; i < player.getCountOfNormalCars(); i++) {
                    cout << i + 1 << ". " << player.getNormalCar(i).getBrand()
                        << ", HP: " << player.getNormalCar(i).getHP() << endl;
                }


                cout << "List of human racers:\n";
                for (size_t i = 0; i < pcracers; i++) {
                    cout << i + 1 << "." << humans[i].getName()
                        << ", exp: " << humans[i].getXP()
                        << ", count of races: " << humans[i].getCountOfRaces() << endl << endl;
                }

                int oppNum;
                cin >> oppNum;

                cout << "Oppenent must choose:\n"
                    << "Enter 1 for normal car\n"
                    << "Enter 2 for nitro car\n";

                int oppCarT;
                cin >> oppCarT;

                if (oppCarT == 1) {
                    int inds = humNum - 1;
                    for (size_t i = 0; i < humans[inds].getCountOfNormalCars(); i++) {
                        cout << i + 1 << ". " << player.getNormalCar(i).getBrand()
                            << ", HP: " << player.getNormalCar(i).getHP() << endl;
                    }

                    cin >> carNum; //current num of

                    double x = player.getXP();
                    double y = player.getNormalCar(carNum - 1).getHP();
                    double z = rand() % 20;
                    double res = ((x + y) * (100.0 + z)) / 100.0;

                    player.setCoef(res);
                    coef1 = player.getCoef();

                }

                else if (oppCarT == 2) {

                }

                if (coef1 > coef2) {
                    cout << player.getName() << ", you wins!\n";
                }
                else if (coef1 < coef2) {
                    cout << humans[humNum - 1].getName() << " wins!\n";
                }
                else {
                    cout << "Players finished at the same time!\n";
                }
            }
        }






















        else {
            cout << "Error: Invalid opponent's type!\n";
        }

        // if (num <= pcracers && num > 0) {
        //     cout << "Race with computer playe " << pcs[num - 1].getName() << endl;
        //
        // }
        // else if (num > pcracers && num <= j) {
        //     /* code */
        // }
        // else {
        //     cout << "Error: Invalid entered racer's number!\n";
        // }
    }

    // void compete(HumanRacer& player)
    // {
    //     double coef1 = 0, coef2 = 0;
    //
    //     cout << "Enter 1 to lists all computer racers and choose an opponent\n"
    //         << "Enter 2 to list all human racers and choose an opponent\n";
    //
    //     int oppType;
    //     cin >> oppType;
    //
    //     //Human vs PC
    //     if (oppType == 1) {
    //         cout << "List of computer racers:\n";
    //         for (size_t i = 0; i < pcracers; i++) {
    //             cout << i + 1 << "." << pcs[i].getName()
    //                 << ", exp: " << pcs[i].getXP()
    //                 << ", count of races: " << pcs[i].getCountOfRaces() << endl << endl;
    //         }
    //
    //         int curruntOpponent;
    //         cin >> curruntOpponent;
    //         cout << "You choose " << curruntOpponent << " " << pcs[curruntOpponent - 1].getName() << endl;
    //
    //         cout << "Select type of your car:\n"
    //             << "Enter 1 for normal car\n"
    //             << "Enter 2 for nitro car\n";
    //
    //         int carType;
    //         cin >> carType;
    //
    //         if (carType == 1) {
    //             for (size_t i = 0; i < player.getCountOfNormalCars(); i++) {
    //                 cout << i + 1 << ". " << player.getNormalCar(i).getBrand()
    //                     << ", HP: " << player.getNormalCar(i).getHP() << endl;
    //             }
    //
    //             int carNum;
    //             cin >> carNum;
    //
    //             double x = player.getXP();
    //             double y = player.getNormalCar(carNum - 1).getHP();
    //             double z = rand() % 20;
    //             double res = ((x + y) * (100.0 + z)) / 100.0;
    //             player.setCoef(res);
    //             coef1 = player.getCoef();
    //
    //             int pcCarT = rand() % 2 + 1;
    //             //rand() % (pcs[pcNum - 1].getCountOfNormalCars() - 1)
    //
    //             if (pcCarT == 1) {
    //                  x = pcs[curruntOpponent - 1].getXP();
    //                  int index = pcs[curruntOpponent - 1].getCountOfNormalCars() - 1;
    //                  y = pcs[curruntOpponent - 1].getNormalCar(rand() % index).getHP();
    //                  z = rand() % 20;
    //                  res = ((x + y) * (100.0 + z)) / 100.0;
    //
    //                  pcs[curruntOpponent - 1].setCoef(res);
    //                  coef2 = pcs[curruntOpponent - 1].getCoef();
    //             }
    //             else if (pcCarT == 2) {
    //                 x = pcs[curruntOpponent - 1].getXP();
    //                 int index = pcs[curruntOpponent - 1].getCountOfNitroCars() - 1;
    //                 y = pcs[curruntOpponent - 1].getNitroCar(rand() % index).getHP();
    //                 z = rand() % 20;
    //                 res = ((x + y) * (100.0 + z)) / 100.0;
    //
    //                 pcs[curruntOpponent - 1].setCoef(res);
    //                 coef2 = pcs[curruntOpponent - 1].getCoef();
    //             }
    //         }
    //
    //         else if (carType == 2) {
    //             for (size_t i = 0; i < player.getCountOfNitroCars(); i++) {
    //                 cout << i + 1 << ". " << player.getNitroCar(i).getBrand()
    //                     << ", HP: " << player.getNitroCar(i).getHP() << endl;
    //             }
    //
    //             int carNum;
    //             cin >> carNum;
    //
    //             double x = player.getXP();
    //             double y = player.getNitroCar(carNum - 1).getHP();
    //             double z = rand() % 20;
    //             double res = ((x + y) * (100.0 + z)) / 100.0;
    //             player.setCoef(res);
    //             coef1 = player.getCoef();
    //
    //             int pcCarT = rand() % 2 + 1;
    //             //rand() % (pcs[pcNum - 1].getCountOfNormalCars() - 1)
    //
    //             if (pcCarT == 1) {
    //                  x = pcs[curruntOpponent - 1].getXP();
    //                  int index = pcs[curruntOpponent - 1].getCountOfNormalCars() - 1;
    //                  y = pcs[curruntOpponent - 1].getNormalCar(rand() % index).getHP();
    //                  z = rand() % 20;
    //                  res = ((x + y) * (100.0 + z)) / 100.0;
    //
    //                  pcs[curruntOpponent - 1].setCoef(res);
    //                  coef2 = pcs[curruntOpponent - 1].getCoef();
    //             }
    //             else if (pcCarT == 2) {
    //                 x = pcs[curruntOpponent - 1].getXP();
    //                 int index = pcs[curruntOpponent - 1].getCountOfNitroCars() - 1;
    //                 y = pcs[curruntOpponent - 1].getNitroCar(rand() % index).getHP();
    //                 z = rand() % 20;
    //                 res = ((x + y) * (100.0 + z)) / 100.0;
    //
    //                 pcs[curruntOpponent - 1].setCoef(res);
    //                 coef2 = pcs[curruntOpponent - 1].getCoef();
    //             }
    //         }
    //
    //         else {
    //             cout << "Error choise of car\n";
    //         }
    //     }
    //
    //     //Human vs Human
    //     else if (oppType == 2) {
    //
    //     }
    //
    //     else {
    //         cout << "Error: Invalid opponent's type!\n";
    //     }
    // }

    // void compete(HumanRacer& player)
    // {
    //     //num is variable vor number of player that we choose to race with
    //     srand(time(NULL));
    //     // int randPC = rand() % pcracers;
    //     // int randHuman = rand() % hracers;
    //     //
    //     //
    //     double x = 0,
    //             y = 0,
    //             z = 0,
    //             res = 0,
    //             coef1 = 0,
    //             coef2 = 0;
    //
    //     cout << "Enter 1 to lists all computer racers and choose an opponent\n"
    //         << "Enter 2 to list all human racers and choose an opponent\n";
    //
    //     int oppType, pcNum, pcCarT, humCarT, humNum, carNum;
    //     cin >> oppType;
    //
    //     //Human vs PC
    //     if (oppType == 1) {
    //         cout << "List of computer racers:\n";
    //         for (size_t i = 0; i < pcracers; i++) {
    //             cout << i + 1 << "." << pcs[i].getName()
    //                 << ", exp: " << pcs[i].getXP()
    //                 << ", count of races: " << pcs[i].getCountOfRaces() << endl << endl;
    //         }
    //
    //         cin >> pcNum; //current num of opp
    //
    //         cout << "Select type of your car.\n"
    //             << "Enter 1 for normal car\n"
    //             << "Enter 2 for nitro car\n";
    //
    //         cin >> humCarT;
    //
    //         if (humCarT == 1) {
    //             for (size_t i = 0; i < player.getCountOfNormalCars(); i++) {
    //                 cout << i + 1 << ". " << player.getNormalCar(i).getBrand()
    //                     << ", HP: " << player.getNormalCar(i).getHP() << endl;
    //             }
    //
    //             cin >> carNum; //current num of
    //
    //             x = player.getXP();
    //             y = player.getNormalCar(carNum - 1).getHP();
    //             z = rand() % 20;
    //             res = ((x + y) * (100.0 + z)) / 100.0;
    //
    //             player.setCoef(res);
    //             coef1 = player.getCoef();
    //
    //             pcCarT = rand() % 2 + 1;
    //
    //             //rand() % (pcs[pcNum - 1].getCountOfNormalCars() - 1)
    //
    //             if (pcCarT == 1) {
    //                  x = pcs[pcNum - 1].getXP();
    //                  int index = pcs[pcNum - 1].getCountOfNormalCars() - 1;
    //                  y = pcs[pcNum - 1].getNormalCar(rand() % index).getHP();
    //                  z = rand() % 20;
    //                  res = ((x + y) * (100.0 + z)) / 100.0;
    //
    //                  pcs[pcNum - 1].setCoef(res);
    //                  coef2 = pcs[pcNum - 1].getCoef();
    //             }
    //             else if (pcCarT == 2) {
    //                 x = pcs[pcNum - 1].getXP();
    //                 int index = pcs[pcNum - 1].getCountOfNitroCars() - 1;
    //                 y = pcs[pcNum - 1].getNitroCar(rand() % index).getHP();
    //                 z = rand() % 20;
    //                 res = ((x + y) * (100.0 + z)) / 100.0;
    //
    //                 pcs[pcNum - 1].setCoef(res);
    //                 coef2 = pcs[pcNum - 1].getCoef();
    //             }
    //
    //             if (coef1 > coef2) {
    //                 cout << player.getName() << ", you wins!\n";
    //             }
    //             else if (coef1 < coef2) {
    //                 cout << pcs[pcNum - 1].getName() << " wins!\n";
    //             }
    //             else {
    //                 cout << "Players finished at the same time!\n";
    //             }
    //         }
    //
    //         else if (humCarT == 2) {
    //             for (size_t i = 0; i < player.getCountOfNitroCars(); i++) {
    //                 cout << i + 1 << ". " << player.getNitroCar(i).getBrand()
    //                     << ", HP: " << player.getNitroCar(i).getHP() << endl;
    //             }
    //
    //             cin >> carNum; //current num of
    //
    //             x = player.getXP();
    //             y = player.getNitroCar(carNum - 1).getHP();
    //             z = rand() % 20;
    //             res = ((x + y) * (100.0 + z)) / 100.0;
    //
    //             player.setCoef(res);
    //             coef1 = player.getCoef();
    //
    //             pcCarT = rand() % 2 + 1;
    //
    //             //rand() % (pcs[pcNum - 1].getCountOfNormalCars() - 1)
    //
    //             if (pcCarT == 1) {
    //                  x = pcs[pcNum - 1].getXP();
    //                  int index = pcs[pcNum - 1].getCountOfNormalCars() - 1;
    //                  y = pcs[pcNum - 1].getNormalCar(rand() % index).getHP();
    //                  z = rand() % 20;
    //                  res = ((x + y) * (100.0 + z)) / 100.0;
    //
    //                  pcs[pcNum - 1].setCoef(res);
    //                  coef2 = pcs[pcNum - 1].getCoef();
    //             }
    //             else if (pcCarT == 2) {
    //                 x = pcs[pcNum - 1].getXP();
    //                 int index = pcs[pcNum - 1].getCountOfNitroCars() - 1;
    //                 y = pcs[pcNum - 1].getNitroCar(rand() % index).getHP();
    //                 z = rand() % 20;
    //                 res = ((x + y) * (100.0 + z)) / 100.0;
    //
    //                 pcs[pcNum - 1].setCoef(res);
    //                 coef2 = pcs[pcNum - 1].getCoef();
    //             }
    //
    //             if (coef1 > coef2) {
    //                 cout << player.getName() << ", you wins!\n";
    //             }
    //             else if (coef1 < coef2) {
    //                 cout << pcs[pcNum - 1].getName() << " wins!\n";
    //             }
    //             else {
    //                 cout << "Players finished at the same time!\n";
    //             }
    //         }
    //     }
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //     //Human vs Human
    //     else if (oppType == 2) {
    //         cout << "List of human racers:\n";
    //         for (size_t i = 0; i < hracers; i++) {
    //             cout << i + 1 << "." << humans[i].getName()
    //                 << ", exp: " << humans[i].getXP()
    //                 << ", count of races: " << humans[i].getCountOfRaces() << endl << endl;
    //         }
    //
    //         cin >> humNum; //current num of opp
    //
    //         cout << "Select type of your car.\n"
    //             << "Enter 1 for normal car\n"
    //             << "Enter 2 for nitro car\n";
    //
    //
    //         cin >> humCarT;
    //
    //         if (humCarT == 1) {
    //             for (size_t i = 0; i < player.getCountOfNormalCars(); i++) {
    //                 cout << i + 1 << ". " << player.getNormalCar(i).getBrand()
    //                     << ", HP: " << player.getNormalCar(i).getHP() << endl;
    //             }
    //
    //             cin >> carNum; //current num of
    //
    //             x = player.getXP();
    //             y = player.getNormalCar(carNum - 1).getHP();
    //             z = rand() % 20;
    //             res = ((x + y) * (100.0 + z)) / 100.0;
    //
    //             player.setCoef(res);
    //             coef1 = player.getCoef();
    //
    //             cout << "Opponent must select a car\n"
    //                 << "Enter 1 for normal car\n"
    //                 << "Enter 2 for nitro car\n";
    //
    //             int oppCarT;
    //             cin >> oppCarT;
    //
    //             if (oppCarT == 1) {
    //                 cout << "Select car (for opponent)\n";
    //                 int ind = humNum - 1;
    //                 for (size_t i = 0; i < humans[ind].getCountOfNormalCars(); i++) {
    //                     cout << i + 1 << ". " << humans[ind].getNormalCar(i).getBrand()
    //                         << ", HP: " << humans[ind].getNormalCar(i).getHP() << endl;
    //                 }
    //
    //                 // int carNumOp;
    //                 // cin >> carNumOp;
    //
    //                 // double res1, x1, y1, z1;
    //                 // x1 = humans[ind].getXP();
    //                 // int jj = carNumOp - 1;
    //                 // y1 = humans[ind].getNormalCar(jj).getHP();
    //                 // z1 = rand() % 20;
    //                 // res1 = ((x + y) * (100.0 + z)) / 100.0;
    //                 //
    //                 // humans[ind].setCoef(res);
    //                 // coef2 = humans[ind].getCoef();
    //             }
    //
    //             // else if (oppCarT == 2) {
    //             //     cout << "Select car (for opponent)\n";
    //             //     for (size_t i = 0; i < humans[humNum - 1].getCountOfNitroCars(); i++) {
    //             //         cout << i + 1 << ". " << humans[humNum - 1].getNitroCar(i).getBrand()
    //             //             << ", HP: " << humans[humNum - 1].getNitroCar(i).getHP() << endl;
    //             //     }
    //             //
    //             //     cin >> carNum;
    //             //
    //             //     x = humans[humNum - 1].getXP();
    //             //     y = humans[humNum - 1].getNitroCar(carNum - 1).getHP();
    //             //     z = rand() % 20;
    //             //     res = ((x + y) * (100.0 + z)) / 100.0;
    //             //
    //             //     humans[humNum - 1].setCoef(res);
    //             //     coef2 = humans[humNum - 1].getCoef();
    //             // }
    //             //
    //             // if (coef1 > coef2) {
    //             //     cout << player.getName() << ", you wins!\n";
    //             // }
    //             // else if (coef1 < coef2) {
    //             //     cout << humans[humNum - 1].getName() << " wins!\n";
    //             // }
    //             // else {
    //             //     cout << "Players finished at the same time!\n";
    //             // }
    //         }
    //         else if (humCarT == 2) {
    //             cout << "Here !!!\n";
    //
    //             for (size_t i = 0; i < player.getCountOfNormalCars(); i++) {
    //                 cout << i + 1 << ". " << player.getNormalCar(i).getBrand()
    //                     << ", HP: " << player.getNormalCar(i).getHP() << endl;
    //             }
    //
    //
    //             cout << "List of human racers:\n";
    //             for (size_t i = 0; i < pcracers; i++) {
    //                 cout << i + 1 << "." << humans[i].getName()
    //                     << ", exp: " << humans[i].getXP()
    //                     << ", count of races: " << humans[i].getCountOfRaces() << endl << endl;
    //             }
    //
    //             int oppNum;
    //             cin >> oppNum;
    //
    //             cout << "Oppenent must choose:\n"
    //                 << "Enter 1 for normal car\n"
    //                 << "Enter 2 for nitro car\n";
    //
    //             int oppCarT;
    //             cin >> oppCarT;
    //
    //             if (oppCarT == 1) {
    //                 int inds = humNum - 1;
    //                 for (size_t i = 0; i < humans[inds].getCountOfNormalCars(); i++) {
    //                     cout << i + 1 << ". " << player.getNormalCar(i).getBrand()
    //                         << ", HP: " << player.getNormalCar(i).getHP() << endl;
    //                 }
    //
    //                 cin >> carNum; //current num of
    //
    //                 double x = player.getXP();
    //                 double y = player.getNormalCar(carNum - 1).getHP();
    //                 double z = rand() % 20;
    //                 double res = ((x + y) * (100.0 + z)) / 100.0;
    //
    //                 player.setCoef(res);
    //                 coef1 = player.getCoef();
    //
    //             }
    //
    //             else if (oppCarT == 2) {
    //
    //             }
    //
    //             if (coef1 > coef2) {
    //                 //cout << player.getName() << ", you wins!\n";
    //             }
    //             else if (coef1 < coef2) {
    //                 //cout << humans[humNum - 1].getName() << " wins!\n";
    //             }
    //             else {
    //                 cout << "Players finished at the same time!\n";
    //             }
    //         }
    //     }
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //     else {
    //         cout << "Error: Invalid opponent's type!\n";
    //     }
    //
    //     // if (num <= pcracers && num > 0) {
    //     //     cout << "Race with computer playe " << pcs[num - 1].getName() << endl;
    //     //
    //     // }
    //     // else if (num > pcracers && num <= j) {
    //     //     /* code */
    //     // }
    //     // else {
    //     //     cout << "Error: Invalid entered racer's number!\n";
    //     // }
    // }
};

#endif
