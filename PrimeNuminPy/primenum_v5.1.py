import math
import numpy as np

n = 2
while n >= 0:
    count = 0
    if n % 2 == 0 and n!= 2:
        n += 1
    div = np.arange(2, math.isqrt(n) + 1)
    result = n % div
    
    if not np.any(result == 0):
        print(n)
    n += 1