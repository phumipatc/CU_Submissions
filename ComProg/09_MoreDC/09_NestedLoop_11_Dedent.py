"""
    Task	: 09_MoreDC_11_Dedent
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 October 2021 [11:25]
    Algo	: 
    Status	: 
"""
n = int(input())
for i in range(n):
    a = input().strip()
    cnt = 0
    for x in a:
        if x == '.' and cnt != -1:
            cnt += 1
        else:
            print('.'*(cnt//2), end='')
            cnt = -1
            print(x, end='')
    print()
