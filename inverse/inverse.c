#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
# define N 5


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
        clock_t start, end;
        double cpu_time_used;
		int det = 0, row, column;
        start = clock(); 
        int DIMENSION = 100;
        float matrix[DIMENSION][DIMENSION];


		// Creates an identity matrix
        int identity[DIMENSION][DIMENSION];
        for(row = 0; row < DIMENSION; row++){
                for(column = 0; column < DIMENSION; column++){
                        if(column == row){
                                identity[row][column] = 1;
                        }else{
                                identity[row][column] = 0;
                        }
                }
        }


		while(det == 0){
			// Creates the new matrix
        	int row, column;
        	srand(time(NULL));
        	for(row = 0; row < DIMENSION; row++){
               	for(column = 0; column < DIMENSION; column++){
                    matrix[row][column] = rand();    
            	}
        	}

			// calculates the determinant
			det = determinant(matrix); 

		}

        
        int i,j,k;
        for(i = 0; i < DIMENSION; i++){
                double pivot = matrix[i][i];
                for(j = 0; j < DIMENSION; j++){
                        matrix[i][j] = matrix[i][j]/pivot;
                        identity[i][j] = identity[i][j]/pivot;
                }    
                for(k = 0; k < DIMENSION; k++){
                        if(k!=i){
                                int factor = matrix[k][i];
                                for(j = 0; j < DIMENSION; j++){
                                        matrix[k][j] = matrix[k][j] - factor * matrix[i][j];
                                        identity[k][j] = identity[k][j] - factor * identity[i][j];
                                }
                        }
                }
		}
		end = clock();
		cpu_time_used = end - start;	
		printf("%f", cpu_time_used);
		return 0;
}

