"""
    Task	: Part_I_Flowchart_02
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 19 August 2021 [21:30]
    Algo	:
    Status	:
"""
n, k = [int(x) for x in input().split()]
if n % 2 == 1:
    suma = sumb = sumc = m = 0
    while(m < k):
        a, b, c = [int(x) for x in input().split()]
        if a == b:
            if a == b == c:
                if a+b > k:
                    suma += 1
                    sumb += 2
                    sumc -= 3
                else:
                    suma -= 3
                    sumb -= 2
                    sumc += 1
            else:
                suma += 2
                sumb -= 3
        m += 1
    print(suma, sumb, sumc)
else:
    s, t = [int(x) for x in input().split()]
    x = s
    y = t
    if s > t:
        x = s-t
    elif s < t:
        y = 2*(t-s)
    if x+y > k:
        x, y = y, x
        x = y + s**2
    print(x, y)
