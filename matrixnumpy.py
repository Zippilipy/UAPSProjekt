import numpy as np
import time as t
import sys

def softmax(x):
    exp_x = np.exp(x - np.max(x))
    return exp_x / np.sum(exp_x, axis=0)

def matrixmultiply():
    contextSize = 2048 # 2048
    amountTokens = 50000 # 50000
    matrix = np.random.uniform(low=-10.0, high=10.0, size=(amountTokens, contextSize))
    matrix = softmax(matrix)
    return np.argmax(matrix, axis=0)[0]

def main():
    amount = int(sys.argv[1])
    for i in range(amount):
        start_time = t.time_ns()
        choice = matrixmultiply()
        end_time = t.time_ns()
        print(end_time - start_time)

if __name__ == "__main__":
    main()