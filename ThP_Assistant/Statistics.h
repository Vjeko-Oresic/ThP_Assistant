namespace ThP
{
	struct ReadValues
	{
		int deal;
		int part;
		int won;
		int tPart;
		int tWon;		
	};
	struct ReadValues ReadFromFile();
	void AddToFile(int deal, int part, int won, bool tWon);
	float Percent (int numberA, int numberB);
	void ResetFile();
};