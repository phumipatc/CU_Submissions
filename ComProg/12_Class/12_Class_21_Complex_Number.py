class Complex:
    def __init__(self, a, b):
        self.real = a
        self.imag = b

    def __str__(self):
        if self.imag == 0:
            return str(self.real)
        elif self.imag < 0:
            return (str(self.real) if self.real != 0 else "") + '-' + (str(abs(self.imag)) if self.imag != -1 else "") + 'i'
        else:
            return ((str(self.real) + '+') if self.real != 0 else "") + (str(self.imag) if self.imag != 1 else "") + 'i'

    def __add__(self, rhs):
        return Complex(self.real + rhs.real, self.imag + rhs.imag)

    def __mul__(self, rhs):
        return Complex(self.real * rhs.real - self.imag * rhs.imag, self.real * rhs.imag + self.imag * rhs.real)

    def __truediv__(self, rhs):
        return Complex((self.real * rhs.real + self.imag * rhs.imag) / (rhs.real ** 2 + rhs.imag ** 2),
                       (self.imag * rhs.real - self.real * rhs.imag) / (rhs.real ** 2 + rhs.imag ** 2))


t, a, b, c, d = [int(x) for x in input().split()]
c1 = Complex(a, b)
c2 = Complex(c, d)
if t == 1:
    print(c1)
elif t == 2:
    print(c2)
elif t == 3:
    print(c1+c2)
elif t == 4:
    print(c1*c2)
else:
    print(c1/c2)
