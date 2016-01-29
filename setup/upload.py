"""
upload.py
A USACO upload script that uploads a training pages practice problem solution.
Copyright (c)2016 Clive Chan
MIT License
"""

from common import *
import requests

mainpage = loginToMainPage()
isMostRecentOne = True

if len(sys.argv) > 1:
	name = sys.argv[1]
else:
	name = getName()

if name == getName():
	isMostRecentOne = True

upload_form = Form(mainpage.soup.select("form")[1])

sys.stderr.write("Uploading...\n")

if not os.path.exists(dir+'/'+name+'/'+name+'.cpp'):
	sys.stderr.write('Expected file '+name+'/'+name+'.cpp: not found\n')
	sys.exit(1)
else:
	res = requests.post(
		url="http://train.usaco.org"+upload_form.form['action'],
		data={element['name']: element['value'] for element in mainpage.soup.find_all('input') if all (k in element.attrs for k in ('name','value'))},
		files={'filename': open(dir+'/'+name+'/'+name+'.cpp', 'rb')})

	uploadoutfile = dir+'/'+name+'/uploadout.txt'
	open(uploadoutfile,'w').write(html2text(res.text[res.text.find('<div style=background-color:white;padding:5px;><pre>')+47:res.text.find("<a href='/usacodatashow?a=")]))

	if res.text.find(" produced all correct answers!") != -1:
		sys.stderr.write("Passed all test cases! ")
		if isMostRecentOne:
			sys.stderr.write("Getting next one... ")
			print(name)
		sys.stderr.write("\n")
		sys.exit(0)
	else:
		sys.stderr.write("Failed some test cases.\n")
		print(uploadoutfile);
		sys.exit(1)

