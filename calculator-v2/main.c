#include <stdio.h>
#include <stdbool.h>
//created by: joshwell
//date: Monday, 20 July 2026, 6:41:43 pm

/*this is the better version of my previous simple calculator.
although, it still looks unorganized. i learned a lot of things after this project*/

//functions//
float readInput();
void displayResult(float result);
void clearBuffer();

//main//
int main()
{

    bool running = true;
    printf("\n=========[CALCULATOR V2]=========\n");
    while (running)
    {
        /*because of the read input function value, it returns the total number calculated from it,
        then i made a float variable that can contain the read input's returned value.*/
        float result = readInput();
        displayResult(result);
        /*i then put the float varibale inside the display result function, in order for it to
        print the result from the read input.*/

    }
    
}

//clears input buffer//
void clearBuffer()
{
    while(getchar() != '\n');
}

//read input//
float readInput()
{
    float firstNum;
    char operation;
    float secondNum;
    float total = 0.0;

    while (true)
    {

        printf("Enter First Number:\n");
        if (scanf("%f", &firstNum) != 1)
        {

            printf("\n==============================\n");
            printf("[INVALID INPUT]\n");
            printf("==============================\n");
            clearBuffer();
            continue;

        } 
        else
        {

            clearBuffer();
            printf("Enter Operator:\n");
            if (scanf(" %c", &operation) != 1)
            {

                printf("\n==============================\n");
                printf("[INVALID INPUT]\n");
                printf("==============================\n");
                clearBuffer();
                continue;

            }
            if (operation != '+' && operation != '-' && operation != '*' && operation != '/')
            {

                printf("\n==============================\n");
                printf("[INVALID INPUT]\n");
                printf("==============================\n");
                clearBuffer();
                continue;

            }
            else
            {

                clearBuffer();
                printf("Enter Second Number:\n");
                if (scanf("%f", &secondNum) != 1)
                {

                    printf("\n==============================\n");
                    printf("[INVALID INPUT]\n");
                    printf("==============================\n");
                    clearBuffer();
                    continue;

                }
                else
                {

                    clearBuffer();
                    switch (operation)
                    {

                        case '+':
                            total = firstNum + secondNum;
                            break;
                    
                        case '-':
                            total = firstNum - secondNum;
                            break;

                        case '*':
                            total = firstNum * secondNum;
                            break;
                    
                        case '/':
                            if (secondNum == 0){
                                printf("\n[INVALID INPUT]\n");
                                continue;
                            }
                            total = firstNum / secondNum;
                            break;
                
                        default:
                            printf("\n==============================\n");
                            printf("[INVALID INPUT]\n");
                            printf("==============================\n");
                            break;
                        
                    }

                }
                if (total != 0.0)
                {
                    return total;
                }

            }

        }

    }

}

//display result//
void displayResult(float result)
{
    printf("\n==============================\n");
    printf("OUTPUT: %.2f\n", result);
    printf("==============================\n");

}