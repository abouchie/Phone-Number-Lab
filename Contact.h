/*
 * Adrienne Bouchie
 * Objective: Create a class named Contact that stores the names and numbers of objects into objects of the contact class
 * Contact.h - Header File
 * July 21st, 2014
 */


#include <iostream>
#include <string>
using namespace std;

class Contact {

	public:

		Contact();
		Contact( string, string );

		void inputContact();
		void displayContact();	  

		string getFirstName();
		string getLastName();

	
    private:

		string fname;
		string lname;


};

