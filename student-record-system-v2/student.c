#include <stdio.h>
#include "student.h"
#include "utils.h"

Student students[MAX_STUDENTS];

void addStudent(int *id, int *studentCount){
    int newId = *id + 1;
    while (1)
    {
        line(2);
        printf("ADD STUDENT\n");
        line(2);

        printf("Student ID: %d\n", newId);

        getchar();


        return;
    }
    

}

void viewStudent(){
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