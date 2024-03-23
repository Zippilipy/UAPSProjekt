#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv){
    long amount = atol(argv[1]);
    for(long j = 0; j < amount; j++) {
        int length = 1000000;
        _Bool isPrime[length];
        int array[length];
        int i = 0;
        for(i = 0; i < length; i++){
            isPrime[i] = 1;
            array[i]=i;
        }

        struct timespec t_one, t_two;
        clock_gettime(CLOCK_MONOTONIC_RAW, &t_one);

        float s = (float)length;
        long square = sqrt(1000000);
        i = 0;
        int a = 0;
        for(i = 2; i < square; i++){
            if(isPrime[i]){
                long multiplier = 0;
                long j = i * i + multiplier * i;
                while(j<length){
                    isPrime[j] = 0;
                    multiplier++;
                    j = i * i + multiplier * i;
                }
            }
        }

        clock_gettime(CLOCK_MONOTONIC_RAW, &t_two);
        long elapsed_ns = (t_two.tv_sec - t_one.tv_sec) * 1000000000L + (t_two.tv_nsec - t_one.tv_nsec);
        printf("%ld\n", elapsed_ns);
    }
    return 0;
}
