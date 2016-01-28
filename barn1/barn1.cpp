/*
ID: doobahe1
PROG: barn1
LANG: C++
*/
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ofstream fout("barn1.out");
	ifstream fin("barn1.in");
	
	int M,S,C;
	fin >> M >> S >> C;
	
	vector<int> sortedinput(C);
	for(int i = 0; i < C; i++)
		fin >> sortedinput[i];
	
	sort(sortedinput.begin(), sortedinput.end());
	
	vector<int> extraBoardLengthToMerge(C-1);
	for(int i = 0; i < C-1; i++)
		extraBoardLengthToMerge[i] = sortedinput[i+1] - sortedinput[i] - 1;
	
	sort(extraBoardLengthToMerge.begin(),extraBoardLengthToMerge.end());
	
	int sum = 0;
	for(int i = 0; i < C - M; i++)
		sum += extraBoardLengthToMerge[i];
	
	fout << sum + C << endl;
	
	fin.close();
	fout.close();
}



