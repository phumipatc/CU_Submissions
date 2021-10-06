"""
    Task	: 09_MoreDC_34_Fill_In_Number
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 October 2021 [12:13]
    Algo	: 
    Status	: 
"""


def pattern1(nrows, ncols):
    return [[i*ncols + j + 1 for j in range(ncols)] for i in range(nrows)]


def pattern2(nrows, ncols):
    return [[j*nrows + i + 1 for j in range(ncols)] for i in range(nrows)]


def pattern3(N):
    ret = [[0]*N for i in range(N)]
    cnt = 1
    for i in range(N):
        for j in range(i, N):
            ret[i][j] = cnt
            cnt += 1
    return ret


def pattern4(N):
    ret = [[0]*N for i in range(N)]
    cnt = 1
    for j in range(N):
        for i in range(j, -1, -1):
            ret[i][j] = cnt
            cnt += 1
    return ret


def pattern5(N):
    ret = [[0]*N for i in range(N)]
    cnt = 1
    st = 0
    for x in range(N):
        i = 0
        j = st
        st += 1
        while i < N and j < N:
            ret[i][j] = cnt
            cnt += 1
            i += 1
            j += 1
    return ret


def pattern6(N):
    ret = [[0]*N for i in range(N)]
    cnt = 1
    stu = 0
    std = N-1
    for x in range(N):
        if x % 2 == 0:
            i = 0
            j = stu
        else:
            i = std
            j = N-1
        stu += 1
        std -= 1
        while i < N and j < N and i >= 0 and j >= 0:
            ret[i][j] = cnt
            cnt += 1
            i += 1 if x % 2 == 0 else -1
            j += 1 if x % 2 == 0 else -1
    return ret


exec(input().strip())
