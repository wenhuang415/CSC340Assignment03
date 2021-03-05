#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

bool isvalidcc(const string& str1) {
	//add a leading 0 or else the foor loop won't include the digit at the beginning
	string str = "0" + str1;
	char c;
	int num;
	int sum = 0;
	for (int i = str.length() - 1; i > 0; i -= 2) {
		//ith - 1 digit will be doubled
		//c -48 will give us value of the char number because 48 = ASCII for 0
		c = str.at(i - 1);
		num = c - 48;
		num *= 2;
		//if num>9 add the digits seperately
		if (num > 9) {
			//add digit in ones place
			sum += num % 10;
			//add digit in tens place
			sum += num / 10 % 10;
		}
		//num < 10 then add into sum
		else {
			sum += num;
		}
		//add ith digit into sum
		sum += str.at(i) - 48;
	}
	//return if sum is divisible by 10
	return sum % 10 == 0;;
}

int main()
{
	//
	// PLEASE DO NOT CHANGE function main
	//
	vector<string> cardnumbers = {
		 "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
		"4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
		"5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
		"4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
		"5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
		 "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
		"4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
		"5556551555555557", "6011316011016011"
	};

	int i;
	vector<string>::iterator itr;

	for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
		cout << setw(2) << i << " "
			<< setw(17) << *itr
			<< ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
	}

	return 0;
}
