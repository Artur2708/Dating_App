#include "File.h"

void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}

void SetColor(int text, int background = 0)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}


void File::Recording(Person& obj)
{
	fstream datafile;
	datafile.open("Person.txt", ios::out | ios::app);
	try
	{

		if (!datafile) throw "Нет файла.";
		datafile << obj.get_ID() << '/' << obj.get_age() << '/' << obj.get_gender() << '/'<< obj.get_education() << '/' << obj.get_city() << '/' << obj.get_size()<<'/';
		for (int i = 0; i < (int)obj.interests.size(); i++)
		{
			datafile << obj.get_interests()[i] << '.';
		}
		datafile << endl;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	datafile.close();
}

void File::Recording(Preferences& obj)
{
	fstream datafile;
	datafile.open("Preferences.txt", ios::out | ios::app);
	try
	{
		if (!datafile) throw "Нет файла.";
		datafile << obj.get_ID() << '/' << obj.get_age() << '/' << obj.get_gender() << '/'<< obj.get_education() << '/' << obj.get_city() << '/' << obj.get_size() << '/';
		for (int i = 0; i < (int)obj.interests.size(); i++)
		{
			datafile << obj.get_interests()[i] << '.';
		}
		datafile << endl;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	datafile.close();

}

void File::Recording()
{
	fstream datafile;
	datafile.open("IDs.txt", ios::out);
	try
	{
		if (!datafile) throw "Нет файла.\n";
		datafile << Person::IDs << endl;
		datafile << Person::if_delete_or_size << endl;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	datafile.close();
}


Person* File::Reading(Person* obj, map<int, Person> person_map_, map<int, Person>::iterator it,bool n = true )
{
	obj = new Person[Person::if_delete_or_size];
	int pos{};
	string str;
	ifstream inputfile;
	inputfile.open("Person.txt");
	try
	{
		if (!inputfile) throw "Нет файла.\n";
		for (int i = 0; i < Person::if_delete_or_size; i++)
		{
			getline(inputfile, str);
			pos = str.find('/');
			obj[i].ID = stoi(str.substr(0, pos)); // положили ID
			str.erase(0, pos + 1);
			pos = str.find('/');
			obj[i].age = stoi(str.substr(0, pos)); // положили возраст
			str.erase(0, pos + 1);
			pos = str.find('/');
			obj[i].gender = *str.substr(0, pos).c_str(); // положили пол
			str.erase(0, pos + 1);
			pos = str.find('/');
			obj[i].education = str.substr(0, pos); // положили образование
			str.erase(0, pos + 1);
			pos = str.find('/');
			obj[i].city = str.substr(0, pos); // положили город
			str.erase(0, pos + 1);
			pos = str.find('/');
			obj[i].size = stoi(str.substr(0, pos)); // положили размер
			str.erase(0, pos + 1);
			for (int j = 0; j < obj[i].size; j++)
			{
				pos = str.find('.');
				obj[i].interests.push_back(str.substr(0, pos));
				str.erase(0, pos + 1);
			}
			if (n == false)
			{
				pair<int, Person> element(obj[i].get_ID(), obj[i]);
				person_map_.insert(element);
			}
		}
		if (n == false)
		{
			int y = 8;
			for (it = person_map_.begin(); it != person_map_.end(); ++it)
			{
				gotoxy(0, y);
				cout << it->second << endl;
				y += 7;
			}
		}
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	inputfile.close();
	return obj;
}

Preferences* File::Reading(Preferences* obj, map<int, Preferences> preferences_map_, map<int, Preferences>::iterator ti, bool n = true)
{
	
	obj = new Preferences[Person::if_delete_or_size];
	int pos{};
	string str;
	ifstream inputfile;
	inputfile.open("Preferences.txt");
	try
	{
		if (!inputfile) throw "Нет файла.\n";
		for (int i = 0; i < Person::if_delete_or_size; i++)
		{
			getline(inputfile, str);
			pos = str.find('/');
			obj[i].ID = stoi(str.substr(0, pos)); // положили ID
			str.erase(0, pos + 1);
			pos = str.find('/');
			obj[i].age = stoi(str.substr(0, pos)); // положили возраст
			str.erase(0, pos + 1);
			pos = str.find('/');
			obj[i].gender = *str.substr(0, pos).c_str(); // положили пол
			str.erase(0, pos + 1);
			pos = str.find('/');
			obj[i].education = str.substr(0, pos); // положили образование
			str.erase(0, pos + 1);
			pos = str.find('/');
			obj[i].city = str.substr(0, pos); // положили город
			str.erase(0, pos + 1);
			pos = str.find('/');
			obj[i].size = stoi(str.substr(0, pos)); // положили размер
			str.erase(0, pos + 1);
			for (int j = 0; j < obj[i].size; j++)
			{
				pos = str.find('.');
				obj[i].interests.push_back(str.substr(0, pos));
				str.erase(0, pos + 1);
			}
			if (n == false)
			{
				pair<int, Preferences> element(obj[i].get_ID(), obj[i]);
				preferences_map_.insert(element);
			}

		}
		if (n == false)
		{
			int y = 8;
			for (ti = preferences_map_.begin(); ti != preferences_map_.end(); ++ti)
			{
				gotoxy(0, y);
				cout << ti->second << endl;
				y += 7;
			}
		}
		
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	inputfile.close();
	return obj;
}

void File::Reading()
{
	int num;
	ifstream inputfile;
	inputfile.open("IDs.txt");
	try
	{
		if (!inputfile) throw "Нет файла.\n";
		inputfile >> num;
		Person::IDs = num;
		inputfile >> num;
		Person::if_delete_or_size = num;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	inputfile.close();
}

void File::Check_in(Person* mass_person, Preferences* mass_preferences)
{
	int remote_{};
	int size{};
	int num{};
	do
	{
		try
		{
			cout << "Сколько пользователей зарегистрировать: ";
			cin >> num;
			if (num > 3) throw "За один раз максимально можно зарегистрировать до 3х пользователей.\n";
			if(num < 1) throw "Минимально можно зарегистрировать 1го пользователя.\n";
		}
		catch (const char*str)
		{
			cout << str << endl;
		}
	} while (num>3 || num<1);
	mass_person = new Person[num];
	mass_preferences = new Preferences[num];
	for (int i = 0; i < num; i++)
	{
		system("cls");
		SetColor(14);
		cout << "Анкета " << i+1 << " пользователя";
		SetColor(7);
		cout << endl;
		cout << "Заполнение анкеты: \n";
		size = size_interests();
		mass_person[i] = Person(age(), gender(), city(), education(), interests_(size));
		cout << "Заполнение пожеланий:\n";
		size = size_interests();
		mass_preferences[i] = Preferences(age(), gender(), city(), education(), interests_(size), mass_person[i].get_ID());
		remote_ = File::Delete_ID();
		if (remote_)
		{
			mass_person[i].Set_ID(remote_);
			mass_preferences[i].Set_ID(remote_);
		}
		Recording(mass_person[i]);
		Recording(mass_preferences[i]);
	}
	system("cls");
	for (int i = 0; i < num; i++)
	{
		cout << "Анкета" << endl;
		cout << mass_person[i] << endl;
		cout << "Пожелания" << endl;
		cout << mass_preferences[i] << endl;
	}
	system("pause");
	system("cls");
	Recording();
}

void File::RemoveFile()
{
	char remove_Person[50] = "Person.txt";
	if (remove(remove_Person) != 0)cout << "Файл не удалён." << endl;
	char remove_Preferences[50] = "Preferences.txt";
	if (remove(remove_Preferences) != 0)cout << "Файл не удалён." << endl;
}

void File::Сomparison_and_conclusion(Person* mass_person, Preferences* mass_preferences, map<int, Person> person_map_, map<int, Preferences> preferences_map_, map<int, Preferences>::iterator ti, map<int, Person>::iterator it,int id)
{
	id = User_ID();
	if (id != -1)
	{
		int count{};
		multimap<int, Person> Candidate;
		mass_person = new Person[Person::if_delete_or_size];
		mass_preferences = new Preferences[Person::if_delete_or_size];
		mass_person = Reading(mass_person, person_map_,it);
		mass_preferences = Reading(mass_preferences, preferences_map_,ti);
		for (int i = 0; i < Person::if_delete_or_size; i++)
		{
			person_map_.insert(pair<int, Person>(mass_person[i].get_ID(), mass_person[i]));
			preferences_map_.insert(pair<int, Preferences>(mass_person[i].get_ID(), mass_preferences[i]));
		}
		ti = preferences_map_.find(id);
		it = person_map_.find(id);
		int k = 1;
		char en = 0;
		do
		{
			system("color 80");
			cout << endl;
			if (en == 80)
			{
				k++;
				if (k == 7)
					k = 1;
			}
			if (en == 72)
			{
				k--;
				if (k == 0)
					k = 6;
			}
			if (en == 13)
			{
				system("cls");
				gotoxy(0, 0);
				Show(it);
				Show(ti);
				switch (k)
				{
				case 1:
				{
					Search_all(count, ti, mass_person, Candidate);
				}break;
				case 2:
				{
					Search_age(count, ti, mass_person, Candidate);
				}break;
				case 3:
				{
					Search_city(count, ti, mass_person, Candidate);
				}break;
				case 4:
				{
					Search_interests(count, ti, mass_person, Candidate);
				}break;
				case 5:
				{
					Search_age_and_city(count, ti, mass_person, Candidate);
				}break;
				default:
					break;
				}
				if (k == 6)break;
				system("pause");
				system("cls");
			}
			gotoxy(28, 0);
			SetColor(12);
			cout << "Поиск по критериям.";
			SetColor(7);
			if (k == 1)
				SetColor(13);
			gotoxy(15, 2);
			cout << "1 - Найти по всем параметрам." << endl;
			SetColor(7);

			if (k == 2)
				SetColor(13);
			gotoxy(15, 3);
			cout << "2 - Найти по возрасту." << endl;
			SetColor(7);

			if (k == 3)
				SetColor(13);
			gotoxy(15, 4);
			cout << "3 - Найти по городу." << endl;
			SetColor(7);
			if (k == 4)
				SetColor(13);
			gotoxy(15, 5);
			cout << "4 - Найти по интересам." << endl;
			SetColor(7);

			if (k == 5)
				SetColor(13);
			gotoxy(15, 6);
			cout << "5 - Найти по городу и возрасту." << endl;
			SetColor(7);

			if (k == 6)
				SetColor(13);
			gotoxy(15, 7);
			cout << "6 - Выход." << endl;
			SetColor(7);
		} while (en = _getch());
	}
	else Sleep(3000);
	system("cls");
	
}

void File::Search_all(int count, map<int, Preferences>::iterator ti, Person* mass_person, multimap<int, Person> Candidate)
{
	
	for (int i = 0; i < Person::if_delete_or_size; i++)
	{
		count = 0;
		if (ti->first != mass_person[i].get_ID()&& ti->second.get_age() + 5 > mass_person[i].get_age() && ti->second.get_age() - 5 < mass_person[i].get_age()&& ti->second.get_gender() == mass_person[i].get_gender()&& ti->second.get_city() == mass_person[i].get_city() && ti->second.get_education() == mass_person[i].get_education())
		{
			if (ti->second.get_age() + 5 > mass_person[i].get_age() && ti->second.get_age() - 5 < mass_person[i].get_age())count++;
			if (ti->second.get_gender() == mass_person[i].get_gender())count++;
			if (ti->second.get_city() == mass_person[i].get_city())count++;
			if (ti->second.get_education() == mass_person[i].get_education())count++;
			if (ti->second.get_interests().size() >= mass_person[i].interests.size())
			{
				for (int s = 0; s < (int)ti->second.get_interests().size(); s++)
				{
					for (int j = 0; j < (int)mass_person[i].interests.size(); j++)
					{
						if (ti->second.get_interests()[s] == mass_person[i].interests[j])count++;
					}
				}
			}
			if (ti->second.get_interests().size() < mass_person[i].interests.size())
			{
				for (int s = 0; s < (int)mass_person[i].interests.size(); s++)
				{
					for (int j = 0; j < (int)ti->second.get_interests().size(); j++)
					{
						if (ti->second.get_interests()[j] == mass_person[i].interests[s])count++;
					}
				}
			}
			if (count > 0)Candidate.insert(pair<int, Person>(count, mass_person[i]));
		}

	}
	if (Candidate.size() > 0)
	{
		multimap<int, Person>::reverse_iterator can = Candidate.rbegin();
		SetColor(5);
		cout << "\nПретенденты:\n\n";
		SetColor(0, 8);
		for (; can != Candidate.rend(); can++)
		{
			SetColor(6);
			cout <<"Количество совпадений: " << can->first << endl;
			SetColor(0, 8);
			cout << can->second << endl << endl;
		}
	}
	else
	{
		SetColor(5);
		cout << "Нет подходящих кандидатов.\n\n";
		SetColor(0, 8);
	}
	
}

void File::Search_age(int count, map<int, Preferences>::iterator ti, Person* mass_person, multimap<int, Person> Candidate)
{
	for (int i = 0; i < Person::if_delete_or_size; i++)
	{
		count = 0;
		if (ti->first != mass_person[i].get_ID() && ti->second.get_gender() == mass_person[i].get_gender()&& ti->second.get_age() + 5 > mass_person[i].get_age() && ti->second.get_age() - 5 < mass_person[i].get_age())count++;
		if (count > 0)Candidate.insert(pair<int, Person>(count, mass_person[i]));
	}
	if (Candidate.size() > 0)
	{
		multimap<int, Person>::iterator can = Candidate.begin();
		SetColor(5);
		cout << "\nПретенденты:\n\n";
		SetColor(0,8);
		for (; can != Candidate.end();  can++)
		{
			cout << can->second << endl << endl;
		}
	}
	else
	{
		SetColor(5);
		cout << "Нет подходящих кандидатов.\n\n";
		SetColor(0, 8);
	}
}

void File::Search_city(int count, map<int, Preferences>::iterator ti, Person* mass_person, multimap<int, Person> Candidate)
{
	for (int i = 0; i < Person::if_delete_or_size; i++)
	{
		count = 0;
		if (ti->first != mass_person[i].get_ID() && ti->second.get_gender() == mass_person[i].get_gender() && ti->second.get_city() == mass_person[i].get_city())count++;
		if (count > 0)Candidate.insert(pair<int, Person>(count, mass_person[i]));
	}
	if (Candidate.size() > 0)
	{
		multimap<int, Person>::iterator can = Candidate.begin();
		SetColor(5);
		cout << "\nПретенденты:\n\n";
		SetColor(0, 8);
		for (; can != Candidate.end();  can++)
		{
			cout << can->second << endl << endl;
		}
	}
	else
	{
		SetColor(5);
		cout << "Нет подходящих кандидатов.\n\n";
		SetColor(0, 8);
	}
}

void File::Search_interests(int count, map<int, Preferences>::iterator ti, Person* mass_person, multimap<int, Person> Candidate)
{
	for (int i = 0; i < Person::if_delete_or_size; i++)
	{
		count = 0;
		if (ti->first != mass_person[i].get_ID() && ti->second.get_gender() == mass_person[i].get_gender())
		{
			if (ti->second.get_interests().size() >= mass_person[i].interests.size())
			{
				for (int s = 0; s < (int)ti->second.get_interests().size(); s++)
				{
					for (int j = 0; j < (int)mass_person[i].interests.size(); j++)
					{
						if (ti->second.get_interests()[s] == mass_person[i].interests[j])count++;
					}
				}
			}
			if (ti->second.get_interests().size() < mass_person[i].interests.size())
			{
				for (int s = 0; s < (int)mass_person[i].interests.size(); s++)
				{
					for (int j = 0; j < (int)ti->second.get_interests().size(); j++)
					{
						if (ti->second.get_interests()[j] == mass_person[i].interests[s])count++;
					}
				}
			}
			if (count > 0)Candidate.insert(pair<int, Person>(count, mass_person[i]));
		}

	}
	if (Candidate.size() > 0)
	{
		multimap<int, Person>::reverse_iterator can = Candidate.rbegin();
		SetColor(5);
		cout << "\nПретенденты:\n\n";
		SetColor(0, 8);
		for (; can != Candidate.rend(); can++)
		{
			SetColor(6);
			cout << "Количество совпадений: " << can->first;
			SetColor(0, 8);
			cout << endl;
			cout << can->second << endl << endl;
		}
	}
	else
	{
		SetColor(5);
		cout << "Нет подходящих кандидатов.\n\n";
		SetColor(0, 8);
	}
}

void File::Search_age_and_city(int count, map<int, Preferences>::iterator ti, Person* mass_person, multimap<int, Person> Candidate)
{
	for (int i = 0; i < Person::if_delete_or_size; i++)
	{
		count = 0;
		if (ti->first != mass_person[i].get_ID() && ti->second.get_gender() == mass_person[i].get_gender() && ti->second.get_age() + 5 > mass_person[i].get_age() && ti->second.get_age() - 5 < mass_person[i].get_age() && ti->second.get_city() == mass_person[i].get_city())
		{
			if (ti->second.get_city() == mass_person[i].get_city() && ti->second.get_age() + 5 > mass_person[i].get_age() && ti->second.get_age() - 5 < mass_person[i].get_age())count++;

		}
		if (count > 0)Candidate.insert(pair<int, Person>(count, mass_person[i]));
	}
	if (Candidate.size() > 0)
	{
		multimap<int, Person>::iterator can = Candidate.begin();
		SetColor(5);
		cout << "\nПретенденты:\n\n";
		SetColor(0, 8);
		for (; can != Candidate.end(); can++)
		{
			cout << can->second << endl << endl;
		}
	}
	else
	{
		SetColor(5);
		cout << "Нет подходящих кандидатов.\n\n";
		SetColor(0, 8);
	}
}

void File::Reading_Person_or_Preferences(Person* obj, Preferences* obj1, map<int, Person> person_map_, map<int, Preferences> preferences_map_, map<int, Preferences>::iterator ti, map<int, Person>::iterator it)
{
	int k = 1;
	char en = 0;
	do
	{
		system("color 80");
		cout << endl;
		if (en == 80)
		{
			k++;
			if (k == 4)
				k = 1;
		}
		if (en == 72)
		{
			k--;
			if (k == 0)
				k = 3;
		}
		if (en == 13)
		{
			system("cls");
			switch (k)
			{
			case 1:
			{
				Reading(obj, person_map_, it, false);
			}break;
			case 2:
			{
				Reading(obj1, preferences_map_, ti, false);
			}break;
			default:
				break;
			}
			if(k==3)break;
		}
		gotoxy(28, 0);
		SetColor(5);
		cout << "Посмотреть пользователей";
		SetColor(7);
		if (k == 1)
			SetColor(9);
		gotoxy(15, 2);
		cout << "1 - Посмотреть все анкеты пользователей." << endl;
		SetColor(7);

		if (k == 2)
			SetColor(9);
		gotoxy(15, 3);
		cout << "2 - Посмотреть все пожелания пользователей." << endl;
		SetColor(7);
		if (k == 3)
			SetColor(9);
		gotoxy(15, 4);
		cout << "3 - Выход." << endl;
		SetColor(9);
	} while (en = _getch());
	system("cls");
}

void File::Delet_user_File(int id)
{
	fstream datafile;
	datafile.open("Delete_User.txt", ios::out | ios::app);
	try
	{
		if (!datafile) throw "Нет файла.\n";
		datafile << id << endl;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
}

int File::User_ID()
{
	int id{};
	int tmp{};
	ifstream inputfile;
	inputfile.open("Delete_User.txt");
	try
	{
		cout << "Введите ваш ID: ";
		cin >> id;
		if(id <=0) throw "Ошибка. Повторите ввод!\n";
		if (id > Person::IDs) throw "Пользователь не зарегистрирован!\n";
		if (!inputfile) throw "Нет файла.\n";
		while (inputfile>> tmp)
		{
			inputfile >> tmp;
			if (id == tmp)
			{
				id = -1;
				throw "Этот пользователь удалён";
			}
		}
	}
	catch (const char* str)
	{
		cout << str << endl;
		id = -1;
	}
	inputfile.close();
	return id;
}

int File::Delete_ID()
{
	int num;
	int count{};
	ifstream inputfile;
	inputfile.open("Delete_User.txt");
	try
	{
		if (!inputfile) throw "Нет файла.\n";
		while (inputfile >> num)
		{
			count++;
		}
		inputfile.close();
		if (count > 0)
		{
			vector<int> del;
			inputfile.open("Delete_User.txt");
			while (inputfile >> num)
			{
				del.push_back(num);
			}
			count -= 1;
			inputfile.close();
			char remove_Delete_User[50] = "Delete_User.txt";
			if (remove(remove_Delete_User) != 0)cout << "Файл не удалён" << endl;
			fstream datafile;
			datafile.open("Delete_User.txt", ios::out);
			try
			{
				if (!datafile) throw "Нет файла.";
				for (int i = 1; i <= count; i++)
				{
					datafile << del[i] << endl;
				}
			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			datafile.close();
			return del.front();


		}
		else return 0;


	}
	catch (const char* str)
	{
		cout << str << endl;
		inputfile.close();
	}
	return 0;
}

void File::Delete_User(int id, Person* mass_person, Preferences* mass_preferences, map<int, Person> person_map_, map<int, Preferences> preferences_map_, map<int, Preferences>::iterator ti, map<int, Person>::iterator it)
{
	if (Person::if_delete_or_size <= 0) cout << "Нет пользователей.\n";
	else
	{
		id = User_ID();
		if (id != -1)
		{
			system("color 80");
			Delet_user_File(id);
			Person* mass_tmp_person = new Person[Person::if_delete_or_size];
			Preferences* mass_tmp_preferences = new Preferences[Person::if_delete_or_size];
			mass_person = new Person[Person::if_delete_or_size];
			mass_preferences = new Preferences[Person::if_delete_or_size];
			mass_tmp_person = Reading(mass_person, person_map_,it);
			mass_tmp_preferences = Reading(mass_preferences, preferences_map_,ti);
			for (int i = 0; i < Person::if_delete_or_size; i++)
			{
				person_map_.insert(pair<int, Person>(mass_tmp_person[i].get_ID(), mass_tmp_person[i]));
				preferences_map_.insert(pair<int, Preferences>(mass_tmp_person[i].get_ID(), mass_tmp_preferences[i]));
			}
			it = person_map_.find(id);
			ti = preferences_map_.find(id);
			int index{};
			for (; index < Person::if_delete_or_size; )
			{
				if (it->first == mass_tmp_person[index].get_ID())
				{
					break;
				}
				index += 1;
			}
			if (index < Person::if_delete_or_size && index >= 0)
			{
				if (mass_person)
				{
					for (int i = 0; i < Person::if_delete_or_size; i++)
					{
						mass_person[i] = mass_tmp_person[i];
						mass_preferences[i] = mass_tmp_preferences[i];
					}
					Person::if_delete_or_size -= 1;
					delete[]mass_tmp_person;
					mass_tmp_person = new Person[Person::if_delete_or_size];
					for (int i = 0; i < Person::if_delete_or_size; i++)
					{
						if (i < index)
						{
							mass_tmp_person[i] = mass_person[i];
							mass_tmp_preferences[i] = mass_preferences[i];
						}
						else if (i >= index)
						{
							mass_tmp_person[i] = mass_person[i + 1];
							mass_tmp_preferences[i] = mass_preferences[i + 1];
						}
					}
				}

			}
			RemoveFile();
			for (int i = 0; i < Person::if_delete_or_size; i++)
			{
				Recording(mass_tmp_person[i]);
				Recording(mass_tmp_preferences[i]);
			}
			cout << "Пользователь удален.\n";
		}
		Sleep(3000);
	}
	Recording();
	system("cls");
}
void File::Show(map<int, Preferences>::iterator ti)
{
	
	SetColor(5);
	cout << "Ваши пожелания:\n";
	SetColor(8);
	cout << "Ваш ID номер: " << ti->second.get_ID() << endl;
	cout << "Возраст: " << ti->second.get_age() << endl;
	cout << "Пол: " << ti->second.get_gender() << endl;
	cout << "Город: " << ti->second.get_city() << endl;
	cout << "Образование: " << ti->second.get_education() << endl;
	cout << "Интересы: ";
	for (int i = 0; i < (int)ti->second.get_interests().size(); i++)
	{
		cout << ti->second.get_interests()[i] << " ";
	}
	cout << endl << endl;
}

void File::Show(map<int, Person>::iterator it)
{
	SetColor(5);
	cout << "Ваша анкета:\n";
	SetColor(8);
	cout << "Ваш ID номер: " << it->second.get_ID() << endl;
	cout << "Ваш возраст: " << it->second.get_age() << endl;
	cout << "Ваш пол: " << it->second.get_gender() << endl;
	cout << "Город: " << it->second.get_city() << endl;
	cout << "Образование: " << it->second.get_education() << endl;
	cout << "Ваши интересы: ";
	for (int i = 0; i < (int)it->second.get_interests().size(); i++)
	{
		cout << it->second.get_interests()[i] << " ";
	}
	cout << endl << endl;
}

int File::size_interests()
{
	int size{};
	do
	{
		try
		{
			cout << "Введите сколько интересов вы хотите ввести: ";
			cin >> size;
			if (size < 1 || size >3) throw "Данные введены вне диапазона. От 1 до 3. Введите правильные данные!";
		}
		catch (const char* str)
		{
			cout << str << endl;
		}
	} while (size < 1 || size >3);
	return size;
}

vector <string> File::interests_(int size)
{
	int choise;
	vector <string> interests;
	string tmp;
	cout << "Введите интересы через Enter\n";
	choise = getchar();
	for (int i = 0; i < size; i++)
	{
		getline(cin, tmp);
		interests.push_back(tmp);
	}
	return interests;
}

int File::age()
{
	int age_{};
	do
	{
		try
		{
			cout << "Введите возраст: ";
			cin >> age_;
			if (age_ < 18) throw "Приложение только для совершеннолетних!";
			if (age_ > 100) throw "Возраст может быть до 100 лет.";
		}
		catch (const char* str)
		{
			cout << str << endl;
		}
	} while (age_ < 18 || age_ > 100);
	return age_;
}

char File::gender()
{
	char s{};
	do
	{
		try
		{
			cout << "Введите пол(в формате М - мужской или Ж - женский): ";
			cin >> s;
			if (s != 'М' && s != 'Ж') throw "Данные введены не правильно. Введите ещё раз.";
		}
		catch (const char* str)
		{
			cout << str << endl;
		}
	} while (s != 'М' && s != 'Ж');
	return s;
}

string File::city()
{
	int choise{};
	string city,tmp;
	ifstream inputfile;
	inputfile.open("city2.txt");
	do
	{
		try
		{
			cout << "Введите город: ";
			choise = getchar();
			getline(cin, city);
			if (!inputfile) throw "Нет файла.\n";
			while (!inputfile.eof())
			{
				getline(inputfile, tmp);
				if (city == tmp)break;
			}
			if (city != tmp) throw "Допустнимы города только Украины!";
			
		}
		catch (const char* str)
		{
			cout << str << endl;
		}
	} while (city != tmp);
	inputfile.close();
	return city;
}

string File::education()
{
	string education{};
	do
	{
		try
		{
			cout << "Введите какое образование(Высшее, Среднее): ";
			cin >> education;
			if (education != "Высшее" && education != "Среднее") throw "Неправильно введены данные. Попробуйте ещё раз.";
		}
		catch (const char* str)
		{
			cout << str << endl;
		}
	} while (education != "Высшее" && education != "Среднее");
	return education;
}




void File::Menu()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int id{};
	Person* mass_person = nullptr;
	Preferences* mass_preferences = nullptr;
	map<int, Person> person_map_;
	map<int, Preferences> preferences_map_;
	map<int, Person>::iterator it;
	map<int, Preferences>::iterator ti;
	int k = 1;
	char en = 0;
	do
	{
		system("color 80");
		system("cls");
		Reading();
		cout << endl;
		if (en == 80)
		{
			k++;
			if (k == 6)
				k = 1;
		}
		if (en == 72)
		{
			k--;
			if (k == 0)
				k = 5;
		}
		if (en == 13)
		{
			system("cls");
			switch (k)
			{
			case 1:
			{
				Check_in(mass_person, mass_preferences);
			}break;
			case 2:
			{
				Reading_Person_or_Preferences(mass_person, mass_preferences, person_map_, preferences_map_, ti, it);
			}break;
			case 3:
			{
				Сomparison_and_conclusion(mass_person, mass_preferences, person_map_, preferences_map_, ti, it, id);
			}break;
			case 4:
			{
				Delete_User(id, mass_person, mass_preferences, person_map_, preferences_map_, ti, it);
			}break;
			case 5: {exit(0); }break;
			default:
				break;
			}
		}
		gotoxy(28, 0);
		SetColor(12);
		cout << "Сваха";
		SetColor(7);
		if (k == 1)
			SetColor(4);
		gotoxy(15, 2);
		cout << "1 - Регистрация пользователя." << endl;
		SetColor(7);

		if (k == 2)
			SetColor(4);
		gotoxy(15, 3);
		cout << "2 - Просмотреть все анкеты и желания." << endl;
		SetColor(7);
		if (k == 3)
			SetColor(4);
		gotoxy(15, 4);
		cout << "3 - Поиск кандидатуры." << endl;
		SetColor(7);
		if (k == 4)
			SetColor(4);
		gotoxy(15, 5);
		cout << "4 - Удалить пользователя." << endl;
		SetColor(7);
		if (k == 5)
			SetColor(4);
		gotoxy(15, 6);
		cout << "5 - Выход." << endl;
		SetColor(7);
		if (mass_person != nullptr) { delete[] mass_person; mass_person = nullptr; }
		if (mass_preferences != nullptr) { delete[] mass_preferences; mass_person = nullptr; }
		person_map_.clear();
		preferences_map_.clear();
	} while (en = _getch());
}

File::~File()
{
}



