#include <iostream>
#include <sqlite3.h>
#include <algorithm>

using namespace std;

void tableGatherName();
void tableAddCol();

string dbName, dbLocation, pathBuilder, tableName;

void newDBnewTable(string Name, string Location)
{
	dbName = Name;
	dbLocation = Location;
	pathBuilder = dbLocation + "\\\\" + dbName;
	tableGatherName();
}

void tableSelectDB()
{
	//display list of databases
	//gather db name & db location
	tableGatherName();
}

void tableGatherName()
{
	bool valid = false;
	while (!valid)
	{
		cout << "Table name: ";
		cin >> tableName;
		bool correct = true;
		while (correct)
		{
			cout << "Creating table named " + tableName + " is that right? <Y/N>";
			string input;
			cin >> input;
			if (input == "y" || "yes")
			{
				tableAddCol();
				valid = true;
				correct = false;
			}
			if (input == "n" || "no")
			{
				correct = false;
			}
			else
			{
				cerr << "Invalid input select from Yes or No";
			}
		}
	}
}

void tableAddCol()
{

}