import time as t
import sys

amount = int(sys.argv[1])
for i in range(0, amount):
    length = 1000000
    root = length**0.5
    array = list(range(0,length,1))
    isPrime = [True for x in range(length)]
    
    i = 2
    start = t.time_ns() 
    while i < root:
        if(isPrime[i]):
            multiplier = 0
            j = i**2+multiplier*i
            while j < length:
                isPrime[j] = False
                multiplier = multiplier + 1
                j = i**2+multiplier*i
        i=i+1
    end = t.time_ns() 
    duration = end - start
    print(duration)
