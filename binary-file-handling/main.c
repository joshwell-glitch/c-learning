#include <stdio.h>
#include "utils.h"
#include "file.h"
//coded by: joshwell
//date: Monday, August 3, 2026, 5:23:04 PM

int main(){
    int choice;
    while (1)
    {
        line(2);
        printf("Binary File Handling\n");
        line(2);

        printf("1. Create file.\n");
        printf("2. Read file.\n");
        printf("3. Append file.\n");
        printf("4. Delete file.\n");
        printf("5. Exit program..\n");
        line(0);

        if (scanf("%d", &choice)!= 1 || choice < 1 || choice > 5){
            clearInt();
            invalid();
            continue;
        }

        clearInt();
        clear();

        switch (choice)
        {
        case 1:
            addFile();
            break;

        case 2:
            readFile();
            break;

        case 3:
            appendFile();
            break;

        case 4:
            deleteFile();
            break;

        case 5:
            return 0;
        
        }
    }
}
