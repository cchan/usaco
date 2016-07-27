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

int main(){
	ofstream fout("ariprog.out");
	ifstream fin("ariprog.in");
	
  int N,M;
  fin >> N >> M;
  bitset<250 * 250 * 2> bisquares;
  
  
  //iterate on the difference --> 25 time
    //iterate on the starting point --> 12500 time
  
  for(int p = 0; p <= M; p++)
    for(int q = p; q <= M; q++)
      bisquares.set(p * p + q * q);
  
  for(int diff = 1; diff < something; diff++){ //iterate on difference
    for(int startval = 0; startval < bisquares.size(); startval++)
      if(bisquares.test(startval)){
        bool a = true;
        for(int i = 0; i < N; i++)
          if(!bisquares.test(startval + i * diff)){
            a = false;
            break;
          }
        if(a)
          cout << startval << ' ' << diff << endl;
      }
  }
  
	fin.close();
	fout.close();
}
