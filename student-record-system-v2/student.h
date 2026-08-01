#ifndef STUDENT_H
#define STUDENT_H

//student structs details.
typedef struct
{
    int id;
    char name[50];
    int age;
    char course[10];
    float grade;
}Student;

//this is where i store my students.
Student students[100];


#endif