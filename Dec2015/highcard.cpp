/*
ID: doobahe1
PROG: highcard
LANG: C++
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	ofstream fout("./highcard.out");
	ifstream fin("./highcard.in");
	
	int N;
	fin >> N;
	vector<int> elsie(N);
	vector<int> bessie(N);
	
	for(int i = 0; i < N; i++)
		fin >> elsie[i];
	sort(elsie.begin(), elsie.end());
	
	int elsieElem = 0, bessieElem = 0;
	for(int i = 1; i <= 2 * N; i++)
		if(elsie[elsieElem] < i){
			elsieElem++;
			i--;
		}
		else if(elsie[elsieElem] > i)
			bessie[bessieElem++] = i;
	
	for(int c : bessie)cout<<c<<" ";
	cout<<endl;
	for(int c : elsie)cout<<c<<" ";
	cout<<endl;
	
	int j = 0;
	int wins = 0;
	for(int i = 0; i < N && j < N; i++){
		while(elsie[i] > bessie[j])
			j++;
		wins++;
		j++;
	}
	
	fout << wins << endl;
	
	fin.close();
	fout.close();
}
