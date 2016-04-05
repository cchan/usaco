/*
ID: doobahe1
PROG: landscape
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
#include <list>
using namespace std;

int main(){
	ofstream fout("landscape.out");
	ifstream fin("landscape.in");
	
  //bulldozer method
  //reduce it from direct-adjustment X+Y by tacking on Zs
  
  int N, X, Y, Z;
  fin >> N >> X >> Y >> Z;
  
  int range = (X+Y)/Z;
  list<int> rangeElements;
  
  int net = 0;
  int totalCost = 0;
  
  for(int i = 0; i < N; i++){
    int A, B;
    fin >> A >> B;
    int S = B-A;//net soil loss/gain for curr plot
    
    int savedZ = 0;
    
    if(S < 0 && net > 0){ //if have opposite signs... cancel stuff out by backtracking in the range
      int l = 1; //distance
      for(auto rit = rangeElements.rbegin(); rit != rangeElements.rend(); ++rit, ++l)
        if(*rit > 0){
          if(*rit + S < 0){
            S += *rit;
            savedZ += *rit * l;
            *rit = 0;
          }else{
            *rit += S;
            savedZ += -S * l;
            S = 0;
            break;
          }
        }
      cout<<endl<<"i: "<<i<<endl;
      cout <<"S: "<<S<<endl;
      cout <<"net: "<<net<<endl;
    }else if(S > 0 && net < 0){
      int l = 1;
      for(auto rit = rangeElements.rbegin(); rit != rangeElements.rend(); ++rit, ++l)
        if(*rit < 0){
          if(*rit + S > 0){
            S += *rit;
            savedZ += -*rit * l;
            *rit = 0;
          }else{
            *rit += S;
            savedZ += S * l;
            S = 0;
            break;
          }
        }
    }
    rangeElements.push_back(S);
    
    int removed = 0;
    if(rangeElements.size() > range){
      removed = *(rangeElements.begin());
      if(removed < 0)
        totalCost += Y * -removed;
      else
        totalCost += X * removed;
      rangeElements.pop_front();
    }
    totalCost += savedZ * Z;
    
    net += B-A-removed; //net soil loss/gain for whole range
  }
  
  for(auto it = rangeElements.begin(); it != rangeElements.end(); ++it)
    if(*it < 0)
      totalCost += Y * -*it;
    else
      totalCost += X * *it;
  
  fout << totalCost << endl;
  
	fin.close();
	fout.close();
}
