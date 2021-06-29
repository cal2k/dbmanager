#include <iostream>
#include <sqlite3.h>
#include <algorithm>

using namespace std;

void newDB();
static int createDB();
void addToDB();
void addTableToNewDB();
void newDBnewTable(string, string);

void cls() { system("cls"); }
void pause() { system("pause"); }

sqlite3* DB;
string dbName1, dbLocation1, pathBuilder1;
const char* dbManagerDB = "D:\\Documents\\Programming\\Databases\\dbManager.db";

size_t replace_all(string& inout, std::string_view what, std::string_view with)
{
	size_t count{};
	for (std::string::size_type pos{}; inout.npos != (pos = inout.find(what.data(), pos, what.length())); pos += with.length(), ++count)
	{
		inout.replace(pos, what.length(), with.data(), with.length());
	}

	return count;
}

static int createDB()
{
	const char* path = pathBuilder1.c_str();
	int exit = 0;
	exit = sqlite3_open(path, &DB);
	sqlite3_close(DB);
	return 0;
}

void addToDB()
{
	char* messageError;
	int exit = sqlite3_open(dbManagerDB, &DB);

	string sql("INSERT INTO databases (name, location) VALUES('" + dbName1 +"', '" + dbLocation1 + "\\\\')");
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK)
	{
		cerr << "Error inserting record";
		sqlite3_free(messageError);
	}
}

void addTableToNewDB()
{
	bool moreTables = true;

	while (moreTables)
	{
		cout << "Do you want to add a table? <Y/N>" << endl;
		string input;
		cin >> input;
		for_each(input.begin(), input.end(), [](char& c) {c = tolower(c);});
		if (input == "y" || "yes")
		{
			newDBnewTable(dbName1, dbLocation1);
		}
		if (input == "n" || "no")
		{
			moreTables = false;
		}
		else
		{
			cls();
		}
	}
}


void newDB()
{
	bool correct = false;
	string input;
	while (!correct)
	{
		cout << "Database name: ";
		cin >> dbName1;
		cout << "Database location: ";
		cin >> dbLocation1;
		cout << "Creating database name " << dbName1 << " at location " << dbLocation1 << endl;
		cout << "Are these details correct Y/N?" << endl;
		cin >> input;
		for_each(input.begin(), input.end(), [](char& c) {c = tolower(c);});

		if (input == "y" || "yes")
		{
			dbName1 = dbName1 + ".db";
			auto count = replace_all(dbLocation1, "\\", "\\\\");
			pathBuilder1 = dbLocation1 + "\\\\" + dbName1;
			createDB();
			addToDB();
			addTableToNewDB();
			cls();
			correct = true;
		}
		else
		{
			cls();
		}
	}
	cls();
}