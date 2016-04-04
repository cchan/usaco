/*
ID: doobahe1
PROG: ariprog
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct seq_comp{
  bool operator()(const pair<int,int>& a, const pair<int,int>& b){
    //whether a>b
    if(a.second > b.second)return false;
    else if (a.second < b.second) return true;
    else return a.first < b.first;
  }
};

int main(){
	ofstream fout("ariprog.out");
	ifstream fin("ariprog.in");
	
  int N,M;
  fin >> N >> M;
  set<int> bisquares;
  for(int i = 0; i <= M; i++)
    for(int j = i; j <= M; j++)
      bisquares.insert(i*i + j*j);
  
  //start off some sequences of bisquares, sorted appropriately
  set<pair<int,int>, seq_comp> sequences;
  int count = 0;
  for(int i = 0; i < bisquares.size(); i++)
    for(int j = i+1; j < bisquares.size() && *next(bisquares.begin(),j)-*next(bisquares.begin(),i)<(*bisquares.rbegin()-*next(bisquares.begin(),i))/(N-1)+1; j++){
      if(++count % 10000 == 0)
        cout<<"10k"<<endl;
      pair<int,int> seq = {*next(bisquares.begin(),i), *next(bisquares.begin(),j) - *next(bisquares.begin(),i)};
      bool valid = true;
      for(int len = 3; len <= N; len++){
        int next = seq.first + (len-1)*seq.second;
        if(bisquares.find(next)==bisquares.end()){
          valid = false;
          break;
        }
      }
      if(valid)
        sequences.insert(seq);
    }
  
  for(pair<int,int> seq : sequences)
    fout << seq.first << " " << seq.second << endl;
  if(sequences.size() == 0)
    fout << "NONE" << endl;
  
	fin.close();
	fout.close();
}
