"""
start.py
A USACO start script that retrieves the next training pages practice problem.
Copyright (c)2016 Clive Chan
MIT License
"""

from common import *
from re import compile as regexCompile

mainpage = loginToMainPage()
name = getName()
fullname = getFull()

probpage = newBrowser().get("http://train.usaco.org"+mainpage.soup.select("a")[6]['href'])
sampleinput = probpage.soup.find(text=regexCompile("SAMPLE INPUT")).findNext("pre").contents[0].strip()
sampleoutput = probpage.soup.find(text=regexCompile("SAMPLE OUTPUT")).findNext("pre").contents[0].strip()

# their html is disturbingly bad
problemstatement = probpage.soup.select("p")[0].decode_contents(formatter="html")
problemstatement = html2text(problemstatement[0:problemstatement.find("<h3>SAMPLE INPUT (")])


startcode = """/*
ID: """+username+"""
PROG: """+name+"""
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
"""+sampleinput+"""
	SAMPLE OUTPUT
"""+sampleoutput+"""
	*/
	ofstream fout(\""""+name+""".out");
	ifstream fin(\""""+name+""".in");
	
	/* Problem: """+fullname+" ("+name+""")
"""+problemstatement+"""
	*/
	
	fin.close();
	fout.close();
}
"""


if not os.path.exists(name):
    os.makedirs(name)

if not os.path.exists(dir+'/'+name+'/'+name+'.cpp'): # Yeah, there are race conditions, but if that's actually relevant in this context you're doing something very wrong
	with open(dir+'/'+name+'/'+name+'.cpp', 'w') as filecpp:
		filecpp.write(startcode)
		sys.stderr.write("write "+name+".cpp\n")
else:
	sys.stderr.write(name+".cpp already exists, nothing written\n")

if not os.path.exists(dir+'/'+name+'/'+name+'.in'):
	with open(dir+'/'+name+'/'+name+'.in', 'w') as filein:
		filein.write(sampleinput+"\n")
		sys.stderr.write("write "+name+".in\n")
else:
	sys.stderr.write(name+".in already exists, nothing written\n")

if not os.path.exists(dir+'/'+name+'/'+name+'.out'):
	with open(dir+'/'+name+'/'+name+'.out', 'w') as fileout:
		fileout.write(sampleoutput+"\n")
		sys.stderr.write("write "+name+".out\n")
else:
	sys.stderr.write(name+".out already exists, nothing written\n")

sys.stderr.write("Success! ("+name+")\n")
print(name)
