/*
 * Adrienne Bouchie
 * Objective: Create a class named Contact that stores the names and numbers of objects into objects of the contact class
 * Contact.cpp - Implementation File
 * July 21st, 2014
 */

#include "Contact.h"
#include <stdio.h>
#include <iomanip>



// Default Constructor that assigns default values to the first and last name of the object
Contact::Contact() {
		fname = "John";
        lname = "Smith";
}


// Constructor that takes in values from the user and assigns them to first and last name
Contact::Contact( string firstName, string lastName ) {
        fname = firstName;
        lname = lastName;
}


// Function that allows the user to input their contact information and stores them into variables
void Contact::inputContact() {
		cout << "Enter contact information:" <<endl;
		cout << "First Name: " << endl;
		cin >> fname;
		cout << "Last Name: " << endl;
		cin >> lname;		
		cout << endl;
}


// Function that displays the contact information of the object
void Contact::displayContact() {
		cout << fname << " " << lname;
}


// Function that returns the first name of the object because it is a private data member
string Contact::getFirstName() {
		return( fname );
}

// Function that returns the last name of the object because it is a private data member
string Contact::getLastName() {
		return( lname );
}
