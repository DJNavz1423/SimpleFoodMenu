#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <map>
#include <windows.h>
#include "MenuStructure.h"

class Menu {
private:
	void menuDisplay() {
		system("cls");
		std::cout << "HERE IS OUR MENU:\n"
			<< "- - - - - - - - \n"
			<< "MAIN COURSE: \n";

		for (const auto& item : elem.menuItems) {
			std::cout << item.itemNumber << ". " << item.name << ": " << elem.pesoSign << item.price << '\n';

			if (item.itemNumber == elem.menuItems[3].itemNumber)
				std::cout << "\nDESSERTS:\n";
			if (item.itemNumber == elem.menuItems[6].itemNumber)
				std::cout << "\nDRINKS:\n";
		}
		std::cout << "\nEnter your orders, seperate them with space(1-10): ";
	}
	void orderProcess() {
		bool correctOrder = true;
		std::cin.ignore();
		do {
			menuDisplay();
			std::string orders;
			std::string list = "\nYOUR ORDERS:\n\n";
			getline(std::cin, orders);
			std::stringstream ss(orders);
			float totalCost = 0.0f;
			short orderNum;

			std::map<short, int> orderCount;
			while (ss >> orderNum) {
				if (orderNum >= elem.menuItems[0].itemNumber && orderNum <= elem.menuItems.size()) {
					totalCost += (elem.menuItems[orderNum - 1.0f].price);
					correctOrder = true;
					orderCount[orderNum]++;
				}
				else {
					std::cout << "\nINVALID INPUT FOR ORDER NUMBER: " << orderNum << " | PRESS ANY KEY TO ORDER AGAIN!";
					std::cin.get();
					std::cin.clear();
					correctOrder = false;
					break;
				}
			}
			if (correctOrder == true) {
				for (const auto& pair : orderCount) {
					const auto& item = elem.menuItems[pair.first - 1.0f];
					std::ostringstream priceStream;
					priceStream << std::fixed << std::setprecision(2) << item.price;
					std::string fixedPrice = priceStream.str();
					// Check if the order is repeated
					if (pair.second > 1) {
						list += std::to_string(item.itemNumber) + ". " + item.name + ": " + elem.pesoSign + fixedPrice + " " + std::to_string(pair.second) + "x\n";
					}
					else {
						list += std::to_string(item.itemNumber) + ". " + item.name + ": " + elem.pesoSign + fixedPrice + '\n';
					}
				}

				std::cout << list << '\n' << "YOUR TOTAL PAYMENT : " << elem.pesoSign << std::fixed << std::setprecision(2) << totalCost << "\n\n" <<"IS YOUR ORDER CORRECT? (Y/N): ";
				char input;
				std::cin >> input;
				if (input == 'Y' || input == 'y') {
					std::cout << "\nGOING TO PAYMENT SECTION";
					Sleep(1800);
					std::cout << "\nPLEASE WAIT...";
					Sleep(1800);
					Payment(totalCost);
				}
				else {
					correctOrder = false;
					std::cout << "\nWRONG ORDER! RESTARTING!";
					Sleep(1800);
					std::cout << "\nPLEASE WAIT TO ORDER AGAIN!";
					Sleep(1800);
				}
			}
	} while (!correctOrder);
}
	void Payment(float& totalCost) {
	   float money = 0.0f;
		bool sufficient = false;

		do {
			system("cls");
			std::cout <<"PAYMENT SECTION:\n"
				      <<"---------------\n\n"
					  <<"TOTAL PAYMENT : " <<elem.pesoSign << totalCost << "\n\n" << "ENTER YOUR MONEY: ";
			std::cin >> money;

			if (money >= totalCost) {
				money = money - totalCost;
				std::cout << "\nYOUR CHANGE IS: " << elem.pesoSign << std::fixed << std::setprecision(2) << money << "\n\n";
				Sleep(1500);
				std::cout << "THANK YOU FOR ORDERING!!! ";
				Sleep(2000);
				std::cout << "GOOD-BYE!\n";
				Sleep(1700);
				sufficient = true;
			}
			else {
				std::cout << "\a\nINSUFFICIENT MONEY! PLEASE ENTER A HIGHER AMOUNT!";
				std::cin.clear();
					Sleep(2500);
			}
		} while (!sufficient);

	}
public:
	elements elem;
	void intro() {
		std::cout << " \tSIMPLE FOOD MENU SELECTION\n"
			<< "\t****************************\n\n"
			<< "Hello and Welcome!!!... Would you like to order? (Y/N): ";
	}

	void Functionality() {
		orderProcess();
	}
};