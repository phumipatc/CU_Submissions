"""
    Task	: 05_List_12_Nickname
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 12 August 2021 [13:56]
    Algo	: 
    Status	: 
"""
name = ['Robert', 'William', 'James', 'John', 'Margaret', 'Edward', 'Sarah', 'Andrew', 'Anthony', 'Deborah']
nickname = ['Dick', 'Bill', 'Jim', 'Jack', 'Peggy', 'Ed', 'Sally', 'Andy', 'Tony', 'Debbie']

n = int(input())
for i in range(n):
    a = input()
    if a in name:
        idx = name.index(a)
        print(nickname[idx])
    else:
        if a in nickname:
            idx = nickname.index(a)
            print(name[idx])
        else:
            print('Not found')
