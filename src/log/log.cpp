#include "log.h"
#include <cstdio>
#include <dirent.h>
#include <iostream>

void Log(char *buf, int line, char* file) {

    std::cout << "An error occured on line " << line << " in file (" << file << "):" << buf << std::endl;

    DIR *dir = opendir("log");

    if (dir) {
        FILE *f = fopen("log.txt", "w");
        if (f) {

        }
    }

}
