/*

 Problem A.Ant on a Chessboard 
 
Background

  One day, an ant called Alice came to an M*M chessboard. She wanted to go around all the grids. So she began to walk along the chessboard according to this way: (you can assume that her speed is one grid per second)
  At the first second, Alice was standing at (1,1). Firstly she went up for a grid, then a grid to the right, a grid downward. After that, she went a grid to the right, then two grids upward, and then two grids to the left��in a word, the path was like a snake.
  For example, her first 25 seconds went like this:
  ( the numbers in the grids stands for the time when she went into the grids)
                .
                .
25 24  23 22 21 5
10 11  12 13 20 4
9  8   7  14 19 3
2  3   6  15 18 2
1  4   5  16 17 1
1  2   3  4  5 .... 
 
1          2          3           4           5
At the 8th second , she was at (2,3), and at 20th second, she was at (5,4).
Your task is to decide where she was at a given time.
(you can assume that M is large enough)
 
 
Input

  Input file will contain several lines, and each line contains a number N(1<=N<=2*10^9), which stands for the time. The file will be ended with a line that contains a number 0.
 
 
Output

  For each input situation you should print a line with two numbers (x, y), the column and the row number, there must be only a space between them.
 
 
Sample Input

8
20
25
0
 
 
Sample Output

2 3
5 4
1 5
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
	
	int n;
	int x_Idx, y_Idx;
	while (cin>>n && n) {
		int mid_Idx = static_cast<int>( 0.5 + pow(n-0.75, 0.5));
		int an = mid_Idx*mid_Idx - mid_Idx + 1;
		if(an+(mid_Idx-1)<n) {
			++mid_Idx;
			an = mid_Idx*mid_Idx - mid_Idx + 1;
		}
		if ((n>an && (mid_Idx & 0x01)) || (n<an && !(mid_Idx & 0x01))) {
			x_Idx = mid_Idx-abs(n-an);
			y_Idx = mid_Idx;
		} else {
			x_Idx = mid_Idx;
			y_Idx = mid_Idx - abs(an-n);
		}

		cout<<x_Idx<<" "<<y_Idx<<endl;
	}

#ifndef ONLINE_JUAGE
	in.close();
	out.close();
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif

	return 0;
}

