import sys
import os
import mechanicalsoup
import warnings
import re
warnings.filterwarnings("ignore")
execfile("secrets.py")

browser = mechanicalsoup.Browser()
login_page = browser.get("http://train.usaco.org/usacogate")
login_form = mechanicalsoup.Form(login_page.soup.select("form")[0])
login_form.input({"NAME":username,"PASSWORD":password})
login_form.choose_submit(login_page.soup.select("form")[0].select("input")[2])

page2 = browser.submit(login_form, login_page.url)
fullname = page2.soup.select("a")[6].decode_contents(formatter="html").strip()
name = page2.soup.select("a")[6]['href']
name = name[name.find("&S=")+3:]
probpage = browser.get("http://train.usaco.org"+page2.soup.select("a")[6]['href'])
sampleinput = probpage.soup.find(text=re.compile("SAMPLE INPUT")).findNext("pre").contents[0].strip()
sampleoutput = probpage.soup.find(text=re.compile("SAMPLE OUTPUT")).findNext("pre").contents[0].strip()

problemstatement = probpage.soup.select("p")[0].decode_contents(formatter="html")
problemstatement = problemstatement[0:problemstatement.find("<h3>PROGRAM NAME:")]

startcode = """/*
ID: doobahe1
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
if not os.path.exists(name+'/'+name+'.cpp'):
	open(name+'/'+name+'.cpp', 'w').write(startcode)
else:
	sys.stderr.write("CPP already exists, nothing written\n")
if not os.path.exists(name+'/'+name+'.in'):
	open(name+'/'+name+'.in', 'w').write(sampleinput)
else:
	sys.stderr.write("IN already exists, nothing written\n")
if not os.path.exists(name+'/'+name+'.out'):
	open(name+'/'+name+'.out', 'w').write(sampleoutput)
else:
	sys.stderr.write("OUT already exists, nothing written\n")

sys.stderr.write("Success! ("+name+")\n")
print name
