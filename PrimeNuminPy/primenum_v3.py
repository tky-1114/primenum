import math

count = 0
n = 1
i = 1
p_num= []

while n >= 0:
    count = 0
    i = 1

    for _i_ in range(0,len(p_num)):
        if n % p_num[_i_] == 0 and n != p_num[_i_]:
            n+=1
    
    for i in range(2, math.isqrt(n) + 1):
        result = n % i
        if result == 0:
            count += 1
        else:
            pass

    if count == 2:
        print(n)
        p_num.append(n)
    n += 1
    count = None
    i = None