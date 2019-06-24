//  Lily Tang
//  main.cpp
//  Lab 6
// replace lab 1 score: 15/20 :(


#include <iostream>
#include <string>
#include <fstream>
#include "Hash.h"
#include "PERSON.h"

using namespace std;

bool isNumber(char n);
int formatBirth(string &b);
int objectsInFile(ifstream &file);

int main() {
    string full, first, last, birth;
    ifstream infile;
	char reply;
	do {
		cout << "\"InputData.txt\" is the default file\nDo you want to enter your own input text file? (y for yes, n for no):" << endl;
		cin >> reply;
	} while (reply != 'y' && reply != 'n');

	cout << endl;
	cin.ignore(256, '\n');
	string inFileName = "InputData.txt";

	if (reply == 'y') {
		do {
			cout << "Enter file path (ie Z:/MyDataFile) or filename (.txt will append automatically)" << endl;
			getline(cin, inFileName);
			inFileName += ".txt";
			infile.open(inFileName);
			if (infile.fail()) {
				cout << "\nError opening " << inFileName << ", check the name and try again" << endl;
			}
		} while (infile.fail());
		cout << "File " << inFileName << " successfully opened." << endl;
	}
	else {
		infile.open(inFileName);
		if (infile.fail())
		{
			cout << "Input file \"" << inFileName << "\" not found. Exiting the program." << endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	}
	int amt = objectsInFile(infile) * 1.1 + 1;
    HashMap<Person, int> *peopleHash = new HashMap<Person, int>(amt);
	infile.close();
	infile.open("InputData.txt");
	if (!infile) {
		cerr << "ERROR: file not found!" << endl;
		exit(1);
	}
    while (infile >> first >> last >> birth){
        full = first + " " + last;
        Person *p = new Person(full, birth);
        int b = formatBirth(birth);
        peopleHash->insert(*p, b);
        delete p;
    }
    cout << "Items loaded into hash map: " << peopleHash->getItems() << endl
    << "Load factor: " << peopleHash->getLoadFactor()<<"%" << endl << "Collisions: " << peopleHash->getCollisions() << endl;
	cout << "\nDisplaying Hash Map by Index: " << endl;
    peopleHash->display();
    char yn;
    string holdkey;
    int intkey;
	do {
		cout << "Would you like to search for a person by birth date? y/n: ";
		cin >> yn;
	} while (yn != 'y' && yn !='n');
	while (yn == 'y') {
		cout << "enter birth date (ie 2017-12-04): ";
		cin >> holdkey;
		intkey = formatBirth(holdkey);
		try {
			cout << peopleHash->search(intkey);
		}
		catch (const char *msg) {
			cerr << msg << endl;
		}
		cout << "Would you like to search another item? y/n: ";
		cin >> yn;
		if (yn == 'n' || yn == 'N')
			break;
		if (yn != 'y' && yn != 'n') {
			cout << "Please enter 'y' or 'n': ";
			cin >> yn;
		}
	}
	system("pause");
    return 0;
}

bool isNumber(char n){
    return (n >= '0'&&n <= '9');
}

int formatBirth(string &b){
    int digitsOnly = 0;
    for (char c : b){
        if (isNumber(c)) {
            digitsOnly = digitsOnly * 10 + (c - '0');
        }
    }
    return digitsOnly;
}

int objectsInFile(ifstream &file)
{
	int lines = 0;
	string holder;
	if (file)
	{
		while (!file.eof())
		{
			getline(file, holder);
			lines++;
		}
	}
	return lines/2;
}