"""
	Task	: 04_Loop_002_Partition
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [23:11]
	Algo	:
	Status	:
"""
d = [int(x) for x in input().split()]

p = d[len(d)-1]
i = -1
j = 0
n = len(d)

while j < n-1:
    if d[j] <= p:
        i += 1
        d[i], d[j] = d[j], d[i]
    j += 1

d[i+1], d[n-1] = d[n-1], d[i+1]
print(d)
