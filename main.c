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
    int out;
    int tran;
    char result[];
    for(int i = 0; str[i] != '\0' ; i++){
        if(isnumber(str[i]) == true){
            num[count] = str[i];
            count ++;
        }else{
            if(count>1){
                tran = count;
                for(int j = 0; j != count; j++){
                    out = out + (num[j] - '0');
                    tran--;
                    if(tran>=1){
                        out = out * 10;
                    }
                }
                char out_1[out];
                for(int n = 0; n != out; n++){
                    out_1[n] = str[i];
                }
                strcat(result,out_1);
                count = 0;
            }else{
                if (count==1){
                    int len = str[i-1] - '0';
                    char out_2[len];
                    for(int m = 0; m != len; m++){
                        out_2[m] = str[i];
                    }
                    strcat(result,out_2);
                }
                count = 0;
            }
        }
    }
    printf("%s\n",result);
}

int main(int argc, char *argv[]) {

    if (decode("11a2b") != 123) {
        fprintf(stderr, "error: \"3a\" did not return the correct integer value.\n");
    }

    /*if (decode("3a6b") != 9) {
        fprintf(stderr, "error: \"3a6b\" did not return the correct integer value.\n");
    }

    if (decode("123*1z10q") != 134) {
        fprintf(stderr, "error: \"123*1z10q\" did not return the correct integer value\n");
    }*/

    return 0;
}
