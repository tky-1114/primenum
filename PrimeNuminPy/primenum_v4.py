import math
import numpy

count = 0
n = 1
i = 1

while n >= 0:
    count = 0
    i = 1
    
    for i in range(2, math.isqrt(n) + 1):
        div = np.aran
        result = n % i
        if result == 0:
            count += 1
        else:
            pass

    if count == 2:
        print(n)
    n += 1
    count = None
    i = None