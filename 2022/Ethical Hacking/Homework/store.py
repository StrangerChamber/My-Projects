#!/usr/bin/python
import sys
import cgi
import random
import os
import tempfile
import Cookie
#debugging
#import cgitb; cgitb.enable()

def die(str):
    print "Content-Type: text/html"
    print ""
    print """<html>
<head><title>Forum</title></head>
<body>
%s
</body>
</html>""" % str
    sys.exit(0)


form = cgi.FieldStorage()

if form.has_key("id"):
    id = form["id"].value;
else:
    id = ""
if form.has_key("site"):
    site = form["site"].value;
else:
    site = ""
if form.has_key("password"):
    password = form["password"].value;
else:
    password = ""
if form.has_key("admin"):
    admin = form["admin"].value;
else:
    admin = "0"

debug = 0
if debug == 1:
    id = "foo"
    site = "www.bar.com"
    password = "zot"

if (id == "" or site == "" or password == ""):
    die("<p>Missing parameters.</p>")

if id.isalnum() == False:
    die("<p>Bad id.</p>")

if admin == "1":
    user = Cookie.SimpleCookie(os.environ['HTTP_COOKIE'])['user'].value
    if user.isalnum() == False:
        die("<p>Malformed cookie.</p>")
    f = open(user, "r")
    m = f.read()
    f.close()
    die("<p>File:</p><pre>%s</pre>" % m)

f = open(id, "a+")
f.write("%s:%s\n" % (site, password))
f.close()

die("<p>Password saved.</p>")
