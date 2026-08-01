#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//created by: joshwell
//date: Monday, 20 July 2026, 11:15:17 pm

//FUNCTIONS:

/*choosing difficulty function.
i practiced using pointers here.*/
int diff(int *korek, int *frst, int *scnd, char *level);
//main game.
int game(int korek, int frst, int scnd, char *level, int *wins, int *attempts);
//clears input buffer.
void clearBuffer();
//prints invalid input.
void invalid();

//clear terminal.
void clear(){
    printf("\e[1H\e[2J");
}

void line(int num){
    if (num == 0){
        printf("\n");
    }
    else if (num == 1){
        printf("------------------------------\n");
    }
    else if (num == 2){
        printf("==============================\n");
    }
}

//main menu
int main(void)
{

    int input;
    int frst;
    int scnd;
    char level[50];
    int wins = 0;
    int korek = 0;
    int attempts = 0;

    //random seed generator.
    srand(time(NULL));

    while (true)
    {
        //title
        line(2);
        printf("NUMBER GUESSING GAME\n");
        line(2);
        printf("Rules: Guess the correct number from a random number range.\n");
        line(0);
        printf("Number of Games: %d\n", wins);
        printf("Number of Attempts: %d\n", attempts);
        line(0);
        printf("[1]Play\n[0]Exit\n");
        line(0);
        printf("Enter Choice: ");
        
        scanf("%d", &input);
        clearBuffer();
        clear();

        switch (input)
        {

        case 1://i made pointers, the "&" means it is pointing to the address of the variable.
            diff(&korek, &frst, &scnd, level);
            if (korek != 0){
                game(korek, frst, scnd, level, &wins, &attempts);
                korek = 0;
            }
            break;

        case 0:
            exit(0);
        
        default:
            invalid();
            break;
            
        }

    }

}
//choose difficulty//
int diff(int *korek, int *frst, int *scnd, char *level)
{

    int input;

    while (true)
    {
        line(2);
        printf("SELECT DIFFICULTY\n");
        line(2);
        printf("[1] Easy(1-10)\n[2] Medium(1-50)\n[3] Hard(1-100)\n[4] Extreme(1-1000)\n");

        line(0);
        printf("[0] Exit\n");
        line(0);

        printf("Enter Choice: ");
        //checks if input is not an integer.
        if (scanf("%d", &input)!= 1)
        {
            clearBuffer();
            clear();
            invalid();
            continue;
        }
        clearBuffer();
        clear();

        switch (input)
        {
            case 0:
                return 0;

            case 1:
                *korek = rand() % 10 + 1;
                strcpy(level, "EASY");
                *frst = 1;
                *scnd = 10;
                return 0;

            case 2:
                *korek = rand() % 50 + 1;
                strcpy(level, "MEDIUM");
                *frst = 1;
                *scnd = 50;
                return 0;

            case 3:
                *korek = rand() % 100 + 1;
                strcpy(level, "HARD");
                *frst = 1;
                *scnd = 100;
                return 0;

            case 4:
                *korek = rand() % 1000 + 1;
                strcpy(level, "EXTREME");
                *frst = 1;
                *scnd = 1000;
                return 0;

            default:
                invalid();
                break;
        }
    }
}

//gameplay//
int game(int korek, int frst, int scnd, char level[], int *wins, int *attempts)
{
    int guess;
    int numAttempts = 0;
     while (true)
     {
        line(2);
        printf("%s DIFFICULTY\n", level);
        line(2);
        printf("Guess the number from %d-%d.\n", frst, scnd);
        printf("Attempts: %d\n", numAttempts);
        line(1);
        printf("Enter Number: ");

        if (scanf("%d", &guess) != 1)
        {
        clear();
        invalid();
        clearBuffer();
        continue;
        }
        if (guess < frst)
        {
            numAttempts += 1;
            clear();
            printf("Guess must be within %d-%d!\n", frst, scnd);
            continue;
        }
        if (guess > scnd)
        {
            numAttempts += 1;
            clear();
            printf("Guess must be within %d-%d!\n", frst, scnd);
            continue;
        }
        if (guess < korek)
        {
            numAttempts += 1;
            clear();
            printf("Too low!\n");
            continue;
        }
        if (guess > korek)
        {
            numAttempts += 1;
            clear();
            printf("Too High!\n");
            continue;
        }
        if (guess == korek)
        {
            
            numAttempts += 1;
            clear();
            line(2);
            printf("GUESS CORRECT\n");
            line(2);
            printf("Guess number: %d\n", korek);
            printf("Attempts: %d\n", numAttempts);
            line(1);
            printf("Press Enter to return...\n");
            getchar();
            clearBuffer();
            clear();
            *attempts+=numAttempts;
            *wins+=1;
            return 0;

        }

    }

}

//clear input buffer//
void clearBuffer()
{
    while (getchar() != '\n');
}
//print invalid//
void invalid()
{
    printf("Error: Invalid Input!\n");
}
