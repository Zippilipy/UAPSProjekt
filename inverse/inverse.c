#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
# define N 100

// Calculates the determinant of a matrix using gaussian elimination
float determinant(float matrix[N][N]) {
    int i, j, k;
    float det = 1;
    
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            float factor = matrix[j][i] / matrix[i][i];
            for (k = i; k < N; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    
    for (i = 0; i < N; i++) {
        det *= matrix[i][i];
    }
    
    return det;
}


int main() {
		int det = 0, row, column;
        float matrix[N][N];
        int identity[N][N];

		// creates the identity matrix	
        for(row = 0; row < N; row++){
                for(column = 0; column < N; column++){
                        if(column == row){
                                identity[row][column] = 1;
                        }else{
                                identity[row][column] = 0;
                        }
                }
        }
		
		struct timespec t_one, t_two;
        clock_gettime(CLOCK_MONOTONIC_RAW, &t_one);

		// creates a random matrix until an invertible is created
		while(det == 0){
        	int row, column;
        	srand(time(NULL));
        	for(row = 0; row < N; row++){
               	for(column = 0; column < N; column++){
                    matrix[row][column] = rand()%100;    
            	}
        	}
			det = determinant(matrix); 
		}

		// inverts the matrix
        int i,j,k;
        for(i = 0; i < N; i++){
                double pivot = matrix[i][i];
                for(j = 0; j < N; j++){
                        matrix[i][j] = matrix[i][j]/pivot;
                        identity[i][j] = identity[i][j]/pivot;
                }    
                for(k = 0; k < N; k++){
                        if(k!=i){
                                int factor = matrix[k][i];
                                for(j = 0; j < N; j++){
                                        matrix[k][j] = matrix[k][j] - factor * matrix[i][j];
                                        identity[k][j] = identity[k][j] - factor * identity[i][j];
                                }
                        }
                }
		}
    	clock_gettime(CLOCK_MONOTONIC_RAW, &t_two);
        long elapsed_ns = (t_two.tv_sec - t_one.tv_sec) * 1000000000L + (t_two.tv_nsec - t_one.tv_nsec);
        printf("%ld\n", elapsed_ns);
		return 0;
}
