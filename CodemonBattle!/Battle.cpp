#include "contestent.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
contestent operator*(contestent& userA, contestent& userB)
{

	codemoninfo weather_element; //even though weather is static and is the same for all codemoninfo members, weahther element is declared for name clarfication purposes, its only use is to return weather.
	int weather_effect = weather_element.weather;
	const float None = 1;
	const float Sunny = 2;
	const float Hail = 0.0625;
	const float Snow = 0.5;
	const float Rain = 1;
	bool stateTheClimate = false;// climate will only be stated on first turn
	int currentMonIndex1 = 0;//index of active battling codemon for userA
	int currentMonIndex2 = 0;//index of active battling codemon for userB
	int User1DefeatCount = 0;//counts fainted codemon in userA
	int User2DefeatCount = 0;//counts fainted codemon in userB
	int Move = 0;//move index
	int Rain_effect = 0;//50/50 rain effect
	bool GO = true;
	const int PARTYSIZE = 10;
	const int FAINTED = 0;
	const int SMALLESTSIZE = 0;
	const int RAIN5050POSSIBILITYRANGE = 2;
	const int WEATHER_CLEAR = 0;
	const int WEATHER_SUNNY = 1;
	const int WEATHER_HAIL = 2;
	const int WEATHER_SNOW = 3;
	const int WEATHER_RAIN = 4;
	const int HIT = 1;
	const int MISS = 0;
	for (int i = 0; i < PARTYSIZE; i++)//sees if their is a default winner. aka if a user adds no codemon to thier party the other user wins by default
	{
		if (userA.Pocket[i].getCHP() <= FAINTED)
		{
			User1DefeatCount++;

		}
	}
	if (User1DefeatCount == PARTYSIZE)
	{
		cout << "The winner by default is " << userB.getName() << endl;
		return userB;
	}
	for (int i = 0; i < PARTYSIZE; i++)//sees if their is a default winner. aka if a user adds no codemon to thier party the other user wins by default
	{
		if (userB.Pocket[i].getCHP() <= FAINTED)
		{
			User2DefeatCount++;
		}
	}
	if (User2DefeatCount == PARTYSIZE)
	{
		cout << "The winner by default is " << userA.getName() << endl;
		return userA;
	}
	User1DefeatCount = 0;
	User2DefeatCount = 0;
	do//picks a valid codemon via shuffling with rand function so the order of codemon is always random for userA
	{
		currentMonIndex1 = (rand() % PARTYSIZE) + SMALLESTSIZE;
	} while (userA.Pocket[currentMonIndex1].getCHP() <= FAINTED);
	do//picks a valid codemon via shuffling with rand function so the order of codemon is always random for userB
	{
		currentMonIndex2 = (rand() % PARTYSIZE) + SMALLESTSIZE;
	} while (userB.Pocket[currentMonIndex2].getCHP() <= FAINTED);
	cout << userA.getName() << " throws out " << userA.Pocket[currentMonIndex1].getCName() << "!" << endl;
	cout << userB.getName() << " throws out " << userB.Pocket[currentMonIndex2].getCName() << "!" << endl;
	while (GO == true)//battle goes until someone loses 
	{
		for (int i = 0; i < PARTYSIZE; i++)//checks to see if userA has lost 
		{
			if (userA.Pocket[i].getCHP() <= FAINTED)
			{
				User1DefeatCount++;

			}
		}
		if (User1DefeatCount == PARTYSIZE)//if all user Codemon have fainted, userB wins 
		{
			cout << "And the winner is...  " << userB.getName() << "!!!" << endl;
			cout << " Healing " << userB.getName() << " team..." << endl;
			for (int i = 0; i < PARTYSIZE; i++)
			{
				userB.Pocket[i](userB.Pocket[i].gethp());// heals a users codemon via () operator 
		
			}
			cout << " Healing " << userA.getName() << " team..." << endl;
			for (int i = 0; i < PARTYSIZE; i++)
			{
				userA.Pocket[i](userA.Pocket[i].gethp());
			}
			return userB;
		}
		for (int i = 0; i < PARTYSIZE; i++)//checks to see if userB has lost 
		{
			if (userB.Pocket[i].getCHP() <= FAINTED)
			{
				User2DefeatCount++;
			}
		}
		if (User2DefeatCount == PARTYSIZE)//if all user Codemon have fainted, userA wins 
		{
			cout << "And the winner is...  " << userA.getName() << "!!!" << endl;
			cout << " Healing " << userB.getName() << " team..." << endl;
			for (int i = 0; i < PARTYSIZE; i++)
			{
				userB.Pocket[i](userB.Pocket[i].gethp());// heals a users codemon via () operator 
			}
			cout << " Healing " << userA.getName() << " team..." << endl;
			for (int i = 0; i < PARTYSIZE; i++)
			{
				userA.Pocket[i](userA.Pocket[i].gethp());
			}
			return userA;
		}
		User1DefeatCount = 0;//resets count values to check if somebody lost for the next turn
		User2DefeatCount = 0;
		if (userA.Pocket[currentMonIndex1].getCHP() <= FAINTED)//sees if current codemon has fainted from previous turn and picks a new codemon in that users party
		{
			cout << userA.Pocket[currentMonIndex1].getCName() << " has fainted!" << endl;
			do
			{

				currentMonIndex1 = (rand() % PARTYSIZE) + SMALLESTSIZE;
			} while (userA.Pocket[currentMonIndex1].getCHP() <= FAINTED);
			cout << userA.getName() << " throws out " << userA.Pocket[currentMonIndex1].getCName() << "!" << endl;
		}
		if (userB.Pocket[currentMonIndex2].getCHP() <= FAINTED)
		{
			cout << userB.Pocket[currentMonIndex2].getCName() << " has fainted!" << endl;
			do
			{
				currentMonIndex2 = (rand() % PARTYSIZE) + SMALLESTSIZE;
			} while (userB.Pocket[currentMonIndex2].getCHP() <= FAINTED);
			cout << userB.getName() << " throws out " << userB.Pocket[currentMonIndex2].getCName() << "!" << endl;
		}
		if (weather_effect == WEATHER_CLEAR)//NONE, no weather effect on battle
		{
			if (stateTheClimate == false)// climate will only be stated on first turn
			{
				stateTheClimate = true;
				cout << "The weather is clear today(None)!" << endl;
			}
			Move = userA.selectSkill(userA.Pocket[currentMonIndex1]);//picks a skill
			cout << userA.Pocket[currentMonIndex1].getCName() << " uses " << userA.Pocket[currentMonIndex1].getsName(Move) << " dealing " << userA.Pocket[currentMonIndex1].getsDamage(Move) << " damage!" << endl;//states attack message
			userB.Pocket[currentMonIndex2].attacked(userB.Pocket[currentMonIndex2].getCHP(), userA.Pocket[currentMonIndex1].getsDamage(Move), None);//deals damage to attacked codemons health
			userB.outputDamage(currentMonIndex2);//outputs attacked codmeons health after being hit with oppnents skill
			if (userB.Pocket[currentMonIndex2].getCHP() > FAINTED)//sees if damaged codemon is still alive to counterattack 
			{
				Move = userB.selectSkill(userB.Pocket[currentMonIndex2]);
				cout << userB.Pocket[currentMonIndex2].getCName() << " uses " << userB.Pocket[currentMonIndex2].getsName(Move) << " dealing " << userB.Pocket[currentMonIndex2].getsDamage(Move) << " damage!!" << endl;
				userA.Pocket[currentMonIndex1].attacked(userA.Pocket[currentMonIndex1].getCHP(), userA.Pocket[currentMonIndex1].getsDamage(Move), None);
				userA.outputDamage(currentMonIndex1);
			}
		}
		else if (weather_effect == WEATHER_SUNNY)//sunny weather so damage is doubled
		{
			if (stateTheClimate == false)
			{
				stateTheClimate = true;
				cout << "The weather today is Sunny!" << endl;
			}
			Move = userA.selectSkill(userA.Pocket[currentMonIndex1]);
			cout << userA.Pocket[currentMonIndex1].getCName() << " uses " << userA.Pocket[currentMonIndex1].getsName(Move) << " dealing " << userA.Pocket[currentMonIndex1].getsDamage(Move) << " damage!!" << endl;
			userB.Pocket[currentMonIndex2].attacked(userB.Pocket[currentMonIndex2].getCHP(), userA.Pocket[currentMonIndex1].getsDamage(Move), Sunny);
			userB.outputDamage(currentMonIndex2);

			if (userB.Pocket[currentMonIndex2].getCHP() > FAINTED)
			{
				Move = userB.selectSkill(userB.Pocket[currentMonIndex2]);
				cout << userB.Pocket[currentMonIndex2].getCName() << " uses " << userB.Pocket[currentMonIndex2].getsName(Move) << " dealing " << userB.Pocket[currentMonIndex2].getsDamage(Move) << " damage!!" << endl;
				userA.Pocket[currentMonIndex1].attacked(userA.Pocket[currentMonIndex1].getCHP(), userA.Pocket[currentMonIndex1].getsDamage(Move), Sunny);
				userA.outputDamage(currentMonIndex1);
			}
		}
		else if (weather_effect == WEATHER_HAIL)//hail, codemon are damaged by after each time they attack (requires more if statements to check if a codemon has survived the hail effect)
		{
			if (stateTheClimate == false)
			{
				stateTheClimate = true;
				cout << "The weather today is Hail!" << endl;
			}
			Move = userA.selectSkill(userA.Pocket[currentMonIndex1]);
			cout << userA.Pocket[currentMonIndex1].getCName() << " uses " << userA.Pocket[currentMonIndex1].getsName(Move) << " dealing " << userA.Pocket[currentMonIndex1].getsDamage(Move) << " damage!!" << endl;
			userB.Pocket[currentMonIndex2].attacked(userB.Pocket[currentMonIndex2].getCHP(), userA.Pocket[currentMonIndex1].getsDamage(Move), None);
			userB.outputDamage(currentMonIndex2);
			cout << "Both codemon are affected by the hail storm!" << endl;
			userA.Pocket[currentMonIndex2].attacked(userA.Pocket[currentMonIndex1].getCHP(), Hail, userA.Pocket[currentMonIndex1].gethp());
			userA.outputDamage(currentMonIndex1);
			if (userB.Pocket[currentMonIndex2].getCHP() > FAINTED)
			{

				userB.Pocket[currentMonIndex2].attacked(userB.Pocket[currentMonIndex2].getCHP(), Hail, userB.Pocket[currentMonIndex2].gethp());
				userB.outputDamage(currentMonIndex2);
			}
			if (userB.Pocket[currentMonIndex2].getCHP() > FAINTED && userA.Pocket[currentMonIndex1].getCHP() > FAINTED)
			{

				Move = userB.selectSkill(userB.Pocket[currentMonIndex2]);
				cout << userB.Pocket[currentMonIndex2].getCName() << " uses " << userB.Pocket[currentMonIndex2].getsName(Move) << " dealing " << userB.Pocket[currentMonIndex2].getsDamage(Move) << " damage!!" << endl;
				userA.Pocket[currentMonIndex1].attacked(userA.Pocket[currentMonIndex1].getCHP(), userA.Pocket[currentMonIndex1].getsDamage(Move), None);
				userA.outputDamage(currentMonIndex1);
				cout << "Both codemon are affected by the hail storm!" << endl;
				if (userA.Pocket[currentMonIndex1].getCHP() > FAINTED)
				{

					userA.Pocket[currentMonIndex1].attacked(userA.Pocket[currentMonIndex1].getCHP(), Hail, userA.Pocket[currentMonIndex1].gethp());
					userA.outputDamage(currentMonIndex1);
				}
				userB.Pocket[currentMonIndex2].attacked(userB.Pocket[currentMonIndex2].getCHP(), Hail, userB.Pocket[currentMonIndex2].gethp());
				userB.outputDamage(currentMonIndex2);
			}
		}
		else if (weather_effect == WEATHER_SNOW)//snowy weather, so damaged is halved
		{
			if (stateTheClimate == false)
			{
				stateTheClimate = true;
				cout << "The weather today is Snow!" << endl;
			}
			Move = userA.selectSkill(userA.Pocket[currentMonIndex1]);
			cout << userA.Pocket[currentMonIndex1].getCName() << " uses " << userA.Pocket[currentMonIndex1].getsName(Move) << " dealing " << userA.Pocket[currentMonIndex1].getsDamage(Move) << " damage!!" << endl;
			userB.Pocket[currentMonIndex2].attacked(userB.Pocket[currentMonIndex2].getCHP(), userA.Pocket[currentMonIndex1].getsDamage(Move), Snow);
			userB.outputDamage(currentMonIndex2);
			if (userB.Pocket[currentMonIndex2].getCHP() > FAINTED)
			{
				Move = userB.selectSkill(userB.Pocket[currentMonIndex2]);
				cout << userB.Pocket[currentMonIndex2].getCName() << " uses " << userB.Pocket[currentMonIndex2].getsName(Move) << " dealing " << userB.Pocket[currentMonIndex2].getsDamage(Move) << " damage!!" << endl;
				userA.Pocket[currentMonIndex1].attacked(userA.Pocket[currentMonIndex1].getCHP(), userA.Pocket[currentMonIndex1].getsDamage(Move), Snow);
				userA.outputDamage(currentMonIndex1);
			}
		}
		else if (weather_effect == WEATHER_RAIN)//rainy weather so moves have 50% chance to miss
		{

			if (stateTheClimate == false)
			{
				stateTheClimate = true;
				cout << "The weather today is Rain!" << endl;
			}
			Rain_effect = (rand() % RAIN5050POSSIBILITYRANGE) + SMALLESTSIZE;

			Move = userA.selectSkill(userA.Pocket[currentMonIndex1]);
			if (Rain_effect == MISS)
			{
				cout << userA.Pocket[currentMonIndex1].getCName() << " uses " << userA.Pocket[currentMonIndex1].getsName(Move) << " but misses." << endl;
			}
			else if (Rain_effect == HIT)
			{
				cout << userA.Pocket[currentMonIndex1].getCName() << " uses " << userA.Pocket[currentMonIndex1].getsName(Move) << " dealing " << userA.Pocket[currentMonIndex1].getsDamage(Move) << " damage!!" << endl;
				userB.Pocket[currentMonIndex2].attacked(userB.Pocket[currentMonIndex2].getCHP(), userA.Pocket[currentMonIndex1].getsDamage(Move), None);
				userB.outputDamage(currentMonIndex2);
				if (userB.Pocket[currentMonIndex2].getCHP() > FAINTED)
				{
					Move = userB.selectSkill(userB.Pocket[currentMonIndex2]);
					Rain_effect = (rand() % RAIN5050POSSIBILITYRANGE) + SMALLESTSIZE;
					if (Rain_effect == MISS)
					{
						cout << userA.Pocket[currentMonIndex1].getCName() << " uses " << userA.Pocket[currentMonIndex1].getsName(Move) << " but misses." << endl;
					}
					else if (Rain_effect == HIT)
					{
						cout << userB.Pocket[currentMonIndex2].getCName() << " uses " << userB.Pocket[currentMonIndex2].getsName(Move) << " dealing " << userB.Pocket[currentMonIndex2].getsDamage(Move) << " damage!!" << endl;
						userA.Pocket[currentMonIndex1].attacked(userA.Pocket[currentMonIndex1].getCHP(), userA.Pocket[currentMonIndex1].getsDamage(Move), None);
						userA.outputDamage(currentMonIndex1);
					}

				}
				cout << "Next Turn!" << endl;

			}
		}
	}
}