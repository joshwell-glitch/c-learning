#include <stdio.h>
#include "student.h"
#include <string.h>
#include "utils.h"

Student students[MAX_STUDENTS];

void addStudent(int *id, int *studentCount){
    FILE *stream = fopen(FILENAME, "ab");
    Student newStudent;
    int newId = *id + 1;
    int course;
    const char *courses[] = {"BSCS", "BSIT", "BSCE"};
    while (1)
    {
        line(2);
        printf("ADD STUDENT\n");
        line(2);

        printf("Student ID: %d\n", newId);
        newStudent.id = newId;
        line(1);

        printf("Enter Name: ");
        fgets(newStudent.name, sizeof(newStudent.name), stdin);
        clearStr(newStudent.name);
        line(1);

        printf("Enter Age (15-100): ");
        if (scanf("%d", &newStudent.age) != 1 || newStudent.age < 15 || newStudent.age > 100){
            clearInt();
            invalidInput();
            continue;   
        }
        clearInt();
        line(1);

        printf("Select Course:\n");
        printf("1. BSCS\n2. BSIT\n3. BSCE\n");
        printf("Enter choice: ");
        if (scanf("%d", &course)!= 1 || course < 1 || course > 3){
            clearInt();
            invalidInput();
            continue;
        }
        clearInt();
        switch (course)
        {
        case 1:
            strcpy(newStudent.course, courses[0]);
            break;
        case 2:
            strcpy(newStudent.course, courses[1]);
            break;
        case 3:
            strcpy(newStudent.course, courses[2]);
            break;
        }
        line(1);

        printf("Enter GPA: ");
        if (scanf("%f", &newStudent.gpa)!= 1 || newStudent.gpa < 0 || newStudent.gpa > 100){
            clearInt();
            invalidInput();
            continue;
        }
        clearInt();

        line(1);
        students[*studentCount] = newStudent;
        fwrite(&students[*studentCount], sizeof(Student), 1, stream);
        (*id)++;
        (*studentCount)++;
        save(*studentCount);
        fclose(stream);
        line(1);

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
        printf("[%d] ID: %d | Name: %s | Age: %d | Course: %s | GPA: %.1f\n",
        i + 1, students[i].id, students[i].name, students[i].age, students[i].course, students[i].gpa);
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

void deleteStudent(int *id, int *studentCount){
    if (remove(FILENAME) == 0 && remove(SAVEDCOUNT) == 0){
        clear();
        printf("Student Deleted Successfully!\n");
        (*studentCount) = 0;
        (*id) = 1000;
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
    FILE *stream = fopen(SAVEDCOUNT, "wb");
    int count = (studentCount);

    if (stream == NULL){
        perror("Failed to save file");
    }

    fwrite(&count, sizeof(count), 1, stream);

    printf("Student Saved Successfully!\n");

    fclose(stream);
}
int load(int *id){
    FILE *stream = fopen(SAVEDCOUNT, "rb");
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