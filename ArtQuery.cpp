HW4-Louis.cpp

Type
Text
Size
29 KB (29,912 bytes)
Storage used
29 KB (29,912 bytes)
Location
HW4 Doc
Owner
me
Modified
Oct 17, 2016 by me
Opened
6:19 PM by me
Created
Oct 17, 2016 with Google Drive Web
Add a description
Viewers can download
//  main.cpp
//  HW4-week6
//  Created by Georgy Louis on 10/2/16.
//  Copyright © 2016 Georgy Louis. All rights reserved.
//

/*
This program read records from a file and offer users
The option of query the database.
These records are about artwork
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>     /* atof */

using namespace std;

/*
* Data structure that holds information
* about paintings and photographs
*/
struct artwork {
	int acquisition;    // variable that hold acquisition number uniquely identified each record
	string lastName;    // variable that hold author's last name
	string firstName;   // variable that hold author's first name
	string medium;      // variable that hold an artwork medium information
	string title;       // variable that hold the titile of an artwork
	double length;      // variable that hold the length of artwork
	double width;       // variable that hold the width of artwork
	string room;        // variable that hold room name
	double price;       // variable that hold artwork price
} gallery[34];         // End with an array data hold the artwork data information

					   /* When reading the file, the data is read line by line
					   * this function identified words that match artwork medium information
					   * this helps with identifying the medium information for each record
					   */
bool checkMedium(string medium_element) {

	bool check(false);  //variable holding information indicating if the data  is medium type information

	string word;        // variable holding data for each word of the data stream

	string sub_word;    // variable holding the extracted word from the data stream
						/*
						* Variable holding the different artwork medium information
						*/
	string medium[16] = { "black chalk","engraving","etching","charcoal","gelatin silver print","gouache",
		"graphite","iris print","lithograph","oil","paper collage","pen and brown ink",
		"photogravure","platinum print","red chalk","tempera and ink" };
	/*
	* Loop comparing the first word of the medium information and compare it
	* with the string extracted from the data being processed.
	*/
	for (int i = 0; i< 16; i++) {

		istringstream word(medium[i]); // variable holding the first word of each medium artwork information
									   /*
									   * This loop extracts each sequence of character separated by space
									   * and compare that information with the artwork information
									   */
		do {
			word >> sub_word;  // extract a string separated by space
							   /*
							   * This check if the data being processed is the one of the possible artwork medium
							   */
			if (medium_element == sub_word) {

				check = true; // indicating that the current data being processed maches possible artwork medium name

			}  //  End if(medium_element == sub_word)

		} while (word);  // End Do {

	}  // End   for (int i =0; i< 16;i++)

	return check;

} // End for (int i =0; i< 16;i++)


  /*
  * This function Checks if a string matches the possible room name for an artwork data record
  */
bool checkRoom(string room_element) {

	bool check(false); // variable indicating whether or not the string matches the possible room name associated with an artwork

	string room[7] = { "main","green","blue","north","south","entry","balcony" }; // array of room name associated with artwork
 /*
Looping comparing a string with each element in the array room
 */
	for (int i = 0; i< 7; i++) {

		if (room_element == room[i]) {   // Check if the roo name matches

			check = true;

		}  // End 	if (room_element == room[i])

	}  // End for (int i = 0; i< 7; i++)

	return check;

} // end for (int i =0; i< 16;i++)

/*Check if a string is a number */
bool isNumeric(string element) {

	bool numeric = false;

	if (isdigit(element.at(0))) {  // Check if first character is numeric

		numeric = true;
	}

	return numeric;

} //bool isNumeric(string element)

/* This function displays the dfferent options that indicate
* how users can query the Museum database or quit the program
* The options are between 1 and 6.
*/
void displayMenu1() {

	cout << "                          Welcome to Smithsonian National Museum " << endl;

	cout << "                 choose among the options below to query our artwork database" << endl;

	cout << "                           Type the corresponding number to proceed" << endl;

	cout << "                      *************************MENU 1*************************" << endl;

	cout << "                      1 - Request all information for artworks" << endl;

	cout << "                      2 - Request titles for one or more artwoks" << endl;

	cout << "                      3 - Reqeust the width of one of the artwork" << endl;

	cout << "                      4 - Request the room for an artwork" << endl;

	cout << "                      5 - Request first letter of an artist last name" << endl;

	cout << "                      6 - Change set of queries" << endl << endl;

}  // End void displayMenu1() 

