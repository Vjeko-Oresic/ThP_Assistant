#include <iostream>

#include "Payouts.h"

using namespace std;

namespace ThP
{
	//max 100 players
	//1st place prize
	int Place1 (int player_number, int money){
		int total = player_number * money;
		if(player_number > 0 && player_number <= 9 )
			return 0.6 * total;
		else if(player_number >= 10 && player_number <= 16 )
			return 0.55 * total;
		else if(player_number >= 17 && player_number <= 23 )
			return 0.45 * total;
		else if(player_number >= 24 && player_number <= 30 )
			return 0.45 * total;
		else if(player_number >= 31 && player_number <= 37 )
			return 0.4 * total;
		else if(player_number >= 38 && player_number <= 44 )
			return 0.35 * total;
		else if(player_number >= 45 && player_number <= 50 )
			return 0.35 * total;
		else if(player_number >= 51 && player_number <= 100 )
			return 0.35 * total;
		else
			return 0;
	}
	//2nd place prize
	int Place2 (int player_number, int money){
		int total = player_number * money;
		if(player_number > 0 && player_number <= 9 )
			return 0.4 * total;
		else if(player_number >= 10 && player_number <= 16 )
			return 0.3 * total;
		else if(player_number >= 17 && player_number <= 23 )
			return 0.3 * total;
		else if(player_number >= 24 && player_number <= 30 )
			return 0.25 * total;
		else if(player_number >= 31 && player_number <= 37 )
			return 0.25 * total;
		else if(player_number >= 38 && player_number <= 44 )
			return 0.23 * total;
		else if(player_number >= 45 && player_number <= 50 )
			return 0.2 * total;
		else if(player_number >= 51 && player_number <= 100 )
			return 0.2 * total;
		else
			return 0;
	}
	//3rd place prize
	int Place3 (int player_number, int money){
		int total = player_number * money;
		if(player_number >= 10 && player_number <= 16 )
			return 0.2 * total;
		else if(player_number >= 17 && player_number <= 23 )
			return 0.15 * total;
		else if(player_number >= 24 && player_number <= 30 )
			return 0.15 * total;
		else if(player_number >= 31 && player_number <= 37 )
			return 0.13 * total;
		else if(player_number >= 38 && player_number <= 44 )
			return 0.12 * total;
		else if(player_number >= 45 && player_number <= 50 )
			return 0.12 * total;
		else if(player_number >= 51 && player_number <= 100 )
			return 0.12 * total;
		else
			return 0;
	}
	//4th place prize
	int Place4 (int player_number, int money){
		int total = player_number * money;
		if(player_number >= 17 && player_number <= 23 )
			return 0.1 * total;
		else if(player_number >= 24 && player_number <= 30 )
			return 0.1 * total;
		else if(player_number >= 31 && player_number <= 37 )
			return 0.1 * total;
		else if(player_number >= 38 && player_number <= 44 )
			return 0.1 * total;
		else if(player_number >= 45 && player_number <= 50 )
			return 0.1 * total;
		else if(player_number >= 51 && player_number <= 100 )
			return 0.08 * total;
		else
			return 0;
	}
	//5th place prize
	int Place5 (int player_number, int money){
		int total = player_number * money;
		if(player_number >= 24 && player_number <= 30 )
			return 0.05 * total;
		else if(player_number >= 31 && player_number <= 37 )
			return 0.07 * total;
		else if(player_number >= 38 && player_number <= 44 )
			return 0.08 * total;
		else if(player_number >= 45 && player_number <= 50 )
			return 0.08 * total;
		else if(player_number >= 51 && player_number <= 100 )
			return 0.07 * total;
		else
			return 0;
	}
	//6th place prize
	int Place6 (int player_number, int money){
		int total = player_number * money;
		if(player_number >= 31 && player_number <= 37 )
			return 0.05 * total;
		else if(player_number >= 38 && player_number <= 44 )
			return 0.07 * total;
		else if(player_number >= 45 && player_number <= 50 )
			return 0.06 * total;
		else if(player_number >= 51 && player_number <= 100 )
			return 0.06 * total;
		else
			return 0;
	}
	//7th place prize
	int Place7 (int player_number, int money){
		int total = player_number * money;
		if(player_number >= 38 && player_number <= 44 )
			return 0.05 * total;
		else if(player_number >= 45 && player_number <= 50 )
			return 0.05 * total;
		else if(player_number >= 51 && player_number <= 100 )
			return 0.05 * total;
		else
			return 0;
	}
	//8th place prize
	int Place8 (int player_number, int money){
		int total = player_number * money;
		if(player_number >= 45 && player_number <= 50 )
			return 0.04  * total;
		else if(player_number >= 51 && player_number <= 100 )
			return 0.04  * total;
		else
			return 0;
	}
	//9th place prize
	int Place9 (int player_number, int money){
		int total = player_number * money;
		if(player_number >= 51 && player_number <= 100 )
			return 0.03 * total;
		else
			return 0;
	}
}

