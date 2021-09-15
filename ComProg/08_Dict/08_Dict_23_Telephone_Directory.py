"""
	Task	: 08_Dict_23_Telephone_Directory
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 15 September 2021 [22:20]
	Algo	: 
	Status	: 
"""
n = int(input())
a = {}
b = {}
for i in range(n):
    name, surname, phone = [x for x in input().split()]
    name = name + ' ' + surname
    a[name] = phone
    b[phone] = name

m = int(input())
for i in range(m):
    target = input().strip()
    if target in a:
        print(target, '-->', a[target])
    elif target in b:
        print(target, '-->', b[target])
    else:
        print(target, '-->', 'Not found')
