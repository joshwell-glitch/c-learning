#ifndef FILE_H
#define FILE_H

#define ACCOUNTS "data/accounts.bin"
#define SAVED "data/saved.bin"

void save(int accountCount);
int load();

#endif