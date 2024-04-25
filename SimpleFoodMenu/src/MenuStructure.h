#pragma once
#include <vector>
#include <string>

struct elements {
	struct menuComps {
		short itemNumber;
		float price;
		std::string name;
	};
	const char* pesoSign = u8"\u20B1";
	std::vector<menuComps> menuItems = {
		{1, 30.00f, "Fried Chicken"},
		{2, 100.00f, "Bulalo"},
		{3, 60.00f, "Palabok"},
		{4, 60.00f, "Sizzling Sisig"},
		{5, 25.00f, "Ice Cream"},
		{6, 100.00f, "Halo-Halo"},
		{7, 40.00f, "Egg Pie"},
		{8, 45.00f, "Coca-Cola"},
		{9, 45.00f, "Sprite"},
		{10, 20.00f, "Mineral Water"}};
};
