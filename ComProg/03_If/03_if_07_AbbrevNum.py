"""
	Task	: 03_if_07_AbbrevNum
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [18:19]
	Algo	: 
	Status	: 
"""
n = int(input())

if n < 1e3:
    print(n)
elif n < 1e4:
    print("%.1fK" % (n/1e3))
elif n < 1e6:
    print("%dK" % (round(n/1e3)))
elif n < 1e7:
    print("%.1fM" % (n/1e6))
elif n < 1e9:
    print("%dM" % (round(n/1e6)))
elif n < 1e10:
    print("%.1fB" % (n/1e9))
else:
    print("%dB" % (round(n/1e9)))
