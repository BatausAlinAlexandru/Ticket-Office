#include <iostream>
#include "Repository.h"
#include "Ticket.h"


#include "Wallet.h"
#include "User.h"

#include "Menu.h"

int main() {

    /*Tests tests;
    Tests::allTests();*/


    Repository<Ticket> repo("C:/Users/batau/Desktop/AnubisSTORE/Database/Tickets.txt");
    Repository<Wallet> appwalletRepo("C:/Users/batau/Desktop/AnubisSTORE/Database/app-wallet.txt");



    Service service(repo, appwalletRepo);


    Wallet appwallet;
    Wallet clientwallet;

    User user("alin", "alin", "bataus.alin@yahoo.com"); // mai bine il las asa in cod decat sa-l pun intr-un txt :)) 

    Menu menu(service, user, appwallet, clientwallet);
    menu.runUI();

}