"""
    Task	: 12_Class_32_Rect_Sorted_by_Area
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 November 2021 [00:20]
    Algo	: 
    Status	: 
"""


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "("+str(self.x)+","+str(self.y)+")"


class Rect:
    def __init__(self, p1, p2):
        self.lowerleft = p1
        self.upperright = p2

    def __str__(self):
        return str(self.lowerleft)+"-"+str(self.upperright)

    def Area(self):
        return (self.upperright.x-self.lowerleft.x)*(self.upperright.y-self.lowerleft.y)

    def __lt__(self, other):
        return self.Area() < other.Area()


n = int(input())
rects = []
for i in range(n):
    x1, y1, x2, y2 = [int(e) for e in input().split()]
    rects.append(Rect(Point(x1, y1), Point(x2, y2)))
rects.sort()
for i in range(n):
    print(rects[i])
