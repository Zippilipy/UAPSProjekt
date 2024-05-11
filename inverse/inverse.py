""" Implements the algorithm in the most effective way """
import time
import numpy as np

DIMENSION = 100 
MIN = 0
MAX = 100

start_time = time.time()

DETERMINANT = 0

while abs(DETERMINANT) < 1:
    A = np.array([np.random.randint(MIN,MAX, size=(DIMENSION,DIMENSION))])
    DETERMINANT = np.linalg.det(A)
    print(A)
    matrix = np.linalg.inv(A)
    if DETERMINANT != 0:
        print("determinant is ", DETERMINANT)


end_time = time.time()
elapsed_time = end_time - start_time

# Prints end time
print(elapsed_time)
