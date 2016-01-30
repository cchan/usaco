/*
ID: doobahe1
PROG: wormhole
LANG: C++11
*/ //http://usaco.org/index.php?page=viewproblem2&cpid=116
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

unsigned long long choose(int n, int k){
	unsigned long long total = 1;
	
	if(k > n-k){
		for(int i = k+1; i <= n; i++)
			total *= i;
		for(int i = 2; i <= n-k; i++)
			total /= i;
		return total;
	}else{
		for(int i = n-k+1; i <= n; i++)
			total *= i;
		for(int i = 2; i <= k; i++)
			total /= i;
		return total;
	}
}
void getNth(ostream& fout, int numDigits, int numOnes, int n){
	if(numOnes == 0)
		for(int i = 0; i < numDigits; i++)
			fout << 0;
	else if(numOnes == numDigits)
		for(int i = 0; i < numDigits; i++)
			fout << 1;
	else if(n > choose(numDigits-1, numOnes)){
		fout << 1;
		getNth(fout, numDigits - 1, numOnes - 1, n - choose(numDigits-1, numOnes));
	}else{
		fout << 0;
		getNth(fout, numDigits - 1, numOnes, n);
	}
}
int mainfunc(ostream& fout, istream& fin){
	int N, K;
	fin >> N >> K;
	
	int n = 0; //numDigits
	while(choose(K+n, K) < N) //hockey stick rule
		n++;
	
	N -= choose(K+n-1, K);
	
	//K+n is the number of digits in the desired
	//K is the number of ones in the desired
	fout << 1;
	getNth(fout, K+n-1, K-1, N);
	//fout << endl;
}
int main(int argc, char* argv[]){
	ostringstream fout;
	ifstream fin;
	for(int i = 1; i <= 10; i++){
		stringstream fname;
		fname << i << ".in";
		fin.open(fname.str());
		mainfunc(fout, fin);
		fin.close();
		
		stringstream fname2;
		fname2 << i << ".out";
		fin.open(fname2.str());
		string content;
		fin >> content;
		fin.close();
		
		if(content == fout.str())
			cout << "Passed case " << i << endl;
		else
			cout << "FAILED case " << i << endl;
		
		fout.str("");
		fout.clear();
	}
}
