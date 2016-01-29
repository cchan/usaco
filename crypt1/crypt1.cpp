/*
ID: doobahe1
PROG: crypt1
LANG: C++
*/
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	/*
	SAMPLE INPUT
5
2 3 4 6 8
	SAMPLE OUTPUT
1
	*/
	ofstream fout("crypt1.out");
	ifstream fin("crypt1.in");
	
	/* Problem: Prime Cryptarithm (crypt1)
The following cryptarithm is a multiplication problem that can be solved by
substituting digits from a specified set of N digits into the positions marked
with *. If the set of prime digits {2,3,5,7} is selected, the cryptarithm is
called a PRIME CRYPTARITHM.

    
    
          * * *
       x    * *
        -------
          * * *         <-- partial product 1
        * * *           <-- partial product 2
        -------
        * * * *
    

Digits can appear only in places marked by `*'. Of course, leading zeroes are
not allowed.  

Write a program that will find all solutions to the cryptarithm above for any
subset of supplied non-zero single-digits.

### PROGRAM NAME: crypt1

### INPUT FORMAT

Line 1:  |  N, the number of digits that will be used |  Line 2:  | N space
separated non-zero digits with which to solve the cryptarithm  
---|---


	*/
	
	int N;
	vector<int> digits(N);
	fin >> N;
	for(int i = 0; i < N; i++)
		fin >> digits[i];
	
	
	
	fin.close();
	fout.close();
}
