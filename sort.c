#include <stdbool.h>
#include "sort.h"

bool test_sort() {
    int array[] = {1,4,2,0};
    int size = sizeof(array)/sizeof(array[0]);
    int tran = 0;
    cse_sort(array);
    for(int i = 0; i != size-2; i++){
        if(array[i] == 0 || array[size] != 0){
            return false;
        }
        if(array[i] <= tran){
            return false;
        }else{
            tran = array[i];
        }
    }
    return true;
}
