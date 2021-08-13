"""
	Task	: 04_Loop_12_ZigZag_1
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 12 August 2021 [12:08]
	Algo	: 
	Status	: 
"""
n = input()

mina = minb = 1e9
maxa = maxb = -1e9
i = 0

while n != 'Zig-Zag' and n != 'Zag-Zig':
    num1, num2 = [int(x) for x in n.split()]
    if i % 2 == 0:
        mina = min(mina, num1)
        maxa = max(maxa, num1)
        minb = min(minb, num2)
        maxb = max(maxb, num2)
    else:
        mina = min(mina, num2)
        maxa = max(maxa, num2)
        minb = min(minb, num1)
        maxb = max(maxb, num1)
    n = input()
    i += 1
if n == 'Zig-Zag':
    print(mina, maxb)
else:
    print(minb, maxa)
