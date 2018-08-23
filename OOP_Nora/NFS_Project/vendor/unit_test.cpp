//Racer Tests
void test1()
{
    std::cout << "Test for Defualt constructor\n";
    Racer r1;

    if (r1.getXP() == 0 && !strcmp(r1.getName(), "Defualt")) {
        r1.print();
    }
    else
    {
        cout << "Error!!!\n";
    }
}

void test2()
{
    std::cout << "Test for Constructor\n";
    Racer r1("human", 300, 350, 10);
    r1.print();
}

void test3()
{
    std::cout << "Test Copy Constructor\n";
    Racer r1("human", 100, 200, 1);
    Racer r2 = r1;

    r1.print();
    r2.print();
}

void test4()
{
    std::cout << "Test for operator=\n";
    Racer r1, r2;
    r1.setRacerType("human");

    r2 = r1;
    r2.print();
}

void test5()
{
    std::cout << "Test setRacerType()\n";
    Racer r1;
    r1.print();

    //Make validations or use heierarchy??
    //r1.setRacerType("humana");
    r1.setRacerType("human");

    r1.print();
}

void test6()
{
    std::cout << "Test for setXP()\n";
    Racer r1("human", 100, 200, 1);
    Racer r2;

    r1.print();
    r1.setXP(342);
    r1.print();

    r2.print();
    r2.setXP(567);
    r2.print();
}

void test7()
{
    std::cout << "Test for setMoney()\n";
    Racer r1("human", 100, 200, 1);
    Racer r2;

    r1.print();
    r1.setMoney(342);
    r1.print();
}
