#pragma once

#include <fstream>
#include <vector>

class Wallet {
private:
    std::vector<int> vec = { 0, 0, 0, 0, 0, 0, 0, 0 };
public:
    Wallet();
    ~Wallet();

    void add1RON(int value), add5RON(int value), add10RON(int value);
    void add20RON(int value), add50RON(int value), add100RON(int value);
    void add200RON(int value), add500RON(int value);

    void delete1RON(int value), delete5RON(int value), delete10RON(int value);
    void delete20RON(int value), delete50RON(int value), delete100RON(int value);
    void delete200RON(int value), delete500RON(int value);

    void clean();

    int get1RON(), get5RON(), get10RON(), get20RON(), get50RON();
    int get100RON(), get200RON(), get500RON();

    bool operator==(const Wallet& wallet);

    friend std::istream& operator>>(std::istream& is, Wallet& wallet); // Read
    friend std::ostream& operator<<(std::ostream& os, const Wallet& wallet); // Write
};