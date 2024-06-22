#include <iostream>
#include "contestent.h"
void contestent::print()
{
	const int MAXPARTYSIZE = 10;
	const int MAXITEMPOUCH = 20;
	cout << "\n" << endl;
	cout << "Contestent " << name << "'s Summary:" << endl;//outputs Summary of Useful data for battle
	cout << "Contestent name: " << name << endl;
	cout << "Number of Codemon owned: " << Codemoncount << endl;
	cout << "Pocket list: " << endl;
	for (int i = 0; i < MAXPARTYSIZE; i++)
	{
		if (Codemonparty[i] != "")
		{
			cout << i + 1 << ") " << Codemonparty[i] << endl;
		}

	}
	cout << "Backpack list:" << endl;
	for (int i = 0; i < MAXITEMPOUCH; i++)
	{
		if (backpack[i] != "")
		{
			cout << i + 1 << ") " << backpack[i] << endl;
		}
	}
	cout << "\n" << endl;
}