#include <iostream>
#include <fstream>

#include "Payouts.h"
#include "Outs.h"
#include "Statistics.h"

int main()
{
	/*int player = 50;
	int money = 100;
	std::cout << ThP::Place1(player,money) << std::endl;
	std::cout << ThP::Place2(player,money) << std::endl;
	std::cout << ThP::Place3(player,money) << std::endl;
	std::cout << ThP::Place4(player,money) << std::endl;
	std::cout << ThP::Place5(player,money) << std::endl;
	std::cout << ThP::Place6(player,money) << std::endl;
	std::cout << ThP::Place7(player,money) << std::endl;
	std::cout << ThP::Place8(player,money) << std::endl;
	std::cout << ThP::Place9(player,money) << std::endl;*/

	/*int out = 2;
	std::cout << ThP::Flop(out) << std::endl;
	std::cout << ThP::Turn(out) << std::endl;*/

	//ThP::AddToFile(20,14,6,false);
	//ThP::AddToFile(30,24,16,true);

	struct ThP::ReadValues rd = ThP::ReadFromFile();
	std::cout << rd.deal << std::endl;
	std::cout << rd.part << std::endl;
	std::cout << rd.won << std::endl;
	std::cout << rd.tPart << std::endl;
	std::cout << rd.tWon << std::endl;
	std::cout << ThP::Percent(rd.part, rd.deal) << std::endl;
	return 0;
}

