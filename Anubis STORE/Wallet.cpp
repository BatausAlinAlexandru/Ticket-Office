#include "Wallet.h"

Wallet::Wallet() = default;

Wallet::~Wallet() = default;

void Wallet::add1RON(int value) { this->vec[0] += value; };
void Wallet::add5RON(int value) { this->vec[1] += value; };
void Wallet::add10RON(int value) { this->vec[2] += value; };
void Wallet::add20RON(int value) { this->vec[3] += value; };
void Wallet::add50RON(int value) { this->vec[4] += value; };
void Wallet::add100RON(int value) { this->vec[5] += value; };
void Wallet::add200RON(int value) { this->vec[6] += value; };
void Wallet::add500RON(int value) { this->vec[7] += value; };

void Wallet::delete1RON(int value) { if (vec[0] - value > 0) this->vec[0] -= value; };
void Wallet::delete5RON(int value) { if (vec[1] - value > 0) this->vec[1] -= value; };
void Wallet::delete10RON(int value) { if (vec[2] - value > 0) this->vec[2] -= value; };
void Wallet::delete20RON(int value) { if (vec[3] - value > 0) this->vec[3] -= value; };
void Wallet::delete50RON(int value) { if (vec[4] - value > 0) this->vec[4] -= value; };
void Wallet::delete100RON(int value) { if (vec[5] - value > 0) this->vec[5] -= value; };
void Wallet::delete200RON(int value) { if (vec[6] - value > 0) this->vec[6] -= value; };
void Wallet::delete500RON(int value) { if (vec[7] - value > 0) this->vec[7] -= value; };


int Wallet::get1RON() { return this->vec[0]; };
int Wallet::get5RON() { return this->vec[1]; };
int Wallet::get10RON() { return this->vec[2]; };
int Wallet::get20RON() { return this->vec[3]; };
int Wallet::get50RON() { return this->vec[4]; };
int Wallet::get100RON() { return this->vec[5]; };
int Wallet::get200RON() { return this->vec[6]; };
int Wallet::get500RON() { return this->vec[7]; }

std::istream& operator>>(std::istream & is, Wallet & wallet) {
    int _1, _5, _10, _20, _50, _100, _200, _500;
    is >> _1 >> _5 >> _10 >> _20 >> _50 >> _100 >> _200 >> _500;
    wallet.add1RON(_1), wallet.add5RON(_5);
    wallet.add10RON(_10), wallet.add20RON(_20);
    wallet.add50RON(_50), wallet.add100RON(_100);
    wallet.add200RON(_200), wallet.add500RON(_500);
    return is;
}

std::ostream& operator<<(std::ostream & os, const Wallet & wallet) {
    os << wallet.vec[0] << " " << wallet.vec[1] << " " << wallet.vec[2] << " ";
    os << wallet.vec[3] << " " << wallet.vec[4] << " " << wallet.vec[5] << " ";
    os << wallet.vec[6] << " " << wallet.vec[7];
    return os;
};

bool Wallet::operator==(const Wallet & wallet) {
    return ((this->vec[0] == wallet.vec[0]) && (this->vec[1] == wallet.vec[1]) &&
        (this->vec[2] == wallet.vec[2]) && (this->vec[3] == wallet.vec[3]) &&
        (this->vec[4] == wallet.vec[4]) && (this->vec[5] == wallet.vec[5]) &&
        (this->vec[6] == wallet.vec[6]) && (this->vec[7] == wallet.vec[7]));
};

void Wallet::clean() {
    this->vec[0] = 0;
    this->vec[1] = 0;
    this->vec[2] = 0;
    this->vec[3] = 0;
    this->vec[4] = 0;
    this->vec[5] = 0;
    this->vec[6] = 0;
    this->vec[7] = 0;
};