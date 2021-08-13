"""
	Task	: Part_I_01_Older
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 12 August 2021 [12:54]
	Algo	: 
	Status	: 
"""
a = [x for x in input().split()]
b = [x for x in input().split()]

if int(a[3]) < int(b[3]):
    print(a[0])
    exit(0)
elif int(a[3]) > int(b[3]):
    print(b[0])
    exit(0)

month = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']
idxa = month.index(a[1])
idxb = month.index(b[1])
if idxa < idxb:
    print(a[0])
    exit(0)
elif idxa > idxb:
    print(b[0])
    exit(0)

a[2] = a[2][:len(a[2])-1]
b[2] = b[2][:len(b[2])-1]
if int(a[2]) < int(b[2]):
    print(a[0])
    exit(0)
elif int(a[2]) > int(b[2]):
    print(b[0])
    exit(0)

print(a[0], b[0])
