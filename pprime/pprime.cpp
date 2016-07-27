/*
ID: doobahe1
PROG: pprime
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int a, b;
	ofstream fout("pprime.out");
	ifstream fin("pprime.in");

bool isPrime(int x){
  if(x == 2 || x == 3 || x == 5) return true;
  if(x % 2 == 0 || x % 3 == 0) return false;
  for(int i = 5; i * i <= x; i += 6){
    if(x % i == 0) return false;
    if(x % (i+2) == 0) return false;
  }
  return true;
}

void checkPrime(vector<int> x, bool evenNumberOfDigits){
  unsigned long long total = 0;
  for(int i = 0; i < x.size(); i++){
    total *= 10;
    total += x[i];
  }
  for(int i = x.size() - 1 - !evenNumberOfDigits; i >= 0; i--){
    total *= 10;
    total += x[i];
  }
  if(a <= total && total <= b && isPrime(total))
    fout << total << endl;
}

void iteratePalindromes(int len){
  bool even = !(len & 1);
  int length = len / 2 + len % 2;
  vector<int> digits(length);
  digits[0] = 1;
  bool done = false;
  while(true){
    checkPrime(digits, even);
    
    int level = length;
    while(digits[level - 1] == 9){
      digits[level - 1] = 0;
      
      level --;
      if(level == 0){
        done = true;
        break;
      }
    }
    if(done) break;
    
    digits[level - 1]++;
  }
}

int main(){
	
  fin >> a >> b;
  
  //list palindromes
  int digitsA = ceil(log10(a)), digitsB = ceil(log10(b));
  for(int i = digitsA; i <= digitsB; i++)
    iteratePalindromes(i);
  
  //check which are prime
  
	fin.close();
	fout.close();
}
