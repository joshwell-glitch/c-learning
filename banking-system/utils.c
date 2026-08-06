#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

//clears terminal(cross platform)
void clear(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
//prints different kind of line (0-2).
void line(int num){
    if (num == 0){
        printf("\n");
    }
    if (num == 1){
        printf("------------------------------\n");
    }
    if (num ==2){
        printf("==============================\n");
    }
}
//use after scanf.
void clearInt(){
    while(getchar() != '\n');
}
//use after fgets.
void clearStr(char str[]){
    size_t len = strlen(str);

    if (len > 0 && str[len - 1] == '\n'){
        str[len - 1] = '\0';
    }
}

void invalidInput(){
    clear();
    fprintf(stderr, "Invalid Input.\n");
}