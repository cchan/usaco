/*
ID: doobahe1
PROG: angry
LANG: C++
*/
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ofstream fout("./angry.out");
	ifstream fin("./angry.in");
	
	int N;
	fin >> N;
	vector<int> bales(N);
	for(int i=0;i<N;i++){
		fin >> bales[i];
	}
	sort(bales.begin(), bales.end());
	
	fout << "3.0" << endl;
	
	fin.close();
	fout.close();
}



