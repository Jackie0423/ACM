#pragma warning(disable:4786)
#include <iostream>
#include <string>
#include <map>
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

map<char, char> m;

void init() {

	m.insert(make_pair('A', 'A'));
	m.insert(make_pair('E', '3'));
	m.insert(make_pair('H', 'H'));
	m.insert(make_pair('I', 'I'));
	m.insert(make_pair('J', 'L'));
	m.insert(make_pair('L', 'J'));
	m.insert(make_pair('M', 'M'));
	m.insert(make_pair('O', 'O'));
	m.insert(make_pair('S', '2'));
	m.insert(make_pair('T', 'T'));
	m.insert(make_pair('U', 'U'));
	m.insert(make_pair('V', 'V'));
	m.insert(make_pair('W', 'W'));
	m.insert(make_pair('X', 'X'));
	m.insert(make_pair('Y', 'Y'));
	m.insert(make_pair('Z', '5'));
	m.insert(make_pair('1', '1'));
	m.insert(make_pair('2', 'S'));
	m.insert(make_pair('3', 'E'));
	m.insert(make_pair('5', 'Z'));
	m.insert(make_pair('8', '8'));
}

bool isMirrStr_Fun(string &str) {
	
	bool isMS = true;

	int len = str.length();

	for (int i=0; i<=len/2; ++i) {
		if (m[str[i]] != str[len-i-1]) {
			isMS = false;
			break;
		}
	}

	return isMS;
}

int main() {

	string str;

	init();
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