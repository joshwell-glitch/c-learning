#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//created by: joshwell
//date: Sunday, 12 July 2026, 9:49:36 pm

//STRUCTS:

//main info of students.
typedef struct
{
    int id;
    char name[30];
    int age;
    char course[30];
    float grade;
}Student;

//this is where i store the students info.
Student students[100];

//FUNCTIONS:

//clears input buffer.
void clearBuffer(){
    while(getchar()!='\n');
}

void clearStringBuffer(char test[]){
    size_t len = strlen(test);

    if (len > 0 && test[len - 1] == '\n'){
        test[len - 1] = '\0';
    }
}

//prints lines and blanks.
void line(int num){
    if (num == 1){printf("------------------------------\n");}
    else if (num == 2){printf("==============================\n");}
    else {printf("\n");}
}

//clears the screen terminal
void clear(){
    printf("\e[1H\e[2J");
}

void pressEnter(){
    printf("Press Enter to return...\n");
}


//FUNCTION DECLARATION:

void addStudent(int *studentCount, int *id);
void viewStudent(int studentCount);
void searchStudent(int studentCount);
void editStudent(int studentCount);
void deleteStudent(int *studentCount);
void statistics(int studentCount);

//MAIN:
int main(void){
    int choice;
    int studentCount = 0;
    int id = 1000;
    while (1)
    {
        line(2);
        printf("STUDENT RECORD SYSTEM\n");
        line(2);
        printf("Total Students: %d/100\n", studentCount);
        line(0);
        printf("[1] Add Student\n");
        printf("[2] View Student\n");
        printf("[3] Search Student\n");
        printf("[4] Edit Student\n");
        printf("[5] Delete Student\n");
        printf("[6] Statistics\n");
        printf("[0] Exit\n");
        printf("\nSelect Choice: ");
        if (scanf("%d", &choice)!= 1){
            clear();
            printf("Error: Invalid Input!\n");
            clearBuffer();
            continue;
        }
        line(0);
        clear();
        clearBuffer();

        switch (choice)
        {
        case 1:
            addStudent(&studentCount, &id);
            break;

        case 2:
            viewStudent(studentCount);
            break;

        case 3:
            searchStudent(studentCount);
            break;

        case 4:
            editStudent(studentCount);
            break;

        case 5:
            deleteStudent(&studentCount);
            break;

        case 6:
            statistics(studentCount);
            break;

        case 0:
            return 0;

        default:
            printf("Error: Invalid Input!\n");
            continue;
        }
    }
}

//ADD STUDENT:
void addStudent(int *studentCount, int *id){
    char input;
    Student newStudent;
    while (1)
    {
        line(2);
        printf("ADD STUDENT\n");
        line(2);
        
        newStudent.age = 0;
        newStudent.grade = 0.0f;

        if (*studentCount == 100){
            printf("Maximum number of students reached!\n");
            pressEnter();
            getchar();
            clear();
            return;
        }

        int newID = 0;
        newID = *id + 1;
        printf("ID: %d\n", newID);
        line(1);

        printf("Enter Name: ");
        fgets(newStudent.name, sizeof(newStudent.name), stdin);
        clearStringBuffer(newStudent.name);
        line(1);

        printf("Enter Age: ");
        if (scanf("%d", &newStudent.age)!=1){
            clear();
            printf("Error: Invalid Input!\n");
            clearBuffer();
            continue;
        }
        clearBuffer();
        line(1);
        if (newStudent.age > 150 || newStudent.age <= 0){
            clear();
            printf("Age must be around 1-150!\n");
            continue;
        }

        printf("Enter Course: ");
        fgets(newStudent.course, sizeof(newStudent.course), stdin);
        clearStringBuffer(newStudent.course);
        line(1);

        printf("Enter Grade: ");
        if (scanf("%f", &newStudent.grade)!= 1){
            clear();
            printf("Error: Invalid Input!\n");
            clearBuffer();
            continue;
        }
        clearBuffer();
        line(1);
        if (newStudent.grade > 100 || newStudent.grade < 0){
            clear();
            printf("Grade must be around 0-100!\n");
            continue;
        }

        *id+=1;
        newStudent.id = *id;
        students[*studentCount] = newStudent;
        *studentCount+=1;

        clear();
        line(1);
        printf("Student Added Successfully!\n");
        line(1);
        printf("Press and Enter [Y] to add another student...\n");
        pressEnter();
        input = '\0';

        scanf("%c", &input);
        if (input == 'Y' || input == 'y'){
            clearBuffer();
            line(0);
            clear();
            continue;
        }
        else{
            line(0);
            clear();
            return;
        }
    }
}

