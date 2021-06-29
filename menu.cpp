#include <iostream>
#include <algorithm>
#include <sqlite3.h>
#include <string_view>

using namespace std;

void newDB();
static void createDB(string);
void cls();
void pause();


sqlite3* DB;
string dbName, dbLocation;
const char* dbManagerDB = "D:\\Documents\\Programming\\Databases\\dbManager.db";


void cls() { system("cls"); }
void pause() { system("pause"); }

static void createDB(string pathBuilder)
{
	const char* path = pathBuilder.c_str();
	int exit = 0;
	exit = sqlite3_open(path, &DB);
	sqlite3_close(DB);
}

size_t replace_all(string& inout, std::string_view what, std::string_view with)
{
	size_t count{};
	for (std::string::size_type pos{}; inout.npos != (pos = inout.find(what.data(), pos, what.length())); pos += with.length(), ++count)
	{
		inout.replace(pos, what.length(), with.data(), with.length());
	}

	return count;
}

void newDB()
{
	bool correct = false;
	string input;
	while (!correct)
	{
		cout << "Database name: ";
		cin >> dbName;
		cout << "Database location: ";
		cin >> dbLocation;
		cout << "Creating database name " << dbName << " at location " << dbLocation << endl;
		cout << "Are these details correct Y/N?" << endl;

		cin >> input;
		for_each(input.begin(), input.end(), [](char& c) {c = tolower(c);});



		if (input == "y" || "yes")
		{
			dbName = dbName + ".db";
			auto count = replace_all(dbLocation, "\\", "\\\\");
			string pathBuilder = dbLocation + "\\\\" + dbName;
			createDB(pathBuilder);
			correct = true;
		}
		cls();
	}
}

int main()
{
	string menuOptions = "1 - View tables\n2 - View table content\n3 - Insert record\n4 - Create new table\n5 - Create new database\n6 - Exit";
	string input;
	bool valid = false;

	while (!valid)
	{
		cout << menuOptions << endl;
		cin >> input;

		if (input == "1") 
		{
		}
		if (input == "2")
		{
		}
		if (input == "3")
		{
		}
		if (input == "4")
		{
		}
		if (input == "5")
		{
			newDB();
		}
		if (input == "6")
		{
			valid = true;
			break;
		}
		system("cls");
	}
	return 0;
}

