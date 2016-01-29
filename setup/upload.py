"""
upload.py
A USACO upload script that uploads a training pages practice problem solution.
Copyright (c)2016 Clive Chan
MIT License
"""

import sys
import os
import mechanize
import warnings
import re
import html2text
warnings.filterwarnings("ignore")
execfile("secrets.py") #Just username and password var defs

browser = mechanicalsoup.Browser()
login_page = browser.get("http://train.usaco.org/usacogate")
login_form = mechanicalsoup.Form(login_page.soup.select("form")[0])
login_form.input({"NAME":username,"PASSWORD":password})
login_form.choose_submit(login_page.soup.select("form")[0].select("input")[2])

page2 = browser.submit(login_form, login_page.url)
fullname = page2.soup.select("a")[6].decode_contents(formatter="html").strip()
name = page2.soup.select("a")[6]['href']
name = name[name.find("&S=")+3:]

upload_form = mechanicalsoup.Form(page2.soup.select("form")[1])
upload_form.