#include <stdio.h>
#include <windows.h>
#include "utils.h"
#include "account.h"
#include "file.h"
//coded by: joshwell

int main(){
    int choice;
    int accountCount = 0;
    int accountNumber = 100000;
    accountCount = load(&accountNumber);

    do{

        line(2);
        printf("BANKING SYSTEM\n");
        line(2);
        printf("Total Accounts: %d/%d\n", accountCount, MAX_ACCOUNT);
        line(0);
        printf("[1] Create Account\n");
        printf("[2] View Accounts\n");
        printf("[3] Search Account\n");
        printf("[4] Edit Account\n");
        printf("[5] Delete Account\n");
        line(1);
        printf("[6] Deposit Money\n");
        printf("[7] Withdraw Money\n");
        printf("[8] Transfer Money\n");
        line(1);
        printf("[9] Statistics\n");
        printf("[0] Exit\n");
        line(0);
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1){
            clearInt();
            invalidInput();
            continue;
        }
        clearInt();
        clear();

        switch (choice)
        {
        case 1:
            createAccount(&accountCount, &accountNumber);
            break;
        case 2:
            viewAccounts(accountCount);
            break;
        case 3:
            searchAccount(accountCount);
            break;
        case 4:
            editAccount(accountCount);
            break;
        case 5:
            deleteAccount(&accountCount, accountNumber);
            break;
        case 6:
            deposit(accountCount);
            break;
        case 7:
            withdraw(accountCount);
            break;
        case 9:
            statistics(accountCount);
            break;
        }

    } while (choice != 0);
    line(2);
    printf("Thank you for using\n");
    printf("BANKING SYSTEM\n");
    line(0);
    printf("Goodbye!\n");
    line(2);
    Sleep(1050);
    return 0;
}