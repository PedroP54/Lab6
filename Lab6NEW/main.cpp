/*
Pedro Aragon
Lab 6 due Novenber 11
This lab reads binary numbers with base 2 and output numbers with base 10 in respect with the numbers with base 2
also reads if the numbers have any letter on itand if the numbers contain more of two spaces to out put a bad digit
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int Decimal(string theBinary);

string binary = "BinaryIn.dat";
//Beginning of Main
int main() {
	//Beginning of file reading 
	ifstream binaryIn;
	binaryIn.open(binary);
	if (binaryIn.fail()) {
		cout << "File not found";
	}
	// End of file reading 



	//Variable declaration zone 
	string num;




	cout << "Binary value" << "\t\t\t   Decimal Value" << endl;
	while (!binaryIn.eof()) {
		getline(binaryIn, num);

		// This if and else if reads the function and understand if there is any error with the set and numbers to out put a "Bad digit on input"
		if (Decimal(num) == -5) {
			cout << "Bad digit on input!!!" << "\t\t\t\t" << endl;
		}
		else if (Decimal(num) != -10) {
			cout << "  " << num << "\t\t\t\t" << Decimal(num) << endl;
		}
		else {
			cout << "Bad digit on input" << "\t\t\t\t" << endl;
		}
	}
	binaryIn.close();
}





//Function Declaration zone				
int Decimal(string theBinary) {// Stores the data from the file 
	int count = theBinary.length();
	int Base = 1;
	int dNum = 0;


	for (int i = count - 1; i >= 0; i--) {
		if (theBinary[i] != '1' && theBinary[i] != '0' && theBinary[count - 1] != ' ') {
			if (theBinary[i] == ' ' && theBinary[i - 1] == ' ') {
				return -5;
				//If the set of numbers contains anything else than 0 and 1 it will retunt a -5 
			}
			else if (theBinary[i] != ' ') {
				return -10;
				//Returns a -10 if the numbers contain more than two spaces 
			}
		}
		else {
			if (theBinary[i] == '1') {
				dNum = dNum + Base;
			}
			Base = Base * 2;
		}
	}
	//End of function declaration zone 

	return dNum;



}
//End of main 
