#ifndef SKILLINFO_H
#define SKILLINFO_H
#include <iostream>
using namespace std;
class skillinfo
{
public:
	string getSname() { return SkillName; }//PRE: called whenever skill name needs to be outputted in battle, DESC: skill name of codemon, POST; returns skill name
	int getDamage() { return BaseDamage; }//PRE: called whenever skill damage needs to be outputted in battle, DESC: skill damage of codemon, POST; returns skill damage
	void setSname(const string SNAME);//PRE: called whenever codemon is being added DESC: sets inputted skill to skill name, POST: skill name has been created for codemon
	void setDamage(const int DAMAGE);//PRE: called whenever codemon is being added DESC: sets inputted skill attack to skill damage, POST: skill damage has been created for codemon
	skillinfo(const string name, const int Damage) { setSname(name); setDamage(Damage); }//stores a individual codemons individual skill ex: users 4th codmeons 5th skill

private:
	string SkillName;//name of skill
	int BaseDamage;//damage of skill
};
#endif