/*Menu 1 that display users option to query
the database
*/
void displayMenu2() {

	cout << "                          Welcome to Smithsonian National Museum " << endl;

	cout << "                 choose among the options below to query our artwork database" << endl;

	cout << "                           Type the corresponding number to proceed" << endl;

	cout << "                      *************************MENU 2*************************" << endl;

	cout << "                      1 - All artst ,titles, and prices" << endl;

	cout << "                      2 - sum the prices for a range" << endl;

	cout << "                      3 - artwork artist,title,medium and square footage" << endl;

	cout << "                      4 - Total price of artwork of a medium" << endl;

	cout << "                      5 - Total Price of all artwork of an artist" << endl;

	cout << "                      6 - Titles of all artwork whose width is greater" << endl;

	cout << "                      7 - End Program" << endl << endl;

}  // End void displayMenu2()

/* This function displays records from a certain range
* that the user provides.Pro
* lower is tied to the lower bound. upper is tied to the upper bound
* This function is also used to display only titles for a range of records
* The variable choice indicates whether the function is used to display
* all information for a range of records or
* only titles for a range of records.
*/
void displayAllInRange(int lower, int upper, int choice) {

	if (lower > upper) {     // Check if lower bound is bigger than upper bound

		cout << "No results.Because lower bound is bigger than upper bound" << endl; // inform user that lower bound is bigger than upper bound

	}  // End if (lower > upper)

	else if (lower< 1 || upper > 34) { // Check if lower bound is within the range of data available in the database

		cout << "Out of range. Choose between 1 and 34" << endl; // inform users that out of range bound was provided

	}  // End else if (lower< 1 || upper > 34)

	else {    // if upper and lower are within range respect their difference, the program displays the results

		if (choice == 1) { // Check if all information should be displayed


				cout << gallery[lower].acquisition << " ";  // Display acquisition number, which is the individual data record number

				cout << gallery[lower].lastName << " ";     // display artist's last name

				cout << gallery[lower].firstName << " ";    // display artist's first name

				cout << gallery[lower].medium << " ";      // display artwork medium

				cout << gallery[lower].title << " ";       // display artwork title

				cout << gallery[lower].length << " ";      // display artwork length

				cout << gallery[lower].width << " ";       // display artowrk  width

				cout << gallery[lower].room << " ";        // display artwork room

				cout << gallery[lower].price << " ";       // display artwork price

				cout << "\n";                          // diplay break line


		}  // end if(choice == 1)

		else if (choice == 2) {  // Check if only titles should be displayed

			for (int i = lower; i < upper+1; i++) { // set the

			cout << gallery[i].acquisition << " ";  // Display acquisition number, which is the individual data record number

			cout << gallery[i].lastName << " ";     // display artist's last name

			cout << gallery[i].firstName << " ";    // display artist's first name

			cout << gallery[i].medium << " ";      // display artwork medium

			cout << gallery[i].title << " ";       // display artwork title

			cout << gallery[i].length << " ";      // display artwork length

			cout << gallery[i].width << " ";       // display artowrk  width

			cout << gallery[i].room << " ";        // display artwork room

			cout << gallery[i].price << " ";       // display artwork price

			cout << "\n";                          // diplay break line

			}  // end for (int i = lower; i < upper; i++) {

		} // End else if(choice == 2)

	} // else



	cout << "\n";

} // End void displayRange (int lower,int upper,int choice)


void displayTitle(int lower,int upper, int choice) {

	if ((lower > upper) || (lower < 1) || (lower > 34)) {

		cout << "Incorrect input" << endl;

	} //End if ((lower > upper) || (lower < 1) || (lower > 34))

	else if (choice == 1) {

		cout << gallery[lower].title << " " << endl;       // display artwork title
	}
	else if (choice == 2) {

		for (int i = lower; i < upper+1; i++) { // set the

			cout << gallery[i].title << " " << endl;       // display artwork title

			cout << "\n";                          // diplay break line

		}  // end for (int i = lower; i < upper; i++) {
	}
}
  /* This function displays records that has width that are greather or lesser than
  * a width that the user provides
  * The variable widthChoice when equals 1 and 2
  * indicate less or greater than
  */
