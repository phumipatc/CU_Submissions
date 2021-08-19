"""
	Task	: Part_I_Flowchart_01_if_elif_else
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 19 August 2021 [21:26]
	Algo	: 
	Status	: 
"""
x1, x2, x3, x4, x5 = [int(x) for x in input().split()]
if x1-x5 > x2:
    if x2 > x3+x1:
        if x3+x5 > x4:
            print('C5')
        else:
            if x3 < x5:
                print('C6')
            else:
                print('C7')
            print('C8')
else:
    if not x2-x1 > x3:
        if not x4 < x5+x1:
            print('C1')
        else:
            if not x3+x2 > x5:
                print('C2')
            else:
                print('C3')
            print('C4')
