import mechanize
import os
from urlparse import urlparse, parse_qs
from urllib import urlencode

from setup import cmn

browser=mechanize.Browser()
browser.open(cmn.uri,"NAME="+cmn.username+"&PASSWORD="+cmn.password)
q=parse_qs(urlparse(browser.find_link(nr=6).url)[4])

proj=raw_input("Enter project name, or press enter to auto-fetch: ")
if proj=="":
    #GET PROJ NAME
    proj=q["S"][0]
path=proj+"/"+proj

#IF NOT THERE, ASK FOR MANUAL SUBMIT NAME
if not os.path.exists(path+".cpp"):
    print "The project "+proj+" was not found.\n"
    proj=raw_input("Enter USACO project to submit: ")
    while not os.path.exists(proj+"/"+proj+".cpp"):
        proj=raw_input("The project does not exist. Try again: ")
elif os.path.exists(path+"_filtered.cpp"):
    yn=""
    yn=raw_input("The project "+proj+" has already been submitted. Resubmit? (Y/N) ")
    while yn!="Y" and yn!="N":
        yn=raw_input("Invalid response. Resubmit? (Y/N) ")
    if yn=="N":
        raw_input("Press enter to exit...")

print "SUBMITTING: "+proj

#PREPREOCESSING & FILTRATION
#pre-look at it for errors; i.e. are there couts/#include <iostream>? no just notify and stop
f1 = open(path+".cpp", "r")
f2 = open(path+"_filtered.cpp", "w")
for line in f1:
    f2.write(line.replace(cmn.main_dir+"/"+proj+"/", ""))
f1.close()
f2.close()

#ATTACHMENT & SUBMISSION
browser.select_form(nr=1)
browser.add_file(open(proj+"/"+proj+"_filtered.cpp"),"text/plain",proj+".cpp")
response=browser.submit()

#PROCESSING RESPONSE, SUCCESS/FAILURE
plain=cmn.strip_tags(response.read())
"""
if #stuff about plain.find() or whatever that is
    print "Probable success!\n"
else:
    print "Probably failure D:
"""
open(path+"_results.txt","w").write(plain)

raw_input("Press enter for detail...")
print plain

raw_input("Press enter to exit.")

