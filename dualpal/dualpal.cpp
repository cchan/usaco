/*
ID: doobahe1
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isPal(string n){
	for(int i=0;i<(n.length()+1)/2;i++)
		if(n[i]!=n[n.length()-1-i])
			return false;
	return true;
}
string iToStr(int x,int b){
	string s="";
	string a="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while(x>0){
		s=a[x%b]+s;
		x/=b;
	}
	return s;
}

int main(){
	int N,S;
	ifstream fin("C:/Users/Moo/Desktop/USACO/dualpal/dualpal.in");
	fin>>N>>S;
	fin.close();
	
	ofstream fout("C:/Users/Moo/Desktop/USACO/dualpal/dualpal.out");
	while(N>0){
		S++;
		int k=0;
		for(int n=2;n<=10;n++)if(isPal(iToStr(S,n)))k++;
		if(k>=2){
			fout<<S<<endl;
			N--;
		}
	}
	fout.close();
}
