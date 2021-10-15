"""
    Task	: 10_TSD_35_Student_Info
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 15 October 2021 [16:33]
    Algo	: 
    Status	: 
"""
data = {}

for i in range(int(input())):
    id = input().split()
    data[id[0]] = id[1:]

target = set(input().split())
ans = sorted([[x]+data[x] for x in data if target.issubset(data[x])])

if len(ans) == 0:
    print('Not Found')
else:
    for x in ans:
        print(' '.join(x))
