import matplotlib.pyplot as plt
import numpy as np

m = [int(x) for x in input('mass: ').split()]
t = [float(x) for x in input('time: ').split()]

T = [9.8 * x / 1000 for x in m]
print(T)

a = [2 * 0.885 / x**2 for x in t]
# print(a)

T2 = [m[i] * (9.8 - a[i]) / 1000 for i in range(len(T))]
print(T2)

alpha = [x * 1000 / 9.75 for x in a]
# print(alpha)

torq = [x * 9.75 / 1000 for x in T2]
print(torq)

plt.scatter(alpha, torq)

z = np.polyfit(alpha, torq, 1)
p = np.poly1d(z)
x_data = [0] + alpha
plt.plot(x_data, p(x_data), "r--")
plt.title("y=%.6fx + %.6f" % (z[0], z[1]))

plt.scatter([0], [0])

plt.show()
