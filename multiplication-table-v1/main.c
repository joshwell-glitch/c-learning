#include <stdio.h>
#include<stdbool.h>
//created by: joshwell
//date: Monday, 13 July 2026, 6:06:13 pm

//main function.
int main(void)
{

    //title.
    printf("\n==============================\n");
    printf("MULTIPLICATION TABLE\n");
    printf("==============================\n");

    //this while loop runs repeatedly after input.
    while (1)
    {

        int num;
        int i;
        printf("Enter a Number:\n"); 

        //checks if number is not a integer.
        if (scanf("%d", &num)!= 1)
        {

            printf("[INVALID INPUT]\n");
            while (getchar()!= '\n');

            continue;

        }
        //closes the program if input is 0.
        if (num == 0){
            return 0;
        }
        
        //for loop that creates the multiplication table 1-10.
        for (i = 1; i < 11; i++)
        {
            
            //prints the multiplication table 1-10.
            printf("%d x %d = %d\n", num, i, num * i);

        }

        printf("==============================\n");
    }
}