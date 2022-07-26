#include "Person.h"
int Person::IDs{};
int Person::if_delete_or_size{};
Person::Person()
{
	size = 0;
	age = 0;
	ID = 0;
	gender = '\0';
	city = '\0';
	education = '\0';
	interests;
}

Person::Person(int _age, char _gender, string _city, string _education, vector <string> _interests)
{
	
	IDs += 1;
	if_delete_or_size += 1;
	ID = IDs;
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


void Person::Set_ID(int _id)
{
	ID = _id;
	IDs -= 1;
	
}

const int Person::get_ID() const
{
	return ID;
}

const int Person::get_age() const
{
	return age;
}

const int Person::get_size() const
{
	return size;
}

const char Person::get_gender() const
{
	return gender;
}

const string Person::get_city() const
{
	return city;
}

const string Person::get_education() const
{
	return education;
}

const vector <string> Person::get_interests() const
{
	return interests;
}




ostream& operator<<(ostream& os, Person& obj)
{
	cout << "ID номер: " << obj.ID << endl;
	cout << "Ваш возраст: " << obj.age << endl;
	cout << "Пол: " << obj.gender << endl;
	cout << "Город: " << obj.city << endl;
	cout << "Образование: " << obj.education << endl;
	cout << "Интересы: ";
	for (int i = 0; i < (int)obj.interests.size(); i++)
	{
		cout << obj.interests[i] << " ";
	}
	cout << endl;
	return os;
}


