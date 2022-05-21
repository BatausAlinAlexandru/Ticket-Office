#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include "Menu.h"


// Constructors
Menu::Menu(Service& service, User& user, Wallet& appwallet, Wallet& clientwallet) : service(service), user(user), appwallet(appwallet), clientwallet(clientwallet) {};

Menu::~Menu() = default;

void Menu::printUI() {
    std::cout << std::endl;
    if (this->LOGGED != 1)
        std::cout << "FOR SOME FEATURES YOU NEED TO BE LOGGED !!!" << std::endl;

    std::cout << "**************************************************" << std::endl;
    std::cout << "* admin menu                                     *" << std::endl;
    std::cout << "* ticket menu                                    *" << std::endl;
    std::cout << "* wallet menu                                    *" << std::endl;
    std::cout << "* transaction                                    *" << std::endl;
    std::cout << "* exit                                           *" << std::endl;
    std::cout << "**************************************************" << std::endl;
    std::cout << std::endl;
};

void Menu::printUserMenu() const {
    std::cout << std::endl;
    if (this->LOGGED != 1)
        std::cout << "FOR SOME FEATURES YOU NEED TO BE LOGGED !!!" << std::endl;
    std::cout << "**************************************************" << std::endl;
    std::cout << "*    login                                       *" << std::endl;
    if (this->LOGGED) {
        std::cout << "*    change name {newName}                       *" << std::endl;
        std::cout << "*    change password {newPassword}               *" << std::endl;
        std::cout << "*    change email {newEmail}                     *" << std::endl;
        std::cout << "*    logout                                      *" << std::endl;
    }
    std::cout << "*    back                                        *" << std::endl;
    std::cout << "**************************************************" << std::endl;
    std::cout << std::endl;
};

void Menu::printTicketMessage() {
    std::cout << std::endl;
    if (this->LOGGED != 1)
        std::cout << "FOR SOME FEATURES YOU NEED TO BE LOGGED !!!" << std::endl;
    std::cout << "**************************************************" << std::endl;
    if (this->LOGGED) {
        std::cout << "*    add {day} {sum} {destination}               *" << std::endl;
        std::cout << "*    modify {day} {newSum} {newDestination}      *" << std::endl;
        std::cout << "*    delete {day}                                *" << std::endl;
    }
    std::cout << "*    sort {operator ->  '<' / '>'}               *" << std::endl;
    std::cout << "*    show                                        *" << std::endl;
    std::cout << "*    back                                        *" << std::endl;
    std::cout << "**************************************************" << std::endl;

    std::cout << std::endl;
};

void Menu::printWalletMenu() {
    std::cout << std::endl;

    std::cout << "**************************************************" << std::endl;
    if (this->LOGGED) {
        std::cout << "*    add                                         *" << std::endl;
        std::cout << "*    withdraw                                    *" << std::endl;
    }
    std::cout << "*    show                                        *" << std::endl;
    //std::cout << "*    transaction                                 *" << std::endl;
    std::cout << "*    back                                        *" << std::endl;
    std::cout << "**************************************************" << std::endl;

    std::cout << std::endl;
}

void Menu::runUserUI() {
    std::string CMD_USER;
    std::vector<std::string> splitedCommandUSER;
    while (true) {
        Menu::printUserMenu();
        std::cout << "Write user command:", std::getline(std::cin, CMD_USER);
        splitedCommandUSER = this->splitNormal(CMD_USER);
        if (splitedCommandUSER[0] == "login")
            Menu::userLogin();
        else if (splitedCommandUSER[0] == "change" && splitedCommandUSER[1] == "name")
            Menu::changeUsername(splitedCommandUSER[2]);
        else if (splitedCommandUSER[0] == "change" && splitedCommandUSER[1] == "password")
            Menu::changePassword(splitedCommandUSER[2]);
        else if (splitedCommandUSER[0] == "change" && splitedCommandUSER[1] == "email")
            Menu::changeEmail(splitedCommandUSER[2]);
        else if (splitedCommandUSER[0] == "logout")
            Menu::logout();
        else if (splitedCommandUSER[0] == "back")
            break;
        else
            std::cout << "Wrong command !!!\n";

        splitedCommandUSER.clear();
    }
    std::cin.clear();
    //std::cin.ignore(1000, '\n');
};



