#include <stdio.h>
//created by: joshwell
//date: Monday, 27 July 2026, 10:01:39 pm

//even better version of my calculator.

//clears input buffer.
void clearBuffer(){
    while(getchar()!= '\n');
}

//prints "=====" line for aesthetic purposes.
void line(){
    printf("==============================\n");
}

//prints "_____" line.
void oneLine(){
    printf("------------------------------\n");
}

//MAIN
int main(void){
        
    float num1, num2 = 0.0f;
    char op = '\0';
    float total = 0.0f;

    line();
    printf("CALCULATOR V3\n");
    line();
    printf("Input 0 to end the program.\n");

    while (1){

        printf("Enter first number: ");
        //always make sure to check if input is an integer.
        if (scanf("%f", &num1)!= 1){
            printf("\nError: input must be a number!\n");
            clearBuffer();
            continue;
        }
        //if num1 is equals to zero, then the program ends.
        if (num1 == 0){
            return 0;
        }
        oneLine();
        clearBuffer();

        printf("Enter operator(+, -, *, /): ");
        scanf("%c", &op);
        oneLine();
        clearBuffer();

        printf("Enter second number: ");
        //always make sure to check if input is an integer.
        if (scanf("%f", &num2)!= 1){
            printf("\nError: input must be a number!\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        //the switch that does the calculations:
        switch (op)
        {
        case '+':
            total = num1 + num2;
            break;

        case '-':
            total = num1 - num2;
            break;

        case '*':
            total = num1 * num2;
            break;

        case '/':
            if (num2 == 0){
                printf("\nError: cannot be divided!\n");
                continue;
            }
            total = num1 / num2;
            break;
        
        default:
            printf("\nError: input must be an operator!\n");
            continue;
        }
        //print total.
        line();
        printf("Total is: %.2f\n", total);
        line();
    }
}