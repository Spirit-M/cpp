// delete.cpp -- using the delete operator
#include <iostream>
#include <cstring>						// or string.h
//#pragma warning(disable:4996)			// use strcpy()
using namespace std;
char * getname(void);					// function prototype
int main()
{
	char * name;						// create ointer but no storage

	name = getname();					// assign address of string to name
	cout << name << " at " << (int *)name << "\n";
	delete[] name;						// memory freed

	name = getname();					// reuse freed memory
	cout << name << " at " << (int *)name << "\n";
	delete[] name;						// memory freed agian
//	cin.get();
	return 0;
}

char * getname()						// return pointer to new string
{
	char temp[80];						// temporary storage
	cout << "Enter last name: ";
	cin >> temp;
//	cin.get();
	char * pn = new char[strlen(temp) + 1];
	strcpy(pn, temp);					// copy string into smaller space

	return pn;							// temp lost when function ends
}