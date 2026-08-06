#include <stdio.h>
#include "account.h"
#include "file.h"

void save(int accountCount, int accountNumber){
    FILE *stream = fopen(SAVED, "wb");
    if (stream == NULL){
        perror("");
        return;
    }
    int count = accountCount;
    int num = accountNumber;

    fwrite(&count, sizeof(count), 1, stream);

    stream = freopen(ID,"wb",stream);

    fwrite(&num, sizeof(num), 1, stream);

    printf("Account Saved Successfully!\n");
    fclose(stream);
    return;
}

int load(int *accountNumber){
    FILE *stream = fopen(SAVED, "rb");
    if (stream == NULL){
        perror("");
        return 0;
    }
    int count;
    int num = (*accountNumber);

    fread(&count, sizeof(count), 1, stream);

    stream = freopen(ID, "rb", stream);

    fread(&num, sizeof(num), 1, stream);

    printf("Accounts Loaded Successfully!\n");
    fclose(stream);
    (*accountNumber) = num;
    return count;
}