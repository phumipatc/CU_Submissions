import matplotlib.pyplot as plt
import numpy as np

l2 = [float(x) for x in input().split()]
T2l = [float(x) for x in input().split()]
plt.scatter(l2, T2l)

z = np.polyfit(l2, T2l, 1)
p = np.poly1d(z)
x_data = [0] + l2
plt.plot(x_data, p(x_data), "r--")
plt.title("y=%.6fx + %.6f" % (z[0], z[1]))
print(p([0]))

plt.show()
