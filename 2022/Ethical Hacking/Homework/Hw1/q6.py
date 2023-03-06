#Jack Blackburn q6 hw1 csci 4413

import socket
Host = "35.83.63.82"
port = 21234

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s: 
    s.connect((Host, port))
    
    numList = []
    
    data = s.recv(1024)
    numList.append(int.from_bytes(data[0:4], byteorder='little'))
    
    data += s.recv(1024)
    numList.append(int.from_bytes(data[4:8], byteorder='little'))
    numList.append(int.from_bytes(data[8:12], byteorder='little'))
    numList.append(int.from_bytes(data[12:16], byteorder='little'))
    
    sum = sum(numList)
    
    s.send(sum.to_bytes(16, byteorder='little' ))
    
    print(s.recv(1024))
