#include <fstream>
#include <string>
using namespace std;
int getN(int n,string*a,string*b){
	bool x[6]={true,true,true,true,true,true};
	bool four[3]={true,true,true};
	char c;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c=a[i][j];
			if(c!=b[j][n-1-i])x[0]=false;
			if(c!=b[n-1-i][n-1-j])x[1]=false;
			if(c!=b[n-1-j][i])x[2]=false;
			if(c!=b[i][n-1-j])x[3]=false;
			if(c!=b[n-1-j][n-1-i])four[0]=false;
			if(c!=b[n-1-i][j])four[1]=false;
			if(c!=b[j][i])four[2]=false;
			if(c!=b[i][j])x[5]=false;
		}
	}
	x[4]=four[0]||four[1]||four[2];
	for(int i=0;i<6;i++)if(x[i])return i+1;
	return 7;
}
int main(){
	ifstream fin("C:/Users/Moo/Desktop/USACO/transform/transform.in");
	int n;
	fin>>n;
	string *a=new string[n],*b=new string[n];
	for(int i=0;i<n;)fin>>a[i++];
	for(int i=0;i<n;)fin>>b[i++];
	fin.close();

	ofstream fout;
	fout.open("C:/Users/Moo/Desktop/USACO/transform/transform.out");
	fout<<getN(n,a,b);
	fout.close();
}
