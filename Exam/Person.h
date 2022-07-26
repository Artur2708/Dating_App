#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include <windows.h>
#include <map>
#include <Vector>
#include <conio.h>
using namespace std;

class Person 
{
protected:
	int size;
	int age; 
	int ID; 
	char gender; 
	string city; 
	string education; 
	vector <string> interests; 
public:
	Person();
	Person(int _age, char _gender, string _city, string _education, vector <string> _interests);
	virtual void Set_ID(int _id);
	friend ostream& operator <<(ostream& os, Person& obj);
	const int get_ID() const; 
	const int get_age() const;
	const int get_size() const;
	const char get_gender() const;
	const string get_city() const;
	const string get_education() const;
	const vector <string>  get_interests() const;
	static int IDs;
	static int if_delete_or_size;
	friend class File;
};



