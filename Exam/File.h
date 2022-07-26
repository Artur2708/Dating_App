#include "Person.h"
#include "Preferences.h"
class File 
{
	
public:
	virtual ~File();
	static void Recording(Person& obj);
	static void Recording(Preferences& obj);
	static void Recording();
	static Person* Reading(Person* obj, map<int, Person> person_map_, map<int, Person>::iterator it, bool n);
	static Preferences* Reading(Preferences* obj, map<int, Preferences> preferences_map_, map<int, Preferences>::iterator ti, bool n);
	static void Reading();
	static void Check_in(Person* mass_person, Preferences* mass_preferences);
	static void RemoveFile();
	static void Ñomparison_and_conclusion(Person* mass_person, Preferences* mass_preferences, map<int, Person> person_map_, map<int, Preferences> preferences_map_, map<int, Preferences>::iterator ti, map<int, Person>::iterator it, int id);
	static void Search_all(int count, map<int, Preferences>::iterator ti, Person* mass_person, multimap<int, Person> Candidate);
	static void Search_age(int count, map<int, Preferences>::iterator ti, Person* mass_person, multimap<int, Person> Candidate);
	static void Search_city(int count, map<int, Preferences>::iterator ti, Person* mass_person, multimap<int, Person> Candidate);
	static void Search_interests(int count, map<int, Preferences>::iterator ti, Person* mass_person, multimap<int, Person> Candidate);
	static void Search_age_and_city(int count, map<int, Preferences>::iterator ti, Person* mass_person, multimap<int, Person> Candidate);
	static void Reading_Person_or_Preferences(Person* obj, Preferences* obj1, map<int, Person> person_map_, map<int, Preferences> preferences_map_, map<int, Preferences>::iterator ti, map<int, Person>::iterator it);
	static void Delet_user_File(int id);
	static int User_ID();
	static int Delete_ID();
	static void Delete_User(int id, Person* mass_person, Preferences* mass_preferences, map<int, Person> person_map_, map<int, Preferences> preferences_map_, map<int, Preferences>::iterator ti, map<int, Person>::iterator it);
	static void Show(map<int, Preferences>::iterator ti);
	static void Show(map<int, Person>::iterator it);
	static int size_interests();
	static vector <string> interests_(int size);
	static int age();
	static char gender();
	static string city();
	static string education();
	static void Menu();
	friend void gotoxy(short x, short y);
	friend void SetColor(int text, int background);
};


