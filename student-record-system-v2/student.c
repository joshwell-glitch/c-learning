#include <stdio.h>
#include "student.h"
#include <string.h>
#include <ctype.h>
#include "utils.h"

Student students[MAX_STUDENTS];

void addStudent(int *id, int *studentCount){
    FILE *stream = fopen(FILENAME, "ab");
    if (stream == NULL){
        perror("");
        return;
    }

    Student newStudent;
    int newId = *id + 1;
    int course;
    const char courses[3][MAX_CHAR_COURSE] = {"BSCS", "BSIT", "BSCE"};
    while (1)
    {
        line(2);
        printf("ADD STUDENT\n");
        line(2);

        printf("Student ID: %d\n", newId);
        newStudent.id = newId;
        line(1);

        printf("Enter Name: ");
        fgets(newStudent.name, sizeof(newStudent.name), stdin);
        clearStr(newStudent.name);
        line(1);

        printf("Enter Age (15 - 100): ");
        if (scanf("%d", &newStudent.age) != 1 || newStudent.age < 15 || newStudent.age > 100){
            clearInt();
            invalidInput();
            continue;   
        }
        clearInt();
        line(1);

        printf("Select Course:\n");
        printf("1. BSCS\n2. BSIT\n3. BSCE\n");
        printf("Enter choice: ");
        if (scanf("%d", &course)!= 1 || course < 1 || course > 3){
            clearInt();
            invalidInput();
            continue;
        }
        clearInt();
        switch (course)
        {
        case 1:
            strcpy(newStudent.course, courses[0]);
            break;
        case 2:
            strcpy(newStudent.course, courses[1]);
            break;
        case 3:
            strcpy(newStudent.course, courses[2]);
            break;
        }
        line(1);

        printf("Enter GWA (1.00 - 5.00): ");
        if (scanf("%f", &newStudent.gwa)!= 1 || newStudent.gwa < 1 || newStudent.gwa > 5.0){
            clearInt();
            invalidInput();
            continue;
        }
        clearInt();

        students[*studentCount] = newStudent;
        fwrite(&students[*studentCount], sizeof(students[*studentCount]), 1, stream);
        (*id)++;
        (*studentCount)++;
        save(*id, *studentCount);
        fclose(stream);

        line(1);
        enterToReturn();
        getchar();
        clear();
        return;
    }
}

void viewStudent(int studentCount){
    FILE *stream = fopen(FILENAME, "rb");
    if (stream == NULL){
        perror("");
        return;
    }

    line(2);
    printf("VIEWING ALL STUDENTS\n");
    line(2);
    printf("Total number of students: %d/%d\n", studentCount, MAX_STUDENTS);
    line(1);

    for (int i = 0; i < studentCount; i++){
        fread(&students[i], sizeof(students[i]), 1, stream);
        printf("[%d.] ID: %d | Name: %s | Age: %d | Course: %s | GWA: %.2f\n",
        i + 1, students[i].id, students[i].name, students[i].age, students[i].course, students[i].gwa);
        line(1);
    }

    fclose(stream);

    enterToReturn();
    getchar();
    clear();
    return;
}

void searchStudent(int studentCount){
    FILE *stream;
    int input;
    while (1)
    {
        stream = fopen(FILENAME, "rb");
        if (stream == NULL){
        perror("");
        return;
        }
        line(2);
        printf("SEARCH STUDENT\n");
        line(2);
        printf("[0] Return\n");
        line(1);
        printf("Enter Student ID: ");
        if (scanf("%d", &input) != 1){
            clearInt();
            clear();
            invalidInput();
            continue;
        }
        clearInt();
        if (input == 0){
            clear();
            fclose(stream);
            return;
        if (input < 1000){
            clear();
            printf("ID starts at 1000!\n");
            continue;
        }
        line(1);
        }
        for (int i = 0; i < studentCount; i++){
            fread(&students[i], sizeof(students[i]), 1, stream);
            if (input == students[i].id){
                clear();
                line(2);
                printf("SEARCH STUDENT\n");
                line(2);

                printf("Student Found!\n");
                line(1);
                printf("[%d.] ID: %d | Name: %s | Age: %d | Course: %s | GWA: %.2f\n"
                ,  i + 1, students[i].id, students[i].name, students[i].age, students[i].course, students[i].gwa);
                line(1);
                enterToReturn();
                getchar();
                fclose(stream);
                clear();
                return;
           }
        }
        clear();
        printf("Student Not Found!\n");
        fclose(stream);
    }
}

void editStudent(){
    return;
}

