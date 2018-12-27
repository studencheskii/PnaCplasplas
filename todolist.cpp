#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int current_month = 0;
vector<vector<string>> todolist(31);


void add(int i, const string &s)
{
	i--;
	int count_day = month[current_month];
	if(i >= 0 && i <= count_day)
	{
		todolist[i].push_back(s);
	}
}

void remove(int i, const string &s)
{
	i--;
	int count_day = month[current_month];
	if(i >= 0 && i <= count_day)
	{
		for(int j = 0; j < todolist[i].size(); j++)
		{
			if(todolist[i][j] == s)
			{
				todolist[i].erase(todolist[i].begin() + j);
			}
		}
	}
}

void next()
{
	int next_month = (current_month > 11) ? 0 : current_month + 1;
	int current_count_day = month[current_month];
	int new_count_day = month[next_month];
	if(new_count_day > current_count_day)
	{
		todolist.resize(new_count_day);
	}
	else
	{
		for(int i = new_count_day; i < current_count_day; i++)
		{
			for(auto item = todolist[i].begin(); item != todolist[i].end(); ++item)
			{
				todolist[new_count_day - 1].push_back(*item);
			}
		}
		todolist.erase(todolist.begin() + new_count_day, todolist.end());
		todolist.resize(new_count_day);
	}
	current_month++;
}

void dump(int i)
{
	i--;
	int count_day = month[current_month];
	if(i >= 0 && i <= count_day)
	{
		cout << todolist[i].size();
		for(auto todo : todolist[i])
		{
			cout << " " << todo;
		}
		cout << endl;
		return;
	}
	cout << "None day." << endl;
}

void Apply()
{
	for(auto instruction : instructions)
	{
		string op;
		int num;
		string doit;
		cin >> op;
	    if (op == "ADD") {
			cin >> num >> doit;
	        add(num, doit);
	    } else if (op == "REMOVE") {
			cin >> num >> doit;
	        remove(num, doit);
	    } else if (op == "NEXT") {
	        next();
	    } else if (op == "DUMP") {
			cin >> num;
	        dump(num);
	    }
	}
}

int main()
{
	int count_operation = -1;
	//string input;
	string todo;

	while(count_operation)
	{
		cout << "Вветиде q для выхода." << endl;
		cin >> count_operation;
		cin.ignore(32767,'\n');


		if(count_operation)
		{
			for(int i = 0; i < count_operation; i++)
			{
				Apply();
			}
			cout << "Что бы продолжить нажмите Enter" << endl;
			cin.get();
		}
	}
	return 0;
}
