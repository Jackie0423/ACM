/*

  Secret Research 
At a certain laboratory results of secret research are thoroughly encrypted. A result of a single experiment is stored as an information of its completion:


`positive result', `negative result', `experiment failed' or `experiment not completed'


The encrypted result constitutes a string of digits S, which may take one of the following forms:


$\bullet$
positive result 		 S = 1 or S = 4 or S = 78 
$\bullet$
negative result 		 S = S35 
$\bullet$
experiment failed 		 S = 9S4 
$\bullet$
experiment not completed 		 S = 190S
(A sample result S35 means that if we add digits 35 from the right hand side to a digit sequence then we shall get the digit sequence corresponding to a failed experiment)


You are to write a program which decrypts given sequences of digits.

Input 

A integer n stating the number of encrypted results and then consecutive n lines, each containing a sequence of digits given as ASCII strings.
Output 

For each analysed sequence of digits the following lines should be sent to output (in separate lines):

		 + 		  for a positive result
		 - 		  for a negative result
		 * 		  for a failed experiment
		 ? 		  for a not completed experiment
In case the analysed string does not determine the experiment result, a first match from the above list should be outputted.

Sample Input 

4
78
7835
19078
944
Sample Output 

+
-
?
*

*/
#define ONLINE_JUAGE
#pragma warning(disable:4786)
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <valarray>
#include <algorithm>
#include <fstream>
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
	int cases;
	cin>>cases;
	int len;
	while (cases--) {
		cin>>str;
		if ("1" == str || "4"==str || "78"==str) {
			cout<<"+"<<endl;
		} else if ((len=str.size())>=2 && str[len-2]=='3' && str[len-1]=='5') {
			cout<<"-"<<endl;
		} else if (len>=2 && str[0]=='9'&& str[len-1]=='4') {
			cout<<"*"<<endl;
		} else if (len>=3 && str[0]=='1' && str[1]=='9' && str[2]=='0') {
			cout<<"?"<<endl;
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

