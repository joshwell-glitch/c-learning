#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "utils.h"

void addFile(){
    FILE *fp = fopen(FILENAME, "wb");
    char content[100];

    if (fp ==   NULL){
        perror("Failed to create file");
        return;
    }

    line(2);
    printf("Create file\n");
    line(2);
    printf("Enter text to create a file:\n");

    fgets(content, sizeof(content), stdin);
    clearStr(content);
    fwrite(&content, sizeof(content), 1, fp);
    fclose(fp);

    line(1);
    printf("File created successfully!\n");
    line(1);

    printf("Enter to return...");
    getchar();
    clear();
    return;
}

void readFile(){
    FILE *fp = fopen(FILENAME, "rb");
    char buffer[100];

    if (fp == NULL){
        perror("Failed to read file");
        return;
    }

    line(2);
    printf("File Content\n");
    line(2);

    while (fread(buffer, sizeof(buffer), 1, fp) == 1){
        printf("%s\n", buffer);
    }
    fclose(fp);

    line(1);
    printf("File read successfully!\n");
    line(1);

    printf("Enter to return...");
    getchar();
    clear();
    return;
}

void appendFile(){
    FILE *fp = fopen(FILENAME, "ab");
    char content[100];
    
    if (fp == NULL){
        perror("Failed to append file");
        return;
    }

    line(2);
    printf("Append File\n");
    line(2);
    printf("Enter text to append:\n");

    fgets(content, sizeof(content), stdin);
    clearStr(content);
    fwrite(content, sizeof(content), 1, fp);
    fclose(fp);

    line(1);
    printf("File appended successfully\n");
    line(1);

    printf("Enter to return...");
    getchar();
    clear();
    return;
}

void deleteFile(){
    clear();
    if (remove(FILENAME) == 0){
        printf("File deleted successfully!\n");
    }
    else
    {
        perror("Failed to remove file");
    }
}