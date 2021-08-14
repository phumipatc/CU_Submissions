"""
    Task	: 06_Func_22_Distance
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 14 August 2021 [12:13]
    Algo	:
    Status	:
"""
import math


def distance1(x1, y1, x2, y2):
    dx = abs(x2-x1)
    dy = abs(y2-y1)
    return math.sqrt(dx*dx + dy*dy)


def distance2(p1, p2):
    dx = abs(p2[0]-p1[0])
    dy = abs(p2[1]-p1[1])
    return math.sqrt(dx*dx + dy*dy)


def distance3(c1, c2):
    dx = abs(c2[0]-c1[0])
    dy = abs(c2[1]-c1[1])
    dis = math.sqrt(dx*dx + dy*dy)
    overlap = True if dis <= c1[2]+c2[2] else False
    return (dis, overlap)


def perimeter(points):
    n = len(points)
    sum = 0
    for i in range(1, n):
        sum += distance2(points[i-1], points[i])
    sum += distance2(points[0], points[n-1])
    return sum


exec(input().strip())
