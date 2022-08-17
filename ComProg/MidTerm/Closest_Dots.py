"""
    Task	: Closest_Dots
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 30 September 2021 [09:41]
    Algo	: 
    Status	: 
"""
import math
dots = [[3, 5], [1, 2], [1, 10], [2, 10]]


def dis(a, b):
    return math.sqrt((a[0]-b[0])**2 + (a[1]-b[1])**2)


new_dot = [int(x) for x in input().split(',')]

dots.append([3, 5])

idx = 0
mn = 1e9
for i in range(len(dots)-1):
    dist = dis(new_dot, dots[i]) + dis(new_dot, dots[i+1]) - dis(dots[i], dots[i+1])
    # print(dist)
    if mn > dist:
        mn = dist
        idx = i

dots.pop()
dots.insert(idx+1, new_dot)
print(dots)
