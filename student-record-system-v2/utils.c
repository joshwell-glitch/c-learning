#include <stdio.h>
#include <string.h>
#include "utils.h"

//"0" for blank, "1" for 1 line, "2" for 2 line.
void line(int num){
    if (num == 0){
        printf("\n");
    }
    else if (num == 1){
        printf("------------------------------\n");
    } else if (num == 2){
        printf("==============================\n");
    }
}

//clears terminal.
void clear(){
    printf("\e[1H\e[2J");
}

//clear integer input buffer.
void clearInt(){
    while (getchar() != '\n');
}

//clear string buffer.
void clearStr(char string[]){
    size_t len = strlen(string);

    if (len > 0 && string[len - 1] == '\n'){
        string[len - 1] = '\n';
    }
}

void invalid(){
    clear();
    fprintf(stderr,"Invalid Input!\n");
}