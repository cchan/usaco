/*
ID: doobahe1
PROG: crypt1
LANG: C++11
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

**The partial products must be three digits long**, even though the general case (see below) might have four digit partial products.   
  

Write a program that will find all solutions to the cryptarithm above for any
subset of supplied non-zero single-digits.

### PROGRAM NAME: crypt1

### INPUT FORMAT

Line 1:  |  N, the number of digits that will be used |  Line 2:  | N space
separated non-zero digits with which to solve the cryptarithm  
---|---


	*/
	
	int N;
	fin >> N;
	vector<int> digits(N);
	vector<bool> hasDigit(10, false);
	for(int i = 0; i < N; i++){
		int digit;
		fin >> digit;
		digits[i] = digit;
		hasDigit[digit] = true;
	}
	
	int total = 0;
	for(int i1 : digits)
	for(int i2 : digits)
	for(int i3 : digits)
	for(int i4 : digits)
	for(int i5 : digits){
		int top = 100*i1 + 10*i2 + i3;
		int pp1 = top * i4, pp2 = top * i5, pp3 = 10 * pp1 + pp2;
		if(hasDigit[(pp1)%10]
			&& hasDigit[(pp1/10)%10]
			&& hasDigit[(pp1/100)%10]
			&& pp1/1000 == 0
			&& hasDigit[(pp2)%10]
			&& hasDigit[(pp2/10)%10]
			&& hasDigit[(pp2/100)%10]
			&& pp2/1000 == 0
			&& hasDigit[(pp3)%10]
			&& hasDigit[(pp3/10)%10]
			&& hasDigit[(pp3/100)%10]
			&& hasDigit[(pp3/1000)%10]
			&& pp3/10000 == 0)
			total++;
	}
	
	fout << ++total << endl;
	
	fin.close();
	fout.close();
}
