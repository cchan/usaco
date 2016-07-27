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
#include <bitset>
using namespace std;

struct cmp{
  bool operator() (const pair<int, int>& a, const pair<int, int>& b) const{
    return a.second == b.second ? a.first < b.first : a.second < b.second;
  }
};

int main(){
	ofstream fout("ariprog.out");
	ifstream fin("ariprog.in");
	
  int N,M;
  fin >> N >> M;
  set<int> bisquares;
  bitset<250 * 250 * 2 + 1> isBisquare;
  set<pair<int,int>, cmp> ans;
  
  //iterate on the difference --> 25 time
    //iterate on the starting point --> 12500 time
  
  for(int p = 0; p <= M; p++){
    for(int q = p; q <= M; q++){
      bisquares.insert(p * p + q * q);
      isBisquare.set(p * p + q * q);
    }
  }
  for(auto it1 = bisquares.begin(); it1 != bisquares.end(); ++it1){
    for(auto it2 = next(it1); it2 != bisquares.end(); ++it2){
      int start = *it1;
      int diff = *it2 - *it1;
      if(start + (N-1) * diff > 2 * M * M)
        break; //lmao it's the easy optimizations that do the most
      
      bool isValid = true;
      for(int i = 2; i < N; i++){
        if(!isBisquare.test(start + i * diff)){
          isValid = false;
          break;
        }
      }
      if(isValid)
        ans.insert(make_pair(start, diff));
    }
  }
  
  for(auto a : ans)
    fout << a.first << " " << a.second << endl;
  if(ans.size() == 0)
    fout << "NONE" << endl;
  
	fin.close();
	fout.close();
}
