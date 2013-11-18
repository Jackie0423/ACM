/*

 Master-Mind Hints 

MasterMind is a game for two players. One of them, Designer, selects a secret code. The other, Breaker, tries to break it. A code is no more than a row of colored dots. At the beginning of a game, the players agree upon the length N that a code must have and upon the colors that may occur in a code.

In order to break the code, Breaker makes a number of guesses, each guess itself being a code. After each guess Designer gives a hint, stating to what extent the guess matches his secret code.

In this problem you will be given a secret code  tex2html_wrap_inline35 and a guess  tex2html_wrap_inline37 , and are to determine the hint. A hint consists of a pair of numbers determined as follows.

A match is a pair (i,j),  tex2html_wrap_inline41 and  tex2html_wrap_inline43 , such that  tex2html_wrap_inline45 . Match (i,j) is called strong when i = j, and is called weak otherwise. Two matches (i,j) and (p,q) are called independent when i = p if and only if j = q. A set of matches is called independent when all of its members are pairwise independent.

Designer chooses an independent set M of matches for which the total number of matches and the number of strong matches are both maximal. The hint then consists of the number of strong followed by the number of weak matches in M. Note that these numbers are uniquely determined by the secret code and the guess. If the hint turns out to be (n,0), then the guess is identical to the secret code.

Input

The input will consist of data for a number of games. The input for each game begins with an integer specifying N (the length of the code). Following these will be the secret code, represented as N integers, which we will limit to the range 1 to 9. There will then follow an arbitrary number of guesses, each also represented as N integers, each in the range 1 to 9. Following the last guess in each game will be N zeroes; these zeroes are not to be considered as a guess.

Following the data for the first game will appear data for the second game (if any) beginning with a new value for N. The last game in the input will be followed by a single zero (when a value for N would normally be specified). The maximum value for N will be 1000.

Output

The output for each game should list the hints that would be generated for each guess, in order, one hint per line. Each hint should be represented as a pair of integers enclosed in parentheses and separated by a comma. The entire list of hints for each game should be prefixed by a heading indicating the game number; games are numbered sequentially starting with 1. Look at the samples below for the exact format.

Sample Input

4
1 3 5 5
1 1 2 3
4 3 3 5
6 5 5 1
6 1 3 5
1 3 5 5
0 0 0 0
10
1 2 2 2 4 5 6 6 6 9
1 2 3 4 5 6 7 8 9 1
1 1 2 2 3 3 4 4 5 5
1 2 1 3 1 5 1 6 1 9
1 2 2 5 5 5 6 6 6 7
0 0 0 0 0 0 0 0 0 0
0
Sample Output

Game 1:
    (1,1)
    (2,0)
    (1,2)
    (1,2)
    (4,0)
Game 2:
    (2,4)
    (3,2)
    (5,0)
    (7,0)
*/

#define ONLINE_JUAGE
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
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
	int N;

	int cases = 0;
	while(cin>>N && N) {

		cout<<"Game "<<++cases<<":"<<endl;
		string strSecret,strTmp;

		cin.ignore();

		getline(cin,strTmp);
		stringstream ss(strTmp);
		string tmp;
		for (int i=0; i<N; ++i) {
			ss>>tmp;
			strSecret += tmp;			
		}

		string strSecretCopy(strSecret);
		sort(strSecretCopy.begin(), strSecretCopy.end());

		while (getline(cin, strTmp)) {
			stringstream ss(strTmp);
			int i;
			string strGuess = "";
			bool allZero = true;
			string tmp;
			for (i=0; i<N; ++i) {
				ss>>tmp;
				strGuess += tmp;
				if ("0" != tmp) {
					allZero = false;
				}
			}
			
			if (allZero) {
				break;
			}

			int strongMatch = 0, weakMatch=0;
			for (i=0; i<N; ++i) {
				if (strSecret[i]==strGuess[i]) {
					++strongMatch;
				}
			}
			
			sort(strGuess.begin(), strGuess.end());

			vector<char> vec_intersection;
			set_intersection(strSecretCopy.begin(), strSecretCopy.end(), strGuess.begin(),strGuess.end(), back_insert_iterator<vector<char> >(vec_intersection));

			weakMatch = vec_intersection.size()-strongMatch;

			cout<<"    ("<<strongMatch<<","<<weakMatch<<")"<<endl;
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
