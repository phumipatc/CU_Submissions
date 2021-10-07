"""
    Task	: 09_MoreDC_21_Naive_Factorization
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 October 2021 [11:36]
    Algo	: 
    Status	: 
"""


def factor(N):
    ret = []
    for i in range(2, N+1):
        if i > N:
            break
        if N % i != 0:
            continue
        cnt = 0
        while N % i == 0:
            cnt += 1
            N //= i
        ret.append([i, cnt])
    return ret


exec(input().strip())
