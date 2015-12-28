/*
ID: doobahe1
PROG: paint
LANG: C++
*/
#include <fstream>
using namespace std;

int main(){
	ofstream fout("./paint.out");
	ifstream fin("./paint.in");
	
	int a,b,c,d, total;
	fin >> a >> b >> c >> d;
	
	if(a < c && b < d)
		total = b-a + d-c - (b>c?b-c:0);
	else if(a >= c && b < d)
		total = d-c;
	else if(a < c && b >= d)
		total = b-a;
	else
		total = b-a + d-c - (d>a?d-a:0);
	
	fout << total << endl;
	
	fin.close();
	fout.close();
}
