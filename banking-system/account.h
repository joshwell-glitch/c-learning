#ifndef ACCOUNT_H
#define ACCOUNT_H

#define MAX_ACCOUNT 100
#define NAME_LIMIT 30
#define MAX_CHAR_ACCOUNT_TYPE 8

typedef struct
{
    int accountNumber;
    char name[NAME_LIMIT];
    char accountType[MAX_CHAR_ACCOUNT_TYPE];
    int age;
    double balance;
}Account;

extern Account accounts[MAX_ACCOUNT];

void createAccount(int *accountCount);
void viewAccounts(int accountCount);
void searchAccount();
void editAccount();
void deleteAccount();

#endif