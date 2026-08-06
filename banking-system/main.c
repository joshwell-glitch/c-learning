#include <stdio.h>
#include "utils.h"
#include "account.h"
//coded by: joshwell

int main(){
    int choice;
    int accountCount = 0;

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
            createAccount(&accountCount);
            break;
        case 2:
            viewAccounts(accountCount);
            break;
        case 3:
            searchAccount();
            break;
        case 4:
            editAccount();
            break;
        case 5:
            deleteAccount();
            break;
        }

    } while (choice != 0);
    return 0;
}