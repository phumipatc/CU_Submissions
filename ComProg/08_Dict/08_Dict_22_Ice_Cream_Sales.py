"""
	Task	: 08_Dict_22_Ice_Cream_Sales
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 15 September 2021 [22:05]
	Algo	: 
	Status	: 
"""
n = int(input())

ice = {}
sale = {}
for i in range(n):
    name, price = [x for x in input().split()]
    ice[name] = float(price)

m = int(input())
for i in range(m):
    name, num = [x for x in input().split()]
    if name in ice:
        if name in sale:
            sale[name] += ice[name]*int(num)
        else:
            sale[name] = ice[name]*int(num)

sum = sum(sale.values())
ans = [x[0] for x in sale.items() if x[1] == max(sale.values())]

if sum == 0:
    print('No ice cream sales')
else:
    print('Total ice cream sales:', sum)
    print('Top sales:', ', '.join(sorted(ans)))
