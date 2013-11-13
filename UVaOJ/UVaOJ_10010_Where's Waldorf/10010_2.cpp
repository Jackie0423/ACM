#pragma warning(disable:4786)
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;
/*
C++中，重定向标准I/O时，在VC6.0中一定要使用完后重置回来，否则会出错。在G++中，无需重置回来。
*/
const int DIRECTION_NUM = 8;
const int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}}; // {左，右，上，下，左上，左下，右上，右下}

// transform 把字符串转成大写, 这里要写成 ::toupper, 不能直接 toupper, 因为这个不是在 std 命名空间里的
// 查找 word 在 grid 中的位置, 返回结果就是 "所在行 第一列 " 组合的字符串
string searchWord(const vector<string>& grid, const string& word)
{	
	const int r = grid.size();
	const int c = grid[0].size();
	int searchedNum = 0;
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			
			// 如果第一个字符查到了，就向八个方向遍历后面所有的字符，看是否匹配
			if(grid[i][j] == word[0]){
				
				for(int d=0; d<DIRECTION_NUM; d++){
					searchedNum = 1;
					
					for(int k=1; k<word.size(); k++){
						
						int row = i + directions[d][0] * k;
						int col = j + directions[d][1] * k;
						
						if(!(row >= 0 && row < r && col >= 0 && col < c)){
							break;
						}
						
						if(grid[row][col] == word[k]){
							++searchedNum;
						}else{
							break;
						}
					}
					
					if(searchedNum == word.size()){
						char a[22];
						sprintf(a, "%d %d", i+1, j+1);
						
						return a;
					}
				}
			}
		}
	}
	
	// 这里不写 return "not found", 当search为 false 时，走到这里，就会报段错误 ...
	return "not found";
}


int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen ("10010_i.txt", "r", stdin);  
	freopen ("10010_o.txt", "w", stdout); 

	/*
	c++ style for redirect stdin and stdout.
	*/
	streambuf * cinbuf = cin.rdbuf();	
	ifstream in("10010_i.txt");
	cin.rdbuf(in.rdbuf());

	streambuf * coutbuf = cout.rdbuf();
	ofstream out("10010_o.txt");
	cout.rdbuf(out.rdbuf());

#endif
	
	int caseNum;
	cin >> caseNum;
	
	while(caseNum--){
		int m;
		int n;
		cin >> m >> n;
		
		vector<string> grid;
		for(int i=0; i<m; i++){
			string line;
			cin >> line;
			
			// 统一转成大写
			transform(line.begin(), line.end(), line.begin(), ::toupper);
			
			grid.push_back(line);
		}
		
		int k;
		cin >> k;
		for(i=0; i<k; i++){
			string word;
			cin >> word;
			
			// 统一转成大写
			transform(word.begin(), word.end(), word.begin(), ::toupper);
			
			cout << searchWord(grid, word) << endl;
		}
		
		// 除了最后一个，都需要输出空行
		if(caseNum > 0)
			cout << endl;
	}

// C++ style redirection of standard i/o stream in VC6.0
// but in g++, it doesn't matter!!!
#ifndef ONLINE_JUDGE
	in.close();
	out.close();
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif
	return 0;
}