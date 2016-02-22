/*
ID: doobahe1
PROG: cbarn
LANG: C++
*/
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ofstream fout("./cbarn.out");
	ifstream fin("./cbarn.in");
	
	long n;
	fin >> n;
	vector<long> c(n,0);
	for(long i = 0; i < n; i++)
		fin >> c[i];
	
	//cout << n << endl;
	
	long totalEnergy = 0; //Energy so far in this streak
	long lastEmpty = n-1; //last empty opening before this continuous streak of filled openings
	long currentOpening = 0; //Current opening
	for(long i = 0; i != lastEmpty; i = (i + 1) % n){
		if(c[i] == 0 && currentOpening == i){ //Oops it's not a continuous smear, gotta try again
			totalEnergy = 0;
			lastEmpty = i;
			currentOpening = (i+1) % n;
		}
		else for(long j = 0; j < c[i]; j++){ //Greedily put each cow in the closest opening
			totalEnergy += ((currentOpening-i + n) % n) * ((currentOpening - i + n) % n);
			currentOpening = (currentOpening + 1) % n;
		}
		//cout << "I:" << i << endl;
		//cout << "TotalEnergy:" << totalEnergy << endl;
		//cout << "LastEmpty:" << lastEmpty << endl;
		//cout << "CurrentOpening:" << currentOpening << endl;
		//cout << endl;
	}
	
	fout << totalEnergy << endl;
		
	
	fin.close();
	fout.close();
}



