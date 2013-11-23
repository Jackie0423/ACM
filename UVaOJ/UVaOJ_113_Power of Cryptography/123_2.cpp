#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double n, p;
	cout<<setprecision(0);
	while(cin>>n>>p) {		
		cout<<fixed<<pow(p, 1/n)<<endl;
	}
	return 0;
}