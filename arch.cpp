#include "arch.h"

Item *NewList(char c, int cnt) {
    Item *it = (Item*)malloc(sizeof(Item));
    it->c = c;
    it->cnt = cnt;
    it->next = NULL;
    return it;
}

Item *AddItem(Item* begin, char c, int cnt) {
    if (begin->next == NULL)
    {
        begin->next = NewList(c, cnt);
        return begin->next;
    } else {
       return AddItem(begin->next, c, cnt);
    }
}

Archive *Pack(const char*tmp) {
    Archive * arch = new Archive();
    arch->Total = strlen(tmp);
    Item *begin = nullptr;
    while (*tmp != '\0') {
        char symbol = *tmp;
        int count = 0;
        do {
            tmp++;
            count++;
        } while (symbol == *tmp);
        // sobsna archivim
        if (begin == nullptr)
        {
            begin = NewList(symbol, count);
        } else {
            AddItem(begin, symbol, count);
        }
    }
    arch->begin = begin;
    return arch;
}

char *Unpack(Archive * arch) {
    if (arch == NULL || arch->begin == NULL || arch->Total == 0)
    {
        return NULL;
    }
    Item *begin = arch->begin;
    int resultI = 0;
    char *result = new char[arch->Total + 1];
    do {
//        size_t count = (begin->cnt * sizeof(char)) + resultI;
//        char *temp = new char[count];//(char*)malloc(count);
//        //memset(temp, 0, count);
//        if (result != NULL) {
//            memcpy(temp, result, resultI);
//            delete[] result;//free(result);
//        }
//        result = temp;
        for (int i=0; i < begin->cnt; ++i)
        {
            result[resultI++] = begin->c;
        }
        begin = begin->next;
    } while (begin != NULL);
    result[resultI] = 0;
    return result;
}