void Menu::runTicketUI() {
    std::string CMD_TICKET;
    std::vector<std::string> splitedCommandTICKET;
    while (true) {
        Menu::printTicketMessage();
        std::cout << "Write command:";
        std::getline(std::cin, CMD_TICKET);
        splitedCommandTICKET = Menu::splitStringTicket(CMD_TICKET);

        if (splitedCommandTICKET[0] == "add")
            Menu::addTicket(std::stoi(splitedCommandTICKET[1]), std::stoi(splitedCommandTICKET[2]), splitedCommandTICKET[3]);
        else if (splitedCommandTICKET[0] == "modify")
            Menu::modifyTicket(std::stoi(splitedCommandTICKET[1]), std::stoi(splitedCommandTICKET[2]), splitedCommandTICKET[3]);
        else if (splitedCommandTICKET[0] == "delete")
            Menu::deleteTicket(std::stoi(splitedCommandTICKET[1]));
        else if (splitedCommandTICKET[0] == "show") {
            system("start C:/Users/batau/Desktop/AnubisSTORE/Plugins/ReadTickets.exe");
        }
        else if (splitedCommandTICKET[0] == "sort")
            Menu::sortTicket(splitedCommandTICKET[1]);
        else if (splitedCommandTICKET[0] == "back") {
            break;
        }
        else
            std::cout << "Wrong command !!!!";

        splitedCommandTICKET.clear();

    }
    std::cin.clear();
    //std::cin.ignore(1000, '\n');
};

void Menu::runUI() {
    std::string CMD;
    while (true) {
        Menu::printUI();
        std::cout << "Write command:", std::getline(std::cin, CMD);

        if (CMD == "admin")
            Menu::runUserUI();
        else if (CMD == "ticket")
            Menu::runTicketUI();
        else if (CMD == "wallet")
            Menu::runWalletUI();
        else if (CMD == "transaction") {
            Menu::transaction();
            std::wcin.clear();
            std::wcin.ignore(1000, '\n');
        }
        else if (CMD == "exit")
            break;
        else
            std::cout << "Wrong command !!!" << std::endl;

    }
    std::cin.clear();
    std::cin.ignore(1000, '\n');
};

// Perfect this <3
void Menu::runWalletUI() {
    std::string first;
    while (true) {
        Menu::printWalletMenu();

        std::cout << "Write command:", std::getline(std::cin, first);
        
        if ((first == "add"))
            Menu::addAppWallet();
        else if (first == "show")
            Menu::show_balance_app();
        else if (first == "withdraw") {
            Menu::withdraw();
            
        }
        else if (first == "transaction")
            Menu::transaction();
        else if (first == "back") {
            std::cin.clear();
            break;
        }
        else
            std::cout << "Wrong command!!!";
    }
    std::cin.clear();
    //std::cin.ignore(1000, '\n');
};


// Menu frunctions

std::vector<std::string> Menu::splitStringTicket(const std::string & line) {
    std::vector<std::string> vector; // This is the vector returned


    std::ofstream fout("C:/Users/batau/Desktop/AnubisSTORE/Database/MenuSplitCommand.txt");
    fout << line;
    fout.close();

    std::ifstream fin("C:/Users/batau/Desktop/AnubisSTORE/Database/MenuSplitCommand.txt");
    std::string initialCommand, day, sum, destination;
    fin >> initialCommand >> day >> sum;
    fin.get();
    std::getline(fin, destination);
    fin.close();

    vector.push_back(initialCommand);
    vector.push_back(day);
    vector.push_back(sum);
    vector.push_back(destination);

    return vector;
};

std::vector<std::string> Menu::splitNormal(std::string line) {
    std::vector<std::string> result; // This is the vector returned
    std::stringstream ss(line);
    std::string token;
    while (getline(ss, token, ' '))
    {
        result.push_back(token);
    }
    return result;
};

// Ticket
void Menu::addTicket(int day, int sum, std::string destination) {
    service.addTicket(day, sum, std::move(destination));
};
void Menu::modifyTicket(int day, int newSum, const std::string & newDestination) {
    service.modifyTicket(day, newSum, newDestination);
};
void Menu::deleteTicket(int day) {
    service.deleteTicket(day);
};
void Menu::sortTicket(const std::string & operatorCOMP) {
    service.sortTicketsByDay(operatorCOMP);
}
void Menu::showTickets() {
    service.showTickets();
};

