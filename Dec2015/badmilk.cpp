/*
ID: doobahe1
PROG: badmilk
LANG: C++
*/
#include <fstream>
#include <vector>
using namespace std;

int main(){
	ofstream fout("./badmilk.out");
	ifstream fin("./badmilk.in");
	
	int N, M, D, S;
	fin >> N >> M >> D >> S;
	
	vector<vector<int> > drinks (D);
	vector<vector<int> > sicks (S);
	vector<bool> types(M, true); //true = possible, false = impossible
	
	for(int i = 0; i < D; i++){
		drinks[i] = vector<int>(3);
		fin >> drinks[i][0] >> drinks[i][1] >> drinks[i][2]; //person, milktype, time
		drinks[i][0]--;
		drinks[i][1]--;
	}
	for(int i = 0; i < S; i++){
		int person, time;
		fin >> person >> time;
		person--;
		
		vector<int> tmptypes(M, false);
		for(int j = 0; j < D; j++)
			if(drinks[j][0]==person && drinks[j][2] < time)
				//if this person could've gotten sick from it
				tmptypes[drinks[j][1]] = true;
		for(int j = 0; j < M; j++)
			if(tmptypes[j] == false)
				types[j] = false;
	}
	
	int maxcount = 0;
	for(int i = 0; i < M; i++){
		if(types[i]){ //if possibly the sickener
			vector<bool> peoplesick(N, false);
			for(int j = 0; j < D; j++)
				if(drinks[j][1] == i)
					peoplesick[drinks[j][0]] = true;
			int count = 0;
			for(int i = 0; i < N; i++)
				if(peoplesick[i])
					count++;
			if(count > maxcount)
				maxcount = count;
		}
	}
	
	fout << maxcount << endl;
	
	fin.close();
	fout.close();
}
