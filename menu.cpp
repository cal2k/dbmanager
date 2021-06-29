#include <iostream>

using namespace std;

void newDB();
void tableSelectDB();

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
			tableSelectDB();
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
		else
		{
			cerr << "Invalid Selection!\nselect from 1 - 6" << endl;
		}
	}
	return 0;
}

