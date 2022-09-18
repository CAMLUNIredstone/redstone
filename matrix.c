#include <stdbool.h>

bool verify_matrix(int x, int y, int **matrix) {
    int tran_y = matrix[0][0];
    int tran_x = matrix[0][0];
    if(x != y){
        return false;
    }
    for(int j = 0; j != y-1; j++){
        for(int k = 0; k != x-1; k++){
            if(matrix[k][j] >= tran_x){
                tran_x = matrix[k][j];
            }else{
                return false;
            }
        }
    }
    for(int i = 0; i != y-1; i++){
        if(matrix[0][i] >= tran_y){
            tran_y = matrix[0][i];
        }else{
            return false;
        }
    }
    return true;
}