void deleteStudent(int id, int *studentCount){
    FILE *stream;
    int input;
    char choice;
    while (1)
    {
        stream = fopen(FILENAME, "rb");
        if (stream == NULL){
        perror("");
        return;
        }
        line(2);
        printf("DELETE STUDENT\n");
        line(2);
        printf("[0] Return\n");
        line(1);
        printf("Enter Student ID: ");
        if (scanf("%d", &input) != 1){
            clearInt();
            clear();
            invalidInput();
            fclose(stream);
            continue;
        }
        clearInt();
        if (input == 0){
            clear();
            fclose(stream);
            return;
        if (input < 1000){
            clear();
            printf("ID starts at 1000!\n");
            continue;
        }
        line(1);
        }
        for (int i = 0; i < *studentCount; i++){
            fread(&students[i], sizeof(students[i]), 1, stream);
            if (input == students[i].id){
                clear();
                line(2);
                printf("DELETE STUDENT\n");
                line(2);

                printf("Student Found!\n");
                line(1);
                printf("[%d.] ID: %d | Name: %s | Age: %d | Course: %s | GWA: %.2f\n"
                ,  i + 1, students[i].id, students[i].name, students[i].age, students[i].course, students[i].gwa);
                line(1);
                printf("Are you sure to delete this student?\n");
                printf("[Y/N]\n");
                line(0);
                printf("Enter Choice: ");
                if (scanf("%c", &choice)!= 1){
                    clearInt();
                    clear();
                    invalidInput();
                    fclose(stream);
                    continue;
                }
                choice = toupper(choice);
                clearInt();
                clear();
                switch (choice)
                {
                case 'Y':
                    if (stream == NULL){
                        clear();
                        perror("");
                        return;
                    }
                    for (i; i < *studentCount - 1; i++){
                        students[i] = students[i+1];
                    }
                    (*studentCount)--;
                    stream = freopen(FILENAME, "wb", stream);
                    for (int f = 0; f < *studentCount; f++){
                        fwrite(&students[f], sizeof(students[f]), 1, stream);
                    }
                    save(id, *studentCount);
                    fclose(stream);
                    printf("Student Deleted Successfully!\n");
                    line(1);
                    enterToReturn();
                    getchar();
                    clear();
                    return;

                case 'N':
                    fclose(stream);
                    return;
                }
           }
        }
        clear();
        printf("Student Not Found!\n");
        fclose(stream);
    }
}

void statistics(int studentCount){
    FILE *stream = fopen(FILENAME, "rb");
    if (stream == NULL){
        perror("");
        return;
    }

    int passed = 0;
    int conditional = 0;
    int failed = 0;
    float averageGWA = 0.0f;
    float averageAge = 0.0f;
    float totalGWA = 0.0f;
    float totalAge = 0.0f;
    float highest = 0.0f;
    float lowest = 0.0f;

    highest = students[0].gwa;
    lowest = students[0].gwa;
    for (int i = 0; i < studentCount; i++){
        fread(&students[i], sizeof(students[i]), 1, stream);
        if (students[i].gwa == 5){
            failed++;
        }
        else if (students[i].gwa == 4){
            conditional++;
        }
        else{
            passed++;
        }
        
        if (highest > students[i].gwa){
            highest = students[i].gwa;
        }
        if (lowest < students[i].gwa){
            lowest = students[i].gwa;
        }

        totalAge += students[i].age;
        totalGWA +=students[i].gwa;
    }

    averageAge = totalAge / studentCount;
    averageGWA = totalGWA / studentCount;

    line(2);
    printf("STATISTICS\n");
    line(2);

    printf("Total number of students: %d/%d\n", studentCount, MAX_STUDENTS);
    line(1);

    printf("Highest GWA: %.2f\n", highest);
    printf("Lowest GWA: %.2f\n", lowest);
    line(0);
    printf("Average GWA: %.2f\n", averageGWA);
    printf("Average Age: %.2f\n", averageAge);
    line(0);
    printf("Passed Students: %d\n", passed);
    printf("Conditional Students: %d\n", conditional);
    printf("Failed Students: %d\n", failed);

    fclose(stream);
    line(1);
    enterToReturn();
    getchar();
    clear();
    return;
}

void reset(int *id, int *studentCount){
    FILE *stream = fopen(FILENAME, "rb");
    if (stream == NULL){
        perror("");
        return;
    }
    fclose(stream);
    char choice;
    while(1){
        line(2);
        printf("RESET RECORDS\n");
        line(2);
        printf("Are you sure to reset the records?\n");
        printf("[Y/N]\n");
        line(0);
        printf("Enter Choice: ");
        if (scanf("%c", &choice) != 1){
            clearInt();
            invalidInput();
        }
        choice = toupper(choice);
        clearInt();
        clear();
        switch (choice)
        {
        case 'Y':
            if (remove(FILENAME) == 0 && remove(SAVED_ID) == 0 && remove(SAVED_COUNT) == 0){
                (*studentCount) = 0;
                (*id) = 1000;
                printf("File Reset Successfully!\n");
            }
            else
            {
                perror("");
            }
            return;
        case 'N':
            return;

        default:
            printf("Choose[Y/N]\n");
            break;
        }
    }
}

//SAVE AND LOAD.

void save(int id, int studentCount){
    FILE *stream = fopen(SAVED_COUNT, "wb");
    int count = (studentCount);

    if (stream == NULL){
        perror("Failed to save file");
        return;
    }

    fwrite(&count, sizeof(count), 1, stream);
    fclose(stream);

//-----------------------------------------
    stream = fopen(SAVED_ID, "wb");
    int saveId = (id);
    if (stream == NULL){
        perror("Failed to save file");
        return;
    }
    fwrite(&saveId, sizeof(saveId), 1,stream);
    fclose(stream);
}

int load(int *id){
    FILE *stream = fopen(SAVED_COUNT, "rb");
    int count = 0;
    
    if (stream == NULL){
        perror("Failed to load file");
        return 0;;
    }

    fread(&count, sizeof(count), 1, stream);
    clear();
    fclose(stream);
//----------------------------------------
    stream = fopen(SAVED_ID, "rb");
    int newId = 1000;

    if (stream == NULL){
        perror("Failed to load file");
        return 0;
    }

    fread(&newId, sizeof(int), 1, stream);
    (*id) = newId;

    clear();
    fclose(stream);
    printf("File Loaded Successfully!\n");
    return count;
}