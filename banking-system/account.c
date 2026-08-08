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

        printf("Account Number: ");
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
    FILE *stream;

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

        printf("Account Number: ");
        if (scanf("%d", &edit) != 1 || edit < 100001){
        clearInt();
        invalidInput();
        continue;
        }
        clearInt();

        stream = fopen(ACCOUNTS, "rb");
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

void deleteAccount(int *accountCount, int accountNumber){
    int delete;
    char choice;
    FILE *stream;

    do
    {
        line(2);
        printf("DELETE ACCOUNT\n");
        line(2);

        if (*accountCount == 0){
        printf("No registered accounts at the moment.\n");
        getchar();
        clear();
        return;
        }

        line(0);
        printf("Enter [0] to Return.\n");
        line(0);

        printf("Account Number: ");
        if (scanf("%d", &delete) != 1 || delete < 100001){
            clearInt();
            invalidInput();
            continue;
        }
        clearInt();

        stream = fopen(ACCOUNTS, "rb");
        for (int i = 0; i < *accountCount; i++){
            fread(&accounts[i],sizeof(accounts[i]),1 ,stream);
            if (delete == accounts[i].accountNumber){
                clear();
                line(2);
                printf("DELETE ACCOUNT\n");
                line(2);
                line(0);
                printf("Account Number: %d\n", accounts[i].accountNumber);
                printf("Name          : %s\n", accounts[i].name);
                printf("Balance       : $%.2lf\n", accounts[i].balance);
                fclose(stream);
                line(0);

                line(1);
                printf("Delete this account?\n");
                line(0);
                printf("[Y] Yes\n");
                printf("[N] No\n");
                line(0);
                printf("Enter Choice: ");

                if (scanf("%C", &choice)!= 1){
                    clearInt();
                    invalidInput();
                    continue;
                }
                clearInt();
                choice = toupper(choice);

                if (choice == 'Y'){
                    for (i; i < *accountCount - 1; i++){
                        accounts[i] = accounts[i+1];
                    }
                    (*accountCount)--;
                    stream = fopen(ACCOUNTS, "wb");
                    for (int j = 0; j < *accountCount; j++){
                        fwrite(&accounts[j], sizeof(accounts[i]), 1, stream);
                    }
                    save(*accountCount, accountNumber);
                    fclose(stream);
                    clear();
                    printf("Account Deleted Successfully!\n");
                    return;
                }
                else{
                    clear();
                    continue;
                }
            }
        }
        clear();
        fclose(stream);
        continue;
        
    }
    while (delete != 0);
    clear();
    return;
}

void statistics(int accountCount){

    int i = 0;
    FILE *stream;
    double totalMoney = 0;
    double highest = 0;
    double lowest = 0;
    double average = 0;
    char type[] = "Savings";
    int result;
    int savings = 0;
    int current = 0;

    highest = accounts[0].balance;
    lowest = accounts[0].balance;
    stream = fopen(ACCOUNTS, "rb");

    for (i; i < accountCount; i++){
        fread(&accounts[i], sizeof(accounts[i]), 1, stream);
        totalMoney += accounts[i].balance;

        if (highest < accounts[i].balance){
            highest = accounts[i].balance;
        }
        if (lowest > accounts[i].balance){
            lowest = accounts[i].balance;
        }

        result = strcmp(type, accounts[i].accountType);
        if (result == 0){
            savings++;
        }
        else{
            current++;
        }

    }
    average = totalMoney / accountCount;

    line(2);
    printf("STATISTICS\n");
    line(2);

    if (accountCount == 0){
        printf("No registered accounts at the moment.\n");
        getchar();
        clear();
        return;
    }

    line(0);
    printf("Total Accounts      : %d", accountCount);
    line(0);

    line(1);

    line(0);
    printf("Total Money         : $%.2lf\n", totalMoney);
    line(0);
    printf("Highest Balance     : $%.2lf\n", highest);
    line(0);
    printf("Lowest Balance      : $%.2lf\n", lowest);
    line(0);
    printf("Average Balance     : $%.2lf\n", average);

    line(0);
    line(1);
    line(0);

    printf("Savings Accounts    : %d\n", savings);
    line(0);
    printf("Current Accounts    : %d\n", current);

    line(0);
    line(1);
    line(0);

    printf("Press Enter to Return...");
    getchar();
    clear();
    return;

}

void deposit(int accountCount){
    int search;
    double amount;
    FILE *stream;
    Account newAccountBalance;

    do
    {
        line(2);
        printf("DEPOSIT MONEY\n");
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

        printf("Account Number: ");
        if (scanf("%d", &search) != 1 || search < 100001){
            clearInt();
            invalidInput();
            continue;
        }
        clearInt();

        stream = fopen(ACCOUNTS, "rb");
        for (int i = 0; i < accountCount; i++){
            fread(&accounts[i], sizeof(accounts[i]), 1, stream);
            if (search == accounts[i].accountNumber){
                fclose(stream);
                newAccountBalance = accounts[i];
                line(0);
                printf("Current Balance : $%.2lf\n", accounts[i].balance);
                line(0);
                printf("Deposit Amount : $");

                if (scanf("%lf", &amount) != 1 || amount < 0){
                    clearInt();
                    invalidInput();
                    continue;
                }
                clearInt();
                line(0);
    

                newAccountBalance.balance += amount;
                accounts[i] = newAccountBalance;

                line(1);
                printf("New Balance : $%.2lf\n", accounts[i].balance);

                stream = fopen(ACCOUNTS, "wb");
                for (int j = 0; j < accountCount; j++){
                    fwrite(&accounts[j], sizeof(accounts[j]), 1, stream);
                }
                fclose(stream);
                
                line(0);
                printf("Deposit Successful!\n");
                line(0);
                printf("Press Enter to Return...");
                getchar();
                clear();
                return;
                
            }
        }
        clear();
        fclose(stream);
        continue;

    } while (search != 0);
    clear();
    return;
}

