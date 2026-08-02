#include <stdio.h>
#include "student.h"
#include "help.h"
//coded by: joshwell
//date: Friday, 31 July 2026, 8:37:11 pm

/*this is the better version of student record system,
the version 2 has the memory of the student's info,
i tried to use my basic file handling skills in this project.*/

int main(){
    int input;
    while (1)
    {
        line(2);
        printf("STUDENT RECORD SYSTEM V2\n");
        line(2);

        if (scanf("%d", &input)!= 1){
            clearInt();
            clear();
            printf("Invalid Input!\n");
            continue;
        }

        clearInt();
        clear();
        switch (input)
        {
        case 1:
            addStudent();
            break;
        
        default:
            break;
        }
    }
}