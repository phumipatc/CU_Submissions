"""
    Task	: Dominoes
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 30 September 2021 [09:33]
    Algo	: 
    Status	: 
"""
a = input().split('|')
k = int(input())
# print(a)
print('|'+a[k*2-1]+'|'+'|'.join(a[:k*2-1])+'|'.join(a[k*2:]))