//VIEW STUDENTS:
void viewStudent(int studentCount){
    line(2);
    printf("VIEWING STUDENTS\n");
    line(2);

    if (studentCount == 0){
        printf("There are no students yet!\n");
        }

    for (int i = 0; i < studentCount; i++){
    printf("ID: %d\n", students[i].id);
    printf("Name: %s\n", students[i].name);
    printf("Age: %d\n", students[i].age);
    printf("Course: %s\n", students[i].course);
    printf("Grade: %.2f\n", students[i].grade);
    line(1);
    }
    pressEnter();
    getchar();
    line(0);
    clear();
    return;
}

//SEARCH STUDENT:
void searchStudent(int studentCount){
    int input;
    while (1)
    {
        line(2);
        printf("SEARCH STUDENT\n");
        line(2);

        if (studentCount == 0){
        printf("There are no students yet!\n");
        pressEnter();
        getchar();
        line(0);
        clear();
        return;
        }

        printf("Enter [0] to return.\n");

        printf("Student ID: ");
        if (scanf("%d", &input)!= 1){
            clear();
            printf("Error: Invalid Input!\n");
            clearBuffer();
            continue;
        }
        clearBuffer();
        line(0);

        if (input == 0){
            clear();
            return;
        }

        if (input < 1000){
            clear();
            printf("ID starts at 1000!\n");
            continue;
        }

        for (int i = 0; i < studentCount; i++){
            if(input == students[i].id){
                clear();
                line(2);
                printf("Student Found!\n");
                line(2);

                printf("ID: %d\n", students[i].id);
                printf("Name: %s\n", students[i].name);
                printf("Age: %d\n", students[i].age);
                printf("Course: %s\n", students[i].course);
                printf("Grade: %.2f\n", students[i].grade);
                line(1);

                pressEnter();
                getchar();
                line(0);
                clear();
                return;
            }
        }   

        clear();
        printf("Student Not Found!\n");
        continue;
    }
}

//EDIT STUDENT:
void editStudent(int studentCount){
    int input;
    Student newStudent;
    while (1)
    {
        line(2);
        printf("EDIT STUDENT\n");
        line(2);

        if (studentCount == 0){
        printf("There are no students yet!\n");
        pressEnter();
        getchar();
        line(0);
        clear();
        return;
        }

        printf("Enter [0] to return.\n");

        printf("Student ID: ");
        if (scanf("%d", &input)!= 1){
            clear();
            printf("Error: Invalid Input!\n");
            clearBuffer();
            continue;
        }
        clearBuffer();
        line(0);

        if (input == 0){
            clear();
            return;
        }

        if (input < 1000){
            clear();
            printf("ID starts at 1000!\n");
            continue;
        }

        for (int i = 0; i < studentCount; i++){
            if(input == students[i].id){
                clear();
                line(2);
                printf("OLD INFO\n");
                line(2);

                printf("ID: %d\n", students[i].id);
                printf("Name: %s\n", students[i].name);
                printf("Age: %d\n", students[i].age);
                printf("Course: %s\n", students[i].course);
                printf("Grade: %.2f\n", students[i].grade);

                line(2);
                printf("EDIT STUDENT\n");
                line(2);
                printf("Enter new name: ");
                fgets(newStudent.name, sizeof(newStudent.name), stdin);
                clearStringBuffer(newStudent.name);
                line(1);

                printf("Enter new age: ");
                if (scanf("%d", &newStudent.age)!=1){
                    clear();
                    printf("Error: Invalid Input!\n");
                    clearBuffer();
                    continue;
                }
                clearBuffer();
                line(1);
                if (newStudent.age > 150 || newStudent.age <= 0){
                clear();
                printf("Age must be around 1-150!\n");
                continue;
                }

                printf("Enter new course: ");
                fgets(newStudent.course, sizeof(newStudent.course), stdin);
                clearStringBuffer(newStudent.course);
                line(1);

                printf("Enter new grade: ");
                if (scanf("%f", &newStudent.grade)!=1){
                    clear();
                    printf("Error: Invalid Input!\n");
                    clearBuffer();
                    continue;
                }
                clearBuffer();
                line(1);
                if (newStudent.grade > 100 || newStudent.grade < 0){
                clear();
                printf("Grade must be around 0-100!\n");
                continue;
                }

                clear();
                line(2);
                printf("NEW INFO\n");
                line(2);
                students[i] = newStudent;
                printf("ID: %d\n", students[i].id);
                printf("Name: %s\n", students[i].name);
                printf("Age: %d\n", students[i].age);
                printf("Course: %s\n", students[i].course);
                printf("Grade: %.2f\n", students[i].grade);
                line(1);

                printf("Student Edited Successfully!\n");
                pressEnter();
                getchar();
                line(0);
                clear();
                return;

            }
            else{
                clear();
                printf("Student Not Found!\n");
                continue;
            }
        }
    }
}

