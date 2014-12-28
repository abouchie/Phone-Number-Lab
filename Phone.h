/*
 * Adrienne Bouchie
 * Objective: Create a class called PhoneNumber that takes in a phone number, displays the number, allows for the user to text or call the number, and provide a summary of the information
 * Phone.h - Header File
 * 07/21/2014
 *
 */


#include <string>
#include <iostream>
#include "Contact.h"
using namespace std;

class PhoneNumber {

	friend ostream &operator<< ( ostream &, PhoneNumber & );
	friend istream &operator>> ( istream &, PhoneNumber & );	

        public:

        	PhoneNumber();
        	PhoneNumber( string, string, string );

        	void inputPhoneNumber();
        	void displayPhoneNumber();

     	   	void dialNum( PhoneNumber );
			bool textNum( PhoneNumber );
			bool operator==( PhoneNumber & );	

			static int MaxPhones;
			static int getTotalLiveCalls();
			static int getTotalTexts();
			void inputContactInfo();
			int getNLive();
			int getNText();
		
			string getAreaCode();
			string getExchange();
			string getLine();	

  
  		private:

       		static int live;
        	static int text;
        	const int MAXTEXTS;
        	string areaCode;
        	string exchange;
        	string line;
        	int nlive;
        	int ntext;
			Contact a;


};
