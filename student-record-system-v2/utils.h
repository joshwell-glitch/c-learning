#ifndef UTILS_H
#define UTILS_H

//HELPER FUNCTIONS:

//"0" for blank, "1" for 1 line, "2" for 2 line.
void line(int num);
//clears terminal.
void clear();
//clear integer input buffer.
void clearInt();
//clear string buffer.
void clearStr(char string[]);
//invalid input.
void invalid();

#endif