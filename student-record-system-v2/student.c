#include <stdio.h>
#include "student.h"
#include "help.h"

Student students[MAX_STUDENTS];

//FUNCTION PROTOTYPES:
void addStudent();
void viewStudent();

//student management:
void studentManagement(){
    int choice;
    while(1){
        line(2);
        printf("Student Management\n");
        line(2);

        if (scanf("%d", &choice)!=1){
            clearInt();
            invalid();
            continue;
        }

        clearInt();
        clear();
        switch (choice)
        {
        case 1:
            
            break;
        
        default:
            break;
        }


    }
}

void addStudent(){
    return;
}

void viewStudent(){
    return;
}

void editStudent(){
    return;
}

void deleteStudent(){
    return;
}