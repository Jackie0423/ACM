/*
  Multiplying by Rotation 
Warning: Not all numbers in this problem are decimal numbers!


Multiplication of natural numbers in general is a cumbersome operation. In some cases however the product can be obtained by moving the last digit to the front.


Example: 179487 * 4 = 717948


Of course this property depends on the numbersystem you use, in the above example we used the decimal representation. In base 9 we have a shorter example:


17 * 4 = 71 (base 9)


as (9 * 1 + 7) * 4 = 7 * 9 + 1

Input 

The input for your program is a textfile. Each line consists of three numbers separated by a space: the base of the number system, the least significant digit of the first factor, and the second factor. This second factor is one digit only hence less than the base. The input file ends with the standard end-of-file marker.
Output 

Your program determines for each input line the number of digits of the smallest first factor with the rotamultproperty. The output-file is also a textfile. Each line contains the answer for the corresponding input line.
Sample Input 

10 7 4
9 7 4
17 14 12
Sample Output 

6
2
4

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

	int base, k, second;

	while(cin>>base>>k>>second) {
		int an = k;
		int count = 0;
		int c = 0;
		int tmp;
		do {			
			tmp = an*second+c;
			an = tmp % base;
			c = tmp / base;
			++count;
		} while (an != k || c);
		
		cout<<count<<endl;
	}

#ifndef ONLINE_JUAGE
	in.close();
	out.close();
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif

	return 0;
}
