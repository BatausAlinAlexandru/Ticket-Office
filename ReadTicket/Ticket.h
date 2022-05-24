#pragma once

#include <string>
#include <fstream>

class Ticket {
private:
    int day, sum;
    std::string destination;
public:
    Ticket();
    Ticket(int day, int sum, std::string destination);
    ~Ticket();

    int getDay() const;
    int getSum() const;
    std::string getDestination() const;

    void setDay(int value);
    void setSum(int value);
    void setDestination(std::string value);

    // Operatori
    Ticket& operator=(const Ticket& ticket);
    bool operator==(const Ticket& ticket);

    bool operator<(const Ticket& other) const;
    bool operator>(const Ticket& other) const;

    friend std::istream& operator>>(std::istream& is, Ticket& ticket); // Read
    friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket); // Write

};
