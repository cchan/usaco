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
	
	/* Problem: Prime Cryptarithm(crypt1)
 The following cryptarithm is a multiplication problem that can be
solved by substituting digits from a specified set of N digits into the
positions marked with *. If the set of prime digits {2,3,5,7} is
selected, the cryptarithm is called a PRIME CRYPTARITHM.
<pre>
      * * *
   x    * *
    -------
      * * *         &lt;-- partial product 1
    * * *           &lt;-- partial product 2
    -------
    * * * *
</pre>
Digits can appear only in places marked by `*'.  Of course, leading
zeroes are not allowed.
<p>
<b>The partial products must be three digits long</b>, even though the
general case (see below) might have four digit partial products.

<br><br>
********** Note About Cryptarithm's Multiplication ************
<br>
In USA, children are taught to perform multidigit multiplication
as described here. Consider multiplying a three digit number
whose digits are 'a', 'b', and 'c' by a two digit number whose
digits are 'd' and 'e':
<pre>
[Note that this diagram shows far more digits in its results than
the required diagram above which has three digit partial products!]

          a b c     &lt;-- number 'abc'
        x   d e     &lt;-- number 'de'; the 'x' means 'multiply'
     -----------
p1      * * * *     &lt;-- product of e * abc; first star might be 0 (absent)
p2    * * * *       &lt;-- product of d * abc; first star might be 0 (absent)
     -----------
      * * * * *     &lt;-- sum of p1 and p2 (e*abc + 10*d*abc) == de*abc

</pre>
<p>Note that the 'partial products' are as taught in USA schools.
The first partial product is the product of the final digit of the
second number and the top number.  The second partial product is
the product of the first digit of the second number and the top
number.

<p> Write a program that will find all solutions to the cryptarithm
above for any subset of supplied non-zero single-digits.


	*/
	
	fin.close();
	fout.close();
}
