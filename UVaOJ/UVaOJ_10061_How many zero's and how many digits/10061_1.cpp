/*
Problem G
How many zeros and how many digits?
Input: standard input
Output: standard output

Given a decimal integer number you will have to find out how many trailing zeros will be there in its factorial in a given number system and also you will have to find how many digits will its factorial have in a given number system? You can assume that for a b based number system there are b different symbols to denote values ranging from 0 ... b-1.

Input
There will be several lines of input. Each line makes a block. Each line will contain a decimal number N (a 20bit unsigned number) and a decimal number B (1<B<=800), which is the base of the number system you have to consider. As for example 5! = 120 (in decimal) but it is 78 in hexadecimal number system. So in Hexadecimal 5! has no trailing zeros

Output
For each line of input output in a single line how many trailing zeros will the factorial of that number have in the given number system and also how many digits will the factorial of that number have in that given number system. Separate these two numbers with a single space. You can be sure that the number of trailing zeros or the number of digits will not be greater than 2^31-1

Sample Input:
2 10
5 16
5 10
 
Sample Output:
0 1
0 2
1 3
*/
/*
解题思路：
分析如下：

1.   求末尾0的个数：

思路是将N!分解为素数的积，记录下<=B的素数因子的个数（小于等于B的原因代码中解释了）。然后不断地从N!的因子中提取因子，使之刚好能乘积为B，则这几个因子可使N!在B进制下末尾产生一个0，直到提取不出为止。（当然，写代码的思路是不断分解B，当不能找到N!中小于等于B的因子用来分解B时结束）。记录下上述过程中B被分解了几次，即在末尾产生了几个0.

2.  求总的位数：

由于B进制下m位数所能表示的最大值在十进制下为B^m-1，故 

设总位数为m，则 B^(m-1) -1 < N! <= B^m -1,即 B^(m-1) <= N! < B^m

取10为底的对数得到：     (m-1)*log10(B) <= log10(N!) < m*log10(B)

故得到求总的位数m的方法。
*/
#define ONLINE_JUAGE
#pragma warning(disable:4786)
#include <iostream>
#include <complex>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;

int factor_count[1000]; //用来记录小于等于B的因子的个数
int N,B;

int main() {

#ifndef ONLINE_JUAGE
	ifstream in("10010_i.txt");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	
	ofstream out("10010_o.txt");
	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
#endif
	int ZeroNum();
	int DigitNum();
	while(cin >> N >> B)
	{
		cout << ZeroNum() << ' ' << DigitNum() << endl;
	}
		
#ifndef ONLINE_JUAGE
	in.close();
	out.close();
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif

	return 0;
}



int ZeroNum()
{
	//decompose N!
	fill(factor_count,factor_count+1000,0);
	for(int i=2; i<=N; i++)
	{//decompose i
		int tmp=i;
		for(int j=2; j<=tmp && j<=B; j++)	//只需要小于等于B的因子，因为大于B的因子一定不会成为B的因子
		{
			while(tmp%j==0)
			{
				factor_count[j]++;
				tmp /= j;
			}
		}
	}
	int nZero=0;
	while(1)
	{//decompose B
		int tmp=B;
		for(int i=2; i<=tmp; i++)
		{
			while(tmp%i==0 && factor_count[i]>0)
			{
				factor_count[i]--;
				tmp /= i;
			}
		}
		if(tmp==1) nZero++;
		else break;
	}
	return nZero;
}

int DigitNum()
{
	//compute logB(N!)
	double sum=0;
	for(int i=2; i<=N; i++)
		sum += log10(double(i));
	sum /= log10(double(B));
	//comput digits num
	return floor(sum+1e-9) + 1;
	
}

