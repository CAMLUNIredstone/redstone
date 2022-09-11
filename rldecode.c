#include <stdio.h>
#include <stdbool.h>

bool isnumber(char c){
    if(c >= '0' && c <= '9'){
        return true;
    }else{
        return false;
    }
}

int decode(char * str){
    char num[100];
    int count = 0;
    int count_result = 0;
    int tran;
    char result;
    for(int i = 0; str[i] != '\0' ; i++){
        if(isnumber(str[i]) == true){
            num[count] = str[i];
            count ++;
        }else{
            int out = 0;
            if(count>1){
                tran = count;
                for(int j = 0; j != count; j++){
                    int next = num[j] - '0';
                    out = out + next;
                    tran = tran - 1;
                    if(tran>=1){
                        out = out * 10;
                    }
                }
                for(int m = 0; m != out; m++){
                    result = str[i];
                    putchar(result);
                    count_result++;
                }
                count = 0;
            }else{
                int last = str[i-1] - '0';
                for(int n = 0; n != last; n++){
                    putchar(str[i]);
                    count_result++;
                }
                count = 0;
            }
        }
    }
    printf("%s","\n");
    printf("%d\n",count_result);
    return count_result;
}
