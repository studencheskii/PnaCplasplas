#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<string, string> dict;
vector<string> vect;

void change_capital(const string &country, const string &new_capital)
{
	if (dict.count(country))
	{
		if (dict[country] == new_capital)
		{
			vect.push_back("Country " + country + " hasn't changed its capital");
		}
		else
		{
			vect.push_back("Country " + country + " has changed its capital from " + dict[country] + " to " + new_capital);
			dict[country] = new_capital;
				
		}
		return;
	}

	vect.push_back("Introduce new_country " + country + " with capital " + new_capital);
	dict[country] = new_capital;
}

void rename(string old_country_name, string new_country_name)
{
	auto iter = dict.find(old_country_name);
	if (iter != dict.end())
	{
		if (old_country_name == new_country_name || dict.count(new_country_name) != 0)
		{
			vect.push_back("Incorrect rename, skip");
			return;
		}
		else if (dict[old_country_name].size() > 0)
		{
			vect.push_back("Country " + old_country_name + " with capital " + dict[old_country_name] + " has been renamed to " + new_country_name);
			string value = iter->second;
			dict.erase(iter);
			dict[new_country_name] = value;
		}
	}
	else
	{
		vect.push_back("Incorrect rename, skip");
	}
}

void about(string country)
{
	auto iter = dict.find(country);
	if (iter != dict.end())
	{
		vect.push_back("Country " + iter->first + " has capital " + iter->second);
	}
	else
	{
		vect.push_back("Country " + country + " doesn't exist");
	}
}

void dump()
{
	if (dict.empty())
	{
		vect.push_back("There are no countries in the world");
		return;
	}
	string s;
	for (auto i = dict.begin(); i != dict.end(); ++i)
	{
		s += i->first + "/" + i->second + " ";
	}
	vect.push_back(s);

}

void apply()
{
	string instruction;
	cin >> instruction;
	if (instruction == "CHANGE_CAPITAL")
	{
		string country, capital;
		cin >> country >> capital;
		change_capital(country, capital);
	}
	else if (instruction == "RENAME")
	{
		string old_country, new_country;
		cin >> old_country >> new_country;
		rename(old_country, new_country);
	}
	else if (instruction == "ABOUT")
	{
		string country;
		cin >> country;
		about(country);
	}
	else if (instruction == "DUMP")
	{
		dump();
	}
}

int main()
{
	int count;
	cin >> count;
	if (count > 0)
	{
		for (int i = 0; i < count; i++)
		{
			apply();
		}
		cout << endl;
		for (string s : vect)
		{
			cout << s << endl;
		}
		vect.clear();
	}
}
