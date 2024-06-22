#ifndef CONTESTENT_H
#define CONTESTENT_H

#include <iostream>
#include "codemoninfo.h"
#include "iteminfo.h"
#include "skillinfo.h"
#include <string>

using namespace std;
class contestent
{
public:
	int getVolume() { return volume; }//PRE: accessed in main before fight, DESC: called to return volume value: Post: used to compare volume to other users class volume member
	string getName() { return name; }//Pre: accessed whenever user's name needs to be consoe outputted, Desc: outputs user name, Post: name outputted in console
	void setName(const string n);// Pre: name given in main to contestent object from queue line, Desc; contestent name is set to queue name, post: Name has now been initailized
	void setVolume();//pre: called whenever contentest(int, string) is called, DESC: randomizes volume for a contestent between 1 - 100. POST: volume has been set for a user
	
	friend contestent operator*(contestent& userA, contestent& userB); // PRE: takes int two contestent objectsDESC:a friend function for the non-member multiplication operator that takes to users and makes them battle POST: returning the winner
	contestent() {} //default constructor for winner of battle stored here
	contestent(const int count, const string NAME) : Codemoncount(0) { setName(NAME); setVolume(); }//used to initalize both trainers by setting count to zero, taking in their name from queue and setting their random volume.
	contestent(const contestent& source); //copy constructor has no use yet, copys contestent name
	void prepare(int count);//PRE: called in main to add codmeon to trainers party.,DESC: takes count to count amount of codemon, and the function call PocketUpdate to get input, POST: populates codemon memebers and their corresponding skill lists
	void PocketUpdate(const string pname, int index);//PRE: called in prepare if user wants to add a codemon, DESC:populates a codemon index object with cin data, POST: codemon has been added to thier roster
	void BagUpdate();//PRE:called by += operator in main, DESC: populates a item index object with cin data from user, POST: item has been added to roster
	void bagRemove();//PRE :called by -= operator in main if user wants to remove an item, DESC: deletes whatever item the user dosent want anymore, POST:iteminfo memeber may have been reset to being empty
	void partyRemove();//PRE: called in main if user wants to remove a party memeber, DESC: deletes whatever codemon the user dosent want anymore, POST:codemoninfo memeber may have been reset to being empty as well as its skills
	int dropLowestLevel();//PRE:called if the i index keeping track of codemon hits 10 meaning the codemon party size has reached its max, DESC: if party is full, the lowest level codemon's index will be identified, POST: lowest level codemon index will bel deleted and the index of that codemon will be replaced by the new codemon being added by the user
	int selectSkill(codemoninfo& codemon);//PRE:in battle *operator, is called whenever its a codemons turn to user a move, DESC: takes in a contestents codemon object as a refrence, POST: randomly picks a valid skill for the codemon to use in the field of battle
	void outputDamage(const int indexB);//PRE:outputs current health info whenever a codemon is attacked by another codemon or weather, DESC: takes in the index of the codemon that is attacked, POST: displays a codemons health after its been attacked
	void print();;// pre: automatically called in main after -= is called, Desc: outputs data, Post: summary of an individual users codemon info (name, party size, codemon, items)
	contestent operator+=(contestent& Itembag)//PRE:called in main DESC:overloads += operator to call bagupdate and popoulate the contestent items  POST: return the item populated contestent
	{
		Itembag.BagUpdate();
		return Itembag;
	}
	contestent operator-=(contestent& Itembag)//PRE:called in main DESC:overloads -= operator to call bagRemove and removes a contestents item if the contestent wants too POST:  returns the contestents data with or without removed items based upon user choice.
	{
		Itembag.bagRemove();
		return Itembag;
	}
private:
	const int POCKETSIZE = 10;
	const int SKILLSIZE = 6;
	const int BAGSIZE = 20;
	int volume;//users volume set to be random
	string name;//name of user
	int Codemoncount;//size of useful info in  thier party
	int Itemcount;// size of useful info in their bag 
	string Codemonparty[10]; // names of all codemon in thier party for print func
	string backpack[20];//names of all items in bag for print func
	int time_invocation = 0;//currently useless time conunter 
	//below are a contestents codemon & bag party as well as each codemons corresponding skill lists 
	skillinfo skillinfo1[6] = { skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0) };
	skillinfo skillinfo2[6] = { skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0) };
	skillinfo skillinfo3[6] = { skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0) };
	skillinfo skillinfo4[6] = { skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0) };
	skillinfo skillinfo5[6] = { skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0) };
	skillinfo skillinfo6[6] = { skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0) };
	skillinfo skillinfo7[6] = { skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0) };
	skillinfo skillinfo8[6] = { skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0) };
	skillinfo skillinfo9[6] = { skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0) };
	skillinfo skillinfo10[6] = { skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0), skillinfo(" ", 0) };
	iteminfo Bag[20] = { iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0), iteminfo(" ", " ",0) };
	codemoninfo Pocket[10] = { codemoninfo(" "," ",0,0,0), codemoninfo(" "," ",0,0,0), codemoninfo(" "," ",0,0,0), codemoninfo(" "," ",0,0,0), codemoninfo(" "," ",0,0,0), codemoninfo(" "," ",0,0,0), codemoninfo(" "," ",0,0,0), codemoninfo(" "," ",0,0,0), codemoninfo(" "," ",0,0,0), codemoninfo(" "," ",0,0,0) };
	
	

};
#endif