#include "Service.h"

#include <utility>

Service::Service() : repo(repo), appWalletRepo(appWalletRepo) {};

Service::Service(Repository<Ticket>& repo) : repo(repo), appWalletRepo(appWalletRepo) { };

Service::Service(Repository<Ticket>& repo, Repository<Wallet>& appWalletRepo) : repo(repo), appWalletRepo(appWalletRepo) { };

Service::~Service() = default;


void Service::addTicket(int day, int sum, std::string destination) {
    Ticket ticket(day, sum, std::move(destination));
    repo.addElem(ticket);
};

void Service::modifyTicket(int day, int newSum, const std::string & newDestination) {
    Ticket newTicket(day, newSum, newDestination);
    std::vector<Ticket> vec = repo.getAll();
    for (auto& i : vec)
        if (i.getDay() == day) {
            repo.updateElem(i, newTicket);
            break;
        }
};

void Service::deleteTicket(int day) {
    std::vector<Ticket> vec = repo.getAll();
    for (auto& i : vec)
        if (i.getDay() == day)
            repo.deleteElem(i);
};

void Service::showTickets() {
    std::vector<Ticket> vec = repo.getAll();
    for (auto& i : vec)
        std::cout << i << '\n';
};

void Service::sortTicketsByDay(const std::string& operatorCOMP) {
    std::vector<Ticket> vec = repo.getAll();
    Ticket aux;
    if (operatorCOMP == "<") {
        for (int i = 0; i < vec.size() - 1; i++)
            for (int j = i + 1; j < vec.size(); j++)
                if (vec[i].getDay() > vec[j].getDay())
                    aux = vec[i], vec[i] = vec[j], vec[j] = aux;

        for (auto& i : vec)
            std::cout << i << '\n';

    }
    else if (operatorCOMP == ">") {
        for (int i = 0; i < vec.size() - 1; i++)
            for (int j = i + 1; j < vec.size(); j++)
                if (vec[i].getDay() < vec[j].getDay())
                    aux = vec[i], vec[i] = vec[j], vec[j] = aux;

        for (auto& i : vec)
            std::cout << i << '\n';
    }

};

std::vector<Ticket> Service::getALL() {
    return this->repo.getAll();
};

void Service::addAppWallet(int _1, int _5, int _10, int _20, int _50, int _100, int _200, int _500) {
    std::vector<Wallet> wallet = appWalletRepo.getAll();
    int lenght = wallet.size() - 1;

    wallet[lenght].add1RON(_1), wallet[lenght].add5RON(_5), wallet[lenght].add10RON(_10), wallet[lenght].add20RON(_20);
    wallet[lenght].add50RON(_50), wallet[lenght].add100RON(_100), wallet[lenght].add200RON(_200), wallet[lenght].add500RON(_500);
    appWalletRepo.addWalletApp(wallet[lenght]);
};

void Service::modifyWallet(int _1, int _5, int _10, int _20, int _50, int _100, int _200, int _500) {
    std::vector<Wallet> wallet = appWalletRepo.getAll();
    int lenght = wallet.size() - 1;

    if (wallet[lenght].get1RON() - _1 > 0)
        wallet[lenght].delete1RON(_1);
    else
        std::cout << "I can't withdraw " << _1 << " RON." << std::endl;
    if (wallet[lenght].get5RON() - _5 > 0)
        wallet[lenght].delete5RON(_5);
    else
        std::cout << "I can't withdraw " << _5 << " RON." << std::endl;
    if (wallet[lenght].get10RON() - _10 > 0)
        wallet[lenght].delete10RON(_10);
    else
        std::cout << "I can't withdraw " << _10 << " RON." << std::endl;
    if (wallet[lenght].get20RON() - _20 > 0)
        wallet[lenght].delete20RON(_20);
    else
        std::cout << "I can't withdraw " << _20 << " RON." << std::endl;
    if (wallet[lenght].get50RON() - _50 > 0)
        wallet[lenght].delete50RON(_50);
    else
        std::cout << "I can't withdraw " << _50 << " RON." << std::endl;
    if (wallet[lenght].get100RON() - _100 > 0)
        wallet[lenght].delete100RON(_1);
    else
        std::cout << "I can't withdraw " << _100 << " RON." << std::endl;
    if (wallet[lenght].get200RON() - _200 > 0)
        wallet[lenght].delete200RON(_200);
    else
        std::cout << "I can't withdraw " << _200 << " RON." << std::endl;
    if (wallet[lenght].get500RON() - _500 > 0)
        wallet[lenght].delete500RON(_500);
    else
        std::cout << "I can't withdraw " << _500 << " RON." << std::endl;

    appWalletRepo.addWalletApp(wallet[lenght]);
};

