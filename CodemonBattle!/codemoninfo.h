#ifndef CODEMONINFO_H
#define CODEMONINFO_H
#include <iostream>

using namespace std;
class codemoninfo
{
public:
	int operator ()(const int fullHP);//PRE: a winner is declared after opponenet loses all their codemon in Battle.cpp. DESC: takes in orginial health value of a codemon, POST: sets current health to orginial health of a codemon and returns current health 
	friend codemoninfo operator+(codemoninfo& addCodemon, const int count);//PRE: called when user decides to add another codemon. DESC: takes in codemon and integer 1 for one codemon and adds, POST: codemon added to static value size.
	friend codemoninfo operator-(codemoninfo&  subCodemon, const int count);//PRE: called when user decides to subtracted another codemon. DESC: takes in codemon and integer 1 for one codemon and removes, POST: codemon subtracted to static value size.
	void setWeather();//PRE:called when default contructor weather_effect is created in battle.cpp. DESC: sets static weather to random number 0 - 4. POST:each number represents a different weather effect 
	void setCName(const string name); //PRE called in codemon update. DESC: sets inputted name to codemon name, POST: a codemons name has been created
	void settype(const string type); //PRE called in codemon update. DESC: sets inputted type to codemon type, POST: a codemons type has been created
	void setlevel(const int level); //PRE called in codemon update. DESC: sets inputted name to codemon name, POST: a codemons level has been created
	void sethp(const int hp); //PRE called in codemon update. DESC: sets inputted name to codemon name, POST: a codemons HP has been created
	void setCHP(int Currenthp); //PRE called in codemon update. DESC: sets inputted current HP to codemon current HP, POST: a codemons current health has been created
	string getsName(const int index) { return skill[index]; }//PRE: called whenever a skill is pulled from move randomizer in battle:DESC stores names of codemons skill; POST:returns a skill name of codmeon based on index
	int getsDamage(const int index) { return skillDamage[index]; }//PRE: called whenever a skill is pulled from move randomizer in battle:DESC stores damage of codemons skill; POST:returns a skill damage of codmeon based on index
	string getCName() { return CodemonName; }//PRE:called whenever codemon name needs to be outputted in battle;DESC: name of codemon, POST: returns codemons name
	string gettype() { return TypeInfo; }//PRE: called whenever codemon type needs to be outputted in battle, DESC: type of codemon, POST; returns type
	int getlevel() { return CodemonLevel; }//PRE: called whenever codemon level needs to be outputted in battle, DESC: type of codemon, POST; returns lvl
	int gethp() { return Healthpoints; }//PRE: called whenever codemon  hp needz to be outputted in battle, DESC: type of codemon, POST; returns hp
	int getCHP() { return CurrentHealth; }//PRE: called whenever codemon current hp needs to be outputted in battle, DESC: type of codemon, POST; returns current hp
	void attacked(const int health, const int attack, const float effect); //PRE: called whenever a codemon or weather effet wants to deal a damaging attack to a codemon. DESC: takes in health of attacked codemon, dmage of skill used against that codemon, and a potential weather effect:POST calculates the current health of the codemon post attack
	void SkillList(const string Codemonname);//PRE:after codemon's name and data in inputted by the user, this function is called if they opt into adding a new skill,Desc: updates skillinfo with user input, Post: populates a reference to a indivdual codemons skillinfo
	void evolve(); //Pre:activates in prepare if codemon is enlightened based on time invocation, Desc: evolves codemon, POST: levels up codemon by 5
	codemoninfo() { setWeather(); }//default operator that will be only be used for weather
	static int weather;//weather randomized once and will remain the same for the duration of a battle
	static int size;//size of codemon created, effected by overloaded operators +(adds a codemon) and -(removes a codemon)
	codemoninfo(const string Cname, const string type, const int level, const int HP, int Currenthp) { setCName(Cname); settype(type); setlevel(level); sethp(HP); setCHP(Currenthp); }//an array of 10 codemon one for each codemon that may be populated by user depending on how many codemon they have
private:
	string CodemonName;//a codemon's name
	string TypeInfo;//a codemon's type
	int CodemonLevel;//a codemon's level
	int Healthpoints;//a codemon's HP
	int CurrentHealth;
	string skill[6] = {" "," "," " ," " ," " ," " };  // a codemon's list of up to 6 skill names for SkillList func
	int skillDamage[6];// a codemon's list of up to 6 skill names attack power for SkillList func
	
};
#endif 
