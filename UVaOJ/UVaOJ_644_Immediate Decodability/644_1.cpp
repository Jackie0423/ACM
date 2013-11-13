/*
UVA 644 Immediate Decodability
 Immediate Decodability 
An encoding of a set of symbols is said to be immediately decodable if no code for one symbol is the prefix of a code for another symbol. We will assume for this problem that all codes are in binary, that no two codes within a set of codes are the same, that each code has at least one bit and no more than ten bits, and that each set has at least two codes and no more than eight.

Examples: Assume an alphabet that has symbols {A, B, C, D}

The following code is immediately decodable:

A:01 B:10 C:0010 D:0000

but this one is not:

A:01 B:10 C:010 D:0000 (Note that A is a prefix of C)
Input 
Write a program that accepts as input a series of groups of records from a data file. Each record in a group contains a collection of zeroes and ones representing a binary code for a different symbol. Each group is followed by a single separator record containing a single 9; the separator records are not part of the group. Each group is independent of other groups; the codes in one group are not related to codes in any other group (that is, each group is to be processed independently).
Output 
For each group, your program should determine whether the codes in that group are immediately decodable, and should print a single output line giving the group number and stating whether the group is, or is not, immediately decodable.

The Sample Input describes the examples above.
Sample Input 
 01
10
0010
0000
9
01
10
010
0000
9
Sample Output 
 Set 1 is immediately decodable
Set 2 is not immediately decodable
*/
//#define ONLINE_JUAGE
//#pragma warning(disable:4786)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
using namespace std;

int main() {

#ifndef ONLINE_JUAGE
	ifstream in("10010_i.txt");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	
	ofstream out("10010_o.txt");
	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
#endif
	vector<string> vec;
	string str;
	int cases = 0;
	while (cin>>str) {
		if (str != "9") {
			vec.push_back(str);
		} else {
			sort(vec.begin(), vec.end());
			bool CanDecode(vector<string> &);
			if (CanDecode(vec)) {
				cout<<"Set "<<++cases<<" is immediately decodable"<<endl;
			} else {
				cout<<"Set "<<++cases<<" is not immediately decodable"<<endl;
			}
			vec.clear();
		}
	}
	
#ifndef ONLINE_JUAGE
	in.close();
	out.close();
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif

	return 0;
}



bool CanDecode(vector<string> & vec) {
	
	bool CanDecode = true;
	for (int i=1; i<vec.size(); ++i) {

		if (vec[i].size()>=vec[i-1].size()) {
			
			if (vec[i].substr(0, vec[i-1].size()) == vec[i-1]) {
				CanDecode = false;
				break;
			}
		}
	}
	
	return CanDecode;
}
