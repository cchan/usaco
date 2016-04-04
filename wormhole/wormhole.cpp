/*
ID: doobahe1
PROG: wormhole
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool hasCycle(vector<int> edges){
  vector<bool> checked(edges.size(),false);
  for(int i = 0; i < edges.size(); i++){
    if(checked[i])
      continue;
    
    int iters = 0;
    int curr = i;
    while(curr >= 0 && iters < edges.size() + 1){
      checked[curr] = true;
      curr = edges[curr];
      iters++;
    }
    if(iters == edges.size() + 1)
      return true;
  }
  return false;
}

int countCyclicGraphs(vector<int> incompleteGraph){
  //Now just pair up the -2s recursively.
  int firstIndex = find(incompleteGraph.begin(),incompleteGraph.end(),-2) - incompleteGraph.begin();
  if(firstIndex == incompleteGraph.size())
    return hasCycle(incompleteGraph);
  
  int sum = 0;
  for(int i = firstIndex + 1; i < incompleteGraph.size(); i++)
    if(incompleteGraph[i] == -2){
      incompleteGraph[firstIndex] = i + 1; // to go to the output of the wormhole, add 1
      incompleteGraph[i] = firstIndex + 1;
      sum += countCyclicGraphs(incompleteGraph);
      incompleteGraph[firstIndex] = incompleteGraph[i] = -2;
    }
  
  return sum;
}


int main(){
	ofstream fout("wormhole.out");
	ifstream fin("wormhole.in");
	
	
	int N;
	fin >> N;
	vector<int> x(N), y(N);
	for(int i = 0; i < N; i++)
		fin >> x[i] >> y[i];
  
  map<int, int> wormholesByY; //y => number of wormholes in that row
  for(int i = 0; i < N; i++)
    wormholesByY[y[i]]++;
  
  vector<int> wormholesByRow; //array of numbers of wormholes in rows
  transform(wormholesByY.begin(),wormholesByY.end(),back_inserter(wormholesByRow), [](map<int,int>::value_type& val){return val.second;});
  
  vector<bool> doesWormholeEnd(N,false); //does the wormhole exit go off to infinity? (otherwise, it'll go to another wormhole)
  int index = -1;
  for(int i = 0; i < wormholesByRow.size(); i++)
    doesWormholeEnd[index += wormholesByRow[i]] = true;
  
  //now make this into a directed graph
  vector<int> edges(N*2); //where now => where going (-1 is no more wormholes, -2 is not yet defined)
  for(int i = 0; i < N; i++){
    //for each wormhole, there's an in-hole and an out-hole
    edges[2*i] = -2; //not yet defined for in-hole
    if(doesWormholeEnd[i])
      edges[2*i+1] = -1; //goes off to infinity for out-hole
    else
      edges[2*i+1] = (2*i+1)+1; //goes to next wormhole for out-hole
  }
	
  fout << countCyclicGraphs(edges) << endl;
  
	fin.close();
	fout.close();
}