//DELETE STUDENT:
void deleteStudent(int *studentCount){
    int input;
    char choice;
    while (1)
    {
        line(2);
        printf("DELETE STUDENT\n");
        line(2);

        if (*studentCount == 0){
        printf("There are no students yet!\n");
        pressEnter();
        getchar();
        line(0);
        clear();
        return;
        }

        printf("Enter [0] to return.\n");

        printf("Student ID: ");
        if (scanf("%d", &input)!= 1){
            clear();
            printf("Error: Invalid Input!\n");
            clearBuffer();
            continue;
        }
        clearBuffer();
        line(0);

        if (input == 0){
            clear();
            return;
        }

        if (input < 1000){
            clear();
            printf("ID starts at 1000!\n");
            continue;
        }

        for (int i = 0; i < *studentCount; i++){
            if(input == students[i].id){
                clear();
                line(2);
                printf("Are you sure to delete this student?\n");
                line(2);

                printf("ID: %d\n", students[i].id);
                printf("Name: %s\n", students[i].name);
                printf("Age: %d\n", students[i].age);
                printf("Course: %s\n", students[i].course);
                printf("Grade: %.2f\n", students[i].grade);
                line(1);

                printf("Press and Enter [Y] to confirm.\n");
                pressEnter();
                scanf("%c", &choice);
                if (choice == 'Y' || choice == 'y'){
                    clearBuffer();
                    line(0);
                    clear();
                    for (; i < *studentCount - 1; i++){
                        
                        students[i] = students[i+1];
                    }
                    *studentCount -= 1;
                    printf("Student Deleted Successfully!\n");
                    line(1);
                    pressEnter();
                    getchar();
                    line(0);
                    clear();
                    return;
                }
                else{
                    line(0);
                    clear();
                    return;
                }
            }
        }
        clear();
        printf("Student Not Found!\n");
        continue;
    }
}

//STATISTICS:
void statistics(int studentCount){

    float avgGrade = 0.0f;
    float gTotal = 0.0f;
    float avgAge = 0.0f;
    float aTotal = 0.0f;
    int passed = 0;
    int failed = 0;

    line(2);
    printf("STATISTICS\n");
    line(2);
    if (studentCount == 0){
    printf("There are no students yet!\n");
    pressEnter();
    getchar();
    line(0);
    clear();
    return;
    }

    printf("Total Students: %d\n", studentCount);

    line(0);

    float highest = students[0].grade;
    float lowest = students[0].grade;
    for (int i = 0; i < studentCount; i++){
        //computation of average grade.
        gTotal += students[i].grade;

        //computation of average age.
        aTotal += students[i].age;

        //computation of passed and failed studends.
        if (students[i].grade >= 75){
            passed++;
        }
        else
        {
            failed ++;
        }

        //checks low or high.
        if (highest < students[i].grade){
            highest = students[i].grade;
        }
        if (lowest > students[i].grade){
            lowest = students[i].grade;
        }
    }

    printf("Highest Grade: %.2f\n", highest);
    printf("Lowest Grade: %.2f\n", lowest);

    line(0);

    avgGrade = gTotal / studentCount;
    printf("Average Grade: %.2f\n", avgGrade);

    avgAge = aTotal / studentCount;
    printf("Average Age: %.1f\n", avgAge);

    line(0);

    printf("Passed Student: %d\n", passed);
    printf("Failed Students: %d\n", failed);

    line(1);


    pressEnter();
    getchar();
    clear();
    return;
}
