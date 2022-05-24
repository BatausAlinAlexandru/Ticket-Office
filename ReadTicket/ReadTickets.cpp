#include <iostream>

#include <thread>
#include <chrono>

#include "Repository.h"
#include "Ticket.h"

#include <Windows.h>


void tick() {
	Repository<Ticket> repo("C:/Users/batau/Desktop/AnubisSTORE/Database/Tickets.txt");

	std::vector<Ticket> wallet = repo.getAll();
	int k = 1;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < wallet.size(); i++) {
		SetConsoleTextAttribute(hConsole, k);
		std::cout << wallet[i] << std::endl;
		k++;

		if (k == 15)
			k = 1;
	}
}

int main() {

	system("mode 40, 10");

	while (true) {
		system("cls");
		tick();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}


	system("pause");
}