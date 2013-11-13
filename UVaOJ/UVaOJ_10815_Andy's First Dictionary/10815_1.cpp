/**
Problem B: Andy's First Dictionary

Time limit: 3 seconds



Andy, 8, has a dream - he wants to produce his very own dictionary. This is not an easy task for him, as the number of words that he knows is, well, not quite enough. Instead of thinking up all the words himself, he has a briliant idea. From his bookshelf he would pick one of his favourite story books, from which he would copy out all the distinct words. By arranging the words in alphabetical order, he is done! Of course, it is a really time-consuming job, and this is where a computer program is helpful.

You are asked to write a program that lists all the different words in the input text. In this problem, a word is defined as a consecutive sequence of alphabets, in upper and/or lower case. Words with only one letter are also to be considered. Furthermore, your program must be CaSe InSeNsItIvE. For example, words like "Apple", "apple" or "APPLE" must be considered the same.

Input

The input file is a text with no more than 5000 lines. An input line has at most 200 characters. Input is terminated by EOF.

Output

Your output should give a list of different words that appears in the input text, one in a line. The words should all be in lower case, sorted in alphabetical order. You can be sure that he number of distinct words in the text does not exceed 5000.

Sample Input

Adventures in Disneyland

Two blondes were going to Disneyland when they came to a fork in the
road. The sign read: "Disneyland Left."

So they went home.
Sample Output

a
adventures
blondes
came
disneyland
fork
going
home
in
left
read
road
sign
so
the
they
to
two
went
were
when
*/
//#pragma warning(disable:4786)
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <fstream>
using namespace std;
#define ONLINE_JUAGE
int main() {

#ifndef ONLINE_JUAGE
	ifstream in("10010_i.txt");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	
	ofstream out("10010_o.txt");
	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
#endif
	string str;

	set<string> s;

	while (getline(cin,str)) {
		str += ".";
		bool wordStart = false;
		string word = "";
		for (int i=0; i<str.size(); ++i) {
			if (!isalpha(str[i])) {
				if (wordStart) {
					s.insert(word);
					word = "";
				}
				wordStart = false;
			} else {
				if (!wordStart) {
					wordStart = true;
					word = tolower(str[i]);
				} else {
					word += tolower(str[i]);
				}
			}
		}
		str.erase(str.end()-1);
	}


/*
	set<string> s;
	s.insert("a");
	s.insert("b");
*/
//	copy(s.begin(), s.end(), ostream_iterator<string>(cout, "\n"));
	set<string>::iterator iter;
	for (iter=s.begin(); iter!=s.end(); ++iter) {
		cout<<*iter<<endl;
	}

#ifndef ONLINE_JUAGE
	in.close();
	out.close();
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif

	return 0;
}