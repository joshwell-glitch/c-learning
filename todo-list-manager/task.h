#ifndef TASK_H /*#ifndef stands for "if not defined."*/
#define TASK_H /*defines*/

/*task.h is where the structs and function prototypes are contained,
this is where i declared the data types i am using to make the task manager work.*/

#define FILENAME  "data.dat"
#define MAX_TASKS 100
#define MAX_DESC  100

typedef struct {
    char description[MAX_DESC];
    char isComplete;
} Task;

/* function prototypes — implemented in task.c */
void line(int num);
void clear();
void clearBuffer();
void clearStringBuffer(char string[]);
void addTask(Task tasks[], int *count);
void viewTasks(Task tasks[], int count);
void completeTask(Task tasks[], int count);
void deleteTask(Task tasks[], int *count);
void saveToFile(Task tasks[], int count);
void loadFromFile(Task tasks[], int *count);


#endif
/*#endif is a preprocessor directive that marks the end of a 
conditional compilation block opened by #if, #ifdef, or #ifndef. */