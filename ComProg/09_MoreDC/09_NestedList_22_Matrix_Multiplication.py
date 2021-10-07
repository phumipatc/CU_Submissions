"""
    Task	: 09_MoreDC_22_Matrix_Multiplication
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 October 2021 [11:40]
    Algo	: 
    Status	: 
"""


def read_matrix():
    m = []
    nrows = int(input())
    for k in range(nrows):
        x = input().split()
        r = []
        for e in x:
            r.append(float(e))
        m.append(r)
    return m


def mult_c(c, A):
    ret = A[:]
    for i in range(len(A)):
        for j in range(len(A[i])):
            ret[i][j] = A[i][j]*c
    return ret


def mult(A, B):
    ret = [[0]*len(B[0]) for i in range(len(A))]
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(A[0])):
                ret[i][j] += A[i][k] * B[k][j]
    return ret


exec(input().strip())
