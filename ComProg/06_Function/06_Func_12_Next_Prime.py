"""
    Task	: 06_Function_12_Next_Prime
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 14 August 2021 [11:56]
    Algo	:
    Status	:
"""


def is_prime(n):
    if n <= 1:
        return False
    for k in range(2, int(n**0.5)+1):
        if n % k == 0:
            return False
    return True


def next_prime(N):
    i = N+1
    while not is_prime(i):
        i += 1
    return i


def next_twin_prime(N):
    a = next_prime(N)
    b = next_prime(a)
    while b-a != 2:
        a = b
        b = next_prime(b)
    return (a, b)


exec(input().strip())
