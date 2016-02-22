/*
ID: doobahe1
PROG: fencedin
LANG: C++
*/
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ofstream fout("./fencedin.out");
	ifstream fin("./fencedin.in");
	
	long long A, B;
	int n, m;
	fin >> A >> B >> n >> m;
	vector<long long> a(n,0), b(m,0);
	//A: vertical fences, B: horizontal fences
	for(int i = 0; i < n; i++)
		fin >> a[i];
	for(int i = 0; i < m; i++)
		fin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	vector<long long> adiff(n+1,0), bdiff(m+1,0);
	
	adiff[0] = a[0] - 0;
	for(int i = 1; i < n; i++)
		adiff[i] = a[i] - a[i-1];
	adiff[n] = A - a[n-1];
	
	bdiff[0] = b[0] - 0;
	for(int i = 1; i < m; i++)
		bdiff[i] = b[i] - b[i-1];
	bdiff[m] = B - b[m-1];
	
	sort(adiff.begin(), adiff.end());
	sort(bdiff.begin(), bdiff.end());
	
	
	long long total = 0;
	int i = 0, j = 0;
	while(i < n+1 && j < m+1) //lol it's hard to explain
		if(adiff[i] < bdiff[j]){
			total += (m - (i==0?0:max(j-1,0))) * adiff[i];
			//cout << "Opened up a row of width " << adiff[i] << " affecting " << (m - (i==0?0:max(j-1,0))) << " vertical fence segments" << endl;
			i++;
		}
		else{
			total += (n - (j==0?0:max(i-1,0))) * bdiff[j];
			//cout << "j="<<j<<" Opened up a column of width " << bdiff[j] << " affecting " << (n - (j==0?0:max(i-1,0))) << " horizontal fence segments" << endl;
			j++;
		}
	//at this point either all columns or all rows are opened, so we're done except if no cols or no rows have been opened
	if(i == 0){
			total += (m - (i==0?0:max(j-1,0))) * adiff[i];
			//cout << "Opened up a row of width " << adiff[i] << " affecting " << (m - (i==0?0:max(j-1,0))) << " vertical fence segments" << endl;
			i++;
		}
		
	else if(j==0){
			total += (n - (j==0?0:max(i-1,0))) * bdiff[j];
			//cout << "j="<<j<<" Opened up a column of width " << bdiff[j] << " affecting " << (n - (j==0?0:max(i-1,0))) << " horizontal fence segments" << endl;
			j++;
		}
	
	
	fout << total << endl;
	
	fin.close();
	fout.close();
}



