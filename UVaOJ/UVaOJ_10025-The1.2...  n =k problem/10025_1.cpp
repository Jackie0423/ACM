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
����˼·��
1�� 1 -1
2�� +3 +1 -1 -3
3�� +6 +4 +2 0 -2 -4 - 6
4: +8 +6 +4 +2 0 -2 -4 -6 -8
.....
n: +(n+2)(n-1)/2, +(n+2)(n-1)/2-2, +(n+2)(n-1)/2-4, ....
��˳�������������У���ż����ͬ��������1������2��ͬ������3������4��ͬ������5������6��ͬ....
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
		//������ͬ
		n = abs(n);
		//���n����������Χ������ȡ����
		int nn = static_cast<int>((pow(2*n-0.75, 0.5)-0.5));

		//�������ֵnn����Ӧ������AnnֵnnNum1
		int nnNum1 = (nn+2)*(nn-1)/2 + 1;

		//���n==nnNum1, ��n������ֵӦΪnn��
		//���n!=nnNum1, ��n������ֵӦ�����������
		if (n != nnNum1) {
			//���nn+1���ֵnnNum2����Ann+1
			int nnNum2 = (nn+3)*nn/2 + 1;
			//���nnNum1��nnNum2��ż����ͬ
			if ((nnNum1 & 0x01)==(nnNum2 & 0x01)) {
				//���nnNum1��n��ż����ͬ��n������ֵӦΪnn+1������nn+2��
				if ((nnNum1 & 0x01)==(n & 0x01) ) {
					++ nn;	
				} else {
					nn += 2;
				}
			} else {//���nnNum1��nnNum2��ż����ͬ
				//���nnNum1��n��ż����ͬ��n������ֵӦΪnn+3������nn+1��
				if ((nnNum1 & 0x01)==(n & 0x01)) {
					nn += 3;
				} else {
					++ nn;
				}
			}
		}

		//��n==0ʱ���Ƚ����⣬����ֵΪ3
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
