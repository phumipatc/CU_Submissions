"""
    Task	: 09_MoreDC_14_Database
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 October 2021 [15:19]
    Algo	: 
    Status	: 
"""
inp = input().strip()
courses = dict()
with open(inp, 'r') as f:
    a = f.readlines()
    for x in a:
        idx, id = x.split(',')
        courses[idx] = id.strip()

inp = input().strip()
teachers = dict()
with open(inp, 'r') as f:
    a = f.readlines()
    for x in a:
        idx, id = x.split(',')
        teachers[idx] = id.strip()

inp = input().strip()
with open(inp, 'r') as f:
    a = f.readlines()
    for x in a:
        id1, id2 = x.strip().split(',')
        if id1 not in courses or id2 not in teachers:
            print('record error')
            continue
        print(courses[id1]+','+teachers[id2])
