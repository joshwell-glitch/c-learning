#include <stdio.h>
#include "account.h"
#include "file.h"

void save(int accountCount){
    FILE *stream = fopen(SAVED, "wb");
    if (stream == NULL){
        perror("");
        return;
    }
    int count = accountCount;

    fwrite(&count, sizeof(count), 1, stream);
    fclose(stream);
}

int load(){
    FILE *stream = fopen(SAVED, "rb");
    if (stream == NULL){
        perror("");
        return 0;
    }
    int count;

    fread(&count, sizeof(count), 1, stream);
    printf("Accounts Loaded Successfully!\n");
    fclose(stream);
    return count;
}