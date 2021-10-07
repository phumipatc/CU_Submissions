"""
    Task	: 09_MoreDC_26_Location_Analysis
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 07 October 2021 [14:33]
    Algo	: 
    Status	: 
"""
n = int(input())
people = []
for i in range(n):
    id, t = input().split(': ')
    t = t.split(', ')
    people.append((id, t))
target = input().strip()
town = [t for id, t in people if id == target][0]

found = False
for id, t in people:
    if id == target:
        continue
    for x in t:
        if x in town:
            print(id)
            found = True
            break

if not found:
    print('Not Found')
