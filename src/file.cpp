#include "file.h"
#include <cstdio>
#include <stdlib.h>

int rfile(const char* filename, char* _buf) {

    FILE *f = fopen(filename, "r");

    fseek(f, 0, SEEK_END);
    int sz = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *buf = (char*)malloc(sz + 1);

    int cnt = fread(buf, sizeof(char), sz, f);

    if (cnt < sz)
        return -1;

    _buf = buf;

    return 0;
}
