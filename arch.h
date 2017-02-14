#ifndef ARCH_H
#define ARCH_H
#include <stdlib.h>
#include <string.h>

struct Item {
    char c;
    int cnt;
    struct Item *next;
};

struct Archive {
    char name[20];
    size_t Total;
    Item * begin;
};

Item *NewList(char, int);
Item *AddItem(Item*, char, int);
Archive *Pack(const char*);
char *Unpack(Archive *);

#endif // ARCH_H
