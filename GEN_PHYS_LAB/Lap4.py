"""
    Task	: Lap4
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 04 October 2021 [08:16]
    Algo	:
    Status	:
"""

import math
import matplotlib.pyplot as plt
import numpy as np
import os


def clear(): return os.system('cls')


print('Secton 1')
d = float(input('Default length of spring: '))
data = []
for i in range(5):
    print('Dataset ' + str(i+1))
    m = float(input('mass: '))
    x = [float(y) for y in input('position of spring: ').split()]
    x = sum(x)/len(x)
    data.append((m, round(x-d, 4)))

plt.scatter(*zip(*data))
z = np.polyfit(*zip(*data), 1)
p = np.poly1d(z)
x_data = [0] + [x for x, y in data]
plt.plot(x_data, p(x_data), "r--")

plt.title("y=%.6fx + %.6f" % (z[0], z[1]))

clear()
print('\n'.join([str(x) for x in data]))
plt.show()

clear()
print('Section 2')
data = []
avg = []
for i in range(5):
    print('Dataset ' + str(i+1))
    m = float(input('mass: '))
    t = [float(x) for x in input('Time: ').split()]
    t = sum(t)/len(t)
    data.append((m, round((t/10)**2, 3)))
    avg.append(str(round(t, 2)))

plt.scatter(*zip(*data))
z = np.polyfit(*zip(*data), 1)
p = np.poly1d(z)
x_data = [0] + [x for x, y in data]
plt.plot(x_data, p(x_data), "r--")

plt.title("y=%.6fx + %.6f" % (z[0], z[1]))

clear()
print(' '.join(avg))
print('\n'.join([str(x) for x in data]))
plt.show()
