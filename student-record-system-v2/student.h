#ifndef STUDENT_H
#define STUDENT_H
#define MAX_STUDENTS 100
#define FILENAME "data.bin"
#define SAVEDFILE "saved.bin"

//student structs details.
typedef struct
{
    int id;
     char name[30];
    int age;
    char course[30];
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

void addStudent(int *id, int *studentCount);
void viewStudent(int studentCount);
void searchStudent();
void editStudent();
void deleteStudent(int *studentCount);
void statistics();

void save(int studentCount);
int load();

#endif