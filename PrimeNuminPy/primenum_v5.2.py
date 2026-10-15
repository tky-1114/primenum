import math
import numpy as np

n = 2
p_num = np.array([])

while n >= 0:
    count = 0
    if np.any(n % p_num == 0) and n!= 2:
        n += 1
        continue
    
    div = np.arange(2, math.isqrt(n) + 1)
    result = n % div

    if not np.any(result == 0):
        print(n)
        p_num = np.append(p_num, n)
    n += 1