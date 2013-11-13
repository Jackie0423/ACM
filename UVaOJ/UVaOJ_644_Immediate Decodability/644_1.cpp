//#define ONLINE_JUAGE
//#pragma warning(disable:4786)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
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
	vector<string> vec;
	string str;
	int cases = 0;
	while (cin>>str) {
		if (str != "9") {
			vec.push_back(str);
		} else {
			sort(vec.begin(), vec.end());
			bool CanDecode(vector<string> &);
			if (CanDecode(vec)) {
				cout<<"Set "<<++cases<<" is immediately decodable"<<endl;
			} else {
				cout<<"Set "<<++cases<<" is not immediately decodable"<<endl;
			}
			vec.clear();
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



bool CanDecode(vector<string> & vec) {
	
	bool CanDecode = true;
	for (int i=1; i<vec.size(); ++i) {

		if (vec[i].size()>=vec[i-1].size()) {
			
			if (vec[i].substr(0, vec[i-1].size()) == vec[i-1]) {
				CanDecode = false;
				break;
			}
		}
	}
	
	return CanDecode;
}