/*
ID: doobahe1
PROG: sprime
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


bool isPrime(int x){
  if(x == 2 || x == 3 || x == 5) return true;
  if(x % 2 == 0 || x % 3 == 0) return false;
  for(int i = 5; i * i <= x; i += 6){
    if(x % i == 0) return false;
    if(x % (i+2) == 0) return false;
  }
  return true;
}


int main(){
  ofstream fout("sprime.out");
  ifstream fin("sprime.in");
  
  int N;
  fin >> N;
  
  //BFS!
  vector<vector<int> > superprimes(N);
  int append[4] = {1, 3, 7, 9};
  superprimes[0] = vector<int>({2, 3, 5, 7});
  for(int i = 1; i < N; i++){
    for(int j = 0; j < superprimes[i-1].size(); j++){
      for(int a = 0; a < 4; a++){
        int candidate = superprimes[i-1][j] * 10 + append[a];
        if(isPrime(candidate))
          superprimes[i].push_back(candidate);
      }
    }
  }
  for(int c : superprimes[N-1])
    fout << c << endl;
  
}
