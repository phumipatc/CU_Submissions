import math
from os import sep

w = [float(x) for x in input('Input W: ').split()]
l = [float(x) for x in input('Input L: ').split()]
d = [float(x) for x in input('Input D: ').split()]
m = [float(x) for x in input('Input M: ').split()]

w_av = sum(w)/len(w)
l_av = sum(l)/len(l)
d_av = sum(d)/len(d)
m_av = sum(m)/len(m)
print("Average\n", w_av, l_av, d_av, m_av, sep='\t')

w_sd = math.sqrt(sum([(x-w_av)**2 for x in w])/(len(w)))
l_sd = math.sqrt(sum([(x-l_av)**2 for x in l])/(len(l)))
d_sd = math.sqrt(sum([(x-d_av)**2 for x in d])/(len(d)))
m_sd = math.sqrt(sum([(x-m_av)**2 for x in m])/(len(m)))
print("S.D.\n", w_sd, l_sd, d_sd, m_sd, sep='\t')

w_sd_mean = w_sd/math.sqrt(len(w))
l_sd_mean = l_sd/math.sqrt(len(l))
d_sd_mean = d_sd/math.sqrt(len(d))
m_sd_mean = m_sd/math.sqrt(len(m))
print("S.D. of mean\n", w_sd_mean, l_sd_mean, d_sd_mean, m_sd_mean, sep='\t')

delta_w = max(w_sd_mean, 0.005)
delta_l = max(l_sd_mean, 0.005)
delta_d = max(d_sd_mean, 0.001)
delta_m = max(m_sd_mean, 0.01)
print("Delta\n", delta_w, delta_l, delta_d, delta_m, sep='\t')

v = w_av*l_av*d_av
print("Volume:", v)

delta_v = v * math.sqrt((delta_w/w_av)**2 + (delta_l/l_av)**2 + (delta_d/d_av)**2)
print("Delta Volume:", delta_v)

p = m_av/v
print("Density:", p)

delta_p = p * math.sqrt((delta_w/w_av)**2 + (delta_l/l_av)**2 + (delta_d/d_av)**2 + (delta_m/m_av)**2)
print("Delta Density:", delta_p)
