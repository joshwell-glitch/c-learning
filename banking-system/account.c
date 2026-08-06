#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include "account.h"
#include "file.h"


Account accounts[MAX_ACCOUNT];

void createAccount(int *accountCount){
    int number = 100000;
    int choose;
    char type[2][MAX_CHAR_ACCOUNT_TYPE] = {"Savings", "Current"};
    Account newAccount;
    FILE *stream = fopen(ACCOUNTS, "wb");
    if (stream == NULL){
        perror("");
        return;
    }

    while(true){
    line(2);
    printf("CREATE ACCOUNT\n");
    line(2);
    line(0);
    printf("Account Number: %d\n", number);
    line(0);

    line(1);
    printf("Enter Name: ");
    fgets(newAccount.name, sizeof(newAccount.name), stdin);
    clearStr(newAccount.name);
    line(1);

    printf("Enter Age (18 - 1000): ");
    if (scanf("%d", &newAccount.age)!= 1 || newAccount.age < 18 || newAccount.age > 100){
        clearInt();
        invalidInput();
        continue;
    }
    clearInt();
    line(1);

    printf("Select Account Type:\n");
    line(0);
    printf("[1] Savings\n");
    printf("[2] Current\n");
    line(0);
    printf("Enter Choice: ");
    if (scanf("%d", &choose)!= 1){
        clearInt();
        invalidInput();
        continue;
    }
    clearInt();
    switch (choose)
    {
    case 1:
        strcpy(newAccount.accountType, type[0]);
        break;
    case 2:
        strcpy(newAccount.accountType, type[1]);
        break;
    default:
        invalidInput();
        continue;
    }
    line(1);

    printf("Initial Deposit: $");
    if (scanf("%d", &newAccount.balance) != 1){
        clearInt();
        invalidInput();
        continue;
    }
    clearInt();
    line(1);

    accounts[*accountCount] = newAccount;
    fwrite(&accounts[*accountCount], sizeof(Account), 1, stream);
    (*accountCount)++;
    save(*accountCount);
    fclose(stream);
    printf("Account Created Successfully!\n");
    line(0);
    printf("Press Enter to return...");
    getchar();
    clear();
    return;
    }
}

void viewAccounts(int accountCount){

}

void searchAccount(){

}

void editAccount(){

}

void deleteAccount(){

}