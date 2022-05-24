// Here we will read app-wallet.txt
#include <iostream>
#include <vector>
#include <Windows.h>

#include <thread>
#include <chrono>

#include "Repository.h"
#include "Wallet.h"

void tick() {

	Repository<Wallet> repo("C:/Users/batau/Desktop/AnubisSTORE/Database/app-wallet.txt");
	
	std::vector<Wallet> wallet = repo.getAll();
	int k = 1;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, k);
	std::cout << "1 RON VALUE: " << wallet[0].get1RON() << std::endl;
	k++;

	SetConsoleTextAttribute(hConsole, k);
	std::cout << "5 RON VALUE: " << wallet[0].get5RON() << std::endl;
	k++;

	SetConsoleTextAttribute(hConsole, k);
	std::cout << "10 RON VALUE: " << wallet[0].get10RON() << std::endl;
	k++;

	SetConsoleTextAttribute(hConsole, k);
	std::cout << "20 RON VALUE: " << wallet[0].get20RON() << std::endl;
	k++;

	SetConsoleTextAttribute(hConsole, k);
	std::cout << "50 RON VALUE: " << wallet[0].get50RON() << std::endl;
	k++;

	SetConsoleTextAttribute(hConsole, k);
	std::cout << "100 RON VALUE: " << wallet[0].get100RON() << std::endl;
	k++;

	SetConsoleTextAttribute(hConsole, k);
	std::cout << "200 RON VALUE: " << wallet[0].get200RON() << std::endl;
	k++;

	SetConsoleTextAttribute(hConsole, k);
	std::cout << "500 RON VALUE: " << wallet[0].get500RON() << std::endl;
	k++;

	SetConsoleTextAttribute(hConsole, 0);

}




int main() {
	// For small window console
	system("mode 40, 10");

	while (true) {
		system("cls");
		tick();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}


	system("pause");

}