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
    studentCount = load(&id);
    while (1)
    {

        line(2);
        printf("STUDENT RECORD SYSTEM V2\n");
        line(2);
        printf("Total number of students: %d/%d\n", studentCount, MAX_STUDENTS);
        line(1);
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Edit Student\n");
        printf("5. Delete Student\n");
        printf("6. Statistics\n");
        printf("7. Reset Records\n");
        printf("8. Exit\n");
        line(0);
        printf("Choice: ");

        if (scanf("%d", &choice)!= 1 || choice < 1 || choice > 8){
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
            searchStudent(studentCount);
            break;
        case 4:
            editStudent(id, studentCount);
            break;
        case 5:
            deleteStudent(id, &studentCount);
            break;
        case 6:
            statistics(studentCount);
            break;
        case 7:
            reset(&id, &studentCount);
            break;
        case 8:
            return 0;
        }
    }
}