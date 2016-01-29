from mechanicalsoup import Browser, Form # We need our own installation (straight from the repo) because the pip package doesn't have choose_submit
from secrets import username, password
from html2text import html2text
import os
import sys

dir = os.path.dirname(os.path.dirname(__file__))

def newBrowser():
	return Browser(soup_config={"features":"html.parser"})

def getName():
	return name

def getFull():
	return fullname

def loginToMainPage():
	"Returns logged in main page for USACO"
	browser = newBrowser()
	
	login_page = browser.get("http://train.usaco.org/usacogate")
	login_form = Form(login_page.soup.select("form")[0])
	login_form.input({"NAME":username,"PASSWORD":password})
	login_form.choose_submit(login_page.soup.select("form")[0].select("input")[2])
	
	mainpage = browser.submit(login_form, login_page.url)
	
	global name
	global fullname
	name = mainpage.soup.select("a")[6]['href']
	name = name[name.find("&S=")+3:]
	fullname = mainpage.soup.select("a")[6].decode_contents(formatter="html").strip()
	
	return mainpage
