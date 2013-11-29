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
����˼·��
�������£�

1.   ��ĩβ0�ĸ�����

˼·�ǽ�N!�ֽ�Ϊ�����Ļ�����¼��<=B���������ӵĸ�����С�ڵ���B��ԭ������н����ˣ���Ȼ�󲻶ϵش�N!����������ȡ���ӣ�ʹ֮�պ��ܳ˻�ΪB�����⼸�����ӿ�ʹN!��B������ĩβ����һ��0��ֱ����ȡ����Ϊֹ������Ȼ��д�����˼·�ǲ��Ϸֽ�B���������ҵ�N!��С�ڵ���B�����������ֽ�Bʱ����������¼������������B���ֽ��˼��Σ�����ĩβ�����˼���0.

2.  ���ܵ�λ����

����B������mλ�����ܱ�ʾ�����ֵ��ʮ������ΪB^m-1���� 

����λ��Ϊm���� B^(m-1) -1 < N! <= B^m -1,�� B^(m-1) <= N! < B^m

ȡ10Ϊ�׵Ķ����õ���     (m-1)*log10(B) <= log10(N!) < m*log10(B)

�ʵõ����ܵ�λ��m�ķ�����
*/
#define ONLINE_JUAGE
#pragma warning(disable:4786)
#include <iostream>
#include <complex>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;

int factor_count[1000]; //������¼С�ڵ���B�����ӵĸ���
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
		for(int j=2; j<=tmp && j<=B; j++)	//ֻ��ҪС�ڵ���B�����ӣ���Ϊ����B������һ�������ΪB������
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

