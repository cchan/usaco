/*
ID: doobahe1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
	ofstream fout;
	ifstream fin;
	string name;
	string num;
	int n=0;
	string serial;
	bool any=false;

	fin.open("namenum.in");
	fin>>serial;
	fin.close();

	fout.open("namenum.out");
	fin.open("dict.txt");
	while(fin.good()){
		num="";
		fin>>name;
		for(int i=0;i<name.length();i++)
			if(name[i]=='Q'||name[i]=='Z'){
				num="0";
				break;
			}
			else{
				num+=((name[i]-'A'-((name[i]>'Q')?1:0))/3+2)+'0';
			}
		if(serial==num){
			fout<<name<<'\n';
			any=true;
		}
		n++;
	}
	fin.close();
	if(!any)fout<<"NONE\n";
	fout.close();
}
