/*
 Power of Cryptography 

Background

Current work in cryptography involves (among other things) large prime numbers and computing powers of numbers modulo functions of these primes. Work in this area has resulted in the practical use of results from number theory and other branches of mathematics once considered to be of only theoretical interest.

This problem involves the efficient computation of integer roots of numbers.

The Problem

Given an integer  tex2html_wrap_inline32 and an integer  tex2html_wrap_inline34 you are to write a program that determines  tex2html_wrap_inline36 , the positive tex2html_wrap_inline38 root of p. In this problem, given such integers n and p, p will always be of the form  tex2html_wrap_inline48 for an integer k (this integer is what your program must find).

The Input

The input consists of a sequence of integer pairs n and p with each integer on a line by itself. For all such pairs  tex2html_wrap_inline56 ,  tex2html_wrap_inline58 and there exists an integer k,  tex2html_wrap_inline62 such that  tex2html_wrap_inline64 .

The Output

For each integer pair n and p the value  tex2html_wrap_inline36 should be printed, i.e., the number k such that  tex2html_wrap_inline64 .

Sample Input

2
16
3
27
7
4357186184021382204544
Sample Output

4
3
1234
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

int max (int a, int b) {
	return a>b?a:b;
}

const int MAXLEN = 2000;
const int ZERO = 0;
const int POSITIVE = 1;
const int NEGATIVE = -1;
class BigNum {
public:
	BigNum(const int=0);
	BigNum(const string &);

	friend istream & operator>>(istream &, BigNum &);
	friend ostream & operator<<(ostream &, const BigNum &);

	BigNum operator-()const;

	const BigNum operator+(const BigNum &) const;
	BigNum & operator+=(const BigNum &);
	const BigNum operator-(const BigNum &) const;
	BigNum & operator-=(const BigNum &);
	const BigNum operator*(const BigNum &) const;
	BigNum & operator*=(const BigNum &);
	const BigNum operator/(const BigNum &) const;
	BigNum & operator/=(const BigNum &);
	const BigNum operator^(const BigNum &) const;
	const BigNum operator^(const int &) const;
	BigNum & operator^=(const int &);
	const BigNum operator%(const BigNum &) const;
	BigNum & operator%=(const BigNum &);

	const BigNum operator--(int);
	BigNum & operator--();
	const BigNum operator++(int);
	BigNum & operator++();

	bool   operator>(const BigNum &) const;
	bool   operator>=(const BigNum & other) const;
	bool   operator<(const BigNum &) const;
	bool   operator<=(const BigNum &) const;
	bool   operator==(const BigNum & other) const;

	void print();

	int getLen() {
		return len;
	};
private:
	char num[MAXLEN];
	int len;
	int sign;

	bool isZero() const;
};

BigNum::BigNum(int x) {
	fill(num, num+MAXLEN, 0);
	if (x == 0) {
		sign = ZERO;
		len = 1;
	} else {
		if (x > 0) {
			sign = POSITIVE;
		} else {
			sign = NEGATIVE;
			x = -x;
		}
		int i = 0;
		while (x != 0) {
			num[i++] = x%10;
			x /= 10;
		}
		len = i;
	}
}

BigNum::BigNum(const string & str) {
	fill(num, num+MAXLEN, 0);

	if (str[0] == '-') {
		sign = NEGATIVE;
	} else {
		sign = POSITIVE;
	}

	int i, j, k, n=str.size();

	for (i=0; i<n; ++i) {
		if (str[i]>'0' && str[i]<='9') {
			break;
		}
	}
	if (i==n) {
		sign = ZERO;
		len = 1;
		num[0] = 0;
	} else {
		for (k=n-1, j=0; k>=i; --k, ++j) {
			num[j] = str[k]-'0';
		}
		len = j;
	}
}

bool BigNum::isZero() const {
	return (sign==ZERO);
}

ostream & operator<<(ostream &out, const BigNum &bn) {
	if (bn.sign == NEGATIVE) {
		out<<"-";
	}
	for (int i=bn.len-1; i>=0; --i) {
		cout<<bn.num[i]+0;
	}
	return out;
}

istream & operator>>(istream &in, BigNum &bn) {
	string strNum;
	in>>strNum;
	bn = BigNum(strNum);
	return in;
}

bool BigNum::operator>(const BigNum & other) const {
	if (sign == other.sign) {
		bool flag = (sign == POSITIVE);
		if (len != other.len) {
			return flag & (len>other.len);
		} else {
			int i;
			for (i=len-1; i>=0; --i) {
				if (num[i] > other.num[i]) {
					return (flag ? true:false);
				} else if (num[i] < other.num[i]) {
					return (flag?false:true);
				}				
			}
			return false;
		}
	} else {
		return sign>other.sign;
	}
}

bool BigNum::operator==(const BigNum & other) const {
	if (sign==other.sign && len==other.len && equal(num, num+len, other.num)) {
		return true;
	}
	return false;
}

bool BigNum::operator>=(const BigNum & other) const {
	return (*this)>other || (*this)==other;
}

bool BigNum::operator<(const BigNum & other) const {
	return other>(*this);
}

bool BigNum::operator<=(const BigNum & other) const {
	return (*this)<other || (*this)==other;
}
const BigNum BigNum::operator+(const BigNum & other) const {
	if (isZero()) {
		return other;
	} 

	if (other.isZero()) {
		return *this;
	}

	BigNum tmp(*this);
	if (sign == other.sign) {
		int maxLen = max(len, other.len);
		for (int i=0; i<maxLen; ++i) {
			tmp.num[i] += (other.num[i]);
			tmp.num[i+1] += tmp.num[i]/10;
			tmp.num[i] = tmp.num[i]%10;
		}

		tmp.len = maxLen;

		if (tmp.num[tmp.len]) {
			++tmp.len;
		}

		return tmp;
	} else if (sign == NEGATIVE) {
		tmp.sign = POSITIVE;
		return (other-tmp);
	} else {
		tmp = other;
		tmp.sign = POSITIVE;
		return (*this)-tmp;
	}
	
}

BigNum & BigNum::operator+=(const BigNum & other) {
	
	return ((*this) = (*this) + other);
}

BigNum BigNum::operator -() const{
	BigNum tmp(*this);
	tmp.sign = (sign==POSITIVE?NEGATIVE:fabs(sign));
	return tmp;
}

const BigNum BigNum::operator-(const BigNum &other) const {

	if (isZero()) {
		return -other;
	}

	if (other.isZero()) {
		return (*this);
	}

	if ((*this)==other) {
		return BigNum(0);
	}

	
	if (sign == other.sign) {
		BigNum tmp(*this);
		if ((sign == POSITIVE && tmp>other) || (sign==NEGATIVE && tmp<other)) {
			int i;
			for (i=0; i<tmp.len; ++i) {
				if (tmp.num[i]>=other.num[i]) {
					tmp.num[i] -= other.num[i];
				} else {
					--tmp.num[i+1];
					tmp.num[i] = tmp.num[i]+10-other.num[i];
				}
			}

			
			for (i=tmp.len; i>=0; --i) {
				if (tmp.num[i]) {
					tmp.len = i+1;
					break;
				}
			}

			return tmp;
		} else {			
			return -(other-tmp);
		}
	
	} else if (sign == POSITIVE){
		BigNum tmp(other);
		tmp.sign = POSITIVE;
		return tmp+(*this);
	} else {
		BigNum tmp(*this);
		return -(-tmp+other);
	}	
}

BigNum & BigNum::operator-=(const BigNum & other) {
	return ((*this)=(*this)-other);
}

const BigNum BigNum::operator--(int) {
	BigNum tmp(*this);
	*this = *this -BigNum(1);
	return tmp;
}

BigNum & BigNum::operator--() {
	return (*this = *this - BigNum(1));
}

const BigNum BigNum::operator++(int) {
	BigNum tmp(*this);
	*this = *this + BigNum(1);
	return tmp;
}

BigNum & BigNum::operator++() {
	return (*this = *this + BigNum(1));
}


const BigNum BigNum::operator*(const BigNum & other) const {

	if (isZero() || other.isZero()) {
		return BigNum(0);
	}

	int i, j;
	BigNum tmp(0);

	for (i=0; i<len; ++i) {
		for (j=0; j<other.len; ++j) {
			tmp.num[i+j] += (num[i]*other.num[j]);
			tmp.num[i+j+1] += tmp.num[i+j] / 10;
			tmp.num[i+j] %= 10;
		}
	}

	tmp.len = (i-1)+(j-1)+1;
	if (tmp.num[tmp.len]) {
		++tmp.len;
	}

	tmp.sign = sign*other.sign;
	return tmp;
}

BigNum & BigNum::operator*=(const BigNum &other) {

	return (*this = (*this)*other);
}

const BigNum BigNum::operator/(const BigNum & other) const {

	BigNum res(0);

	int res_sign = sign * other.sign; //保存结果符号

	if (res_sign == ZERO) {
		return res;
	} 

	BigNum n1(*this), n2(other);

	n1.sign = POSITIVE; //都转为正整数
	n2.sign = POSITIVE;

	while (n1>=n2) {
		++res;
		n1 = n1-n2;
	}

	res.sign = res_sign;

	return res;
}

BigNum & BigNum::operator/=(const BigNum & other) {
	return (*this=*this/other);
}

const BigNum BigNum::operator%(const BigNum & other) const {
	return *this-*this/other*other;
}

BigNum & BigNum::operator%=(const BigNum &other) {
	return (*this -= *this/other*other);
}


const BigNum BigNum::operator^(const int & n) const {

	BigNum t, ret(1);
	if (n<0) {
		exit(-1);
	}
	if (n==0) {
		return 1;
	} 
	if (n==1) {
		return *this;
	}
	int m = n;
	BigNum tmp(*this);
	while(m) {
		if (m & 0x01) {
			ret *= tmp;
		}
		tmp *= tmp;
		m >>= 1;
	}

	return ret;
}

BigNum & BigNum::operator^=(const int & n) {
	return (*this=*this^n);
}
int main() {

#ifndef ONLINE_JUAGE
	ifstream in("10010_i.txt");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	
	ofstream out("10010_o.txt");
	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
#endif

	int n;
	BigNum p;

	while (cin>>n>>p) {
		int L = p.getLen()-1;
		int s = (int)pow(10,(L/n));
		int t = (int)pow(10,(int)ceil(static_cast<double>(L+1)/n));
		while (s<t) {
			int m = s + (t-s)/2;
			BigNum bm(m);
			BigNum bn(bm^n);
			if (bn == p) {
				cout<<m<<endl;
				break;
			} else if (bn<p){
				s = m+1;
			} else {
				t = m;
			}
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