void displayWidth(int acquisition, double widthBound, int options) {

	if (options == 1) {  // Check users option

		cout << "Width of " << acquisition << "th : " << gallery[acquisition].width << endl;

	}  // End if (options == 1)

/* loop to visit each record line and display
 * the ones that match the request criteria, less than or greater than
 */

	if (options == 2) {
		for (int i = 1; i < 35; i++) {
			
			if (gallery[i].width <= widthBound) {

				cout << gallery[i].width << endl;

			}  // end if (gallery[i].width < widthBound)

		} // end  for (int i = 1; i < 35; i++)

	} // end if (options == 2)

	else if (options == 3) {

		for (int i = 1; i < 35; i++) {

			if (gallery[i].width > widthBound) {

				cout << gallery[i].width << endl;

			}  // end if (gallery[i].width < widthBound)

		} // end  for (int i = 1; i < 35; i++)

	}  // else if (options == 2)
	

} // End void displayWidth (double width)

  /*
  * This function find the room matching an acquisition number
  */
void displayRoom(int recordNumber) {

	if (recordNumber < 1 || recordNumber > 34) {  // Check acquisition number validity

		cout << "Out of range. Please enter a number between 1 and 34" << endl;

	}  // End if (recordNumber < 1 || recordNumber > 34)
	else {

		cout << gallery[recordNumber].room << " " << endl;  // display the room name

	} // end if (recordNumber < 1 || recordNumber > 34)

}  // End void displayRoom (int recordNumber)


   /*
   * This function dsiplays the first letter of an artist
   */
void displayArtist(int recordNumber) {

	if (recordNumber < 1 || recordNumber > 34) {  // Check if the record number is in range

		cout << "out of range. Please type a number between 1 and 34"  << endl;  // Incorrect input
		 
	} // End if (recordNumber < 1 || recordNumber > 34) 
	
	else {

		cout << gallery[recordNumber].lastName.substr(0, 1) << " " << endl;  // Display result

	}  // End else
	
}  // End void displayArtist(int recordNumber) 

//Display artist works by last name
void displaybyLastName(string lastName) {

	for (int i = 1; i < 35; i++) {

		// Find records matching a certain last name
		if ((gallery[i].lastName  == lastName)) {

			cout << gallery[i].lastName << " " ; // display lastname

			cout << gallery[i].firstName << " " ;      // display firstname

			cout << gallery[i].title << " "; // display title

			cout << gallery[i].price << " " << endl;      // display price

		} // End if(width >  gallery[i].width )

	} // End for (int i =0; i < 34; i++)

} //End void displaybyLastName(string lastName)

//Find some of prices in a range
void displayPricesSum(double price,int options ) {

	double sum(0.00); // prices summation

	for (int i = 1; i < 35; i++) {

		// Calculate price aboce
		if (gallery[i].price > price && options == 1) {

			sum =sum+gallery[i].price;

		} // if (gallery[i].price > price && options == 1)

		//calculate price below
		else if (gallery[i].price < price && options == 2) {

			sum = sum+gallery[i].price;

		} // else if (gallery[i].price < price && options == 2)	

	} // End for (int i =0; i < 34; i++)

	cout << "Sum prices = " << sum << endl;

}  // End void displayPricesSum(double price,int options )


   // Find record for a specific room

void displaybyRoom(string room) {
	
	for (int i = 1; i < 35; i++) {

		// Check if the record matches the room
		if (gallery[i].room == room) {

			cout << gallery[i].lastName << "  ";

			cout << gallery[i].title  << "  ";

			cout << gallery[i].medium << "  ";

			// calculate and display square footage
			cout << "square footage : " << gallery[i].width*gallery[i].length << endl; 

		} //	if (gallery[i].room == room)


	} // End for (int i =0; i < 34; i++)

}  // void displaybyRoom(string room)


// function displaying total price by medium

void displayTotalPriceByMedium(string medium) {

	double sum(0); // Total price by medium

	string mediumInrecord;

	// loop looking for price matching medium
	for (int i = 1; i < 35; i++) {

		//extract the first word in the character sequence
		istringstream dataSequence(gallery[i].medium);

		dataSequence >> mediumInrecord;  // Extract the first word in the 
										 // medium record string

										 // Check if the record matches the room
		if (mediumInrecord == medium) { // compare the first words in both string
										// 
			sum = sum + gallery[i].price;  // Caclulate total price by medium

		} //if (gallery[i].medium == medium)


	} // End for (int i =0; i < 34; i++)

	cout << "price summation for mum : " << medium << " : " << sum << endl;

}  // End void displayTotalPriceByMedium(string medium)


