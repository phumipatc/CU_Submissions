"""
	Task	: 05_List_11_Missing_Digits
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 12 August 2021 [13:51]
	Algo	: 
	Status	: 
"""
a = input()
num = [str(x) for x in range(0, 10) if a.find(str(x)) == -1]
print(','.join(num) if len(num) != 0 else 'None')
