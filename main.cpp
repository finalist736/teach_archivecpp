#include <iostream>
#include "arch.h"
#include <stdlib.h>
#include <string.h>
using namespace std;


int main(int argc, char *argv[])
{

    FILE *f = fopen("C:\\Users\\finalist\\html.txt", "r");
    if (f == NULL) {
        cout << "file open error";
        return -1;
    }

    fseek(f, 0L, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0L, SEEK_SET);

    char *fileContent = new char[sz];
    size_t readed = 0;
    while (!feof(f))
    {
        //fgets()
        readed += fread(fileContent + readed, sizeof(char), sz - readed, f);
    }

    fclose(f);



    Archive *begin = Pack(fileContent);

    char *result = Unpack(begin);


    if (strcmp(fileContent, result) == 0) {
        cout << "project sdan! go po domam!!";
    }



    return 0;
}