void withdraw(int accountCount){
    int input;
    double amount;
    FILE *stream;
    Account withdrawAccountBalance;

    do
    {
        line(2);
        printf("WITHDRAW MONEY\n");
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

        printf("Account Number: ");
        if (scanf("%d", &input) != 1 || input < 100001){
            clearInt();
            invalidInput();
            continue;
        }
        clearInt();

        stream = fopen(ACCOUNTS, "rb");
        for (int i = 0; i < accountCount; i++){
            fread(&accounts[i], sizeof(accounts[i]), 1, stream);
            if (input == accounts[i].accountNumber){
                fclose(stream);
                withdrawAccountBalance = accounts[i];
                line(0);
                printf("Current Balance : $%.2lf\n", accounts[i].balance);
                line(0);
                printf("Withdraw Amount : $");

                if (scanf("%lf", &amount)!= 1){
                    clearInt();
                    invalidInput();
                    continue;
                }
                clearInt();

                if (amount > accounts[i].balance){
                    clear();
                    fprintf(stderr, "Error: Insufficient Balance.\n");
                    continue;
                }

                if (amount < 0){
                    clear();
                    fprintf(stderr, "Error: Amount must not be less than 0.\n");
                    continue;
                }

                withdrawAccountBalance.balance -= amount;
                accounts[i] = withdrawAccountBalance;
                stream = fopen(ACCOUNTS, "wb");
                for (int j = 0; j < accountCount; j++){
                    fwrite(&accounts[j], sizeof(accounts[j]), 1, stream);
                }
                fclose(stream);
                line(0);
                line(1);
                printf("Remaining Balance : $%.2lf\n", accounts[i].balance);
                line(0);
                printf("Withdrawal Successful!\n");
                line(0);
                printf("Press Enter to Return...");
                getchar();
                clear();
                return;
            }
        }

    } while (input != 0);
    clear();
    return;
       
}

void transfer(int accountCount){
    int first;
    int second;
    double amount;
    FILE *stream;
    Account firstAcc;
    Account secondAcc;

    do
    {
        line(2);
        printf("TRANSFER MONEY\n");
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

        printf("Sender Account Number: ");
        if (scanf("%d", &first)!= 1 || first < 100001){
            clearInt();
            invalidInput();
            continue;
        }
        clearInt();
        int i = 0;
        stream = fopen(ACCOUNTS, "rb");
        for (i; i < accountCount; i++){
            fread(&accounts[i], sizeof(accounts[i]), 1, stream);
            if (first == accounts[i].accountNumber){
                fclose(stream);
                firstAcc = accounts[i];
                break;
            }
        }

        if (first != accounts[i].accountNumber && i == accountCount){
            clear();
            printf("Account not found.\n");
            continue;
        }

        line(0);
        printf("Receiver Account Number: ");
        if (scanf("%d", &second) != 1 || second < 100001){
            clearInt();
            invalidInput();
            continue;
        }
        clearInt();
        int j = 0;
        stream = fopen(ACCOUNTS, "rb");
        for (j; j < accountCount; j++){
            fread(&accounts[j], sizeof(accounts[j]), 1, stream);
            if (second == accounts[j].accountNumber){
                fclose(stream);
                secondAcc = accounts[j];
                break;
            }
        }

        if (second != accounts[j].accountNumber && j == accountCount){
            clear();
            printf("Account not found.\n");
            continue;
        }

        if (firstAcc.accountNumber == secondAcc.accountNumber){
            clear();
            fprintf(stderr, "Error: You can't transfer money to the same account.\n");
            continue;
        }

        line(0);
        printf("Transfer Amount: $");
        if (scanf("%lf", &amount) != 1 || amount < 0){
            clearInt();
            invalidInput();
            continue;
        }
        clearInt();

        if (amount > firstAcc.balance){
            clear();
            fprintf(stderr, "Error: Insufficent funds.\n");
            continue;
        }

        firstAcc.balance -= amount;
        secondAcc.balance += amount;
        accounts[i].balance = firstAcc.balance;
        accounts[j].balance = secondAcc.balance;
        stream = fopen(ACCOUNTS, "wb");
        for (int k = 0; k < accountCount; k++){
            fwrite(&accounts[k], sizeof(accounts[k]), 1, stream);
        }
        fclose(stream);

        
        line(1);
        printf("Transfer Sucessful!\n");
        line(0);

        printf("From : %s\n", firstAcc.name);
        printf("To   : %s\n", secondAcc.name);
        line(0);
        printf("Amount: $%.2lf\n", amount);
        line(0);
        printf("New Balance: $%.2lf\n", secondAcc.balance);
        line(0);
        printf("Press Enter to Return...");
        getchar();
        clear();
        return;

    } while (first != 0 || second != 0);
    clear();
    return;
}