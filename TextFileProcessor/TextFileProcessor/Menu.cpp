#include "stdafx.h"
#include "Menu.h"

using namespace std;

void menu()
{
	cout << "\033[2J\033[1;1H";		//clear screen

	int select;
	cout << "Please select an option by entering their corresponding number." << endl;
	cout << "1. Search text file" << endl;
	cout << "2. Choose text file" << endl;
	cout << "3. Options" << endl;
	cout << "4. Exit Program" << endl;
	cin >> select;

	//check user choice while it is not 4
	do
	{
		//execute the choice if the corresponding number is entered
		switch (select)
		{
		case 1:
			processText();
			break;
		case 2:
			listFiles();
			break;
		case 3:
			options();
			break;
		case 4:
			break;

		default:
			cout << "Please select one of the three choices.\n";
		}
	} while (select != 4);
}