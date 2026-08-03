#include <stdio.h>
#include "student.h"
#include "utils.h"
//coded by: joshwell
//date: Friday, 31 July 2026, 8:37:11 pm

/*this is the better version of student record system,
the version 2 has the memory of the student's info,
i tried to use my basic file handling skills in this project.*/

int main(){
    int choice;
    int studentCount = 0;
    int id = 1000;
    while (1)
    {
        line(2);
        printf("STUDENT RECORD SYSTEM V2\n");
        line(2);
        printf("Total number of students: %d/%d\n", studentCount, MAX_STUDENTS);
        line(0);
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Edit Student\n");
        printf("5. Delete Student\n");
        printf("6. Statistics\n");
        printf("0. Exit\n");
        line(0);
        printf("Choice: ");

        if (scanf("%d", &choice)!= 1){
            clearInt();
            invalidInput();
            continue;
        }

        clearInt();
        clear();
        switch (choice)
        {
        case 1:
            addStudent(&id, &studentCount);
            break;
        case 2:
            viewStudent(studentCount);
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            editStudent();;
            break;
        case 5:
        deleteStudent();
            break;
        case 6:
            statistics();
            break;
        case 0:
            return 0;
        }
    }
}