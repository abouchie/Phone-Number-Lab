/*
 * Adrienne Bouchie
 * Objective: Create a class called PhoneNumber that takes in a phone number, displays the number, allows for the user to text or call the number, and provide a summary of the information
 * Phone.cpp - Implementation File
 * 07/21/2014
 *
 */


#include "Phone.h"
#include <stdio.h>
#include <iomanip>


// Default Constructor that sets variables to default values
PhoneNumber::PhoneNumber() : MAXTEXTS(10), a("", "") {
	nlive=0;
	ntext=0;
}


// Constructor that takes in the area code, exchange, and line number that the user enters
PhoneNumber::PhoneNumber( string aCode, string exch, string ln ) 
	: MAXTEXTS(10) {
	
	areaCode = aCode;
	exchange = exch;
	line = ln;
}


// Function of the iostream class that allows the user to input the phone number through the cin command
istream &operator>> ( istream &input, PhoneNumber &number ) {

	cout << "Enter a phone number in the format: (NNN)-NNN-NNNN" << endl;
	
	input.ignore(1);
        input >> setw(3) >> number.areaCode;
        input.ignore(2);
        input >> setw(3) >> number.exchange;
        input.ignore(1);
        input >> setw(4) >> number.line;
      	cout << endl;

	return ( input );
}


// Function that calls the inputContact function from the Contact.cpp file to allow the user to enter his or her contact information
void PhoneNumber::inputContactInfo() {
	a.inputContact();
}
    

// Function that displays the phone number entered by calling the displayContact function from the Contact.cpp file	
void PhoneNumber::displayPhoneNumber() {
    cout << "(" << areaCode << ")-" <<  exchange << "-" << line << " ";
	a.displayContact();
} 


// Function from the iostream class that displays the contact information that was entered 
ostream &operator<< ( ostream &output, PhoneNumber &number ) {

 	output << "(" << number.areaCode << ")-" << number.exchange << "-" << number.line << " ";
	number.a.displayContact();

    return ( output );	
}

// Function that overloads the equals operator 
bool PhoneNumber:: operator==( PhoneNumber &newPhone ) {

    if ( areaCode == newPhone.areaCode && exchange == newPhone.exchange && line == newPhone.line ) {
		return ( true );  
	}
	
	else 
		return ( false );          
}


// Function that allows the user to dial a number he or she has entered 
void PhoneNumber::dialNum( PhoneNumber passed ) {
	
    displayPhoneNumber();
		cout << " is dialing ";
   	 	passed.displayPhoneNumber();
		cout << endl;
		nlive++;
    	live ++;    
}


// Function that allows the user to text a number he or she has entered and send a text message to that number
bool PhoneNumber::textNum( PhoneNumber passed ) {
    
    bool messageSent = true;
    string textMessage = " ";
    
    if ( ntext < MAXTEXTS ) {
        cout << "Enter the message being sent to ";
        passed.displayPhoneNumber();
        cout << endl;
        getline( cin, textMessage );
        ntext++;
        text++;
    }
    
    else {
        cout << "You have reached the maximum number of texts you can send to ";
        passed.displayPhoneNumber();
        cout << endl;
        messageSent = false;
    }
    
    return( messageSent );
}


// Function that accesses and returns the total number of live phone calls because it is a private data member
int PhoneNumber::getTotalLiveCalls() {
    return( live );
}


// Function that accesses and returns the total number of texts sent because it is a private data member
int PhoneNumber::getTotalTexts() {
    return( text );
}


// Function that accesses and returns the number of live calls per phone number because it is a private data member
int PhoneNumber::getNLive() {
    return( nlive );
}


// Function that accesses and returns the number of texts that have been sent to a particular phone number because it is a private data member
int PhoneNumber::getNText() {
    return( ntext );
}


// Function that accesses and returns the area code because it is a private data member
string PhoneNumber::getAreaCode() { 
    return( areaCode );
}


// Function that accesses and returns the exchange because it is a private data member
string PhoneNumber::getExchange() {
   return( exchange );
}


// Function that accesses and returns the line because it is a private data member
string PhoneNumber::getLine() {
	return( line );
}
