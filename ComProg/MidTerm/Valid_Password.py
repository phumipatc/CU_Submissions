"""
    Task	: Valid_Password
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 30 September 2021 [09:33]
    Algo	: 
    Status	: 
"""
pw = input()

sm = bg = n = False
for x in pw:
    if x.isnumeric():
        n = True
    if x.islower():
        sm = True
    if x.isupper():
        bg = True

if len(pw) == 5 and sm and bg and n:
    print('Valid Password')
else:
    print('Invalid Password')
