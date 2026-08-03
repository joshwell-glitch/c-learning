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

        printf("Enter name: ");
        fgets(newStudent.name, sizeof(newStudent.name), stdin);
        clearStr(newStudent.name);

        students[*studentCount] = newStudent;
        fwrite(students, sizeof(Student), 1, stream);
        (*studentCount)++;

        fclose(stream);
        printf("Student Added Successfully!\n");

        enterToReturn();
        getchar();
        clear();
        return;
    }
}

void viewStudent(int studentCount){
    FILE *stream = fopen(FILENAME, "rb");
    char name[30];

    line(2);
    printf("VIEWING ALL STUDENTS\n");
    line(2);

    while (fread(name, sizeof(name), 1, stream) == 1){
        printf("Name: %s\n", name);
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

void deleteStudent(){
    return;
}

void statistics(){
    return;
}

//SAVE AND LOAD.

void save(){
    return;
}
void load(){
    return;
}