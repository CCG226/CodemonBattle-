#include "contestent.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
void contestent::setName(const string n)// sets name
{
	name = n;
}
void contestent::setVolume()
{
	const int LOUDESTSOUND = 101;
	const int QUIETESTSOUND = 1;
	volume = (rand() % LOUDESTSOUND) + QUIETESTSOUND;
}
contestent::contestent(const contestent& source) //currently useless copy (might be used in later assignment)
{
	setName(source.name);
}

void contestent::prepare(int count)
{
	bool partyFull = false;//activates if party is full
	cout << "Preparing " << name << "'s Codemon for battle!" << endl;
	char continueP = 'y';
	int i = 0;
	cout << "Enter a new Codemon?(y/n)" << endl;
	cin >> continueP;//asked whenever codemon wants to enter another
	codemoninfo Sizeadd;//used for + operator
	while(continueP == 'y' || continueP == 'Y')//recieves info for each codemon user want to enter
	{
		count++;//counts codemon size
		Codemoncount = count;//sets that size equal to Codemoncount private variable
		Sizeadd = Pocket[i] + 1;//increases size of valide codemon in party via + operator
		if (count == POCKETSIZE)//if party is full codemoncount will and will remain 10 to prevent Codemoncount going over 10 whenver a codemon is dropped
		{
			Codemoncount = POCKETSIZE;
		}
		if (i >= POCKETSIZE)//if i is greater than or equal to pocketsize the party is full and lowestlevel will be dropped via function
		{
			i = dropLowestLevel(); // index i is now equal to the lowest level codemon, so whenver the user filles in data for i in a full party the lowest level codemon data is replaced by the new codemon
			Codemoncount = POCKETSIZE;//ensures Codemoncount is 10
			partyFull = true;
		}
		cout << "Enter  A Codemon's name" << endl;
		cin.ignore();
		getline(cin, Codemonparty[i]);//gets  a codemons name
		PocketUpdate(Codemonparty[i], i);//populates rest of a codemons's data
		
		switch (i) //if i = 0, then skillinfo for the first codemon is entered, if i = 1, then skillinfo for the second codemon is entered, until user reachs max size or stops entering codemon
		{
		case 0:
			Pocket[i].SkillList(Codemonparty[i]);//populates skillinfo for the first codemon, Skillinfo1 being for the first codemon in the codemon info list, Skillinfo2 being for the second codmeon in the codemon info list and so on
			
			for (int j = 0; j < SKILLSIZE; j++) 
			{
				skillinfo1[j].setSname(Pocket[i].getsName(j));
				skillinfo1[j].setDamage(Pocket[i].getsDamage(j));
			}
			break;
		case 1:
			Pocket[i].SkillList(Codemonparty[i]);
			for (int j = 0; j < SKILLSIZE; j++)
			{
				skillinfo2[j].setSname(Pocket[i].getsName(j));
				skillinfo2[j].setDamage(Pocket[i].getsDamage(j));

			}
			break;
		case 2:
			Pocket[i].SkillList(Codemonparty[i]);
			for (int j = 0; j < SKILLSIZE; j++)
			{
				skillinfo3[j].setSname(Pocket[i].getsName(j));
				skillinfo3[j].setDamage(Pocket[i].getsDamage(j));

			}
			break;
		case 3:
			Pocket[i].SkillList(Codemonparty[i]);
			for (int j = 0; j < SKILLSIZE; j++)
			{
				skillinfo4[j].setSname(Pocket[i].getsName(j));
				skillinfo4[j].setDamage(Pocket[i].getsDamage(j));

			}
			break;
		case 4:
			Pocket[i].SkillList(Codemonparty[i]);
			for (int j = 0; j < SKILLSIZE; j++)
			{
				skillinfo5[j].setSname(Pocket[i].getsName(j));
				skillinfo5[j].setDamage(Pocket[i].getsDamage(j));

			}
			break;
		case 5:
			Pocket[i].SkillList(Codemonparty[i]);
			for (int j = 0; j < SKILLSIZE; j++)
			{
				skillinfo6[j].setSname(Pocket[i].getsName(j));
				skillinfo6[j].setDamage(Pocket[i].getsDamage(j));

			}
			break;
		case 6:
			Pocket[i].SkillList(Codemonparty[i]);
			for (int j = 0; j < SKILLSIZE; j++)
			{
				skillinfo7[j].setSname(Pocket[i].getsName(j));
				skillinfo7[j].setDamage(Pocket[i].getsDamage(j));

			}
			break;
		case 7:
			Pocket[i].SkillList(Codemonparty[i]);
			for (int j = 0; j < SKILLSIZE; j++)
			{
				skillinfo8[j].setSname(Pocket[i].getsName(j));
				skillinfo8[j].setDamage(Pocket[i].getsDamage(j));

			}
			break;
		case 8:
			Pocket[i].SkillList(Codemonparty[i]);
			for (int j = 0; j < SKILLSIZE; j++)
			{
				skillinfo9[j].setSname(Pocket[i].getsName(j));
				skillinfo9[j].setDamage(Pocket[i].getsDamage(j));

			}
			break;
		case 9:
			Pocket[i].SkillList(Codemonparty[i]);
			for (int j = 0; j < SKILLSIZE; j++)
			{
				skillinfo10[j].setSname(Pocket[i].getsName(j));
				skillinfo10[j].setDamage(Pocket[i].getsDamage(j));
			}
			break;
		default:
			cout << "ERROR: Index out of range " << endl;//will never run

		}
		
		i++;//to move on to next codemon in party
		if (partyFull == true)//if party is full i is reset to 10 so that a the lowestlevel will be dropped if user  wants to enter another codemon
		{
			i = POCKETSIZE;
		}
		cout << "Enter a new Codemon?(y/n)" << endl;
		cin >> continueP;
		
	}
	
}
	void contestent::PocketUpdate(const string pname,const int index)
	{
		string UserInputtedType = "";
		int UserInputtedLevel = 0;
		int UserInputtedHP = 0;
		const int LEVEL5MULTI = 5;//make sure level multiple of 5
		const int ZERONULL = 0;//prevents user from entering below zero;
		const int ENLIGHTENMENT = 1;//needed for evolution
		cout << "Enter " << pname << "'s type " << endl; //recieves pname from prepare aka name of Codemon
		cin.ignore();
		getline(cin, UserInputtedType);//gets name of type (Can be anything really)



		do
		{
			cout << "Enter " << pname << "'s level (level must be a multiple of 5 and greater than or equal to 0)" << endl;
			cin >> UserInputtedLevel;
		} while (UserInputtedLevel % LEVEL5MULTI != ZERONULL && UserInputtedLevel < ZERONULL);//gets codemon level (level must be a multiple of 5 and greater than or equal to 0)
		do
		{
			cout << "Enter " << pname << "'s HP" << endl;
			cin >> UserInputtedHP;
		} while (UserInputtedHP < ZERONULL);//gets Codemons health points, cant be negative
		Pocket[index].setCName(pname);//populating Codemoninfo
		Pocket[index].settype(UserInputtedType);
		Pocket[index].setlevel(UserInputtedLevel);
		Pocket[index].sethp(UserInputtedHP);
		Pocket[index].setCHP(UserInputtedHP);
		if (time_invocation == ENLIGHTENMENT)//doesnt activate rn
		{
			//would call evolve() but evolve() currently has no user
		}
		
	}
	void contestent::BagUpdate()
	{
		cout << "\nNow lets add " << name << "'s items\n" << endl;
		char continueI = 'y';
		int tempDuration = 0;
		const int infinite = -1;
		string tempDesc = "";
		for (int i = 0; i < BAGSIZE; i++)//recieving potential item info from user
		{
			cout << "Enter a new Item?(y/n)" << endl;
			cin >> continueI;
			if (continueI != 'y' && continueI != 'Y')
			{
				break;
			}
			cout << "Enter Item " << i + 1 << "'s name" << endl;
			cin.ignore();
			getline(cin, backpack[i]);
			cout << "Enter item " << backpack[i] << "'s Description." << endl;//recieves iname from prepare aka name of item
			cin.ignore();
			getline(cin, tempDesc);//gets items decription 
			do
			{
				cout << "Enter time duration of item " << backpack[i] << ". (if items effect is permanent, Enter -1)" << endl;
				cin >> tempDuration;
			} while (tempDuration < infinite);
			Itemcount++;//keeping track of item size
			Bag[i].setIname(backpack[i]);
			Bag[i].setDescription(tempDesc);
			Bag[i].setDuration(tempDuration);

		}
		
	}
	void contestent::bagRemove()
	{
		string tempName = "";
		bool isIteminParty = false; //activates if item to be removed is found
		bool avoidDeletingMatchingNames = false;//ensures that the user dosent delete all items with the same name
		cout << "\n" << endl;
		cout << "Contestent " << name << "'s Item Summary:" << endl;
		for (int i = 0; i < BAGSIZE; i++)//prints list of items owned by the user so they can write the name of the one intended to be deleted
		{
			if (backpack[i] != "")
			{
				cout << i + 1 << ") " << backpack[i] << endl;
			}
		}
		
		cout << "Enter the name of the item you want to remove." << endl;
		getline(cin, tempName);//name of item to be dropped
		cin.ignore();
		for (int i = 0; i < BAGSIZE; i++)//searches for item
		{
			if (backpack[i] == tempName && avoidDeletingMatchingNames == false)//if item is found and thier has not been a duplicate found yet
			{
				avoidDeletingMatchingNames = true;//duplicates will not be deleted only one item can be deleted at a time
				Itemcount--; //one less item
				isIteminParty = true;//item discoved
				backpack[i] = "";//resets backpack index for deleted item so it isnt printed in summary
				Bag[i] = iteminfo(" ", " ", 0);//empties that item objects data 
			}
		}
		cout << "\n" << endl;
		if (isIteminParty == false)//item wasnt found 
		{
			cout << "Error, Item not found." << endl;
		}
	}
			void contestent::partyRemove()
			{
	
				codemoninfo subSize;
				string tempName = "";
				bool isCodemoninParty = false;
				bool avoidDeletingMatchingNames = false;
				cout << "\n" << endl;
				cout << "Contestent " << name << "'s Codemon Summary:" << endl;
				
				for (int i = 0; i < POCKETSIZE; i++)//outputs codemons names so a user can see and retype the one they want to remove
				{
					if (Codemonparty[i] != "")
					{
						cout << i + 1 << ") " << Codemonparty[i] << endl;
					}

				}
				
				cout << "Enter the name of the Codemon you want to remove" << endl;
				getline(cin, tempName);//get name of desired codemon to remove
				cin.ignore();
				for (int i = 0; i < POCKETSIZE; i++)
				{
					cout << Codemonparty[i] << endl;
					if (Codemonparty[i] == tempName && avoidDeletingMatchingNames == false)//searching for that codmeon
					{
						avoidDeletingMatchingNames = true;//duplicates not removed
						Codemoncount--;//overall party size is dropped by 1
						isCodemoninParty = true;//found
						Codemonparty[i] = "";//reset name to avoid printing deleted codemon
						subSize = Pocket[i] - 1;//- operator removes total party size by deleteing a codemon
						Pocket[i] = codemoninfo(" ", " ", 0, 0,0);//codemon object is reset to default and so is its corresponding skills 
						switch (i)
						{
						case 0:
							for (int j = 0; j < SKILLSIZE; j++)
							{
								skillinfo1[j] = skillinfo(" ", 0);
							}
						case 1:
							for (int j = 0; j < SKILLSIZE; j++)
							{
								skillinfo2[j] = skillinfo(" ", 0);
							}
						case 2:
							for (int j = 0; j < SKILLSIZE; j++)
							{
								skillinfo3[j] = skillinfo(" ", 0);
							}
						case 3:
							for (int j = 0; j < SKILLSIZE; j++)
							{
								skillinfo4[j] = skillinfo(" ", 0);
							}
						case 4:
							for (int j = 0; j < SKILLSIZE; j++)
							{
								skillinfo5[j] = skillinfo(" ", 0);
							}
						case 5:
							for (int j = 0; j < SKILLSIZE; j++)
							{
								skillinfo6[j] = skillinfo(" ", 0);
							}
						case 6:
							for (int j = 0; j < SKILLSIZE; j++)
							{
								skillinfo7[j] = skillinfo(" ", 0);
							}
						case 7:
							for (int j = 0; j < SKILLSIZE; j++)
							{
								skillinfo8[j] = skillinfo(" ", 0);
							}
						case 8:
							for (int j = 0; j < SKILLSIZE; j++)
							{
								skillinfo9[j] = skillinfo(" ", 0);
							}
						case 9:
							for (int j = 0; j < SKILLSIZE; j++)
							{
								skillinfo10[j] = skillinfo(" ", 0);
							}
						}
					}
					
				}
				if (isCodemoninParty == false)//user misinput catcher 
				{
					cout << "Error, Codemon not found." << endl;
				}

				return;
			}
			int contestent::selectSkill(codemoninfo& codemon)
			{
				const int MOVESET = 6;
				int findMove = 0;//stores a skills index of a individual codemon refrenced 
				do
				{
					findMove = (rand() % MOVESET) + 0;//randomly selects and index until a skill name index is found that has been filled by user input
				} while (codemon.getsName(findMove) == " ");
				return findMove;//returns a valid skill for the codemon to use battle
			}
			int contestent::dropLowestLevel()
			{
				int min = Pocket[0].getlevel();
				int indexOfLowestLevel = 0;//tracks index of lowest level
				for (int i = 0; i < POCKETSIZE; i++)//basically minmium value array search
				{
					if (min > Pocket[i].getlevel())
					{
						min = Pocket[i].getlevel();
						indexOfLowestLevel = i;
					}
				}
				cout << "Party Full, removing your lowest level codemon " << Pocket[indexOfLowestLevel].getCName() << endl;
				cout << "Now please enter the data for the replacement codemon " << endl;
				return indexOfLowestLevel;//returns index of lowest level to be replaced by new codemon 
			}
			void contestent::outputDamage(const int index)
			{
				const int DEAD = 0;
				if (Pocket[index].getCHP() <= DEAD)//outputs an attacked codemons health depending on wheater they've been knocked out
				{
					cout << Pocket[index].getCName() << " now has 0 HP!" << endl;
				}
				else
				{
					cout << Pocket[index].getCName() << " now has " << Pocket[index].getCHP() << " HP!" << endl;
				}
				return;
			}