"""
	Task	: 02_StrList_03_US_Date
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 10 August 2021 [15:06]
	Algo	:
	Status	:
"""
date = [int(x) for x in input().split('/')]

month = ['', 'January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']

print(month[date[1]], str(date[0])+',', date[2])
