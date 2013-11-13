/*
A regular palindrome is a string of numbers or letters that is the same forward as backward. For example, the string "ABCDEDCBA" is a palindrome because it is the same when the string is read from left to right as when the string is read from right to left.


A mirrored string is a string for which when each of the elements of the string is changed to its reverse (if it has a reverse) and the string is read backwards the result is the same as the original string. For example, the string "3AIAE" is a mirrored string because "A" and "I" are their own reverses, and "3" and "E" are each others' reverses.


A mirrored palindrome is a string that meets the criteria of a regular palindrome and the criteria of a mirrored string. The string "ATOYOTA" is a mirrored palindrome because if the string is read backwards, the string is the same as the original and because if each of the characters is replaced by its reverse and the result is read backwards, the result is the same as the original string. Of course, "A", "T", "O", and "Y" are all their own reverses.


A list of all valid characters and their reverses is as follows.


Character	Reverse	Character	Reverse	Character	Reverse
A	A	M	M	Y	Y
B		N		Z	5
C		O	O	1	1
D		P		2	S
E	3	Q		3	E
F		R		4	
G		S	2	5	Z
H	H	T	T	6	
I	I	U	U	7	
J	L	V	V	8	8
K		W	W	9	
L	J	X	X		

Note that O (zero) and 0 (the letter) are considered the same character and therefore ONLY the letter "0" is a valid character.

Input 

Input consists of strings (one per line) each of which will consist of one to twenty valid characters. There will be no invalid characters in any of the strings. Your program should read to the end of file.
Output 

For each input string, you should print the string starting in column 1 immediately followed by exactly one of the following strings.

STRING	CRITERIA
" -- is not a palindrome."	 if the string is not a palindrome and is not a mirrored string
" -- is a regular palindrome."	 if the string is a palindrome and is not a mirrored string
" -- is a mirrored string."	 if the string is not a palindrome and is a mirrored string
" -- is a mirrored palindrome."	 if the string is a palindrome and is a mirrored string
Note that the output line is to include the -'s and spacing exactly as shown in the table above and demonstrated in the Sample Output below.

In addition, after each output line, you must print an empty line.

Sample Input 

NOTAPALINDROME 
ISAPALINILAPASI 
2A3MEAS 
ATOYOTA
Sample Output 

NOTAPALINDROME -- is not a palindrome.
 
ISAPALINILAPASI -- is a regular palindrome.
 
2A3MEAS -- is a mirrored string.
 
ATOYOTA -- is a mirrored palindrome.
*/

#include <iostream>
#include <string>
using namespace std;

string isNotPalin = " -- is not a palindrome.";

string isRegPalin = " -- is a regular palindrome.";

string isMirrStr = " -- is a mirrored string.";

string isMirrPalin = " -- is a mirrored palindrome.";

bool isRegPalin_Fun(string &str) {

	int i = 0;
	int len = str.length();

	bool isRP = true;

	for (i=0; i<len/2; ++i) {
		if (str[i]!=str[len-1-i]) {
			isRP = false;
			break;
		}
	}

	return isRP;
}

char validChRe[35] = {'A', ' ', ' ', ' ', '3', //A-E
					  ' ', ' ', 'H', 'I', 'L', //F-J
					  ' ', 'J', 'M', ' ', 'O', //K-O
					  ' ', ' ', ' ', '2', 'T', //P-T
					  'U', 'V', 'W', 'X', 'Y', //U-Y
					  '5', '1', 'S', 'E', ' ', //Z-4
					  'Z', ' ', ' ', '8', ' ',
					};

bool isMirrStr_Fun(string &str) {
	
	bool isMS = true;

	int len = str.length();

	int baseIndex = 0;
	char baseCh = 'A';
	for (int i=0; i<=len/2; ++i) {
		if (str[i]>='A' && str[i]<='Z') {
			baseIndex = 0;
			baseCh = 'A';
		} else {
			baseIndex = 26;
			baseCh = '1';
		}
	
		int chIndex = baseIndex + (str[i]-baseCh);
		if (validChRe[chIndex] == ' ' || validChRe[chIndex]!= str[len-i-1]) {
			isMS = false;
			break;
		}
	}

	return isMS;
}


int main() {

	string str;

	while (cin>>str) {
		bool isRegPa = isRegPalin_Fun(str);
		bool isMirStr = isMirrStr_Fun(str);
		if (isRegPa && isMirStr) {
			cout<<str<<isMirrPalin<<endl<<endl;
		} else if (isRegPa) {
			cout<<str<<isRegPalin<<endl<<endl;
		} else if (isMirStr) {
			cout<<str<<isMirrStr<<endl<<endl;
		} else {
			cout<<str<<isNotPalin<<endl<<endl;
		}
	}


	return 0;
}
