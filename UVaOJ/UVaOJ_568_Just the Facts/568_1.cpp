/*
  Just the Facts 
The expression N!, read as ``N factorial," denotes the product of the first N positive integers, where N is nonnegative. So, for example,
N	N!
0	 1
1	 1
2	 2
3	 6
4	 24
5	 120
10	 3628800
For this problem, you are to write a program that can compute the last non-zero digit of any factorial for (  $0 \le N \le 10000$). For example, if your program is asked to compute the last nonzero digit of 5!, your program should produce ``2" because 5! = 120, and 2 is the last nonzero digit of 120.

Input 

Input to the program is a series of nonnegative integers not exceeding 10000, each on its own line with no other letters, digits or spaces. For each integer N, you should read the value and compute the last nonzero digit of N!.
Output 

For each integer input, the program should print exactly one line of output. Each line of output should contain the value N, right-justified in columns 1 through 5 with leading blanks, not leading zeroes. Columns 6 - 9 must contain `` -> " (space hyphen greater space). Column 10 must contain the single last non-zero digit of N!.
Sample Input 

1
2
26
125
3125
9999
Sample Output 

    1 -> 1
    2 -> 2
   26 -> 4
  125 -> 8
 3125 -> 2
 9999 -> 8
*/
#define ONLINE_JUAGE
#pragma warning(disable:4786)
#include <iostream>
#include <string>
#include <iomanip>
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

	int N;
	cout.setf(ios_base::right, ios_base::adjustfield);
	while (cin>>N) {
		int num_5 = 0;
		int num_2 = 0;
		
		int digit = 1;
		for (int i=1; i<=N; ++i) {
			int tmp = i;
			while (!(tmp & 0x01)) {
				tmp>>=1;
				++ num_2;
			}
			
			while(tmp%5==0) {
				tmp/=5;
				++ num_5;
			}

			digit = (digit * (tmp % 10))%10;
		}

		int n = num_2-num_5;
		if (n) {
			switch(n % 4) {
			case 0:
				digit = (digit*6)%10;
				break;	
			case 1:
				digit = (digit*2)%10;
				break;
			case 2:
				digit = (digit*4)%10;
				break;
			case 3:
				digit = (digit*8)%10;
				break;
		
			}
		}
		
		cout<<setw(5)<<N<<" -> "<<digit<<endl;
	}

#ifndef ONLINE_JUAGE
	in.close();
	out.close();
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif

	return 0;
}
