#pragma once

#include "Service.h"
#include "User.h"
#include "Wallet.h"

class Menu {
private:
    Service service;
    User user;
    Wallet& appwallet;
    Wallet& clientwallet;
    bool LOGGED = false;
public:

    Menu(Service& service, User& user, Wallet& appwallet, Wallet& clientwallet);
    ~Menu();

    void runUI();

private:
    void printUI();


    static std::vector<std::string> splitStringTicket(const std::string& line);
    std::vector<std::string> splitNormal(std::string line);

    void runTicketUI();
    void printTicketMessage();
    void addTicket(int day, int sum, std::string destination);
    void modifyTicket(int day, int newSum, const std::string& newDestination);
    void deleteTicket(int day);
    void sortTicket(const std::string& operatorCOMP);
    void showTickets();

    // USER
    void printUserMenu() const;
    void runUserUI();
    void userLogin();
    void changeUsername(std::string newValue);
    void changePassword(std::string& newValue);
    void changeEmail(std::string& newValue);
    void logout();

    // Shopping
    void runWalletUI();
    void printWalletMenu();

    void addAppWallet();
    void addClientWallet();

    void withdraw();
    void show_balance_app();
    //void show_balance_client();
    void transaction();

    void clean_client_bills();

};