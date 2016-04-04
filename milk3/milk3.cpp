/*
ID: doobahe1
PROG: milk3
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;

set<vector<int> > possible3;
set<int> possibleC;
vector<int> bck(3);
vector<int> maxb(3);

int max(int a, int b){
  if(a > b) return a;
  else return b;
}
int min(int a, int b){
  if(a < b) return a;
  else return b;
}

void pour(){
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      if(i != j && bck[i] > 0 && bck[j] < maxb[j]){
        int oldi = bck[i];
        int oldj = bck[j];
        bck[j] = bck[j] + bck[i];
        bck[i] = max(bck[j] - maxb[j], 0);
        bck[j] = min(bck[j], maxb[j]);
        
        if(bck[0] == 0)
          possibleC.insert(bck[2]);
        if(possible3.insert(bck).second==true)//never been here
          pour();
        
        bck[i] = oldi;
        bck[j] = oldj;
      }
  
}

int main(){
	ofstream fout("milk3.out");
	ifstream fin("milk3.in");
	
  fin >> maxb[0] >> maxb[1] >> maxb[2];
  bck[0] = bck[1] = 0;
  bck[2] = maxb[2];
  
  pour();
  
  for(int x : possibleC){
    if(x != *possibleC.begin())
      fout << " ";
    fout << x;
  }
  fout << endl;
  
  
	fin.close();
	fout.close();
}
