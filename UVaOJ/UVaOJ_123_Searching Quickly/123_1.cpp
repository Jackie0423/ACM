/*
 Searching Quickly 

Background

Searching and sorting are part of the theory and practice of computer science. For example, binary search provides a good example of an easy-to-understand algorithm with sub-linear complexity. Quicksort is an efficient  tex2html_wrap_inline29 [average case] comparison based sort.

KWIC-indexing is an indexing method that permits efficient ``human search'' of, for example, a list of titles.

The Problem

Given a list of titles and a list of ``words to ignore'', you are to write a program that generates a KWIC (Key Word In Context) index of the titles. In a KWIC-index, a title is listed once for each keyword that occurs in the title. The KWIC-index is alphabetized by keyword.

Any word that is not one of the ``words to ignore'' is a potential keyword.

For example, if words to ignore are ``the, of, and, as, a'' and the list of titles is:

Descent of Man
The Ascent of Man
The Old Man and The Sea
A Portrait of The Artist As a Young Man
A KWIC-index of these titles might be given by:

                      a portrait of the ARTIST as a young man 
                                    the ASCENT of man 
                                        DESCENT of man 
                             descent of MAN 
                          the ascent of MAN 
                                the old MAN and the sea 
    a portrait of the artist as a young MAN 
                                    the OLD man and the sea 
                                      a PORTRAIT of the artist as a young man 
                    the old man and the SEA 
          a portrait of the artist as a YOUNG man
The Input

The input is a sequence of lines, the string :: is used to separate the list of words to ignore from the list of titles. Each of the words to ignore appears in lower-case letters on a line by itself and is no more than 10 characters in length. Each title appears on a line by itself and may consist of mixed-case (upper and lower) letters. Words in a title are separated by whitespace. No title contains more than 15 words.

There will be no more than 50 words to ignore, no more than than 200 titles, and no more than 10,000 characters in the titles and words to ignore combined. No characters other than 'a'-'z', 'A'-'Z', and white space will appear in the input.

The Output

The output should be a KWIC-index of the titles, with each title appearing once for each keyword in the title, and with the KWIC-index alphabetized by keyword. If a word appears more than once in a title, each instance is a potential keyword.

The keyword should appear in all upper-case letters. All other words in a title should be in lower-case letters. Titles in the KWIC-index with the same keyword should appear in the same order as they appeared in the input file. In the case where multiple instances of a word are keywords in the same title, the keywords should be capitalized in left-to-right order.

Case (upper or lower) is irrelevant when determining if a word is to be ignored.

The titles in the KWIC-index need NOT be justified or aligned by keyword, all titles may be listed left-justified.

Sample Input

is
the
of
and
as
a
but
::
Descent of Man
The Ascent of Man
The Old Man and The Sea
A Portrait of The Artist As a Young Man
A Man is a Man but Bubblesort IS A DOG
Sample Output

a portrait of the ARTIST as a young man 
the ASCENT of man 
a man is a man but BUBBLESORT is a dog 
DESCENT of man 
a man is a man but bubblesort is a DOG 
descent of MAN 
the ascent of MAN 
the old MAN and the sea 
a portrait of the artist as a young MAN 
a MAN is a man but bubblesort is a dog 
a man is a MAN but bubblesort is a dog 
the OLD man and the sea 
a PORTRAIT of the artist as a young man 
the old man and the SEA 
a portrait of the artist as a YOUNG man
*/
#define ONLINE_JUAGE
#pragma warning(disable:4786)
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <cmath>
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
	
	string tmp;

	set<string> ignoreWords;
	typedef set<string>::iterator ss_iter;
	typedef vector<string>::iterator vs_iter;
	while (cin>>tmp && tmp!="::") {
		ignoreWords.insert(tmp);
	}

	cin.ignore();

	vector<vector<string> > sentences;

	set<string> keyWords;
	while(getline(cin, tmp)) {
		transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
		stringstream ss(tmp);
		vector<string> sentence;
		string wordTmp;
		while (ss>>wordTmp) {
			sentence.push_back(wordTmp);
			if (ignoreWords.count(wordTmp) < 1) {
				keyWords.insert(wordTmp);
			}
		}
		sentences.push_back(sentence);
	}
	
	for (ss_iter iter=keyWords.begin(); iter!=keyWords.end(); ++iter) {

		for (int i=0; i<sentences.size(); ++i) {
		
			vs_iter offsetIter = sentences[i].begin();
			vs_iter endIter = sentences[i].end();
			vs_iter res;
			while (endIter!=(res=find(offsetIter, endIter, *iter))) {
				vs_iter vsiter;
				for (vsiter=sentences[i].begin(); vsiter!=res; ++vsiter) {
					cout<<*vsiter<<" ";
				}
				string resTemp(*res);
				transform(resTemp.begin(), resTemp.end(), resTemp.begin(), ::toupper);
				if (vsiter+1 != endIter) {
					cout<<resTemp<<" ";
					++vsiter;
					while(vsiter+1!=endIter) {
						cout<<*vsiter<<" ";
						++vsiter;
					}
					cout<<*vsiter<<endl;
				} else {
					cout<<resTemp<<endl;
				}

				offsetIter = res+1;
			}
			
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

