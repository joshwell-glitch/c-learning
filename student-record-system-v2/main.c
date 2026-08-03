#include <stdio.h>
#include "student.h"
#include "help.h"
//coded by: joshwell
//date: Friday, 31 July 2026, 8:37:11 pm

/*this is the better version of student record system,
the version 2 has the memory of the student's info,
i tried to use my basic file handling skills in this project.*/

int main(){
    int choice;
    int studentCount;
    while (1)
    {
        line(2);
        printf("STUDENT RECORD SYSTEM V2\n");
        line(2);
        line(0);
        printf("1. Student Management\n");
        printf("2. Search Records\n");
        printf("3. Academic Reports\n");
        printf("4. Statictics\n");
        printf("5. File Operations\n");
        printf("6. Settings\n");
        printf("0. Exit\n");
        line(0);
        printf("Choice: ");

        if (scanf("%d", &choice)!= 1){
            clearInt();
            invalid();
            continue;
        }

        clearInt();
        clear();
        switch (choice)
        {
        case 1:
            studentManagement();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 0:
            return 0;

        default:
            break;
        }
    }
}