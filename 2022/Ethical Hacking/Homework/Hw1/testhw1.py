#!/usr/bin/python
import hashlib

login_db = {
        'john'   : 'f56f6c2009c63dac4328d45fe4865ccf',
        'alisha' : '09d412324fdb8f8673626ceefbb402d0',
        'chris'  : '9d9116194481d02a2e1dc8a8700f6af1',
        'jared'  : '2b00142f7481c7b056c4b410d28f33cf',
    }

def check(cred):
    user    = cred.split('&')[0]
    pwdhash = cred.split('&')[1]
    #print(login_db[user])
    return (user in login_db) and (login_db[user] == pwdhash)


if __name__ == "__main__":
    username = raw_input("Username: ")
    if not username: exit("Invalid Username")

    password = raw_input("Password: ")
    if not password: exit("Invalid Password")

    # hash the password and package up with username
    userpass = username + '&' + hashlib.md5(password).hexdigest()
    if check(userpass):
        print ('Login successful')
    else:
        print ('Login rejected')
