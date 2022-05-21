#pragma once

#include "Repository.h"
#include "Ticket.h"
#include "Wallet.h"



class Service {
private:
    // Ticket
    Repository<Ticket>& repo;

    // Wallet
    Repository<Wallet>& appWalletRepo;
public:
    Service();
    Service(Repository<Ticket>& repo);
    explicit Service(Repository<Ticket>& repo, Repository<Wallet>& appWalletRepo);
    ~Service();

    // Will  be functions here
    void addTicket(int day, int sum, std::string destination);
    void modifyTicket(int day, int newSum, const std::string& newDestination);
    void deleteTicket(int day); // Delete all ticket from that day
    void showTickets();

    std::vector<Ticket> getALL();

    void sortTicketsByDay(const std::string& operatorCOMP);


    // Wallet service
    void addAppWallet(int _1, int _5, int _10, int _20, int _50, int _100, int _200, int _500);
    void modifyWallet(int _1, int _5, int _10, int _20, int _50, int _100, int _200, int _500);


    int returnSumByIndex(int index);
    int getDestinationPrice(const std::string& destionation);
    int return_price(std::vector<int> vec);

    void transaction(int _1, int _5, int _10, int _20, int _50, int _100, int _200, int _500, int pricee);
    std::vector<Wallet> getAppWallet();

};
