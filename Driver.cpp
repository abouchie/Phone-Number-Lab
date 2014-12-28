/*
 * Adrienne Bouchie
 * Objective: Create a program that accepts as many phone numbers as the user would like, stores them into the Contact class and provide them the option to call or text another number. The program should then provide a summary of the calls and texts made
 * Driver.cpp
 * July 21st, 2014
 */


#include "Phone.h"
#include <iostream>
using namespace std;

int PhoneNumber::live=0;
int PhoneNumber::text=0;
int PhoneNumber::MaxPhones=10;

int main() {

	
    	char choice = '@';
		char answer = '@';
    	int phonesEntered =0;
    	int originatingNum = 0;
    	int receivingNum = 0;
    	bool messageSent = true;
   		bool alreadyInList = true;
    	void summaryInformation( PhoneNumber[], int );
		bool phoneInList( PhoneNumber[], PhoneNumber, int );
 
    	
		PhoneNumber P[PhoneNumber::MaxPhones];
    
	
		for ( int i=0; i< PhoneNumber::MaxPhones; i++ ) {
        	cout << "Would you like to enter a phone number? (y/n)" << endl;
			cin>> answer;
		
			if ( answer == 'y' || answer == 'Y' ) {
				cin.ignore(1);
				cin>> P[i];
				P[i].inputContactInfo();
				phonesEntered++;
				cin.ignore(1); 
     		} 
		
			else {
				i = PhoneNumber::MaxPhones;
		
   			}
		} // end of for statement 
        
    		cout << "You have entered " << phonesEntered << " phone numbers" << endl;
    		for ( int i = 0; i< phonesEntered; i++ ) {
         		cout << P[i];  	
            	cout << endl;
    		}
        
    		do { 
    			cout << "Enter C to make a call, T to send a text, S for summary information, K to check if a number was entered, or X to exit" <<endl;
       			cin >> choice;
	
			if ( choice == 'C' || choice == 'c' || choice == 'T' || choice == 't' ) {
					cout << "Enter the number of the originating phone (1-" << phonesEntered << ") " << endl;
        			cin >> originatingNum;
	
        			cout << "Enter the number of the receiving phone (1-" << phonesEntered << ") " << endl;
        			cin >> receivingNum;

        			if ( choice == 'C' || choice == 'c' ) {
            			P[originatingNum-1].dialNum( P[receivingNum-1] );
       		 		}
	
        			else if ( choice =='T' || choice == 't' ) {
	    				cin.ignore(1);
            			messageSent = P[originatingNum-1].textNum( P[receivingNum-1] );
                		if ( messageSent == true ) {
                    			cout << "Your message has been sent" << endl;
                		}
            		}

			}

        	else if ( choice == 'S' || choice == 's' ) {
            		summaryInformation( P, phonesEntered );
        	}
	
			else if ( choice == 'k' || choice == 'K' ) {
					PhoneNumber newPhone;
					cin.ignore(1);
					cin>> newPhone;
					cin.ignore(1);
					alreadyInList = phoneInList( P, newPhone, phonesEntered );
			
					if ( alreadyInList == true ) { 
					cout << newPhone << " is in the list" << endl;
					}
					else {
						cout << newPhone << " is not in the list" << endl;
					}
			}	
    
        	else if ( choice == 'X' || choice == 'x' ) {
            		cout << "Okay goodbye!" << endl;
        			break;
			}
    
        	else {
            		cout << "Could not recognize your choice" << endl;
            		summaryInformation( P, phonesEntered );
        	} 

			} while ( choice != 'x' || choice != 'X' );

};  // end of main()


// Function that displays a summary of the calls and texts made in total and for each number entered
void summaryInformation( PhoneNumber P[], int phonesEntered ) {
    
    	cout << "The total amount of calls made is:  " << PhoneNumber::getTotalLiveCalls() << endl;
    	cout << "The total amount of texts sent is:  " << PhoneNumber::getTotalTexts() << endl;
    

    	for ( int i=0; i< phonesEntered; i++ ) {
    		cout << "For phone: " ;
    		cout << P[i];
    		cout << " " << P[i].getNLive() << " calls were made and " << P[i].getNText() << " texts were sent." << endl;
		}
    
} 


// Function that checks to see if a number has already been entered
bool phoneInList( PhoneNumber P[], PhoneNumber newPhone, int phonesEntered ) {

	bool alreadyInList = false;
 
	for ( int i = 0; i < phonesEntered; i++ ) {
		if ( P[i] == newPhone ) {
			alreadyInList = true;
			i = phonesEntered;
		}
		else
			alreadyInList = false;
	}  	
	return ( alreadyInList );
};