// Display total price of artwork of a specific artist
void displayArtitTotalPrice(string lastName) {

	double sum(0);

	for (int i = 1; i < 35; i++) {  // go over data records

		// Check if the first word of both firstname string matches
		if (gallery[i].lastName == lastName) {

			sum = sum + gallery[i].price;  // Calculate sum

		} // if (gallery[i].lastName == lastname)

	} // End for (int i =0; i < 34; i++)

	cout << "Total Price (" << lastName << ") :" << sum << endl;

}  //void displayArtitTotalPrice(string lastname)

// Find the title of all artwork whose width is greater than a certain number
// located in a specific room
void displayTitleByRoomAndWith(string room, double width) {
	
	/*Loop that search through the records*/
	for (int i = 1; i < 35; i++) {

		if (gallery[i].width > width && gallery[i].room == room) {

			cout << gallery[i].title << endl;

		} //if (gallery[i].width > width && gallery[i].room == room)

	} // for (int i = 1; i < 35; i++)

} // void displayTitleByRoomAndWith(string room, double width) 


int main() {

	string LineRec;

	string subLine;  // a part of a line of the data file

	ifstream InformationIn;

	int word_count(0);   // identify a word in a line of data record

	int work_count(1);  // count the number of line of database records

	int options(0);     // users choice

	int lowerBound(1);  // rand lower bound

	double widthBound(0.00); // width provided by users to compare with the width in records

	int upperBound(34);    // range upper bound

	int widthChoice;      // width choice

	int recordNumber;  // acquisition number

	InformationIn.open("ARTbytabs.txt");  // data file

	if (InformationIn.is_open()) {    // open the data file

		/*This loop reads the data file until it reaches the end of the file*/

		while (!InformationIn.eof()) {   

			getline(InformationIn, LineRec);  // read each line of data

			istringstream dataSequence(LineRec); // sequence of character extracted from a line of

			do
			{
				dataSequence >> subLine;
				// cout << "Substring: " << sub << endl;
				/* Assign the first word to last name
				* First word is the last name
				*/
				if (word_count == 0) {
					gallery[work_count].lastName = subLine;
					// cout << "last name : "  << gallery[work_count].lastName << endl;
				}  // if (word_count == 0)
				/* Assign the second word to first name
				* Since the second word will be the first name or part
				* of the first name
				*/
				else  if (word_count == 1) {

					gallery[work_count].firstName.append(subLine);

				}  // else  if (word_count == 1) 
				/* Check if the third word is part of the last name
				* or the beginning of the medium of the art work
				*
				*/
				else if (word_count == 2) {

					if (checkMedium(subLine)) {

						gallery[work_count].medium = subLine;  // Asssign the word to the medium information

					} // if (checkMedium(subLine))

					else {       // if the word does not begin medium, the character exctracted is added to first name

						gallery[work_count].firstName.append(" "); // separate differnt part of the first name

						gallery[work_count].firstName.append(subLine); // add the string to the first name record

						word_count--;   // to contiune to look for remaining part of the first name

					}  // end else

				} // end else if(word_count == 2)


				/*No more word for the first name. now the program is reading a medium record*/

				else if (word_count == 3) {

					if (checkMedium(subLine)) { // if the data correspond to medium

						gallery[work_count].medium.append(" ");   //space sparated different word of the medium string

						gallery[work_count].medium.append(subLine);  // the data is added to the medium

						word_count--;   // to continue looking for medium information 

					}  //if (checkMedium(subLine))

					else {

						gallery[work_count].title = subLine;

					}  // end else

				} // end  else if(word_count == 3)


				/*The progam is reading part of the length of an artwork*/
				else if (word_count == 4) {

					if (isNumeric(subLine)) {  // check if the string is a number

						gallery[work_count].length =stod(subLine);  // conver string to double

					}  // else if (word_count == 4)

					else {

						gallery[work_count].title.append(" ");

						gallery[work_count].title.append(subLine);

						word_count--;

					}  // end else

				} // end  else if(word_count == 3)

				/*reading an artwork width*/

				else if (word_count == 5) {   

					if (isNumeric(subLine)) {  // check if string is number

						gallery[work_count].width = stod(subLine); // convert string to double

					}
				} // end  else if(word_count == 3)


				/* read the room info */
				else if (word_count == 6) {

					if (checkRoom(subLine)) {  // check if the data matches the room possible value

						gallery[work_count].room = subLine;  // if yes the data is recorded

					}
				} // end  else if(word_count == 3)

				/* Extract the last number of the string and 
				 * assign it to the price of the artwork
				 * in the meantime set the acquisition number
				 */
				else if (word_count == 7) {

					if (isNumeric(subLine)) { // check if the string is a number o

						gallery[work_count].price= stod(subLine); //convert string to double and set artwork price

						gallery[work_count].acquisition = work_count; // set acquisition number
					}

				} // end  else if(word_count == 3)

				word_count++;

			} while (dataSequence); // End do

			work_count++;    // move to the next acquisition number

			word_count = 0;  // reinitialize the word counter for each line of data

		} // end  while (! InformationIn.eof() )

		InformationIn.close();  // close the file

	}
	else {

		cout << "Unable to open file";

	} // end InformationIn.is_open()

	  /* 
	  * This loop manages all request in the Menu 1
	  */
	while (true) {	

		system("CLS");   // Clear screen

		displayMenu1();   // Display menu

		cout << "Type one of the option above to request information" << endl;

		cin >> options; // Read user's request option

		/*
		* Mamange to query all information about an artwork or a range of artwork
		* according to the user specified option.
		*/
		if (options == 1) {
		
			cout << "Enter 1 to request one item" << endl;

			cout << "Enter 2 to request a range of item"  << endl;

			cin >> options;

			if (options == 1) {  // requesti all  information for one artwork

				cout << "Enter the item acquisition number" << endl;

				cin >> lowerBound;

				displayAllInRange(lowerBound, upperBound, 1);

			} //if (options == 1)

			else if (options == 2) {  // request all information for a range of artwork

				cout << "Please type the lower bound" << endl;  // Display action option to the user

				cin >> lowerBound; // read lower bound user provided data

				cout << "Please type the upper bound" << endl;  // Display action options to the user

				cin >> upperBound; // read upper bound user provided data

				displayAllInRange(lowerBound, upperBound, 2);  // Call function to Display all information

			}	//else if (options == 2) {

			else {

				cout << "Please. Incorrect option.It should have been 1 or 2";

			}
	
		} // End  if(options == 1)

		  /*
		  * Request  title for an artwork or a range of artwork
		  */
		else if (options == 2) {
			
			cout << "Enter 1 to reqeuest title for an artwork" << endl;

			cout << "Enter 2 to reqeuest title for a range of artwork " << endl;

			cin >> options;  // read user options

			if (options == 1) {

				cout << "Enter the acquisition number of the artwork" << endl;

				cin >> lowerBound;

				upperBound = lowerBound;


				displayTitle(lowerBound, upperBound, 1);

			}
			else if (options == 2) {

				cout << "Please type the lower bound" << endl;  // Display action option to the user

				cin >> lowerBound; // read lower bound user provided data

				cout << "Please type the upper bound" << endl;  // Display action option to the user

				cin >> upperBound;  // read upper bound user provided data

				displayTitle(lowerBound, upperBound, 2); // Call function to Display all reqeusted artwork title

			}

			else {

				cout << "Incorrect option. The number should have been 1 or 2" << endl;

			}
			
		} // else if(options == 2)

		  /*
		  * Check the user's request option and display
		  * the width for artwork lesser or greater than a user provided width
		  */
		else if (options == 3) {
			
			int acquisitionNumber(0);

			cout << "Enter 1 to request the width of an artwork" << endl;

			cout << "Enter 2 to request the width lesser than the one you provided" << endl;

			cout << "Enter 3 to request the width greater than the one you provided" << endl;

			cin >> options; // read users options

			
            
			if (options == 1) {  // Find the width that match the acquisition number
				
				cout << "Please enter the acquisition number" << endl;

				cin >> acquisitionNumber; // Read acquisiton number

				displayWidth(acquisitionNumber, widthBound, options);  // Find and display the width matching the acquisition number
			}  

			else if (options == 2 || options == 3) {    // Find all records lesser or greater than the width provided

				cout << "Please Enter the width bound" << endl; // display action option to user

				cin >> widthBound;

				displayWidth(acquisitionNumber,widthBound, options); // Find and display the width greater or less then the one provided

			}

			else {

				cout << "Incorrect options. You should type either 1 or 2 or 3" << endl;

			}	
		
		}   // End else if(options == 3)


/*
* Find the room corresponding to an acquisition number
*/
		else if (options == 4) {

			cout << "Please Enter the acquisition of the record corresponding to a room" << endl;// display action options to user

			cin >> recordNumber;  // read user provided data record number
		    /*
		    * this functions displays room associated with the
		    * record number that the user provided
		    */
			displayRoom(recordNumber);
			
		} // End  else if(options == 4)
		  
		  
		  /*
		  * Check the user's requestion option and display
		  * the first letter of the lastname name associated with the acquisition number the
		  * the user provided.
		  */
		else if (options == 5) {

			cout << "Please Enter the acquisition number for the artist's artwork" << endl;

			cin >> recordNumber;  // read user provided data record number
								  
			displayArtist(recordNumber);  // Find and dislay the first letter of the artist lastname
			
		} // End  else if(options == 5)


		  /*
		  * By typing 6 the user quit the program
		  */
		else if (options == 6) {
			break;
		}  // End  else if(options == 6)
		   /*
		   * This statement executes if the user has not entered any valid options
		   */		
		else {
			cout << "Invalid options. Type a number between 1 and 6" << endl;
		} // End else

		cout << "Please type 7 to continue" << endl;
			cin >> options;
		
		
	} // End  while(true)


	/***********************************************************************************************
	***************************************Second Menu start here **********************************
	************************************************************************************************/

	/*This loop manages all request presented in the second menu */
	while (true) {

		system("CLS");   // Clear screen

		displayMenu2();   // Display menu

		cout << "Type one of the option above to request information" << endl;

		cin >> options; // Read user's request option

		// Find all works corresponding to an artist last name			
		if (options == 1) {

			string artistLastName; // artist last name

			cout << "Enter an artist lastname " << endl;

			cin >> artistLastName;

			displaybyLastName(artistLastName);  // Find and display artist artwork

		}  // end if (options == 1)

		// find sum of prices in a certain range
		else if (options == 2) {
			
			double price;

			cout << "Enter 1 to sum prices above"  << endl;

			cout << "Enter 2 to sum prices blow" << endl;

			cin >> options;

			cout << "Enter the price" << endl;

			cin >> price;

			if (options == 1 || options == 2) {

				displayPricesSum(price, options);

			}  // if (options == 1 || options == 2)

			else {

				cout << "invalid option. the number should be 1 or 2" << endl;

			}  // end else
		

		} // else if (options == 2)


		// display records by room
		else if (options == 3) {

			string room;

			cout << "Enter a room " << endl;

			cin >> room;  // read room information

			displaybyRoom(room); //find and display records matching the room

		}  // else if (options == 3)


		//Find prices summation for a specific medium
		// this solution matches only the first word in the string
		//the user entered and the string in the database
		else if (options == 4) {
			
			string medium;

			cout << "Enter medium name" << endl;

			cin >> medium;

			displayTotalPriceByMedium(medium); // find and display total price by medium

		} //else if (options == 4)

		// find the toal prices of artwork for a specfic artist
		else if (options == 5) {

			string artistLastName; // artist last name

			cout << "Enter an artist lastname " << endl;

			cin >> artistLastName;

			displayArtitTotalPrice(artistLastName);  // find and sum prices of artword for a specific artist

		} // else if (options == 5)
		
		  /* Find all artwork title greater then a specific size 
		  * located in a  specific room 
		  */
		else if (options == 6) {

			string room; // variable holding gallery home

			double width; //variable holding artwork width

			cout << "Enter the room name" << endl;

			cin >> room;   

			cout << "Enter the width of the artwork" << endl;

			cin >> width;

			displayTitleByRoomAndWith(room, width); // display all the list of all titles

		}  // End else if (options == 6)


		// Exit the program 
		else if (options == 7) {

			cout << " End of the program";

			break;
		}  // end else if (options == 7)

		else {

			cout << "Invalid options. Type a number between 1 and 7" << endl;

		} // End else

		cout << "Please type 7 to continue" << endl;  // Allow the user to see the menu again

		cin >> options;   // read the user option

	}  // End while(true)

	

	return 0;

} // End int main() 











