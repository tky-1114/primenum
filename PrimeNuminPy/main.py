import numpy as np
import time

start = time.perf_counter()

a = np.arange(1000000)
b = a * 2
print(b)
end = time.perf_counter()

print(end - start,"s")
#2.285779541125521 s