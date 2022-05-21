#include "Ticket.h"
#include <iostream>
#include <utility>

Ticket::Ticket() {
    this->day = -1;
    this->sum = 0;
    this->destination = "";
};

Ticket::Ticket(int day, int sum, std::string destination) {
    this->day = day, this->sum = sum, this->destination = std::move(destination);
};

Ticket::~Ticket() = default;


int Ticket::getDay() const {
    return this->day;
};

int Ticket::getSum() const {
    return this->sum;
};

std::string Ticket::getDestination() const {
    return this->destination;
};

void Ticket::setDay(int value) {
    this->day = value;
};

void Ticket::setSum(int value) {
    this->sum = value;
};

void Ticket::setDestination(std::string value) {
    this->destination = std::move(value);
};


Ticket& Ticket::operator=(const Ticket & ticket) {
    if (this != &ticket)
        this->setDay(ticket.day), this->setSum(ticket.sum), this->setDestination(ticket.destination);

    return *this;
};

bool Ticket::operator==(const Ticket & ticket) {
    return((this->day == ticket.day) && (this->sum == ticket.sum) && (this->destination == ticket.destination));
};

std::istream& operator>>(std::istream & is, Ticket & ticket) {
    is >> ticket.day >> ticket.sum >> ticket.destination;
    return is;
};

std::ostream& operator<<(std::ostream & os, const Ticket & ticket) {
    os << ticket.day << " " << ticket.sum << " " << ticket.destination;
    return os;
}

bool Ticket::operator<(const Ticket & other) const {
    if ((this->day < other.day))
        return true;
    else
        return false;
};

bool Ticket::operator>(const Ticket & other) const {
    if ((this->day > other.day))
        return true;
    else
        return false;
}
