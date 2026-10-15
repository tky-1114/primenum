import numpy as np
import time

start = time.perf_counter()

i=0

while(True):
    a = np.arange(i, i+1)
    b = a * 2
    print(b)
    i+=1
end = time.perf_counter()

print(end - start,"s")
#2.285779541125521 s