// TextFileProcessor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkList.h"



using namespace std;

void processText();
void menu();
void listFiles();
void options();
void setFile(string);

int main()
{
	menu();
	return 0;
}

//shows a menu in which the user is able to select the choice that they want

//https://stackoverflow.com/questions/875249/how-to-get-current-directory
string getPath() 
{
	CHAR buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

//lists the available .txt files within the current directory
void listFiles()
{
	//gets directory of the compiled program
	

	string confirm;
	cout << "\033[2J\033[1;1H";		//clear screen
	map<int, string> files;
	int i = 1;
	int select;
	bool found = false;
	string path = getPath();
	string filePath;
	
	//check each file within the path to see which ones contain an '.txt' extenstion 
	for (auto& dir : experimental::filesystem::directory_iterator(path))
	{
		//if the path contains an '.txt' extension, add it to the map
		if (dir.path().extension() == ".txt")
		{
			//places file path within the map
			files.emplace(i,dir.path().string());
			cout << i++ << ". " << dir.path().filename() << endl;
			found = true;
		}
			
	}
	//if text file is or is not found display the corresponding message.
	if (found)
	{
		//repeat while select is not less or more than i
		do
		{
			cout << "Enter the corresponding number to select the text file that you to search." << endl;
			cin >> select;
		} while (!(select > i || select < i));
	}
	else
	{
		cout << "No text files found within directory." << endl;
		cout << "Please ensure that there are text files within the executables directory." << endl;
		cout << "Press enter to continue." << endl;
		cin >> confirm;
	}

	//find the user entered number within the files map
	auto it = files.find(select);
	//loop through the map until the user entered number is found
	for (it = files.begin(); it != files.end(); ++it)
		if (it->first == select)
			filePath = it->second;

	setFile(filePath);

	menu();
}

void options()
{

}

void setFile(string selectedFile)
{
	string path = selectedFile;
}

//write from text file each word into linked list node
void processText()
{
	ifstream file;
	string word;
	smatch m;
	regex ep("([[:punct:]])");
	WordList wl;
	string query;

	file.open("testfile.txt");
	
	//Writes from text file to linked list.
	while (file >> word)
	{
		//Checks if the word contains punctuation, if so, removes the punctuation.
		if (!regex_search(word, m, ep))
		{
			wl.addWord(word);
		}
		else
		{
			wl.addWord(regex_replace(word, ep, ""));
		}
	}
	file.close();
	cout << word;

	wl.listAllWords(cout);

	cout << "Please enter a word to search: ";
	//reads user search input
	cin >> query;
	wl.check(query);
}