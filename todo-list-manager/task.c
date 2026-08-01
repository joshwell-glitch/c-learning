#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"   /*it's must to include this header so the function prototypes are accessible.*/

/*task.c contains all the logic of my functions from task.h*/

void line(int num){
    if (num == 0){
        printf("\n");
    }
    else if(num == 1){
        printf("------------------------------\n");
    }
    else if (num == 2){
        printf("==============================\n");
    }
}

 //clear terminal.
void clear(){
    printf("\e[1H\e[2J");
}
//clear input buffer.
void clearBuffer() {
    while (getchar() != '\n');
}
//clear string input buffer.
void clearStringBuffer(char string[]){
    size_t len = strlen(string);

    if (len > 0 && string[len - 1] == '\n'){
        string[len - 1] = '\0';
    }
}

//FUNCTIONS:

void addTask(Task tasks[], int *count) {
    line(2);
    printf("ADDING TASK\n");
    line(2);

    if (*count >= MAX_TASKS){
        printf("Task limit reached. Cannot add more tasks.\n");
        line(1);
        printf("Enter to return...");
        getchar();
        clear();
        return;
    }

    printf("Add task description: ");
    if (*count < MAX_TASKS){
        fgets(tasks[*count].description, sizeof(tasks[*count].description), stdin);
        clearStringBuffer(tasks[*count].description);
        tasks[*count].isComplete = 'O';
        (*count)++;
        line(0);
        printf("Saving task...\n");
        saveToFile(tasks, *count);
        line(1);
        printf("Enter to return...");
        getchar();
        clear();
        return;
    }
}

void viewTasks(Task tasks[], int count) {
    line(2);
    printf("VIEWING TASKS\n");
    line(2);
    printf("Tasks: %d/%d\n", count, MAX_TASKS);

    if (count == 0){
        printf("No tasks to view.\n");
        line(1);
        printf("Enter to return...");
        getchar();
        clear();
        return;
    }

    for (int i = 0; i < count; i++){
        printf("%d. %s [%c]\n", i+1, tasks[i].description, tasks[i].isComplete);
        line(1);
    }

    printf("Enter to return...");
    getchar();
    clear();
    return;
}

void completeTask(Task tasks[], int count) {
    int input;
    while (1){
        line(2);
        printf("COMPLETING TASK\n");
        line(2);
        printf("Tasks: %d/%d\n",count, MAX_TASKS);

        if (count == 0){
            printf("No tasks to complete.\n");
            line(1);
            printf("Enter to return...");
            getchar();
            clear();
            return;
        }

        for (int i = 0; i < count; i++){
            printf("%d. %s [%c]\n", i+1, tasks[i].description, tasks[i].isComplete);
            line(1);
        }

        printf("Enter task number to complete or [0] to return: ");
        if (scanf("%d", &input)!= 1){
            clearBuffer();
            clear();
            printf("Invalid Input.\n");
            continue;
        }
        if (input == 0){
            clearBuffer();
            clear();
            return;
        }

        if (input < 1 || input > count) {
        clearBuffer();
        clear();
        printf("Invalid task number.\n");
        continue;
        }

        for (int i = 0; i < count; i++){
            if (input == i+1){
                if (tasks[i].isComplete == 'O'){
                    tasks[i].isComplete = 'X';
                }
                else{
                    tasks[i].isComplete = 'O';
                }
                saveToFile(tasks, count);
                clearBuffer();
                clear();
                continue;
            }
        }
    }    
}

void deleteTask(Task tasks[], int *count) {
    int input;
    while (1) {
        line(2);
        printf("DELETE TASK\n");
        line(2);
        printf("Tasks: %d/%d\n", *count, MAX_TASKS);

        if (*count == 0) {
            printf("No tasks to delete.\n");
            line(1);
            printf("Enter to return...");
            getchar();
            clear();
            return;
        }

        for (int i = 0; i < *count; i++) {
            printf("%d. %s [%c]\n", i + 1, tasks[i].description, tasks[i].isComplete);
            line(1);
        }

        printf("Enter task number to delete or [0] to return: ");
        if (scanf("%d", &input) != 1) {
            clearBuffer();
            clear();
            printf("Invalid Input.\n");
            continue;
        }

        if (input == 0) {
            clearBuffer();
            clear();
            return;
        }

        if (input < 1 || input > *count) {
            clearBuffer();
            clear();
            printf("Invalid task number.\n");
            continue;
        }

        int index = input - 1;
        for (int j = index; j < *count - 1; j++) {
            tasks[j] = tasks[j + 1];
        }
        (*count)--;
        saveToFile(tasks, *count);
        clearBuffer();
        clear();
        printf("Task deleted successfully!\n");
    }
}

void saveToFile(Task tasks[], int count) {
    FILE *fp = fopen(FILENAME, "w");

    if (fp == NULL){
        clear();
        fprintf(stderr, "Error: failed to save file!\n");
        return;
    }

    for (int i = 0; i < count; i++){
    fprintf(fp, "%c|%s \n", tasks[i].isComplete, tasks[i].description);
    }


    printf("Task saved successfully!\n");
    fclose(fp);
}

void loadFromFile(Task tasks[], int *count) {
    FILE *fp = fopen(FILENAME, "r");
    char description[MAX_DESC];
    char isComplete;

    if (fp == NULL){
        clear();
        fprintf(stderr, "No saved file!\n");
        return;
    }

    while(*count < MAX_TASKS && fscanf(fp, " %c|%99[^\n]", &isComplete, description) == 2){
        strcpy(tasks[*count].description, description);
        tasks[*count].isComplete = isComplete;
        (*count)++;
    }

    printf("Task load successfully!\n");
    fclose(fp);
}