#include "stdafx.h"
#include "LinkList.h"
#include <set>

Node::Node()
{
	word = NULL;  // default 
	next = NULL;		 // initialise next
}


Node::Node(string text)
{
	word = new string(text);  
	next = NULL;                  
}

void Node::setNext(Node* nextNode)
{
	next = nextNode;  // change next node
}

//return the next node
Node* Node::getNext()
{
	return next;
}

//return the word within node
string* Node::getWord()
{
	return word;
}

WordList::WordList()
{
	start = NULL;   // both set to NULL
	end = NULL;
}

//check if list is empty
bool WordList::isEmpty()
{
	return start == NULL;
}

//add word to the linked list head
void WordList::addFirstWord(string text)
{
	Node* current;
	current = new Node(text);  
	start = current;               
	end = current;				  
}


//add words to the linked list
void WordList::addWord(string text)
{
	Node* current;

	//check if list is empty
	if (end == NULL)       
		addFirstWord(text);
	else
	{
		current = new Node(text);   
		current->setNext(start);         
		start = current;                  
	}
}


//Check user search query then find the word within the linked list
void WordList::check(string query)
{
	Node* current = start;
	string result;
	bool found = false;
	regex wce("([*])");
	smatch match;
	vector<string> results;

	//check query for wildcard value, if wildcard found, replace it with ECMAScript syntax
	if (regex_search(query, match, wce))
	{
		//replaces '*' character with '.*' for regular expression use
		query = regex_replace(query, regex("[*]"), ".*");

	}
	
	//creates a regular expression with the value of the query
	//uses '\\b' word boundary syntax
	//search is set to case insensitive
	regex e("\\b"+query+"\\b", regex_constants::icase);	

	//while the linked list node has not reached the final node check if the query can be found
	while (current != end)
	{
		//check each word with the regular expression
		if (regex_search(*(current->getWord()), match, e))
		{
			//enter each match into a string vector
			for (int i = 0; i < match.size(); i++) 
			{
				results.push_back(match[i].str());
			}
			found = true;

		}
		//iterate to the next node
		current = current->getNext();
	}
	//if a result is found, display results
	if (found)
	{
		showResults(results);
	}
	else
	{
		cout << "Word was not found. " << endl;
	}

}

//display the words resulting from the query and their frequency
void WordList::showResults(vector<string>& rList)
{
	string match;
	int fre;
	int select;

	//end function if list is empty
	if (rList.empty())
	{
		cout << "The list is empty" << endl;
		cin.ignore();
		return;
	}

	//create a set of unique words
	set<string> uWord(rList.begin(), rList.end());

	//output the words and their frequency
	for (auto word : uWord)
	{
		//count the frequency of replicate words
		fre = count(rList.begin(), rList.end(), word);
		//if word occurs more than once, display the appropriate wording
		if (fre == 1)
			match = " match";
		else
			match= " matches";

		cout << word << "\t\t " << fre << match << endl;
	}

	//display result statistics
	cout << "Unique words: " << uWord.size() << endl;
	cout << "Total words: " << rList.size() << endl << endl;
	cout << "What would like to do?" <<  endl;
	cout << "1. Search for another word" << endl;
	cout << "2. Return to main menu" << endl;
	cin >> select;
	do
	{
		switch (select)
		{
		case 1:
			cout << "";
			break;
		case 2:
			break;

		default:
			cout << "Please enter the respective number of one of the choices above.\n";
		}
	} while (select != 2);
}


//display all of the stored words
void WordList::listAllWords(ostream & os)
{
	Node* current;
	//if the list is not empty, display the words
	if (!isEmpty())
	{
		cout << "Start of List" << endl;
		current = start;
		//while current node is not null, iterate through each word
		while (current != NULL)
		{
			//display the word
			cout << "Next word is: " << *(current->getWord()) << endl;
			//iterate to the next node
			current = current->getNext();
		}
		cout << "End of List" << endl << endl;
	}
	else
		cout << "List empty" << endl << endl;
}


