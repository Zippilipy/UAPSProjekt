#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {

        clock_t start, end;
        double cpu_time_used;

        start = clock(); 

        int DIMENSION = 100;

        // Creates the new matrix
        double matrix[DIMENSION][DIMENSION];
        int row, column;
        srand(time(NULL));
        for(row = 0; row < DIMENSION; row++){
                for(column = 0; column < DIMENSION; column++){
                        matrix[row][column] = rand();    
                }
        }
    
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

        // Inverts the matrix
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
		return 0;
}


