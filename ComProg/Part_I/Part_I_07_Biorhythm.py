"""
	Task	: Part_I_07_Biorhythm
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 18 August 2021 [14:10]
	Algo	:
	Status	:
"""
import math

bd, bm, by, d, m, y = [int(x) for x in input().split()]
y -= 543
by -= 543

cnt = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

f = sum(cnt[:bm]) + bd
all = 365
if by % 400 == 0 or (by % 4 == 0 and by % 100 != 0):
    if bm > 2:
        f += 1
    all += 1

l = sum(cnt[:m]) + d
if y % 400 == 0 or (y % 4 == 0 and y % 100 != 0):
    if m > 2:
        l += 1
# print(f, l, all)
sum = (y-by-1)*365 + (all-f) + l
print(sum, "{:.2f}".format(math.sin(2*math.pi*sum/23)), "{:.2f}".format(math.sin(2*math.pi*sum/28)), "{:.2f}".format(math.sin(2*math.pi*sum/33)))
