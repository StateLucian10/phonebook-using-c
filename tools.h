
#ifndef TOOLS_H
#define TOOLS_H

#define LENGTH_NAME 30
#define LENGTH_NUMBER 25

unsigned int hash(const char *name);
bool load(const char *file_name);
bool check(const char *name);
void print_number();
bool unload(void);

#endif //TOOLS_H
