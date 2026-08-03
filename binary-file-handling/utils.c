#include <stdio.h>
#include <string.h>
#include "utils.h"

//clears terminal.
void clear(){
    printf("\e[1H\e[2J");
}

//prints different lines depending on the number.
void line(int num){
    if (num == 0){
        printf("\n");
    }
    else if (num == 1){
        printf("------------------------------\n");
    }
    else if (num == 2){
        printf("==============================\n");
    }
}

//clears integer input buffer.
void clearInt(){
    while(getchar()!='\n');
}

//clears string input buffer.
void clearStr(char string[]){
    size_t len = strlen(string);

    if (len > 0 && string[len - 1] == '\n'){
        string[len -  1] = '\0';
    }
}

//print invalid input.
void invalid(){
    clear();
    perror("Error: Invalid Input!\n");
}