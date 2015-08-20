/*
ID: doobahe1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ifstream fin("milk.in");
	ofstream fout("milk.out");
    int milk, farmers, totalcost=0;
    fin >> milk >> farmers;
    map<int,int> costquant;
    for(int i=0;i<farmers;i++){
        int cost,quant;
        fin >> cost >> quant;
        costquant[cost] += quant;
    }
    for(map<int,int>::iterator it = costquant.begin(); it != costquant.end(); it++){
        if(milk > it->second){
            totalcost += it->first * it->second;
            milk -= it->second;
        }
        else{
            totalcost += it->first * milk;
            break;
        }
    }
    
    fout << totalcost << endl;
}
