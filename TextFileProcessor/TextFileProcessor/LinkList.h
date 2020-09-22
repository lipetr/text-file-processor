#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

class Node
{
private:
	string* word;          
	Node* next;            
public:
	Node();                
	Node(string text);
	void setNext(Node* nextNode);
	Node* getNext();
	string* getWord();
};


class WordList
{
private:
	Node* start, * end;

public:
	WordList();
	bool isEmpty();
	void addFirstWord(string text);
	void addWord(string text);
	void check(string query);
	void showResults(vector<string>& rList);
	void listAllWords(ostream& os);
};