// User
void Menu::userLogin() {
    std::string username, password;
    std::cout << "Username: ";
    std::getline(std::cin, username);
    if (username == user.getName()) {
        std::cout << "Password: ";
        std::getline(std::cin, password);
        if (password == user.getPassword())
            std::cout << "Logged..." << std::endl, this->LOGGED = true;
    }
};
void Menu::changeUsername(std::string newValue) {
    if (this->LOGGED)
        user.setName(newValue), std::cout << user.getName();
};
void Menu::changePassword(std::string & newValue) {
    if (this->LOGGED)
        user.setPassword(newValue), std::cout << user.getPassword();

};
void Menu::changeEmail(std::string & newValue) {
    if (this->LOGGED)
        user.setEmail(newValue);
    else
        std::cout << "You need to login." << std::endl;
};
void Menu::logout() { this->LOGGED = false; };

// Wallet
// OK
void Menu::addAppWallet() {
    int _1, _5, _10, _20, _50, _100, _200, _500;
    std::cout << "1 RON value:"; std::cin >> _1;
    std::cout << "5 RON value:"; std::cin >> _5;
    std::cout << "10 RON value:"; std::cin >> _10;
    std::cout << "20 RON value:"; std::cin >> _20;
    std::cout << "50 RON value:"; std::cin >> _50;
    std::cout << "100 RON value:"; std::cin >> _100;
    std::cout << "200 RON value:"; std::cin >> _200;
    std::cout << "500 RON value:"; std::cin >> _500;

    service.addAppWallet(_1, _5, _10, _20, _50, _100, _200, _500);

};

void Menu::addClientWallet() {
    int _1, _5, _10, _20, _50, _100, _200, _500;
    std::cout << "1 RON value:"; std::cin >> _1;
    std::cout << "5 RON value:"; std::cin >> _5;
    std::cout << "10 RON value:"; std::cin >> _10;
    std::cout << "20 RON value:"; std::cin >> _20;
    std::cout << "50 RON value:"; std::cin >> _50;
    std::cout << "100 RON value:"; std::cin >> _100;
    std::cout << "200 RON value:"; std::cin >> _200;
    std::cout << "500 RON value:"; std::cin >> _500;

    clientwallet.add1RON(_1), clientwallet.add5RON(_5), clientwallet.add10RON(_10);
    clientwallet.add20RON(_20), clientwallet.add50RON(_50), clientwallet.add100RON(_100);
    clientwallet.add200RON(_200), clientwallet.add500RON(_500);
};

void Menu::withdraw() {
    int _1, _5, _10, _20, _50, _100, _200, _500;
    std::cout << "1 RON value:"; std::cin >> _1;
    std::cin.ignore(1000, '\n');
    std::cout << "5 RON value:"; std::cin >> _5;
    std::cin.ignore(1000, '\n');
    std::cout << "10 RON value:"; std::cin >> _10;
    std::cin.ignore(1000, '\n');
    std::cout << "20 RON value:"; std::cin >> _20;
    std::cin.ignore(1000, '\n');
    std::cout << "50 RON value:"; std::cin >> _50;
    std::cin.ignore(1000, '\n');
    std::cout << "100 RON value:"; std::cin >> _100;
    std::cin.ignore(1000, '\n');
    std::cout << "200 RON value:"; std::cin >> _200;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "500 RON value:"; std::cin >> _500;
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    std::cout << "\n\n\n" << _500;

    service.modifyWallet(_1, _5, _10, _20, _50, _100, _200, _500);
};

// OK
void Menu::show_balance_app() {
    system("start C:/Users/batau/Desktop/AnubisSTORE/Plugins/ReadWallet.exe");
    std::cout << "PRESS ENTER: ";
};

// OK
void Menu::transaction() {
    std::vector<Ticket> vec = service.getALL();
    std::string destination;
    int price = 0;
    bool exist = false;
    std::cout << "Destination:"; std::getline(std::cin, destination);

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].getDestination() == destination) {
            price = vec[i].getSum(), exist = true;
        }
    }

    if (exist) {
        std::cout << "For your destination you need to pay " << price << " RON" << std::endl;

        this->addClientWallet();

        service.transaction(clientwallet.get1RON(), clientwallet.get5RON(), clientwallet.get10RON(), clientwallet.get20RON(),
            clientwallet.get50RON(), clientwallet.get100RON(), clientwallet.get200RON(), clientwallet.get500RON(), price);

        // Clean the prices
        clientwallet.clean();
    }
    else {
        std::cout << "Destination does not exist !!!" << std::endl;
    }
};

