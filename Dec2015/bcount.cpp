/*
ID: doobahe1
PROG: bcount
LANG: C++
*/
#include <fstream>
#include <vector>
using namespace std;

vector<int> add(vector<int> a, vector<int> b){
	vector<int> c(3);
	for(int i = 0; i < 3; i++)
		c[i] = a[i]+b[i];
	return c;
}

int main(){
	ofstream fout("./bcount.out");
	ifstream fin("./bcount.in");
	
	int N, Q;
	fin >> N >> Q;
	
	vector<int> cowsType1(N+1); //running sum
	vector<int> cowsType2(N+1);
	vector<int> cowsType3(N+1);
	cowsType1[0] = cowsType2[0] = cowsType3[0] = 0;
	for(int i = 1; i <= N; i++){
		cowsType1[i] = cowsType1[i-1];
		cowsType2[i] = cowsType2[i-1];
		cowsType3[i] = cowsType3[i-1];
		
		int type;
		fin >> type;
		if(type == 1)cowsType1[i]++;
		else if(type == 2)cowsType2[i]++;
		else cowsType3[i]++;
	}
	
	/*
	//twas a cool idea - caching singles, doubles, quadruples, etc. sums, so it would approx n log n instead of n^2.
	int currN = N / 2;
	int level = 1;
	while(currN > 0){
		cows.push_back(vector<vector<int> >());
		
		for(int i = 0; i < currN; i++){
			cows[level].push_back(add(cows[level-1][2*i], cows[level-1][2*i+1]));
		}
		
		currN /= 2;
		level ++;
	}
	*/
	
	
	for(int i = 0; i < Q; i++){
		int a,b;
		fin >> a >> b;
		fout << cowsType1[b] - cowsType1[a-1] << ' ' << cowsType2[b] - cowsType2[a-1] << ' ' << cowsType3[b] - cowsType3[a-1] << endl;
	}
	
	fin.close();
	fout.close();
}
