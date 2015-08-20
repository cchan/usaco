/*
ID: doobahe1
PROG: palsquare
LANG: C++
*/
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
	int b,s,l;
	ifstream fin("C:/Users/Moo/Desktop/USACO/palsquare/palsquare.in");
	fin>>b;
	fin.close();
	
	ofstream fout("C:/Users/Moo/Desktop/USACO/palsquare/palsquare.out");
	for(int n=1;n<=300;n++){
		if(isPal(iToStr(n*n,b)))fout<<iToStr(n,b)<<" "<<iToStr(n*n,b)<<endl;
	}
	fout.close();
}
