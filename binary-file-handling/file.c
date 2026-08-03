#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "utils.h"

void addFile(){
    FILE *fp = fopen(FILENAME, "wb");
    char content[100];

    line(2);
    printf("Create file\n");
    line(2);

    if (fp ==   NULL){
        perror("Error: Failed to create file!\n");
        return;
    }

    fgets(content, sizeof(content), stdin);
    clearStr(content);
    fwrite(&content, sizeof(content), 1, fp);
    line(1);
    printf("File created successfully!\n");
    fclose(fp);
    line(1);

    printf("Enter to return...");
    getchar();
    clear();
    return;
}

void readFile(){
    FILE *fp = fopen(FILENAME, "rb");
    char buffer[101];

    line(2);
    printf("File Content\n");
    line(2);

    if (fp == NULL){
        perror("Error: Failed to read file!\n");
        return;
    }

    size_t bytes_read = fread(&buffer, 1, 100, fp);
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);
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
    char current[100];
    
    line(2);
    printf("Append File\n");
    line(2);

    if (fp == NULL){
        perror("Error: Failed to append file!\n");
        return;
    }

    fgets(current, sizeof(current), stdin);
    clearStr(current);
    size_t remaining_space = sizeof(content) - strlen(content) - 1;
    strncat(content, current, remaining_space);
    printf("%s", content);
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
        perror("Error: Failed to remove file!\n");
    }
}