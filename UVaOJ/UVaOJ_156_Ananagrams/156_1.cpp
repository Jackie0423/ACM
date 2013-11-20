/*

 Ananagrams 

Most crossword puzzle fans are used to anagrams--groups of words with the same letters in different orders--for example OPTS, SPOT, STOP, POTS and POST. Some words however do not have this attribute, no matter how you rearrange their letters, you cannot form another word. Such words are called ananagrams, an example is QUIZ.

Obviously such definitions depend on the domain within which we are working; you might think that ATHENE is an ananagram, whereas any chemist would quickly produce ETHANE. One possible domain would be the entire English language, but this could lead to some problems. One could restrict the domain to, say, Music, in which case SCALE becomes a relative ananagram (LACES is not in the same domain) but NOTE is not since it can produce TONE.

Write a program that will read in the dictionary of a restricted domain and determine the relative ananagrams. Note that single letter words are, ipso facto, relative ananagrams since they cannot be ``rearranged'' at all. The dictionary will contain no more than 1000 words.

Input

Input will consist of a series of lines. No line will be more than 80 characters long, but may contain any number of words. Words consist of up to 20 upper and/or lower case letters, and will not be broken across lines. Spaces may appear freely around words, and at least one space separates multiple words on the same line. Note that words that contain the same letters but of differing case are considered to be anagrams of each other, thus tIeD and EdiT are anagrams. The file will be terminated by a line consisting of a single #.

Output

Output will consist of a series of lines. Each line will consist of a single word that is a relative ananagram in the input dictionary. Words must be output in lexicographic (case-sensitive) order. There will always be at least one relative ananagram.

Sample input

ladder came tape soon leader acme RIDE lone Dreis peat
 ScAlE orb  eye  Rides dealer  NotE derail LaCeS  drIed
noel dire Disk mace Rob dries
#
Sample output

Disk
NotE
derail
drIed
eye
ladder
soon
*/
#define ONLINE_JUAGE
#pragma warning(disable:4786)
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

struct WordAnagram {
	string oldWord;
	string newWord;

};
struct myless : public binary_function<WordAnagram, WordAnagram, bool> {
	
	bool operator()(const WordAnagram& _Left, const WordAnagram & _Right) const {
		if (_Left.newWord < _Right.newWord) {
			return true;
		} else {
			return false;
		}
	}

};

int main() {
#ifndef ONLINE_JUAGE
	ifstream in("10010_i.txt");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	ofstream out("10010_o.txt");
	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
#endif
	
	map<WordAnagram, bool, myless> m;

	typedef map<WordAnagram, bool, myless>::iterator WI_Iter;
	
	string line;
	while (getline(cin, line) && line!="#") {
		stringstream ss(line);
		
		string tmp;
		while (ss>>tmp) {

			WordAnagram wa;
			wa.oldWord = tmp;
			transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
			sort(tmp.begin(), tmp.end());
			wa.newWord = tmp;
			pair<WI_Iter, bool> p = m.insert(make_pair(wa, false));
			if(!p.second) {
				p.first->second = true;
			}
		}
	}
	set<string> s;
	for (WI_Iter iter=m.begin(); iter!=m.end(); ++iter) {
		if (false == iter->second) {
			s.insert(iter->first.oldWord);
		}		
	}
	for (set<string>::iterator iters=s.begin(); iters!=s.end(); ++iters) {
		cout<<*iters<<endl;
	}
#ifndef ONLINE_JUAGE
	in.close();
	out.close();
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif

	return 0;
}

