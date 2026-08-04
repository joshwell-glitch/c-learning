#include <stdio.h>
#include "student.h"
#include "utils.h"

Student students[MAX_STUDENTS];

void addStudent(int *id, int *studentCount){
    int newId = *id + 1;
    Student newStudent;
    FILE *stream = fopen(FILENAME, "wb");
    while (1)
    {
        line(2);
        printf("ADD STUDENT\n");
        line(2);

        printf("Student ID: %d\n", newId);
        newStudent.id = newId;

        printf("Enter name: ");
        fgets(newStudent.name, sizeof(newStudent.name), stdin);
        clearStr(newStudent.name);

        students[*studentCount] = newStudent;
        fwrite(&students, sizeof(Student), 1, stream);
        (*id)++;
        (*studentCount)++;
        save(*studentCount);

        fclose(stream);

        enterToReturn();
        getchar();
        clear();
        return;
    }
}

void viewStudent(int studentCount){
    FILE *stream = fopen(FILENAME, "rb");

    line(2);
    printf("VIEWING ALL STUDENTS\n");
    line(2);

    for (int i = 0; i < studentCount; i++){
        fread(&students[i], sizeof(Student), 1, stream);
        printf("[%d] ID: %d | NAME: %s\n", studentCount, students[i].id, students[i].name);
        line(1);
    }


    fclose(stream);

    enterToReturn();
    getchar();
    clear();
    return;
}

void searchStudent(){
    return;
}

void editStudent(){
    return;
}

void deleteStudent(int *studentCount){
    if (remove(FILENAME) == 0 && remove(SAVEDFILE) == 0){
        clear();
        printf("Student Deleted Successfully!\n");
        (*studentCount) = 0;
    } else
    {
        clear();
        perror("Student Delete Failed");
    }
}

void statistics(){
    return;
}

//SAVE AND LOAD.

void save(int studentCount){
    FILE *stream = fopen(SAVEDFILE, "wb");
    int count = (studentCount);

    if (stream == NULL){
        perror("Failed to save file");
    }

    fwrite(&count, sizeof(count), 1, stream);

    printf("Student Saved Successfully!\n");

    fclose(stream);
}
int load(){
    FILE *stream = fopen(SAVEDFILE, "rb");
    int count = 0;
    
    if (stream == NULL){
        perror("Failed to load file");
    }

    fread(&count, sizeof(count), 1, stream);

    clear();
    printf("File Loaded Successfully!\n");

    fclose(stream);
    return count;
}