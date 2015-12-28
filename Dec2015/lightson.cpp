/*
ID: doobahe1
PROG: lightson
LANG: C++
*/
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef int Coord;
typedef unordered_multimap<Coord,Coord> SwitchMap;

int N;

Coord makeCoord(int x, int y){
	return x + N * y;
}
int CoordX(Coord c){
	return c % N;
}
int CoordY(Coord c){
	return c / N;
}

int main(){
	ofstream fout("./lightson.out");
	ifstream fin("./lightson.in");
	
	int M;
	fin >> N >> M;
	vector<int> accessible(N * N, 0); //0 if not, 1 if lightable, 2 if accessible
	SwitchMap switches;
	for(int i = 0; i < M; i++){
		int a,b,c,d;
		fin >> a >> b >> c >> d;
		Coord coord1 = makeCoord(a-1,b-1), coord2 = makeCoord(c-1,d-1);//because zero-indexing is easier
		switches.insert(SwitchMap::value_type(coord1, coord2));
	}
	
	
	bool changed;
	
	accessible[0] = 2;
	changed = true;
	auto its = switches.equal_range(0);
	for(auto it = its.first; it != its.second; ++it)
		if(accessible[it->second] == 0)
			accessible[it->second] = 1;
	
	while(changed){
		changed = false;
		for(Coord i = 0; i < N * N; i++){//for all rooms
			if(accessible[i] == 2)//if it's accessible
				for(Coord adj : {i+1, i-1, i+N, i-N})//for all adjacent rooms
					if(adj >= 0 && adj < N*N && accessible[adj] == 1){ //if it's actually a room, and it's lit
						accessible[adj] = 2; //let's move there
						changed = true;
						auto its = switches.equal_range(adj);
						for(auto it = its.first; it != its.second; ++it) //and turn on every light switch in that room.
							if(accessible[it->second] == 0)
								accessible[it->second] = 1;
					}
		}
	}
	
	int count = 0;
	for(int i = 0; i < N*N; i++){
		if(accessible[i]>0)
			count++;
	}
	fout << count << endl;
	
	fin.close();
	fout.close();
}
