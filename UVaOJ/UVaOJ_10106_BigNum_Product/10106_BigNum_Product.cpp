/**
 Product 

The Problem

The problem is to multiply two integers X, Y. (0<=X,Y<10250)

The Input

The input will consist of a set of pairs of lines. Each line in pair contains one multiplyer.

The Output

For each input pair of lines the output line should consist one integer the product.

Sample Input

12
12
2
222222222222222222222222
Sample Output

144
444444444444444444444444
*/
#define ONLINE_JUAGE
#pragma warning(disable:4786)
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

const int MAXLEN = 500+2;
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



int main() {

#ifndef ONLINE_JUAGE
	ifstream in("10010_i.txt");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	
	ofstream out("10010_o.txt");
	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
#endif

	string strX, strY;
	while (cin>>strX>>strY) {
		BigNum X(strX);
		BigNum Y(strY);
		cout<<X*Y<<endl;
	}


#ifndef ONLINE_JUAGE
	in.close();
	out.close();
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif

	return 0;
}

