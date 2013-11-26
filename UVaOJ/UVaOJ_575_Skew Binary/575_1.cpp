/*
  Skew Binary 
When a number is expressed in decimal, the k-th digit represents a multiple of 10k. (Digits are numbered from right to left, where the least significant digit is number 0.) For example, 

\begin{displaymath}81307_{10} = 8 \times 10^4 + 1 \times 10^3 + 3 \times 10^2 + ...
...mes 10^1 +
7 \times 10 0 = 80000 + 1000 + 300 + 0 + 7
= 81307.
\end{displaymath}

When a number is expressed in binary, the k-th digit represents a multiple of 2k. For example, 

\begin{displaymath}10011_2 = 1 \times 2^4 + 0 \times 2^3 + 0 \times 2^2 + 1 \times 2^1 +
1 \times 2^0 = 16 + 0 + 0 + 2 + 1 = 19.
\end{displaymath}

In skew binary, the k-th digit represents a multiple of 2k+1 - 1. The only possible digits are 0 and 1, except that the least-significant nonzero digit can be a 2. For example, 

\begin{displaymath}10120_{skew} = 1 \times (2^5 - 1) + 0 \times (2^4-1) + 1 \tim...
...2 \times (2^2-1) + 0 \times (2^1-1)
= 31 + 0 + 7 + 6 + 0 = 44.
\end{displaymath}

The first 10 numbers in skew binary are 0, 1, 2, 10, 11, 12, 20, 100, 101, and 102. (Skew binary is useful in some applications because it is possible to add 1 with at most one carry. However, this has nothing to do with the current problem.)

Input 

The input file contains one or more lines, each of which contains an integer n. If n = 0 it signals the end of the input, and otherwise n is a nonnegative integer in skew binary.
Output 

For each number, output the decimal equivalent. The decimal value of n will be at most 231 - 1 = 2147483647.
Sample Input 

10120
200000000000000000000000000000
10
1000000000000000000000000000000
11
100
11111000001110000101101102000
0
Sample Output 

44
2147483646
3
2147483647
4
7
1041110737

*/
#define ONLINE_JUAGE
#pragma warning(disable:4786)
#include <iostream>
#include <string>
#include <vector>
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
	while(cin>>str && str!="0") {
		int sum = 0;
		for (int i=str.size()-1, j=1; i>=0; --i, ++j) {
			sum += (str[i]-'0')*((1<<j)-1);
		}

		cout<<sum<<endl;
	}

#ifndef ONLINE_JUAGE
	in.close();
	out.close();
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif

	return 0;
}
