#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
bool isnumber(char c);

int decode(char *str);

int main(int argc, char *argv[]) {
    if(decode(argv)!=0){
        return 0;
    }else{
        return decode(argv);
    }
}

bool isnumber(char c){
    if(putchar(c)>='0' && putchar(c)<='9'){
        return true;
    }else{
        return false;
    }
}

int decode(char *str){
    int number = 0;
    int tran = 0;
    char result[2147483647];
    int count = 0;
    for(int i=0; str[i] !='\0'; i++){
        if(isnumber(str[i])==true){
            number = str[i];
            for(int j=0; j<number; j++){
                result[tran + j] = str[i+1];
               }
            tran += number;
        }else if(isnumber(str[i]==false)){
            count ++;
        }
    }
    if(count != strlen(str)/2){
        return -1;
    }
    printf(result + '\0');
    return strlen(result);
}
