/**

 Train Swapping 

At an old railway station, you may still encounter one of the last remaining ``train swappers''. A train swapper is an employee of the railroad, whose sole job it is to rearrange the carriages of trains.

Once the carriages are arranged in the optimal order, all the train driver has to do, is drop the carriages off, one by one, at the stations for which the load is meant.

The title ``train swapper'' stems from the first person who performed this task, at a station close to a railway bridge. Instead of opening up vertically, the bridge rotated around a pillar in the center of the river. After rotating the bridge 90 degrees, boats could pass left or right.

The first train swapper had discovered that the bridge could be operated with at most two carriages on it. By rotating the bridge 180 degrees, the carriages switched place, allowing him to rearrange the carriages (as a side effect, the carriages then faced the opposite direction, but train carriages can move either way, so who cares).

Now that almost all train swappers have died out, the railway company would like to automate their operation. Part of the program to be developed, is a routine which decides for a given train the least number of swaps of two adjacent carriages necessary to order the train. Your assignment is to create that routine.

Input Specification

The input contains on the first line the number of test cases (N). Each test case consists of two input lines. The first line of a test case contains an integer L, determining the length of the train ( tex2html_wrap_inline30 ). The second line of a test case contains a permutation of the numbers 1 through L, indicating the current order of the carriages. The carriages should be ordered such that carriage 1 comes first, then 2, etc. with carriage L coming last.

Output Specification

For each test case output the sentence: 'Optimal train swapping takes S swaps.' where S is an integer.

Example Input

3
3
1 3 2
4
4 3 2 1
2
2 1
Example Output

Optimal train swapping takes 1 swaps.
Optimal train swapping takes 6 swaps.
Optimal train swapping takes 1 swaps.
*/
#define ONLINE_JUAGE
#pragma warning(disable:4786)
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
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
	vector<int> vec;
	int N = 0;
	cin>>N;
	while(N--) {
		int L;
		cin>>L;
		int i;
		for(i=0; i<L; ++i) {
			int tmp;
			cin>>tmp;
			vec.push_back(tmp);
		}

		int steps = 0;
		/*
		冒泡排序法，时间复杂度O(n^2);
		
		bool exchange = true;
		for (i=0; i<L-1&& exchange; ++i) {
			exchange = false;
			for (int j=0; j<L-1-i ; ++j) {
				if (vec[j]>vec[j+1]) {
					swap(vec[j], vec[j+1]);
					++steps;
					exchange = true;
				}
			}
		}

		*/

		//归并排序法，时间复杂度为O(nlogn)
		int reverseOrder(vector<int> &);
		steps = reverseOrder(vec);

		cout<<"Optimal train swapping takes "<<steps<<" swaps."<<endl;
		vec.clear();
	}
#ifndef ONLINE_JUAGE
	in.close();
	out.close();
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif

	return 0;
}

int merge(vector<int> & arr, int s, int m, int t, int * A) {
	int reverseCount = 0;
	int i=s, j=m+1, k=s;
	while(i<=m && j<=t) {
		if (arr[i]<=arr[j]) {
			A[k++] = arr[i++];
		} else {
			reverseCount += m-i+1;
			A[k++] = arr[j++];
			
		}
	}
	
	while (i<=m) {
		A[k++] = arr[i++];
	}
	while (j<=t) {
		A[k++] = arr[j++];
	}
	
	for (i=s; i<=t; ++i) {
		arr[i] = A[i];
	}
	return reverseCount;
}

int merge_sort(vector<int> & arr, int s, int t, int *A) {
	if (s >= t) {
		return 0;
	}
	
	int m = s + (t-s)/2;
	int a = merge_sort(arr, s, m, A);
	int b = merge_sort(arr, m+1, t, A);	
	
	int c = merge(arr, s, m, t, A);
	return a+b+c;
}

int reverseOrder(vector<int> & arr) {
	int n = arr.size();
	int *A = new int[n];
	int count = merge_sort(arr, 0, n-1, A);
	delete [] A;
	return count;
}
