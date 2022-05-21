#pragma once

#include <string>
#include <fstream>

class User {
private:
    std::string name, password, email;
public:
    User();
    User(const std::string& name, const std::string& password, const std::string& email);
    ~User();

    std::string getName(), getPassword(), getEmail();

    void setName(std::string& value), setPassword(std::string& value);
    void setEmail(std::string& value);

    bool operator==(const User& user);


    friend std::istream& operator>>(std::istream& is, User& user); // Read
    friend std::ostream& operator<<(std::ostream& os, const User& user); // Write
};