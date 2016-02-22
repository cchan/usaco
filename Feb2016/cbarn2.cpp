/*
ID: doobahe1
PROG: cbarn2
LANG: C++
*/
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;


int cost(vector<int> r, vector<int> dp){
	vector<int> doorpos(dp);
	
	sort(doorpos.begin(), doorpos.end());
	vector<int>::iterator it = unique(doorpos.begin(), doorpos.end());
	doorpos.resize(distance(doorpos.begin(), it));
	
	int j = doorpos[0];
	int n = r.size();
	int k = doorpos.size();
	int totalcost = 0;
	for(int i = 1; i < k; i++) //for each door
		for(; j < doorpos[i]; j++){ //go through the rooms in front
			totalcost += (j - doorpos[i-1]) * r[j];
			//cout << r[j] << " cows are going from door " << doorpos[i-1] << " to room " << j 
			//	<<", total distance " << ((j - doorpos[i-1]) * r[j]) << endl;
		}
	if(k == 1){
		//cout << r[j] << " cows are going from door " << doorpos[k-1] << " to room " << j
		//	<< ", total distance " << (((j - doorpos[k-1] + n) % n) * r[j]) << endl;
		j = (j+1) % n;
	}
	for(; j != doorpos[0]; j = (j+1) % n){
		totalcost += ((j - doorpos[k-1] + n) % n) * r[j];
		//cout << r[j] << " cows are going from door " << doorpos[k-1] << " to room " << j
		//	<< ", total distance " << (((j - doorpos[k-1] + n) % n) * r[j]) << endl;
	}
	
	return totalcost;
}
int main(){
	ofstream fout("./cbarn2.out");
	ifstream fin("./cbarn2.in");
	
	int n, k;
	fin >> n >> k;
	vector<int> r(n,0);
	for(int i = 0; i < n; i++)
		fin >> r[i];
	
	vector<int> doorpos;
	int currDoorIndex = 0;
	
	/*
	//Lol I tried
	
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,k-1);
	std::uniform_int_distribution<int> randroom(0,n-1);
	auto randDoorIndex = std::bind ( distribution, generator );
	for(int i = 0; i < k; i++)
		doorpos[i] = randroom(generator);
	
	
	int mincost = cost(r,doorpos);
	for(int iter = 0; iter < 100000; iter++){
		int rnd = randDoorIndex();
		
		doorpos[rnd] = (doorpos[rnd] + iter / 5000) % n; //Simulated annealing ayyyyyy
		
		int thiscost = cost(r, doorpos);
		if(thiscost < mincost)
			mincost = thiscost;
		else
			doorpos[rnd] = (doorpos[rnd] - iter / 5000 + n * 100) % n;
	}*/
	for(int currDoorIndex = 0; currDoorIndex < k; currDoorIndex++){
		doorpos.push_back(0);
		int minRoomIndex = 0;
		int minRoomCost = 1000000000;
		for(int i = 0; i < n; i++){
			doorpos[currDoorIndex] = i;
			int thiscost = cost(r,doorpos);
			if(minRoomCost > thiscost){minRoomCost = thiscost; minRoomIndex = i;}
		}
		doorpos[currDoorIndex] = minRoomIndex;
	}
	
	fout << cost(r,doorpos) << endl;
	
	fin.close();
	fout.close();
}



