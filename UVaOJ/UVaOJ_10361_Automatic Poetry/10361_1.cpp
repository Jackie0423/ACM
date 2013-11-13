#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
/**
Problem I
Automatic Poetry
Input: standard input
Output: standard output
Time Limit: 2 seconds
Memory Limit: 32 MB
 
¡°Oh God¡±, Lara Croft exclaims, ¡°it¡¯s one of these dumb riddles again!¡±
 
In Tomb Raider XIV, Lara is, as ever, gunning her way through ancient Egyptian pyramids, prehistoric caves and medival hallways. Now she is standing in front of some important Germanic looking doorway and has to solve a linguistic riddle to pass. As usual, the riddle is not very intellectually challenging.
 
This time, the riddle involves poems containing a ¡°Schuttelreim¡±. An example of a Schuttelreim is the following short poem:
 
Ein Kind halt seinen Schnabel nur,
wenn es hangt an der Nabelschnur.        
 
//German contestants please forgive me. I had to modify something as they were not appearing correctly in plain text format
 
A Schuttelreim seems to be a typical German invention. The funny thing about this strange type of poetry is that if somebody gives you the first line and the beginning of the second one, you can complete the poem yourself. Well, even a computer can do that, and your task is to write a program which completes them automatically. This will help Lara concentrate on the ¡°action¡± part of Tomb Raider and not on the ¡°intellectual¡± part.
Input

The input will begin with a line containing a single number n. After this line follow n pairs of lines containing Schuttelreims. The first line of each pair will be of the form
s1<s2>s3<s4>s5
 
where the si are possibly empty, strings of lowercase characters or blanks. The second line will be a string of lowercase characters or blanks ending with three dots ¡°...¡±. Lines will we at most 100 characters long.
Output

For each pair of Schuttelreim lines l1 and l2 you are to output two lines c1 and c2 in the following way: c1 is the same as l1 only that the bracket marks ¡°<¡± and ¡°>¡± are removed. Line c2 is the same as l2 , except that instead of the three dots the string s4s3s2s5 should appear.

Sample Input

3
ein kind haelt seinen <schn>abel <n>ur
wenn es haengt an der ...
weil wir zu spaet zur <>oma <k>amen
verpassten wir das ...
<d>u <b>ist
...
Sample Output

ein kind haelt seinen schnabel nur
wenn es haengt an der nabel schnur
weil wir zu spaet zur oma kamen
verpassten wir das koma amen
du bist
bu dist
*/
using namespace std;
const int nMax = 100;
int main() {

#ifndef ONLINE_JUDGE
	streambuf * cinbuf = cin.rdbuf();
	ifstream in("10010_i.txt");
	cin.rdbuf(in.rdbuf());

	ofstream out("10010_o.txt");
	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
#endif
	int k;
	cin>>k;
//	getchar();
	cin.ignore();
	while (k--) {
		char cstr1[nMax+1], cstr2[nMax+1];
		cin.getline(cstr1, nMax+1);
		cin.getline(cstr2, nMax+1);
//		getchar();
		string str1(cstr1), str2(cstr2);
		string s1="", s2="", s3="", s4="";
		int i=0;
		for (; str1[i]!='<'; ++i) {
			cout<<str1[i];
		}
		for (i++; str1[i]!='>'; ++i) {
			cout<<str1[i];
			s1 += str1[i];
		}
		for (i++; str1[i]!='<'; ++i) {
			cout<<str1[i];
			s2 += str1[i];
		}
		for (i++; str1[i] != '>'; ++i) {
			cout<<str1[i];
			s3 += str1[i];
		}
		for (i++; i<str1.size(); ++i) {
			cout<<str1[i];
			s4 += str1[i];
		}

		cout<<endl;

		for (i=0; i<str2.size()-3; ++i) {
			cout<<str2[i];
		}
		cout<<s3+s2+s1+s4<<endl;
	}

#ifndef ONLINE_JUDGE
	in.close();
	out.flush();
	out.close();
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif
	return 0;
}