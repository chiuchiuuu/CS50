import crypt
import string
import sys

if len(sys.argv) != 2:
    print("Usage: ./crack hash")
    exit(1)

hashed = sys.argv[1]
salt = hashed[0:2]
letters = string.ascii_letters

def check_pw(password):
    if (hashed == crypt.crypt(password, salt)):
        print(password)
        exit(0)

for letter1 in letters:
    password = letter1
    check_pw(password)
    for letter2 in letters:
        password = letter1 + letter2
        check_pw(password)
        for letter3 in letters:
            password = letter1 + letter2 + letter3
            check_pw(password)
            for letter4 in letters:
                password = letter1 + letter2 + letter3 + letter4
                check_pw(password)