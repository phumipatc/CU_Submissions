"""
    Task	: 07_StrFile_21_Rot13
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 14 August 2021 [00:21]
    Algo	:
    Status	:
"""
a = input()
while a != 'end':
    for x in a:
        if not x.isalpha():
            print(x, end='')
        else:
            if x.isupper():
                print(chr((ord(x)-ord('A')+13) % 26+ord('A')), end='')
            else:
                print(chr((ord(x)-ord('a')+13) % 26+ord('a')), end='')
    print('')
    a = input()
