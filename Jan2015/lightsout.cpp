/*
ID: doobahe1
PROG: lightsout
LANG: C++
*/
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;


int totallength, N;
vector<int> realpathlen(N, 0),  //the real shortest path length (in the light)
	lengths(N, 0);//from P_i to P_i+1
vector<bool> angles(N, false); //left or right (at P_i)
int extraSearchLength(int thisI, int otherI){
	if(thisI == otherI) return 0;
	if(thisI == 0 || otherI == 0)return 0;
	if(angles[thisI] != angles[otherI])return 0;
	
	int searchlen = 0;
	int a = 0;
	
	while(true){
		if(angles[(thisI+a) % N] != angles[(otherI+a) % N])break;
		searchlen += lengths[(thisI+a) % N];
		
		a++;
		
		if(thisI == 6 && otherI == 11)
			cout << angles[thisI+1] << " " << angles[otherI+1];
		
		if((thisI + a) % N == 0 || (otherI + a) % N == 0)break;
		if(lengths[(thisI+a+N-1) % N] != lengths[(otherI+a+N-1) % N])break;
	}
	
	if(thisI == 6 && otherI == 11){
	cout<<"["<<thisI<<","<<otherI<<"] "<<searchlen<<" + " <<realpathlen[(thisI + a) % N]<<" - "<<realpathlen[thisI]<<" = "<<
		searchlen + realpathlen[(thisI + a) % N] - realpathlen[thisI] << endl;
	}
	
	return searchlen + realpathlen[(thisI + a) % N] - realpathlen[thisI];
}
int main(){
	ofstream fout("./lightsout.out");
	ifstream fin("./lightsout.in");
	
	fin >> N;
	vector<int> x(N,0), y(N,0);
	for(int i = 0; i < N; i++)
		fin >> x[i] >> y[i];
	
	realpathlen.resize(N,0);
	lengths.resize(N,0);
	angles.resize(N,false);
	
	for(int i = 0; i < N; i++){
		lengths[i] = x[(i+1)%N] - x[i] + y[(i+1)%N] - y[i];
		lengths[i] = lengths[i] > 0 ? lengths[i] : -lengths[i];
		
		//cout << lengths[i] << "!\n";
		
		int dx1 = x[(i+1)%N] - x[i%N];
		int dx0 = x[i%N] - x[(i-1+N)%N];
		int dy1 = y[(i+1)%N] - y[i%N];
		int dy0 = y[i%N] - y[(i-1+N)%N];
		
		angles[i] = dx1 > 0 && dy0 > 0
			|| dx0 > 0 && dy1 < 0
			|| dx1 < 0 && dy0 < 0
			|| dx0 < 0 && dy1 > 0; //ugh; true == right
		
		//cout << (angles[i] ? "right" : "left") << lengths[i] << endl;
	}
	
	cout << angles[11] << endl;
	
	for(int i = 1; i < N; i++)
		realpathlen[i] = realpathlen[i-1] + lengths[i-1];
	totallength = realpathlen[N-1] + lengths[N-1];
	for(int i = 0; i < N; i++)
		if(totallength < 2 * realpathlen[i])
			realpathlen[i] = totallength - realpathlen[i];
	
	
	int max = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == j) continue;
			int extra = extraSearchLength(i, j);
			if(max < extra)
				max = extra;
		}
	}
	fout << max << endl;
	//cout << max << endl;
	
	fin.close();
	fout.close();
}



