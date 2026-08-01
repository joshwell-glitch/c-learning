#include <stdio.h>
#include <stdbool.h>
//created by: joshwell
//date: Sunday, 19 July 2026, 11:00:37 pm


/*i absolutely do NOT recommend this way of coding, this was my first calculator code.
 in later projects, i learned to use functions and it helped me a lot in making my code shorter.
 (always try to make your code short as possible to make it more readable).
 NOTE: the simple calculator v2 is much better than this.*/

 //addition function
int addition()
{
    
    bool running = true;
    int input;
    int firstNum;
    int secondNum;
    int total;

    while (running)
    {

        printf("===ADDITION===\n");
        printf("First number:\n");
        if (scanf("%d", &firstNum) != 1)
        {
            printf("===INVALID INPUT===\n");
            while (getchar() != '\n');
            continue;
        }
        printf("Second Number:\n");
        if (scanf("%d", &secondNum) != 1)
        {
            printf("===INVALID INPUT===\n");
            while (getchar() != '\n');
            continue;
        }

        while(getchar() != '\n');

        total = firstNum + secondNum;
        printf("==============================\n");
        printf("Total: %d\n", total);
        printf("==============================\n");
        printf("Use Again?\n");
        printf("(1)Yes\n(2)No\n");
        if (scanf("%d", &input) != 1)
        {
            printf("===INVALID INPUT===\n");
            while (getchar() != '\n');
            continue;
        }

        //clear input buffer.
        while (getchar() != '\n');

        switch (input)
        {

            case 1:
                continue;
        
            case 2:
                return 0;

            default:
                printf("===INVALID INPUT===\n");
                break;
                
        }

    }

}

//subtraction function.
int subtraction()
{
    
    bool running = true;
    int input;
    int firstNum;
    int secondNum;
    int total;

    while (running)
    {

        printf("===SUBTRACTION===\n");
        printf("First number:\n");
        if (scanf("%d", &firstNum) != 1)
        {
            printf("===INVALID INPUT===\n");
            while (getchar() != '\n');
            continue;
        }
        printf("Second Number:\n");
        if (scanf("%d", &secondNum) != 1)
        {
            printf("===INVALID INPUT===\n");
            while (getchar() != '\n');
            continue;
        }

        while(getchar() != '\n');

        total = firstNum - secondNum;
        printf("==============================\n");
        printf("Total: %d\n", total);
        printf("==============================\n");
        printf("Use Again?\n");
        printf("(1)Yes\n(2)No\n");
        if (scanf("%d", &input) != 1)
        {
            printf("===INVALID INPUT===\n");
            while (getchar() != '\n');
            continue;
        }

        while (getchar() != '\n');

        switch (input)
        {

            case 1:
                continue;
        
            case 2:
                return 0;

            default:
                printf("===INVALID INPUT===\n");
                break;
                
        }
        
    }

}

//multiplication function.
int multiplication()
{
    
    bool running = true;
    int input;
    int firstNum;
    int secondNum;
    int total;

    while (running)
    {

        printf("===MULTIPLICATION===\n");
        printf("First number:\n");
        if (scanf("%d", &firstNum) != 1)
        {
            printf("===INVALID INPUT===\n");
            while (getchar() != '\n');
            continue;
        }
        printf("Second Number:\n");
        if (scanf("%d", &secondNum) != 1)
        {
            printf("===INVALID INPUT===\n");
            while (getchar() != '\n');
            continue;
        }

        while(getchar() != '\n');

        total = firstNum * secondNum;
        printf("==============================\n");
        printf("Total: %d\n", total);
        printf("==============================\n");
        printf("Use Again?\n");
        printf("(1)Yes\n(2)No\n");
        if (scanf("%d", &input) != 1)
        {
            printf("===INVALID INPUT===\n");
            while (getchar() != '\n');
            continue;
        }

        while (getchar() != '\n');

        switch (input)
        {

            case 1:
                continue;
        
            case 2:
                return 0;

            default:
                printf("===INVALID INPUT===\n");
                break;
                
        }
        
    }

}

//division function
int division()
{
    
    bool running = true;
    int input;
    float firstNum;
    float secondNum;
    float total;

    while (running)
    {

        printf("===DIVISION===\n");
        printf("First number:\n");
        if (scanf("%f", &firstNum) != 1)
        {
            printf("===INVALID INPUT===\n");
            while (getchar() != '\n');
            continue;
        }
        printf("Second Number:\n");
        if (scanf("%f", &secondNum) != 1 || secondNum == 0)
        {
            printf("===INVALID INPUT===\n");
            while (getchar() != '\n');
            continue;
        }

        while(getchar() != '\n');

        total = firstNum / secondNum;
        printf("==============================\n");
        printf("Total: %.2f\n", total);
        printf("==============================\n");
        printf("Use Again?\n");
        printf("(1)Yes\n(2)No\n");
        if (scanf("%d", &input) != 1)
        {
            printf("===INVALID INPUT===\n");
            while (getchar() != '\n');
            continue;
        }

        while (getchar() != '\n');

        switch (input)
        {

            case 1:
                continue;
        
            case 2:
                return 0;

            default:
                printf("===INVALID INPUT===\n");
                break;
                
        }
        
    }

}


//MAIN//

int main()
{
    bool running = true;
    int input;

    while (running)
    {

        printf("===SIMPLE CALCULATOR===\n");
        printf("(1)Addition\n");
        printf("(2)Subtraction\n");
        printf("(3)Multiplication\n");
        printf("(4)Division\n");
        printf("(5)Exit\n");
        printf("Enter a number:\n");
        scanf("%d", &input);

        while (getchar() != '\n');

        switch (input)
        {

            case 1:
                addition();
                break;

            case 2:
                subtraction();
                break;

            case 3:
                multiplication();
                break;

            case 4:
                division();
                break;

            case 5:
                printf("===PROGRAM CLOSED==\n");
                return 0;
        
            default:
                printf("===INVALID INPUT===\n");
                break;

        }

    }

}