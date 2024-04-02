import numpy as np
import time as t
import sys

def softmax(matrix):
    exp_x = np.exp(matrix - np.max(matrix))
    return exp_x / np.sum(exp_x, axis=0)

def matrixmultiply(matrix, vector):
    result = np.dot(matrix, vector)
    result = softmax(result)
    return np.argmax(result, axis=0)[0]

def main():
    amount = int(sys.argv[1])
    dimensions = 12288 # chatgpt har 12288 dimensioner
    amountTokens = 50000 # chatgpt har 50000 så kallade tokens, kan tänka sig att det är som ord i chatgpts lexikon
    for i in range(amount):
        matrix = np.random.uniform(low=-10.0, high=10.0, size=(amountTokens, dimensions))
        matrix = np.round(matrix, 1)
        word = np.random.uniform(low=-10.0, high=10.0, size=(dimensions, 1))
        word = np.round(word, 1)
        start_time = t.time_ns()
        choice = matrixmultiply(matrix, word)
        end_time = t.time_ns()
        print(end_time - start_time)

if __name__ == "__main__":
    main()