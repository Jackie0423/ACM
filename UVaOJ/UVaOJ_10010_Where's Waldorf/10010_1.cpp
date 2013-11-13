#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

/**
  Where's Waldorf? 
Given a m by n grid of letters, (  ), and a list of words, find the location in the grid at which the word can be found. A word matches a straight, uninterrupted line of letters in the grid. A word can match the letters in the grid regardless of case (i.e. upper and lower case letters are to be treated as the same). The matching can be done in any of the eight directions either horizontally, vertically or diagonally through the grid.
Input 

The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs.
The input begins with a pair of integers, m followed by n,   in decimal notation on a single line. The next m lines contain n letters each; this is the grid of letters in which the words of the list must be found. The letters in the grid may be in upper or lower case. Following the grid of letters, another integer k appears on a line by itself (  ). The next k lines of input contain the list of words to search for, one word per line. These words may contain upper and lower case letters only (no spaces, hyphens or other non-alphabetic characters).

Output 

For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line.
For each word in the word list, a pair of integers representing the location of the corresponding word in the grid must be output. The integers must be separated by a single space. The first integer is the line in the grid where the first letter of the given word can be found (1 represents the topmost line in the grid, and m represents the bottommost line). The second integer is the column in the grid where the first letter of the given word can be found (1 represents the leftmost column in the grid, and n represents the rightmost column in the grid). If a word can be found more than once in the grid, then the location which is output should correspond to the uppermost occurence of the word (i.e. the occurence which places the first letter of the word closest to the top of the grid). If two or more words are uppermost, the output should correspond to the leftmost of these occurences. All words can be found at least once in the grid.

Sample Input 

1

8 11
abcDEFGhigg
hEbkWalDork
FtyAwaldORm
FtsimrLqsrc
byoArBeDeyv
Klcbqwikomk
strEBGadhrb
yUiqlxcnBjf
4
Waldorf
Bambi
Betty
Dagbert
Sample Output 

2 5
2 3
1 2
7 8

*/

/*
cannot be accept. I don't know why?
*/
int main() {

	//count of test
	int t;

	//m : row, n: column
	int m,n;

	//
	int k;
	cin>>t;
	while (t--) {
		cin>>m>>n;
		vector<string> vec;
		for (int i=0; i<m; ++i) {
			string str;
			cin>>str;
			string strTemp = "";
			for (int j=0; j<n; j++) {
				strTemp += tolower(str[j]);
			}
//			transform(str.begin(), str.end(), str.begin(), tolower);
			vec.push_back(strTemp);
		}
		cin>>k;

		vector<string> testVec;
		for (int i=0; i<k; ++i) {
			string str;
			cin>>str;
			int strLen = str.size();
			string strTemp = "";
			for (int j=0; j<strLen; j++) {
				strTemp += tolower(str[j]);
			}
			testVec.push_back(strTemp);
		}
		pair<int,int> FindFirstAdapt(vector<string> &, int, int, string &);
		for (int i=0; i<k; ++i) {
			pair<int,int> p = FindFirstAdapt(vec, m, n, testVec[i]);
			cout<<p.first<<" "<<p.second<<endl;
		}
	}
	return 0;
}

pair<int,int> FindFirstAdapt(vector<string> &vec, int m, int n, string & str) {

	int p, q;

	int sz = str.size();
	for (int i=0; i<m; ++i) {
		int offset = 0;
		bool found = false;
		while (string::npos != (q=vec[i].find(str[0], offset))) {
			offset = q+1;
			//right			
			bool ok = true;
			if (n-q>=sz) {
				for (int j=q, kk=0; kk<sz; ++j,++kk) {
					if (vec[i][j] != str[kk]) {
						ok = false;
						break;
					}
				}
				
			} else {
				ok = false;
			}
			if (ok) {
				found = true;
				break;
			}


			//left
			ok = true;
			if (q+1>=sz) {
				for (int j=q, kk=0; kk<sz; --j,++kk) {
					if (vec[i][j] != str[kk]) {
						ok = false;
						break;
					}
				}
				
			} else {
				ok = false;
			}
			if (ok) {
				found = true;
				break;
			}

			//up			
			ok = true;
			if (i+1>=sz) {
				for (int j=i, kk=0; kk<sz; --j,++kk) {
					if (vec[j][q] != str[kk]) {
						ok = false;
						break;
					}
				}

			} else {
				ok = false;
			}
			if (ok) {
				found = true;
				break;
			}
			
			//down
			ok = true;
			if (m-i>=sz) {
				for (int j=i, kk=0; kk<sz; ++j,++kk) {
					if (vec[j][q] != str[kk]) {
						ok = false;
						break;
					}
				}
				
			} else {
				ok = false;
			}
			if (ok) {
				found = true;
				break;
			}

			//right-up
			ok = true;
			if (min(i+1, n-q)>=sz) {
				for (int j=i, jj=q, kk=0; kk<sz; --j,++jj,++kk) {
					if (vec[j][jj] != str[kk]) {
						ok = false;
						break;
					}
				}
				
			} else {
				ok = false;
			}
			if (ok) {
				found = true;
				break;
			}

			//left-up
			ok = true;
			if (min(i+1, q+1)>=sz) {
				for (int j=i, jj=q, kk=0; kk<sz; --j,--jj,++kk) {
					if (vec[j][jj] != str[kk]) {
						ok = false;
						break;
					}
				}
				
			} else {
				ok = false;
			}
			if (ok) {
				found = true;
				break;
			}

			//right-down
			ok = true;
			if (min(m-i, n-q)>=sz) {
				for (int j=i, jj=q, kk=0; kk<sz; ++j,++jj,++kk) {
					if (vec[j][jj] != str[kk]) {
						ok = false;
						break;
					}
				}
				
			} else {
				ok = false;
			}
			if (ok) {
				found = true;
				break;
			}
			
			//left-down
			ok = true;
			if (min(m-i, q+1)>=sz) {
				for (int j=i, jj=q, kk=0; kk<sz; ++j,--jj,++kk) {
					if (vec[j][jj] != str[kk]) {
						ok = false;
						break;
					}
				}
				
			} else {
				ok = false;
			}
			if (ok) {
				found = true;
				break;
			}

		}

		if (found) {
			p = i;
			break;
		}
		

	}
	return make_pair(p+1,q+1);
}