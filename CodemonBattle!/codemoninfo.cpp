#include "codemoninfo.h"
#include <iostream>
#include<string>
#include <ctime>
#include <cstdlib>
using namespace std;
int codemoninfo::size = 0;
int codemoninfo::operator()(const int fullHP)
{
	CurrentHealth = fullHP;//refills hp value
	return CurrentHealth;
}
codemoninfo operator+(codemoninfo& addCodemon, const int count)
{
	addCodemon.size = addCodemon.size + count; //adds codemon to static size of the party
	return addCodemon;
}
codemoninfo operator-(codemoninfo& subCodemon, const int count)
{
	subCodemon.size = subCodemon.size - count;//removes a codemon from size
	return subCodemon;
}
void codemoninfo::setCName(const string name)
{
	CodemonName = name;
}
void codemoninfo::settype(const string type)
{
	TypeInfo = type;
}
void codemoninfo::setlevel(const int level)
{
	CodemonLevel = level;
}
void codemoninfo::sethp(const int hp)
{
	Healthpoints = hp;
}
void codemoninfo::evolve()
{
	const int LEVELUP = 5;
	CodemonLevel = CodemonLevel + LEVELUP;//this is evolution of codemon
}
void codemoninfo::setCHP(int Currenthp)
{
	CurrentHealth = Currenthp;//sets currenthp to total hp when initialized in update codemon
}
void codemoninfo::SkillList(const string Codemonname)
{
	const int MAXSKILLS = 6;
	char tempcontinue = 'y';
	cout << "Enter a skill " << endl;
	for (int i = 0; i < MAXSKILLS; i++)
	{
		
		cout << "Enter Skill " << i + 1 << "'s name." << endl;
		cin.ignore();//gets skill name for private variable skill
		getline(cin, skill[i]);
		cout << "Enter Skill " << i + 1 << "'s base damage for " << Codemonname << "'s skill" << endl;
		cin >> skillDamage[i];//gets damage amount of skill, it is allowed to be negative because I assume that a skill that does negative damage is a healing skill
		cout << "Enter a new skill? (y/n)" << endl;//sees if user wants to enter a skill for a codemon
		cin >> tempcontinue;
		if (tempcontinue != 'Y' && tempcontinue != 'y')
		{
			break;//breaks if no more skills are to be inputted
		}
	}
	
}
void codemoninfo::attacked(const int health, const int attack, const float effect)
{

	CurrentHealth = health - (effect * attack); //damageto health  a codemon takes from weather effect and attack
		
}
int codemoninfo::weather = 0;//weather intiazed at zero
void codemoninfo::setWeather()
{
	const int MAXAMOUNTOFWEATHEREFFECTS = 5;
	const int MINAMOUNTOFWEATHEREFFECTS = 0;
	weather = (rand() % MAXAMOUNTOFWEATHEREFFECTS) + MINAMOUNTOFWEATHEREFFECTS; //weather is randomized when weather element is called in battle.cpp
}