#include <iostream>
#include <string>
#include <iterator>
using namespace std;

/*
g++和vc6.0关于getline（）函数的处理方式不同。
在vc6.0中，getline()函数向字符串输入值时，需要两次回车才能真正的输入值；在linux/g++中，仅需一次即可。很可能是操作系统的原因
在VC6.0中，cin.getline()函数，仅需一次回车即可。
*/
int main() {

	int k;
	cin>>k;
//	getchar();
	cin.ignore();
	while (k--) {		
		string str1, str2;
		getline(cin, str1);
		getline(cin, str2);
		string s1="", s2="", s3="", s4="";
		int i=0;
		for (; str1[i]!='<'; ++i) {
			cout<<str1[i];
		}
		for (i++; str1[i]!='>'; ++i) {
			cout<<str1[i];
			s1 += str1[i];
		}
		for (i++; str1[i]!='<'; ++i) {
			cout<<str1[i];
			s2 += str1[i];
		}
		for (i++; str1[i] != '>'; ++i) {
			cout<<str1[i];
			s3 += str1[i];
		}
		for (i++; i<str1.size(); ++i) {
			cout<<str1[i];
			s4 += str1[i];
		}

		cout<<endl;

		for (i=0; i<str2.size()-3; ++i) {
			cout<<str2[i];
		}
		cout<<s3+s2+s1+s4<<endl;
	}
	return 0;
}