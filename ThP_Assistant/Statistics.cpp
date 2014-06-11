#include <iostream>
#include <fstream>

#include "Statistics.h"

using namespace std;

namespace ThP
{	
	struct ReadValues ReadFromFile()
	{
		struct ReadValues value;
		//Read values from Statistics.txt
		char line[10];
		ifstream file;
		file.open("Statistics.txt");
		//Deal hand
		file.getline(line, 10);
		value.deal = atoi(line);
		//Participate hand
		file.getline(line, 10);
		value.part = atoi(line);
		//Won hand
		file.getline(line, 10);
		value.won = atoi(line);
		//Participate tournament
		file.getline(line, 10);
		value.tPart = atoi(line);
		//Won tournament
		file.getline(line, 10);
		value.tWon = atoi(line);
		file.close();
		return value;
	}

	void AddToFile(int deal, int part, int won, bool cWon)
	{
		//Read values from Statistics.txt
		char line[20];
		ifstream iFile;
		iFile.open("Statistics.txt");
		//Read deal hand
		iFile.getline(line, 10);
		int rDeal = atoi(line);
		//Read participate hand
		iFile.getline(line, 10);
		int rPart = atoi(line);
		//Read won hand
		iFile.getline(line, 10);
		int rWon = atoi(line);
		//Read participate tournament
		iFile.getline(line, 10);
		int rTPart = atoi(line);
		//Read won tournament
		iFile.getline(line, 10);
		int rTWon = atoi(line);
		//Add read values and input values
		//Calculate deal hand 
		int wDeal = rDeal + deal;
		//Calculate participate hand
		int wPart = rPart + part;
		//Calculate won hand
		int wWon = rWon + won;
		//Write values to Statistics.txt
		ofstream oFile;
		oFile.open("Statistics.txt");
		//Write deal hand
		oFile << wDeal;
		oFile << "\n";
		//Write participate hand
		oFile << wPart;
		oFile << "\n";
		//Write won hand
		oFile << wWon;
		oFile << "\n";
		//Calculate and write participate and won tournament
		if(cWon == true)
		{
			int wTPart = rTPart + 1;
			int wTWon = rTWon + 1;
			oFile << wTPart;
			oFile << "\n";
			oFile << wTWon;
			oFile << "\n";
		}
		else
		{
			int wTPart = rTPart + 1;
			int wTWon = rTWon + 0;
			oFile << wTPart;
			oFile << "\n";
			oFile << wTWon;
			oFile << "\n";
		}
		iFile.close();
		oFile.close();
	}

	float Percent (int numberA, int numberB)
	{
		float percent = float(numberA) / float(numberB) * 100;
		return percent;
	}

	void ResetFile()
	{
		//Set values on 0 and input values in file
		//Set deal hand on 0
		int wDeal = 0;
		//Set participate hand on 0
		int wPart = 0;
		//Set won hand on 0
		int wWon = 0;
		//Set participate tournament on 0
		int wTPart = 0;
		//Set won tournament on 0
		int wTWon = 0;
		//Write values to Statistics.txt
		ofstream oFile;
		oFile.open("Statistics.txt");
		//Write deal hand
		oFile << wDeal;
		oFile << "\n";
		//Write participate hand
		oFile << wPart;
		oFile << "\n";
		//Write won hand
		oFile << wWon;
		oFile << "\n";
		//Write participate tournament
		oFile << wTPart;
		oFile << "\n";
		//Write won tournament
		oFile << wTWon;
		oFile << "\n";
		oFile.close();
	}
}
