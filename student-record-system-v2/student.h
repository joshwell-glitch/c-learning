#ifndef STUDENT_H
#define STUDENT_H
#define MAX_STUDENTS 100
#define FILENAME "data/data.bin"
#define SAVED_COUNT "data/saved.bin"
#define SAVED_ID "data/id.bin"
#define MAX_CHAR_COURSE 5

//student structs details.
typedef struct
{
    int id;
    char name[30];
    int age;
    char course[MAX_CHAR_COURSE];
    float gwa;
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
void searchStudent(int studentCount);
void editStudent();
void deleteStudent(int *id, int *studentCount);
void reset(int *id, int *studentCount);
void statistics(int studentCount);

void save(int id, int studentCount);
int load(int *id);

#endif