#ifndef FILE_H
#define FILE_H

#define ACCOUNTS "data/accounts.bin"
#define SAVED "data/saved.bin"
#define ID "data/id.bin"

void save(int accountCount, int accountNumber);
int load(int *accountNumber);

#endif