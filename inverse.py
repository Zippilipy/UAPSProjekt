# Uses numpy
import time
import numpy as np

DIMENSION = 100

start_time = time.time()

# Calculates and prints an array
A = np.array([np.random.rand(DIMENSION,DIMENSION)])
matrix = np.linalg.inv(A)

end_time = time.time()
elapsed_time = end_time - start_time

# Prints end time
print(elapsed_time)
