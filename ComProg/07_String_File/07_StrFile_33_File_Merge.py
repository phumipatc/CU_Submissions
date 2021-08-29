"""
	Task	: 07_StrFile_33_File_Merge
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 29 August 2021 [12:09]
	Algo	: 
	Status	: 
"""


def compare(a: list, b: list):
    if a[0][8:] < b[0][8:]:
        return 0
    if a[0][8:] > b[0][8:]:
        return 1
    if a[0] < b[0]:
        return 0
    if a[0] > b[0]:
        return 1


f1, f2 = [x.strip() for x in input().split()]
with open(f1, 'r') as a, open(f2, 'r') as b:
    i = j = True
    data_a = a.readline().strip().split()
    if data_a == []:
        i = False
    data_b = b.readline().strip().split()
    if data_b == []:
        j = False
    # print(data_a, data_b, i, j)
    while i and j:
        if compare(data_a, data_b) == 0:
            print(' '.join(data_a))
            data_a = a.readline().strip().split()
            if data_a == []:
                i = False
        elif compare(data_a, data_b) == 1:
            print(' '.join(data_b))
            data_b = b.readline().strip().split()
            if data_b == []:
                j = False

    while i:
        print(' '.join(data_a))
        data_a = a.readline().strip().split()
        if data_a == []:
            i = False

    while j:
        print(' '.join(data_b))
        data_b = b.readline().strip().split()
        if data_b == []:
            j = False
