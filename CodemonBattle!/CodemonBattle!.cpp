// CodemonBattle!.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "queue.h"
#include <string>
#include "contestent.h"
#include <ctime>
#include <cstdlib>

using namespace std;
int main()
{
  srand(time(NULL));//random seed to ensure codemon and weather are shuffled differently every run
  queue<string> ListofConstestents;//list of contestents in queue
  char AnotherUser = 'y';
  char Fight = 'y';
  char Remove = 'y';
  string tempName = "";
  while ((AnotherUser == 'y' || AnotherUser == 'Y'))//while user wants to add another round of contestents
  {
    cout << "Enter the name of the next contestent." << endl;
    getline(cin, tempName);
    ListofConstestents.pushBack(tempName);//puts contestent to back of line
    cout << "Enter the name of the opponent " << tempName << " will be facing! " << endl;
    getline(cin, tempName);
    ListofConstestents.pushBack(tempName);
    cout << "Would you like to enter another set of contestents?(y/n) " << endl;
    cin >> AnotherUser;
    cin.ignore();
    if (ListofConstestents.isArrayFilled() == true)//ensures queue is not full if user wants to add more contestents
    {
      cout << "Sorry you can have up to 100 contestents and you hav reached that limit" << endl;
      AnotherUser = 'n';
    }
  }
  cout << "\n" << endl;
  while (Fight == 'y' || Fight == 'Y')//runs as long as user wants to see more battles
  {
    cout << "Let's prepare for battle!\n" << endl;
    contestent Trainer1(0, ListofConstestents.peek());//creates a contestent from the name of first name in queue
    ListofConstestents.popFront();//removes that name
    contestent Trainer2(0, ListofConstestents.peek());//creates rival
    ListofConstestents.popFront();
    Trainer1.prepare(0);//adds codemon to part and thier corresponding skills 
    Trainer2.prepare(0);
    Trainer1 += Trainer1;//adds items to contestents backpack
    Trainer2 += Trainer2;
    cout << "Before we start does " << Trainer1.getName() << " remove an item/codemon from their party?(y/n)" << endl;
    cin >> Remove;
    while(Remove == 'y')//as long as user wants to keep removing codemon or items
    {
      Trainer1.partyRemove();//gives user oppurtonity to remove a codemoninfo member 
      Trainer1 -= Trainer1;//gives user oppurtonity to remove a iteminfo member
      cout << "Remove another item/codemon from party(y/n)?" << endl;
      cin >> Remove;
    }
    cout << "Before we start does " << Trainer2.getName() << " remove an item/codemon from their party?(y/n)" << endl;
    cin >> Remove;
    while (Remove == 'y')
    {
      Trainer2.partyRemove();
      Trainer2 -= Trainer2;
      cout << "Remove another item/codemon from party(y/n)?" << endl;
      cin >> Remove;
    }
    if (Trainer1.getVolume() >= Trainer2.getVolume())//louder contestent goes first 
    {
     
      cout << Trainer1.getName() << " calls going first with his loud voice!" << endl;
      contestent winner = Trainer1 * Trainer2;//battle occurs int overloaded * operator winner = winner of battle
    }
    else if (Trainer1.getVolume() < Trainer2.getVolume())
    {

      cout << Trainer2.getName() << " calls going first with his loud voice!" << endl;
      contestent winner = Trainer2 * Trainer1;
    }
    
    
    if (ListofConstestents.isArrayEmpty() == true)//makes sure queue is not empty if user wanta another battle
    {
      cout << "Sorry no more contestents remain to battle" << endl;
      break;
    }
    cout << "Would you like to start another battle? (y/n)" << endl;
    cin >> Fight;
  }


  return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
