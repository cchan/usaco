/*
ID: doobahe1
PROG: radio
LANG: C++
*/
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int getX(char c){
	if(c == 'W') return -1;
	else if(c == 'E') return 1;
	else return 0;
}
int getY(char c){
	if(c == 'S') return -1;
	else if(c == 'N') return 1;
	else return 0;
}
int cost(int fx, int fy, int bx, int by){
	return (fx - bx) * (fx - bx) + (fy - by) * (fy - by);
}

int main(){
	ofstream fout("./radio.out");
	ifstream fin("./radio.in");
	
	int N, M, fx, fy, bx, by;
	fin >> N >> M >> fx >> fy >> bx >> by;
	vector<char> fpath(N), bpath(M);
	for(int i = 0; i < N; i++)
		fin >> fpath[i];
	for(int i = 0; i < M; i++)
		fin >> bpath[i];
	
	if(N > M){ //Assume wlog that Bessie walks >= steps than FJ.
		vector<char> tmp1 = fpath;
		fpath = bpath;
		bpath = tmp1;
		int tmp = fx;
		fx = bx;
		bx = tmp;
		tmp = fy;
		fy = by;
		by = tmp;
		tmp = N;
		N = M;
		M = tmp;
	}
	
	int totalcost = 0;
	int findex = 0;
	for(int bindex = 0; bindex < M; bindex++){
		//move Bessie
		bx += getX(bpath[bindex]);
		by += getY(bpath[bindex]);
		//if FJ moving with Bessie reduces cost
		if(cost(fx, fy, bx, by) > cost(fx + getX(fpath[findex]), fy + getY(fpath[findex]), bx, by)){
			//move FJ with Bessie
			fx += getX(fpath[findex]);
			fy += getY(fpath[findex]);
			findex++;
		}
		//add cost
		totalcost += cost(fx, fy, bx, by);
	}
	for(; findex < N; findex++){
		fx += getX(fpath[findex]);
		fy += getY(fpath[findex]);
		totalcost += cost(fx, fy, bx, by);
	}
	
	fout << totalcost << endl;
	
	fin.close();
	fout.close();
}



