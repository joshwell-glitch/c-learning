#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"   /* gives access to functions in task.h*/
//coded by: joshwell
//date: Saturday, 1 August 2026, 11:23:47 am

/*the main.c will be the main part of the program,
it contains functions from task.h*/

int main() {
    Task tasks[MAX_TASKS];
    int  taskCount = 0;
    int  choice;

    loadFromFile(tasks, &taskCount); /* load saved tasks on startup */

    while (1) {
        line(2);
        printf("TO-DO LIST MANAGER\n");
        line(2);
        printf("Tasks: %d/%d\n", taskCount, MAX_TASKS);
        printf("1. Add task\n");
        printf("2. View tasks\n");
        printf("3. Complete task\n");
        printf("4. Delete task\n");
        printf("0. Exit\n");
        line(1);
        printf("Enter Choice: ");

        if (scanf("%d", &choice) != 1) {
            clearBuffer();
            clear();
            printf("Invalid input.\n");
            continue;
        }
        clear();
        clearBuffer();
        switch (choice) {
            case 1: addTask(tasks, &taskCount);      break;
            case 2: viewTasks(tasks, taskCount);      break;
            case 3: completeTask(tasks, taskCount);   break;
            case 4: deleteTask(tasks, &taskCount);    break;
            case 0:
                printf("Goodbye!\n");
                exit(0);
            default:
                clear();
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
