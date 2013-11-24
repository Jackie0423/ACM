/*

 The ? 1 ? 2 ? ... ? n = k problem 

The problem

Given the following formula, one can set operators '+' or '-' instead of each '?', in order to obtain a given k
? 1 ? 2 ? ... ? n = k

For example: to obtain k = 12 , the expression to be used will be:
- 1 + 2 + 3 + 4 + 5 + 6 - 7 = 12 
with n = 7

The Input

The first line is the number of test cases, followed by a blank line.

Each test case of the input contains integer k (0<=|k|<=1000000000).

Each test case will be separated by a single line.

The Output

For each test case, your program should print the minimal possible n (1<=n) to obtain k with the above formula.

Print a blank line between the outputs for two consecutive test cases.

Sample Input

2

12

-3646397
Sample Output

7

2701
*/

/*
解题思路：
1： 1 -1
2： +3 +1 -1 -3
3： +6 +4 +2 0 -2 -4 - 6
4: +8 +6 +4 +2 0 -2 -4 -6 -8
.....
n: +(n+2)(n-1)/2, +(n+2)(n-1)/2-2, +(n+2)(n-1)/2-4, ....
按顺序相邻两个数列，奇偶性相同，即数列1和数列2相同，数列3和数列4相同，数列5和数列6相同....
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
	int cases;
	cin>>cases;
	while (cases--) {
		
		int n;
		cin>>n;
		//正负相同
		n = abs(n);
		//求得n所在索引范围，索引取下限
		int nn = static_cast<int>((pow(2*n-0.75, 0.5)-0.5));

		//求得下限值nn所对应的数列Ann值nnNum1
		int nnNum1 = (nn+2)*(nn-1)/2 + 1;

		//如果n==nnNum1, 则n的索引值应为nn；
		//如果n!=nnNum1, 则n的索引值应分如下情况。
		if (n != nnNum1) {
			//求得nn+1项的值nnNum2，即Ann+1
			int nnNum2 = (nn+3)*nn/2 + 1;
			//如果nnNum1和nnNum2奇偶性相同
			if ((nnNum1 & 0x01)==(nnNum2 & 0x01)) {
				//如果nnNum1和n奇偶性相同，n的索引值应为nn+1；否则nn+2；
				if ((nnNum1 & 0x01)==(n & 0x01) ) {
					++ nn;	
				} else {
					nn += 2;
				}
			} else {//如果nnNum1和nnNum2奇偶性相同
				//如果nnNum1和n奇偶性相同，n的索引值应为nn+3；否则nn+1；
				if ((nnNum1 & 0x01)==(n & 0x01)) {
					nn += 3;
				} else {
					++ nn;
				}
			}
		}

		//当n==0时，比较特殊，索引值为3
		if (n) {
			cout<<nn<<endl;
		} else {
			cout<<3<<endl;
		}
		
		
		if (cases) {
			cout<<endl;
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
