"""
	Task	: 07_StrFile_23_Min_Max_Average
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 22 August 2021 [00:09]
	Algo	: 
	Status	: 
"""
f, y = [x for x in input().strip().split()]
y = y[2:]

all = []
with open(f, 'r') as file:
    n = file.readlines()
    for x in n:
        id, num = [y for y in x.split()]
        num = float(num)
        if id[:2] == y:
            all.append(num)

if len(all) == 0:
    print('No data')
    exit(0)

all.sort()
print(all[0], all[len(all)-1], sum(all)/len(all))
