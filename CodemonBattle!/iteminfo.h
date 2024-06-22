#ifndef ITEMINFO_H
#define ITEMINFO_H
#include <iostream>
using namespace std;
class iteminfo
{
public:
	string getIname() { return itemName; }
	string getDescription() { return itemDesc; }
	int getDuration() { return timeDuration; }
	void setIname(const string name);
	void setDescription(const string Desc);
	void setDuration(const int Time);
	iteminfo(const string Name, const string IDesc, const int TDuration) { setIname(Name); setDescription(IDesc); setDuration(TDuration); }
private:
	string itemName;
	string itemDesc;
	int timeDuration; //if -1 its permanent


};
#endif