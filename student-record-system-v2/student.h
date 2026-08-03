#ifndef STUDENT_H
#define STUDENT_H
#define MAX_STUDENTS 100
#define FILENAME "data.bin"

//student structs details.
typedef struct
{
    int id;
    char firstName[20];
    char lastName[20];
    int age;
    char gender;
    char course[10];
    char level[10];
    char section[10];
    char email[20];
    int phoneNumber;
    float gpa;

}Student;

/*this is where i store my students.
notice that i used "extern". it means that,
this variable struct exists somewhere(in this case, it is in student.c).
it avoids creating this variable multiple times
when i declared "student.h" in main, if i don't do this, the compiler won't
work.*/

extern Student students[MAX_STUDENTS];

//FUNCTIONS:

void studentManagement();


#endif