import math

n = 2#12940619

while n >= 0:
    count = 0
    if n % 2 == 0:
        n += 1
    
    for i in range(2, math.isqrt(n) + 1):
        if n%i == 0:
            count += 1
            break

    if count == 0:
        print(n)
    n += 1