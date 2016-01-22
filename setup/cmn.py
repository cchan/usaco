print("""USACO Training Program Project Setup & Submission Script
Written in Python by Clive Chan\n
Last Updated 9-5-2013\n""")

"""username, password, uri"""
import secrets

template="""/*
ID: """+secrets.username+"""
PROG: %x%
LANG: C++
*/

/*
SAMPLE INPUT:
%i%
EXPECTED OUTPUT:
%o%
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream fin(\"./%x%.in\");
	ofstream fout(\"./%x%.out\");
	
	
	//Program goes here. Mhm.
	
	
	fin.close();
	fout.close();
}
"""

def strip_tags(s):
    tag = False
    out = ""
    for c in s:
            if c == '<':
                tag = True
            elif c == '>':
                tag = False
            elif not tag:
                out = out + c
    return out.replace("&lt;","<").replace("&gt;",">").replace("&quot;","\"");