int Service::returnSumByIndex(int index) {
    if (index == 0)
        return 1;
    else if (index == 1)
        return 5;
    else if (index == 2)
        return 10;
    else if (index == 3)
        return 20;
    else if (index == 4)
        return 50;
    else if (index == 5)
        return 100;
    else if (index == 6)
        return 200;
    else if (index == 7)
        return 500;
};

int Service::getDestinationPrice(const std::string& destionation) {
    std::vector<Ticket> vec = this->repo.getAll();
    std::string destination;
    int price = 0;

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].getDestination() == destination) {
            price = vec[i].getSum();
            break;
        }
    }
    return price;
};

int Service::return_price(std::vector<int> vec) {
    int price = 0;

    for (int i = 0; i < vec.size(); i++) {
        price += (vec[i] * this->returnSumByIndex(i));
    }
    return price;
};

void Service::transaction(int _1, int _5, int _10, int _20, int _50, int _100, int _200, int _500, int pricee) {
    std::vector<Wallet> wallet = appWalletRepo.getAll();
    int lenght = wallet.size() - 1;

    std::vector<int> app_wallet = { wallet[lenght].get1RON(),wallet[lenght].get5RON(), wallet[lenght].get10RON(),
                            wallet[lenght].get20RON(), wallet[lenght].get50RON(), wallet[lenght].get100RON(),
                            wallet[lenght].get200RON(), wallet[lenght].get500RON() };
    std::vector<int> client_wallet = { _1, _5, _10, _20, _50, _100, _200, _500 };
    std::vector<int> used_bills = { 0, 0, 0, 0, 0, 0, 0, 0 };

    if ((return_price(client_wallet) - pricee) < 0)
        std::cout << "Need more money !!!  " << (return_price(client_wallet) - pricee) << std::endl;
    else {
        int rest = return_price(client_wallet) - pricee;

        for (int i = 7; i >= 0; i--) {
            for (int j = 0; j < app_wallet[i]; j++) {
                if (rest - this->returnSumByIndex(i) >= 0) {
                    rest -= this->returnSumByIndex(i);
                    used_bills[i]++;
                }
            }
        }

        std::cout << "\nUsed bills: ";
        for (int i = 0; i < used_bills.size(); i++)
            std::cout << used_bills[i] << ' ';

        // Update money array
        for (int i = 0; i < app_wallet.size(); i++)
            app_wallet[i] -= used_bills[i];

        wallet[lenght].delete1RON(used_bills[0]);
        wallet[lenght].delete5RON(used_bills[1]);
        wallet[lenght].delete10RON(used_bills[2]);
        wallet[lenght].delete20RON(used_bills[3]);
        wallet[lenght].delete50RON(used_bills[4]);
        wallet[lenght].delete100RON(used_bills[5]);
        wallet[lenght].delete200RON(used_bills[6]);
        wallet[lenght].delete500RON(used_bills[7]);

        appWalletRepo.addWalletApp(wallet[lenght]);

        if (rest == 0)
            std::cout << "Succesfully !!!" << rest << std::endl;
        else
            std::cout << "Failed !!!!" << rest << std::endl;
    }
};

std::vector<Wallet> Service::getAppWallet() {
    return this->appWalletRepo.getAll();
};