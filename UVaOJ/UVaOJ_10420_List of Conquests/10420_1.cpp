/**
Problem B
List of Conquests
Input: standard input
Output: standard output
Time Limit: 2 seconds

In Act I, Leporello is telling Donna Elvira about his master's long list of conquests:

``This is the list of the beauties my master has loved, a list I've made out myself: take a look, read it with me. In Italy six hundred and forty, in Germany two hundred and thirty-one, a hundred in France, ninety-one in Turkey; but in Spain already a thousand and three! Among them are country girls, waiting-maids, city beauties; there are countesses, baronesses, marchionesses, princesses: women of every rank, of every size, of every age.'' (Madamina, il catalogo ии questo)
As Leporello records all the ``beauties'' Don Giovanni ``loved'' in chronological order, it is very troublesome for him to present his master's conquest to others because he needs to count the number of ``beauties'' by their nationality each time. You are to help Leporello to count.

Input

The input consists of at most 2000 lines, but the first. The first line contains a number n, indicating that there will be n more lines. Each following line, with at most 75 characters, contains a country (the first word) and the name of a woman (the rest of the words in the line) Giovanni loved. You may assume that the name of all countries consist of only one word.

Output

The output consists of lines in alphabetical order. Each line starts with the name of a country, followed by the total number of women Giovanni loved in that country, separated by a space.

Sample Input

3
Spain Donna Elvira
England Jane Doe
Spain Donna Anna
Sample Output

England 1
Spain 2

*/
#define ONLINE_JUAGE
#pragma warning(disable:4786)
#include <iostream>
#include <fstream>
#include <string>
#include <map>
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
	typedef map<string,int>::iterator si_iter;
	int n;
	while(cin>>n) {
		map<string, int> m;
		
		string country;
		while(n--) {
			cin>>country;
			cin.ignore();
			string str;
			getline(cin, str);
			pair<si_iter, bool> p = m.insert(make_pair(country, 1));
			if (p.second == false) {
				++(p.first->second);
			}
		}

		for (si_iter iter=m.begin(); iter!=m.end(); ++iter) {
			cout<<iter->first<<" "<<iter->second<<endl;
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
