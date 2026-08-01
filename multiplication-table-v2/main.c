#include <stdio.h>
//created by: joshwell
//date: Thursday, 30 July 2026, 9:54:18 am


//function prototype:
void line(int num);

//MAIN FUNCTION:
int main(){
    int rows = 10;
    int columns = 10;

    line(2);
    printf("              Multiplication Table\n");
    line(2);

    /*i made a row loop, the outer "for" loop acts as the row for the
    multiplication table, everytime the inner "for" loop finishes the loop, the outer loop will create a row,
    so what happens in the inner loop is that, it prints the columns of the table. 
    whenever the outer loop "i" increases it's value, it will
    be multiplied with "j" that is also increaing its value in the inner loop,
    thus it perfectly acts as a multiplication table */
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            printf("%4d ", j * i);
        }        
        line(0);
    }
    line(1);
    printf("Press Enter to close program...");
    getchar();
    return 0;
}

//function for printing the lines and blanks
void line(int num){
    if (num == 1){
    printf("--------------------------------------------------\n");
    }
    else if (num == 2)
    {printf("==================================================\n");
    }
    else {
        printf("\n");
    }
}