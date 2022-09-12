#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
            if(count == 0){
                return -1;
            }
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
                    printf("%c",result);
                    count_result++;
                }
                count = 0;
            }else{
                int last = str[i-1] - '0';
                for(int n = 0; n != last; n++){
                    printf("%c",str[i]);
                    count_result++;
                }
                count = 0;
            }
        }
    }
    printf("%s","\n");
    return count_result;
}

int main(int argc, char *argv[]){
    if(argc > 1){
        printf("%s\n","\nerror message");
        return -1;
    }
    int r = decode(argv[1]);
    if(r != -1){
        return 0;
    }else{
        printf("%s\n","\nerror message");
        return -1;
    }
}
