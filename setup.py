import mechanicalsoup
import os
import re

from setup import cmn

#GET PROJ NAME
browser=mechanicalsoup.Browser()
browser.post(cmn.secrets.uri,"NAME="+cmn.secrets.username+"&PASSWORD="+cmn.secrets.password)
q=parse_qs(urlparse(browser.find_link(nr=6).url)[4])
proj=q["S"][0]

if browser.find_link(nr=6).url.split('/')[-1].split('#')[0].split('?')[0]=="usacotext2":
    print ("TEXT: "+proj)
    response=browser.follow_link(nr=6)
    open(proj+".txt","w").write(strip_tags(response.read()))
    print ("Successfully created file - text to be opened in notepad.")
    os.startfile(proj+"/"+proj+".txt")
    raw_input("Press enter to exit...")
else:
    #IF SET UP, ASK IF OVERWRITE OR OPEN
    print ("PROJECT: "+proj)
    if os.path.exists(proj):
        c=''
        while c!='Y' and c!='N':
            c=raw_input("The project "+proj+" is already set up. Overwrite? (Y/N) ")
        if c=='N':
            print ("Opening...")
            os.startfile("./setup/USACO/USACO.sln")
            os.startfile(proj+"/"+proj+".txt")
            raw_input("Press enter to exit...")
            exit();
    else:
        os.mkdir(proj)

    #GET PROB TEXT & GET SAMPLE INPUT/OUTPUT & WRITE TEMPLATE
    response=browser.follow_link(nr=6)
    plain=cmn.strip_tags(response.read())
    sample_in=re.search("SAMPLE INPUT \([^\)]*\)(.*?)OUTPUT FORMAT",plain,re.DOTALL).group(1).strip("\r\n ")+"\n"
    sample_out=re.search("SAMPLE OUTPUT \([^\)]*\)(.*?)Submission",plain,re.DOTALL).group(1).strip("\r\n ")+"\n"
    open(proj+"/"+proj+".in","w").write(sample_in) #auto-closed?
    open(proj+"/"+proj+".out","w").write("")
    open(proj+"/"+proj+".txt","w").write(plain)
    open(proj+"/"+proj+".cpp", "w").write(cmn.template.replace('%x%', proj).replace("%i%",sample_in).replace("%o%",sample_out))
    #auto-get sample inputs and put them in *.in, *.out, and also *.cpp for ref

    #OPEN IT ALL
    #what was the point of the with-as again?
    print("Successfully created files. Problem text to be opened in notepad and problem solution/project to be opened in Visual Studio.")
    os.startfile("./setup/USACO/USACO.sln")
    os.startfile("./"+proj+"/"+proj+".txt")
    raw_input("Press enter to exit...")
