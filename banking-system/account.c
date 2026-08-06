#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"
#include "account.h"
#include "file.h"

Account accounts[MAX_ACCOUNT];

void createAccount(int *accountCount, int *accountNumber){
    int choose;
    char type[2][MAX_CHAR_ACCOUNT_TYPE] = {"Savings", "Current"};
    Account newAccount;
    FILE *stream = fopen(ACCOUNTS, "ab");
    if (stream == NULL){
        perror("");
        return;
    }

    while(true){
    line(2);
    printf("CREATE ACCOUNT\n");
    line(2);
    line(0);
    printf("Account Number: %d\n", (*accountNumber) + 1);
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
    if (scanf("%lf", &newAccount.balance) != 1){
        clearInt();
        invalidInput();
        continue;
    }
    clearInt();
    line(1);

    (*accountNumber)++;
    newAccount.accountNumber = (*accountNumber);
    accounts[*accountCount] = newAccount;
    fwrite(&accounts[*accountCount], sizeof(Account), 1, stream);
    (*accountCount)++;
    save(*accountCount, *accountNumber);
    fclose(stream);
    line(0);
    printf("Press Enter to return...");
    getchar();
    clear();
    return;
    }
}

void viewAccounts(int accountCount){
    line(2);
    printf("VIEW ACCOUNTS\n");
    line(2);

    if (accountCount == 0){
        printf("No registered accounts at the moment.\n");
        getchar();
        clear();
        return;
    }

    FILE *stream = fopen(ACCOUNTS, "rb");
    if (stream == NULL){
        perror("");
        return;
    }
    for (int i = 0; i < accountCount; i++){
        line(0);
        fread(&accounts[i], sizeof(accounts[i]), 1, stream);
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Name          : %s\n", accounts[i].name);
        printf("Age           : %d\n", accounts[i].age);
        printf("Type          : %s\n", accounts[i].accountType);
        printf("Savings       : $%.2lf\n", accounts[i].balance);
        line(1);
    }
    fclose(stream);
    line(0);
    printf("Press Enter to return...");
    getchar();
    clear();
    return;
}

void searchAccount(int accountCount){
    int search;

    do
    {
        line(2);
        printf("SEARCH ACCOUNT\n");
        line(2);
        if (accountCount == 0){
        printf("No registered accounts at the moment.\n");
        getchar();
        clear();
        return;
        }

        line(0);
        printf("Enter [0] to Return.\n");
        line(0);

        printf("Account number: ");
        if (scanf("%d", &search) != 1 || search < 100001){
            clearInt();
            invalidInput();
            continue;
        }
        clearInt();

        FILE *stream = fopen(ACCOUNTS, "rb");
        for (int i = 0; i < accountCount; i++){
            fread(&accounts[i], sizeof(accounts[i]), 1, stream);
            if (search == accounts[i].accountNumber){
                clear();
                line(2);
                printf("ACCOUNT FOUND\n");
                line(2);
                line(0);
                printf("Account Number: %d\n", accounts[i].accountNumber);
                printf("Name          : %s\n", accounts[i].name);
                printf("Age           : %d\n", accounts[i].age);
                printf("Type          : %s\n", accounts[i].accountType);
                printf("Balance       : $%.2lf\n", accounts[i].balance);
                line(0);
                fclose(stream);
                printf("Press Enter to return...");
                getchar();
                clear();
                return;
            }
        }
        clear();
        printf("Account not found.\n");
        continue;

    } while (search != 0);
    clear();
    return;
    
}

void editAccount(int accountCount){
    int edit;
    int choose;
    char type[2][MAX_CHAR_ACCOUNT_TYPE] = {"Savings", "Current"};

    do
    {
        line(2);
        printf("EDIT ACCOUNT\n");
        line(2);
        if (accountCount == 0){
        printf("No registered accounts at the moment.\n");
        getchar();
        clear();
        return;
        }

        line(0);
        printf("Enter [0] to Return.\n");
        line(0);

        printf("Account number: ");
        if (scanf("%d", &edit) != 1 || edit < 100001){
        clearInt();
        invalidInput();
        continue;
        }
        clearInt();

        FILE *stream = fopen(ACCOUNTS, "rb");
        for (int i = 0; i < accountCount; i++){
            fread(&accounts[i], sizeof(accounts[i]), 1, stream);
            if (edit == accounts[i].accountNumber){
                clear();
                line(2);
                printf("OLD INFO\n");
                line(2);
                line(0);
                printf("Account Number: %d\n", accounts[i].accountNumber);
                printf("Name          : %s\n", accounts[i].name);
                printf("Age           : %d\n", accounts[i].age);
                printf("Type          : %s\n", accounts[i].accountType);
                printf("Balance       : $%.2lf\n", accounts[i].balance);
                line(0);
                fclose(stream);

                Account editAccount;
                line(2);
                printf("NEW INFO\n");
                line(2);
                line(0);
                printf("Enter New Name: ");
                fgets(editAccount.name,sizeof(editAccount.name),stdin);
                clearStr(editAccount.name);

                printf("Enter New Age (18 - 100): ");
                if (scanf("%d", &editAccount.age)!= 1 || editAccount.age < 18 || editAccount.age > 100){
                    clearInt();
                    invalidInput();
                    continue;
                }
                clearInt();
                line(0);

                printf("Select New Account Type:\n");
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
                    strcpy(editAccount.accountType, type[0]);
                    break;
                case 2:
                    strcpy(editAccount.accountType, type[1]);
                    break;
                default:
                    invalidInput();
                    continue;
                }
                line(0);
                
                stream = fopen(ACCOUNTS, "wb");
                editAccount.accountNumber = accounts[i].accountNumber;
                editAccount.balance = accounts[i].balance;
                accounts[i] = editAccount;
                for (int j = 0; j < accountCount; j++){
                    fwrite(&accounts[j], sizeof(accounts[j]), 1, stream);
                }
                fclose(stream);
                printf("Account Edited Successfully!\n");
                printf("Press Enter to return...");
                getchar();
                clear();
                return;
            }
        }
        clear();
        fclose(stream);
        continue;

    } while (edit != 0);
    clear();
    return;
    
}

void deleteAccount(int accountCount){
    int delete;

    do
    {
        line(2);
        printf("DELETE ACCOUNT\n");
        line(2);
        if (accountCount == 0){
        printf("No registered accounts at the moment.\n");
        getchar();
        clear();
        return;
        }
        line(0);
        printf("Press Enter to return...");
        line(0);
    }
    while (delete != 0);
    clear();
    return;
}