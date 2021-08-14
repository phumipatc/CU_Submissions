"""
    Task	: 07_StrFIle_13_CamelCase
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 14 August 2021 [00:03]
    Algo	:
    Status	:
"""
a = input()
for x in a:
    if not x.isalnum() and x != ' ':
        a = a.replace(x, ' ')
a = a.lower().split()
print(a[0], end='')
for x in a[1:]:
    print(x.capitalize(), end='')
