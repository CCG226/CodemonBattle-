#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
template <class T_contestent>
class queue
{
public:
	queue() : totalAmountOfObjects(0) {}//empty queue
	void pushBack(const T_contestent user);//PRE: called whenever user wants to enter two comptetitors into the queue line; DESC: takes an a contestent and add them to the line:POST: contestent is put to the back of the line,first come first serve
	bool isArrayFilled();//PRE: called whenver user wants to add more contestents, DESC: checks to see if an empty spots are availbe in queue line: POST: if no empty slots function returns true and user cannot add more contestents
	bool isArrayEmpty();//PRE: called after battle finishes and user wants to see another:DESC checks to see if their are two more contestents available to fight: PSOT: returns true if their are still contestents in line
	T_contestent peek() { return objects[FRONTOFLINE]; }//PRE: called whenever a contestent is being created. DESC: finds first contestent in line, POST: returns first contestent in queue making them a trainer for battle
	static int SIZE;
	static int ROTATELINE;
	void popFront();//PRE: after peek is called to create a contestent popback is called: DESC: removes used contestent from queue as they are now in battle: POST: first in line is now gone
private:
	int ENDOFLINE = -1;
	int FRONTOFLINE = 0;
	int totalAmountOfObjects; //keeps track a valid entries 
	T_contestent objects[100];
};
template <class T>
int queue<T>::SIZE = 100;
template <class T>
int queue<T>::ROTATELINE = 1;
template <class T_contestent>
void queue<T_contestent>::pushBack(const T_contestent user)
{
	totalAmountOfObjects++;//adds new object to total out of 100
	ENDOFLINE = (ENDOFLINE + ROTATELINE) % SIZE;//adds an object to end of valid objects in the queue by rotating the queue forward by 1 and geting that remainder from size to get last positon of contestents 
	objects[ENDOFLINE] = user;

}
template <class T_contestent>
bool queue<T_contestent>::isArrayFilled()
{
	int temp = 0;
	const int MAX = SIZE;
	for (int i = 0; i < MAX; i++)//counts empty slots and if empty slots = 100 queue is full.
	{
		if (objects[i] != "")
		{
			temp++;
		}
	}
	if (MAX == temp)
	{
		return true;
	}
	else
		return false;
}
template <class T_contestent>
bool queue<T_contestent>::isArrayEmpty()
{
	const int EMPTY = 0;
	if(totalAmountOfObjects == EMPTY)//no more valid objects left
	{
		return true;
	}
	return false;
}
template <class T_contestent>
void queue<T_contestent>::popFront()
{
	totalAmountOfObjects--;//contestent is dropped
	FRONTOFLINE = (FRONTOFLINE + ROTATELINE) % SIZE; //stays ahead of endofline by keeping track of object in the front of the line to remove after peek
}
#endif