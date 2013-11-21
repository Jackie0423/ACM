/*
  487-3279 
Businesses like to have memorable telephone numbers. One way to make a telephone number memorable is to have it spell a memorable word or phrase. For example, you can call the University of Waterloo by dialing the memorable TUT-GLOP. Sometimes only part of the number is used to spell a word. When you get back to your hotel tonight you can order a pizza from Gino's by dialing 310-GINO. Another way to make a telephone number memorable is to group the digits in a memorable way. You could order your pizza from Pizza Hut by calling their ``three tens'' number 3-10-10-10.


The standard form of a telephone number is seven decimal digits with a hyphen between the third and fourth digits (e.g. 888-1200). The keypad of a phone supplies the mapping of letters to numbers, as follows:


A, B, and C map to 2

D, E, and F map to 3

G, H, and I map to 4

J, K, and L map to 5

M, N, and O map to 6

P, R, and S map to 7

T, U, and V map to 8

W, X, and Y map to 9


There is no mapping for Q or Z. Hyphens are not dialed, and can be added and removed as necessary. The standard form of TUT-GLOP is 888-4567, the standard form of 310-GINO is 310-4466, and the standard form of 3-10-10-10 is 310-1010.


Two telephone numbers are equivalent if they have the same standard form. (They dial the same number.)


Your company is compiling a directory of telephone numbers from local businesses. As part of the quality control process you want to check that no two (or more) businesses in the directory have the same telephone number.

Input 

The first line of the input contains the number of datasets in the input. A blank line follows. The first line of each dataset specifies the number of telephone numbers in the directory (up to 100,000) as a positive integer alone on the line. The remaining lines list the telephone numbers in the directory, with each number alone on a line. Each telephone number consists of a string composed of decimal digits, uppercase letters (excluding Q and Z) and hyphens. Exactly seven of the characters in the string will be digits or letters. There's a blank line between datasets.
Output 

Generate a line of output for each telephone number that appears more than once in any form. The line should give the telephone number in standard form, followed by a space, followed by the number of times the telephone number appears in the directory. Arrange the output lines by telephone number in ascending lexicographical order. If there are no duplicates in the input print the line:
No duplicates.
Print a blank line between datasets.

Sample Input 

1

12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279
Sample Output 

310-1010 2
487-3279 4
888-4567 3
*/

#define ONLINE_JUAGE
#pragma warning(disable:4786)
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
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
	typedef map<string, int>::iterator s_i_iter;
	int N;
	cin>>N;
	while(N--) {

		map<string, int> m;
		int M;
		cin>>M;
		while (M--) {
			string strTel;
			cin>>strTel;
			string telNum = "";
			for (int i=0, j=0; i<strTel.size() && j<7; ++i) {
				char ch = toupper(strTel[i]);
				if (isalpha(ch)) { 					
					char tmp;
					switch (ch) {
					case 'A':
					case 'B':
					case 'C':
						tmp = '2';
						break;
					case 'D':
					case 'E':
					case 'F':
						tmp = '3';
						break;
					case 'G':
					case 'H':
					case 'I':
						tmp = '4';
						break;
					case 'J':
					case 'K':
					case 'L':
						tmp = '5';
						break;
					case 'M':
					case 'N':
					case 'O':
						tmp = '6';
						break;
					case 'P':
					case 'R':
					case 'S':
						tmp = '7';
						break;
					case 'T':
					case 'U':
					case 'V':
						tmp = '8';
						break;
					case 'W':
					case 'X':
					case 'Y':
						tmp = '9';
						break;
					}

					telNum += tmp;
					++j;
					if (j==3) {
						telNum += '-';
					}
				} else if (isdigit(strTel[i])) {
					telNum += strTel[i];
					++j;
					if (j==3) {
						telNum += '-';
					}
				}
				
			}

			pair<s_i_iter, bool> res = m.insert(make_pair(telNum, 1));
			if (!res.second) {
				++ res.first->second;
			}
		}
		bool noDuplicate = true;
		for (s_i_iter iter=m.begin(); iter!=m.end(); ++iter) {
			if (iter->second>1) {
				noDuplicate = false;
				cout<<iter->first<<" "<<iter->second<<endl;
			}		
		}
		if (noDuplicate) {
			cout<<"No duplicates."<<endl;
		}
		if (N) {
			cout<<endl;
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

