/*
ID: doobahe1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
	int n=0;
	fin >> n;
	int **time=0;
	time=new int *[n];
	for(int i=0;i<n;i++){time[i]=new int[2];fin>>time[i][0];fin>>time[i][1];}
	/*
	int maxlen;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(time[i][0]<time[j][1]&&maxlen<time[j][1]-time[i][0]){
				//maxlen=time[j][1]-time[i][0];
			}
		}
	}
	int maxgap;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(time[i][1]<time[j][0]&&maxlen<time[j][0]-time[i][1]){
				//maxlen=time[j][0]-time[i][1];
			}
		}
	}
	*/
	for(int i=0;i<n;i++){
		fout<<time[i][0]<<" "<<time[i][1]<<endl;
	}
	
	return 0;
}