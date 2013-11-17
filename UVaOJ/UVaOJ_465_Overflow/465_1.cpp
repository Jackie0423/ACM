/*
 Overflow 

Write a program that reads an expression consisting of two non-negative integer and an operator. Determine if either integer or the result of the expression is too large to be represented as a ``normal'' signed integer (type integer if you are working Pascal, type int if you are working in C).

Input

An unspecified number of lines. Each line will contain an integer, one of the two operators + or *, and another integer.

Output

For each line of input, print the input followed by 0-3 lines containing as many of these three messages as are appropriate: ``first number too big'', ``second number too big'', ``result too big''.

Sample Input

300 + 3
9999999999999999999999 + 11
Sample Output

300 + 3
9999999999999999999999 + 11
first number too big
result too big
*/
#define ONLINE_JUAGE
#include <iostream>
#include <sstream>
#include <string>
#include <climits>
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
	string str;

	while (getline(cin, str)) {
		cout<<str<<endl;
		stringstream ss(str);
		double d1,d2;
		char op;
		ss>>d1>>op>>d2;

		
		if (d1>INT_MAX) {
			cout<<"first number too big"<<endl;
		} 
		if (d2>INT_MAX) {
			cout<<"second number too big"<<endl;
		}
        
        if(('+'==op && (d1+d2)>INT_MAX) || ('*'==op && (d1*d2)>INT_MAX)) {
            cout<<"result too big"<<endl;
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
