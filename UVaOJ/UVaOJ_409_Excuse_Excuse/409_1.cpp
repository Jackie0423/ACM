//#pragma warning(disable:4786)
/**
 Excuses, Excuses! 

Judge Ito is having a problem with people subpoenaed for jury duty giving rather lame excuses in order to avoid serving. In order to reduce the amount of time required listening to goofy excuses, Judge Ito has asked that you write a program that will search for a list of keywords in a list of excuses identifying lame excuses. Keywords can be matched in an excuse regardless of case.

Input

Input to your program will consist of multiple sets of data.

Line 1 of each set will contain exactly two integers. The first number ( tex2html_wrap_inline30 ) defines the number of keywords to be used in the search. The second number ( tex2html_wrap_inline32 ) defines the number of excuses in the set to be searched.
Lines 2 through K+1 each contain exactly one keyword.
Lines K+2 through K+1+E each contain exactly one excuse.
All keywords in the keyword list will contain only contiguous lower case alphabetic characters of length L ( tex2html_wrap_inline42 ) and will occupy columns 1 through L in the input line.
All excuses can contain any upper or lower case alphanumeric character, a space, or any of the following punctuation marks [SPMamp".,!?&] not including the square brackets and will not exceed 70 characters in length.
Excuses will contain at least 1 non-space character.
Output

For each input set, you are to print the worst excuse(s) from the list.

The worst excuse(s) is/are defined as the excuse(s) which contains the largest number of incidences of keywords.
If a keyword occurs more than once in an excuse, each occurrance is considered a separate incidence.
A keyword ``occurs" in an excuse if and only if it exists in the string in contiguous form and is delimited by the beginning or end of the line or any non-alphabetic character or a space.
For each set of input, you are to print a single line with the number of the set immediately after the string ``Excuse Set #". (See the Sample Output). The following line(s) is/are to contain the worst excuse(s) one per line exactly as read in. If there is more than one worst excuse, you may print them in any order.

After each set of output, you should print a blank line.

Sample Input

5 3
dog
ate
homework
canary
died
My dog ate my homework.
Can you believe my dog died after eating my canary... AND MY HOMEWORK?
This excuse is so good that it contain 0 keywords.
6 5
superhighway
crazy
thermonuclear
bedroom
war
building
I am having a superhighway built in my bedroom.
I am actually crazy.
1234567890.....,,,,,0987654321?????!!!!!!
There was a thermonuclear war!
I ate my dog, my canary, and my homework ... note outdated keywords?
Sample Output

Excuse Set #1
Can you believe my dog died after eating my canary... AND MY HOMEWORK?

Excuse Set #2
I am having a superhighway built in my bedroom.
There was a thermonuclear war!
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
	
	int K, E;

	int cases = 0;
	while (cin>>K>>E) {
		
		
		vector<string> keywords;
		
		vector<string> excuses;
		int i;
		for (i=0; i<K; ++i) {
			string str;
			cin>>str;
			keywords.push_back(str);
		}

		cin.ignore();

		for (i=0; i<E; ++i) {
			string str;
			getline(cin, str);
			excuses.push_back(str);
		}
		int getNum(string &, vector<string> &);
		int worstIndex = 0;
		int worstNum = -1;

		//first is count, second is index
		
		typedef pair<int, int> ii_pair;
		vector<ii_pair> vec;
		for (i=0; i<E; ++i) {
			int count = getNum(excuses[i], keywords);
			if (count > worstNum) {
				worstNum = count;
			}
			vec.push_back(make_pair(count, i));			
		}

		cout<<"Excuse Set #"<<++cases<<endl;
		for (i=0; i<vec.size(); ++i) {
			if (vec[i].first == worstNum) {
				cout<<excuses[vec[i].second]<<endl;
			}
		}

	}
	
	return 0;
}

int getNum(string & excuse, vector<string> &keywords) {

//	vector<string> words;

	set<string> m;
	
	int i;
	for (i=0; i<keywords.size(); ++i) {
		m.insert(keywords[i]);
	}
	
	int count = 0;

	bool wordStart = false;

	excuse += ".";

	string tempStr = "";


	for (i=0; i<excuse.size(); ++i) {

		if (isalpha(excuse[i])) {
			if (wordStart) {
				tempStr += excuse[i];
			} else {
				tempStr = "";
				wordStart = true;
				tempStr += excuse[i];
			}
		} else if (wordStart) {
			string strTemp(tempStr);
			for (int i=0; i<strTemp.size(); ++i) {
				if(isupper(strTemp[i])) {
					strTemp[i] += 32;
				}
			}
			if (m.count(strTemp)) {
				++count;
			}
			wordStart = false;
		}
			
					
	}
	excuse.erase(excuse.end()-1);
	return count;
}
