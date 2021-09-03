import math

w = [float(x) for x in input('Input W (cm):\t').split()]
l = [float(x) for x in input('Input L (cm):\t').split()]
d = [float(x) for x in input('Input D (cm):\t').split()]
m = [float(x) for x in input('Input M (g):\t').split()]

w_av = sum(w) / len(w)
l_av = sum(l) / len(l)
d_av = sum(d) / len(d)
m_av = sum(m) / len(m)
w_av = round(w_av, 4 - int(math.floor(math.log10(abs(w_av)))) - 1)
l_av = round(l_av, 4 - int(math.floor(math.log10(abs(l_av)))) - 1)
d_av = round(d_av, 4 - int(math.floor(math.log10(abs(d_av)))) - 1)
m_av = round(m_av, 3 - int(math.floor(math.log10(abs(m_av)))) - 1)
print("Average\n", w_av, l_av, d_av, m_av, sep='\t')

w_sd = math.sqrt(sum([(x - w_av)**2 for x in w]) / (len(w) - 1))
l_sd = math.sqrt(sum([(x - l_av)**2 for x in l]) / (len(l) - 1))
d_sd = math.sqrt(sum([(x - d_av)**2 for x in d]) / (len(d) - 1))
m_sd = math.sqrt(sum([(x - m_av)**2 for x in m]) / (len(m) - 1))
w_sd = round(w_sd, 4 - int(math.floor(math.log10(abs(w_sd)))) - 1)
l_sd = round(l_sd, 4 - int(math.floor(math.log10(abs(l_sd)))) - 1)
d_sd = round(d_sd, 4 - int(math.floor(math.log10(abs(d_sd)))) - 1)
m_sd = round(m_sd, 3 - int(math.floor(math.log10(abs(m_sd)))) - 1)
print("S.D.\n", w_sd, l_sd, d_sd, m_sd, sep='\t')

w_sd_mean = w_sd / math.sqrt(len(w))
l_sd_mean = l_sd / math.sqrt(len(l))
d_sd_mean = d_sd / math.sqrt(len(d))
m_sd_mean = m_sd / math.sqrt(len(m))
w_sd_mean = round(w_sd_mean, 4 - int(math.floor(math.log10(abs(w_sd_mean)))) - 1)
l_sd_mean = round(l_sd_mean, 4 - int(math.floor(math.log10(abs(l_sd_mean)))) - 1)
d_sd_mean = round(d_sd_mean, 4 - int(math.floor(math.log10(abs(d_sd_mean)))) - 1)
m_sd_mean = round(m_sd_mean, 3 - int(math.floor(math.log10(abs(m_sd_mean)))) - 1)
print("S.D. of mean\n", w_sd_mean, l_sd_mean, d_sd_mean, m_sd_mean, sep='\t')

delta_w = max(w_sd_mean, 0.005)
delta_l = max(l_sd_mean, 0.005)
delta_d = max(d_sd_mean, 0.001)
delta_m = max(m_sd_mean, 0.01)
print("Delta\n", delta_w, delta_l, delta_d, delta_m, sep='\t')

v = w_av * l_av * d_av
v = round(v, 6 - int(math.floor(math.log10(abs(v)))) - 1)
print("Volume:", v)

delta_v = v * math.sqrt((delta_w / w_av)**2 + (delta_l / l_av)**2 + (delta_d / d_av)**2)
delta_v = round(delta_v, 6 - int(math.floor(math.log10(abs(delta_v)))) - 1)
print("Delta Volume:", delta_v)

p = m_av / v
p = round(p, 6 - int(math.floor(math.log10(abs(p)))) - 1)
print("Density:", p)

delta_p = p * math.sqrt((delta_w / w_av)**2 + (delta_l / l_av)**2 + (delta_d / d_av)**2 + (delta_m / m_av)**2)
delta_p = round(delta_p, 6 - int(math.floor(math.log10(abs(p)))) - 1)
print("Delta Density:", delta_p)
