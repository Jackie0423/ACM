#include <iostream>
#include <string>
#include <iterator>
using namespace std;

/*
g++��vc6.0����getline���������Ĵ���ʽ��ͬ��
��vc6.0�У�getline()�������ַ�������ֵʱ����Ҫ���λس���������������ֵ����linux/g++�У�����һ�μ��ɡ��ܿ����ǲ���ϵͳ��ԭ��
��VC6.0�У�cin.getline()����������һ�λس����ɡ�
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