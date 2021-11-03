import math

u = 0.123 / 1000

l = [float(x) for x in input("l: ").split()]
m = [float(x) for x in input("m: ").split()]

lam = [2*x for x in l]
print("lambda", lam)

v = [round(math.sqrt(x * 9.8 / u), 2) for x in m]
print("v", v)

f = [round(v[i] / lam[i], 2) for i in range(len(v))]
print("f", f, sum(f)/len(f))
