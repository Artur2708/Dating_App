#include "Preferences.h"

Preferences::Preferences()
{
	size = 0;
	age = 0;
	ID = 0;
	gender = '\0';
	city = '\0';
	education = '\0';
	interests;
}

Preferences::Preferences(int _age, char _gender, string _city, string _education, vector <string> _interests, int _ID)
{
	
	ID = _ID;
	age = _age;
	gender = _gender;
	city = _city;
	education = _education;
	size = _interests.size();
	for (int i = 0; i < (int)_interests.size(); i++)
	{
		interests.push_back(_interests[i]);
	}
}

void Preferences::Set_ID(int _id)
{
	ID = _id;
}


