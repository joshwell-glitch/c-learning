#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//define means, i named "FILENAME to "file.text" for easy input.
#define FILENAME "file.text"

//coded by: joshwell
//date: Friday, 31 July 2026, 9:53:31 pm

//FUNCTION PROTOTYPES:
void clearBuffer();
void clear();
void line(int num);
void print(char letter);
void createFile();
void readFile();
void appendFile();
void deleteFile();

//MAIN FUNCTION:
int main(){
    int input;
    while(true){
        line(2);
        printf("FILE HANDLING PRACTICE\n");
        line(2);
        printf("Select a number to:\n");
        line(0);
        printf("[1] Create file.\n");
        printf("[2] Read file.\n");
        printf("[3] Append file.\n");
        printf("[4] Delete file.\n");
        printf("[5] Exit program..\n");
        line(0);
        printf("Enter Choice: ");

        if (scanf("%d", &input) != 1 || input < 1 || input > 5){
            clearBuffer();
            clear();
            print('i');
            continue;
        }
        clearBuffer();
        clear();

        switch (input)
        {
        case 1:
            createFile();
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
        default:
            clearBuffer();
            clear();
            print('i');
            continue;
        }
    }
}



//FUNCTIONS:

//clear input buffer.
void clearBuffer(){
    while (getchar() != '\n');
}
//clears terminal screen.
void clear(){
    printf("\e[1H\e[2J");
}
//(0) for blank, (1) for single line, (2) for double line.
void line(int num){
    if (num == 0){
        printf("\n");
    }
    else if (num == 1){
        printf("----------------------------------------\n");
    }
    else if (num == 2){
        printf("========================================\n");
    }
}
//prints (i)invalid input.
void print(char letter){
    if (letter == 'i'){
        printf("Error: Invalid Input!\n");
    } 
}

//CREATE FULE FUNC:
void createFile(){
    //creates the file and gives permission to write inside the file because of mode "w":
    FILE *fp = fopen(FILENAME, "w");
    char contents[256];

    line(2);
    printf("CREATING FILE\n");
    line(2);

    //checks if fp is NULL:
    if (fp == NULL){
        clear();
        printf("File cannot be created!\n");
        return;
    }

    //input in file:
    printf("Enter some text to write it inside the file.\n");
    printf("---------------[CONTENTS]---------------\n");
    /*fgets means, getting the string, like, "contents" is the string variable
     that i am about to input to. then i set the size of this input to be the same size as "contents",
     i then declared "stdin", meaning standard input.*/
    fgets(contents, sizeof(contents), stdin);
    line(1);

    //fputs means, putting the "contents"(string that i just input) into the fp pointer, contents -> fp.
    fputs(contents, fp);
    fclose(fp);
    printf("File created successfully!\n");
    printf("Press any key to return...");
    //make sure to close the file.
    getchar();

    clear();
    return;
}

//READ FILE FUNCTION:
void readFile(){
    //"r" mode means read only.
    FILE *fp = fopen(FILENAME, "r");
    char buffer[256];

    line(2);
    printf("READING FILE\n");
    line(2);

    if (fp == NULL){
        clear();
        printf("File cannot be found!\n");
        return;
    }

    printf("---------------[CONTENTS]---------------\n");
    //while fgets is not detecting NULL, it will print the contents from the file line by line
    while (fgets(buffer, sizeof(buffer), fp)!= NULL){
        printf("%s", buffer);
    }
    line(1);
    //if done reading, it prints this:
    if (feof(fp)){
        printf("End of file reached.\n");
    }
    fclose(fp);

    printf("Press any key to return...");
    getchar();

    clear();
    return;
}

//APPEND FILE:
void appendFile(){
    //"a" mode means append(add another line of text in the existing file).
    FILE *fp = fopen(FILENAME, "a");
    char contents[256];

    line(2);
    printf("APPENDING FILE\n");
    line(2);


    if (fp == NULL){
        clear();
        printf("File cannot be found!\n");
        return;
    }

    printf("---------------[CONTENTS]---------------\n");
    fgets(contents, sizeof(contents), stdin);
    fputs(contents, fp);
    fclose(fp);
    line(1);

    printf("Appended successfully!\n");
    printf("Press any key to return...");
    getchar();

    clear();
    return;
}

//DELETE FILE:
void deleteFile(){
    line(2);
    printf("DELETING FILE\n");
    line(2);

    //remove function, it removes the file inside its parenthesis.
    if (remove(FILENAME) == 0){
        printf("File deleted successfully!\n");
    }
    else{
        printf("File cannot be deleted!\n");
    }

    printf("Press any key to return...");
    getchar();

    clear();

}