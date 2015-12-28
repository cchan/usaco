/*
ID: doobahe1
PROG: speeding
LANG: C++
*/
#include <fstream>
#include <vector>
using namespace std;

int main(){
	ofstream fout("./speeding.out");
	ifstream fin("./speeding.in");
	
	int N,M;
	fin >> N >> M;
	int speedlim[100];
	int speed[100];
	
	int pos1 = 0;
	for(int i = 0; i < N; i++){
		int len, lim;
		fin>>len>>lim;
		for(int j = 0; j < len; j++)
			speedlim[j + pos1] = lim;
		pos1 += len;
	}
	
	
	int pos2 = 0;
	for(int i = 0; i < M; i++){
		int len, spd;
		fin>>len>>spd;
		for(int j = 0; j < len; j++)
			speed[j + pos2] = spd;
		pos2 += len;
	}
	
	int max = 0;
	for(int i = 0; i < 100; i++)
		if(speed[i] - speedlim[i] > max)
			max = speed[i] - speedlim[i];
	
	fout << max << endl;
	
	fin.close();
	fout.close();
}
