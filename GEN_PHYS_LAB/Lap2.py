import matplotlib.pyplot as plt
import numpy as np
import math

l = [float(x) for x in input('Input Length: ').split()]
t = [float(x) for x in input('Input Time: ').split()]

T = [x / 10 for x in t]
T2 = [round(x**2, 4 - int(math.floor(math.log10(abs(x**2)))) - 1) for x in T]

print("Period")
print('\n'.join([str(x) for x in T]))

print("Quadratic Period")
print('\n'.join([str(x) for x in T2]))

plt.plot(l, T2, 'o')

z = np.polyfit(l, T2, 1)
p = np.poly1d(z)
line = l[:]
line.append(0)
plt.plot(line, p(line), "r--")

plt.xlabel('Length')
plt.ylabel('Quadratic Period')
plt.title("y=%.6fx+%.6f" % (z[0], z[1]))
plt.axis([0, 115, 0, 4.5])

plt.show()

print()
print("x")
print('\n'.join([str(x) for x in l]))
sum_x = sum(l)
print("sum x:", sum(l))

print("y")
print('\n'.join([str(x) for x in T2]))
sum_y = sum(T2)
print("sum y:", sum(T2))

print("Quadratic x")
print('\n'.join([str(x**2) for x in l]))
sum_x2 = sum([x**2 for x in l])
print("sum quadratic x:", sum_x2)

print("xy")
print('\n'.join([str(round(l[i] * T2[i], 2)) for i in range(len(l))]))
sum_xy = sum([round(l[i] * T2[i], 2) for i in range(len(l))])
print("sum xy:", sum_xy)

m = (len(l)*sum_xy - sum_x*sum_y)/(len(l)*sum_x2 - sum_x**2)
print("m =", m)
