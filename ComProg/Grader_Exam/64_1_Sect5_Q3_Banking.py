"""
    Task	: 64_1_Sect5_Q3_Banking
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 23 November 2021 [09:33]
    Algo	: 
    Status	: Finished
"""
banking = dict()
n = int(input())
for i in range(n):
    name, id, val = input().split()
    banking[id] = {'name': name, 'val': float(val)}

inp = input().strip().split()
while inp[0] != 'exit':
    if len(inp) == 4:
        if(inp[2] == 'deposit'):
            if inp[1] not in banking:
                banking[inp[1]] = {'name': inp[0], 'val': 0}
            if(inp[0] != banking[inp[1]]['name']):
                print('Transaction Failed')
            else:
                banking[inp[1]]['val'] += float(inp[3])
                val = banking[inp[1]]['val']
                if val//1 == val:
                    val = int(val)
                print(banking[inp[1]]['name'], '(' + inp[1] + ')', val)
        elif inp[2] == 'withdraw':
            if(inp[1] not in banking or inp[0] != banking[inp[1]]['name'] or banking[inp[1]]['val'] < float(inp[3])):
                print('Transaction Failed')
            else:
                banking[inp[1]]['val'] -= float(inp[3])
                val = banking[inp[1]]['val']
                if val//1 == val:
                    val = int(val)
                print(banking[inp[1]]['name'], '(' + inp[1] + ')', val)
    elif len(inp) == 5:
        if inp[2] == 'transfer':
            if(inp[1] not in banking or inp[3] not in banking or inp[0] != banking[inp[1]]['name'] or banking[inp[1]]['val'] < float(inp[4])):
                print('Transaction Failed')
            else:
                banking[inp[1]]['val'] -= float(inp[4])
                banking[inp[3]]['val'] += float(inp[4])
                val = banking[inp[1]]['val']
                if val//1 == val:
                    val = int(val)
                print(banking[inp[1]]['name'], '(' + inp[1] + ')', val)
                val = banking[inp[3]]['val']
                if val//1 == val:
                    val = int(val)
                print(banking[inp[3]]['name'], '(' + inp[3] + ')', val)
    inp = input().strip().split()
