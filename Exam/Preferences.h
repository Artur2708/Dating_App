#pragma once
#include "Person.h"
class Preferences : public Person
{
public:
	Preferences();
	Preferences(int _age, char _gender, string _city, string _education, vector <string> _interests, int _ID);
	virtual void Set_ID(int _id);
};

