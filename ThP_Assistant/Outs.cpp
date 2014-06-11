#include <iostream>

#include "Outs.h"

using namespace std;

namespace ThP
{
//max 20 outs
//Hand after flop - percent
	float Flop (int outs)
	{
		switch(outs)
		{
		case 1:
			return float(4.27);
			break;
		case 2:
			return float(8.4);
			break;
		case 3:
			return float(12.5);
			break;
		case 4:
			return float(16.39);
			break;
		case 5:
			return float(20.4);
			break;
		case 6:
			return float(24.39);
			break;
		case 7:
			return float(27.77);
			break;
		case 8:
			return float(31.25);
			break;
		case 9:
			return float(34.48);
			break;
		case 10:
			return float(38.46);
			break;
		case 11:
			return float(41.66);
			break;
		case 12:
			return float(45.45);
			break;
		case 13:
			return float(47.61);
			break;
		case 14:
			return float(51.28);
			break;
		case 15:
			return float(54.50);
			break;
		case 16:
			return float(57.14);
			break;
		case 17:
			return float(59.88);
			break;
		case 18:
			return float(62.5);
			break;
		case 19:
			return float(64.93);
			break;
		case 20:
			return float(67.56);
			break;
		default:
			return 0;
		}
	}
//Hand after turn - percent
	float Turn (int outs)
	{
		switch(outs)
		{
		case 1:
			return float(2.19);
			break;
		case 2:
			return float(4.29);
			break;
		case 3:
			return float(6.49);
			break;
		case 4:
			return float(8.69);
			break;
		case 5:
			return float(10.86);
			break;
		case 6:
			return float(12.98);
			break;
		case 7:
			return float(15.15);
			break;
		case 8:
			return float(17.54);
			break;
		case 9:
			return float(19.6);
			break;
		case 10:
			return float(21.73);
			break;
		case 11:
			return float(23.8);
			break;
		case 12:
			return float(26.31);
			break;
		case 13:
			return float(28.57);
			break;
		case 14:
			return float(30.3);
			break;
		case 15:
			return float(32.25);
			break;
		case 16:
			return float(34.48);
			break;
		case 17:
			return float(37.3);
			break;
		case 18:
			return float(38.46);
			break;
		case 19:
			return float(41.66);
			break;
		case 20:
			return float(43.47);
			break;
		default:
			return 0;
		}
	}
}