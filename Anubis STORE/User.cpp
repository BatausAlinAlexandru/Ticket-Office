#include "User.h"

User::User() = default;

User::User(const std::string & name, const std::string & password, const std::string & email) {
    this->name = name, this->password = password, this->email = email;
};

User::~User() = default;

std::string User::getName() { return this->name; };
std::string User::getPassword() { return this->password; };
std::string User::getEmail() { return this->email; };

void User::setName(std::string& value) { this->name = value; };
void User::setPassword(std::string & value) { this->password = value; };
void User::setEmail(std::string & value) { this->email = value; }

bool User::operator==(const User& user)
{
    return ((this->name == user.name) && (this->password == user.password) && (this->email == user.email));
};

std::istream& operator>>(std::istream& is, User& user) {
    is >> user.name >> user.password >> user.email;
    return is;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << user.name << user.password << user.email;
    return os;
};