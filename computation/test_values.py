import numpy as np
from numpy.random import default_rng

rng = np.random.default_rng(12345)

def get_rand(min_, max_):
    return rng.random() * (max_ - min_) + min_

Ds = 5.0
Dp = 2.0

x = get_rand(1.5, 2.5)

Lx = get_rand(3.0, 6.0)
Ly = get_rand(3.0, 6.0)

print(f"x = {x}")
print(f"Ds = {Ds}")
print(f"Dp = {Dp}")
print(f"L = ({Lx}/{Ly})")

a = np.sqrt(Lx**2 + Ly**2)
b = np.sqrt((Lx+Ds)**2 + Ly**2)
c = np.sqrt(Lx**2 + (Ly-Dp)**2)
d = np.sqrt((Lx+Ds)**2 + (Ly-Dp)**2)

A, B, C, D = a / x, b / x, c / x, d / x

print(f"a={a}, b={b}, c={c}, d={d}")
print(f"A={A}, B={B}, C={C}, D={D}")



