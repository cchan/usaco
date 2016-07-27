/*
ID: doobahe1
PROG: numtri
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
	ofstream fout("numtri.out");
	ifstream fin("numtri.in");
	
  int R;
  fin >> R;
  
  vector<vector<int> > maxSum(R); //min sum to get to that node
    //bfs/dynamic prog!
  
  for(int i = 0; i < R; i++)
    for(int j = 0; j <= i; j++){
      int x;
      fin >> x;
      maxSum[i].push_back(x);
      if(i > 0){
        if(j > i - 1)
          maxSum[i][j] += maxSum[i-1][j-1];
        else if(j < 1)
          maxSum[i][j] += maxSum[i-1][j];
        else
          maxSum[i][j] += max(maxSum[i-1][j-1], maxSum[i-1][j]);
      }
    }
  
  fout << *std::max_element(maxSum[R-1].begin(), maxSum[R-1].end()) << endl;
  
	fin.close();
	fout.close();
}
