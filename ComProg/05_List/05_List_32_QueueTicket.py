"""
	Task	: 05_List_32_QueueTicket
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 14 August 2021 [11:40]
	Algo	: 
	Status	: 
"""
Q = int(input())
que = []
idx = -1
sum = num = 0
for q in range(Q):
    cmd = input().split()
    if cmd[0] == 'reset':
        cnt = int(cmd[1])
    elif cmd[0] == 'new':
        que.append((cnt, int(cmd[1])))
        print('ticket', cnt)
        cnt += 1
    elif cmd[0] == 'next':
        idx += 1
        print('call', que[idx][0])
    elif cmd[0] == 'order':
        sum += int(cmd[1])-que[idx][1]
        num += 1
        print('qtime', que[idx][0], int(cmd[1])-que[idx][1])
    elif cmd[0] == 'avg_qtime':
        print('avg_qtime', sum/num)
