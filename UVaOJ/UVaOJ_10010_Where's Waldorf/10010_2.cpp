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
C++�У��ض����׼I/Oʱ����VC6.0��һ��Ҫʹ��������û���������������G++�У��������û�����
*/
const int DIRECTION_NUM = 8;
const int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}}; // {���ң��ϣ��£����ϣ����£����ϣ�����}

// transform ���ַ���ת�ɴ�д, ����Ҫд�� ::toupper, ����ֱ�� toupper, ��Ϊ��������� std �����ռ����
// ���� word �� grid �е�λ��, ���ؽ������ "������ ��һ�� " ��ϵ��ַ���
string searchWord(const vector<string>& grid, const string& word)
{	
	const int r = grid.size();
	const int c = grid[0].size();
	int searchedNum = 0;
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			
			// �����һ���ַ��鵽�ˣ�����˸���������������е��ַ������Ƿ�ƥ��
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
	
	// ���ﲻд return "not found", ��searchΪ false ʱ���ߵ�����ͻᱨ�δ��� ...
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
			
			// ͳһת�ɴ�д
			transform(line.begin(), line.end(), line.begin(), ::toupper);
			
			grid.push_back(line);
		}
		
		int k;
		cin >> k;
		for(i=0; i<k; i++){
			string word;
			cin >> word;
			
			// ͳһת�ɴ�д
			transform(word.begin(), word.end(), word.begin(), ::toupper);
			
			cout << searchWord(grid, word) << endl;
		}
		
		// �������һ��������Ҫ�������
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