#include "iteminfo.h"
#include <iostream>
using namespace std;
void iteminfo::setIname(const string name)
{
	itemName = name;
}
void iteminfo::setDescription(const string Desc)
{
	itemDesc = Desc;
}
void iteminfo::setDuration(const int Time)
{
	timeDuration = Time;
}


