#include "log.h"
#include "../file.h"
#include <cstdio>
#include <dirent.h>
#include <errno.h>

void Log(const std::string &buf, int line, const std::string &file, const std::string &func) {

    std::string str = "An error in function (" + func + ") occured on line " + std::to_string(line) +
                      " in file (" + file + "): " +
                      buf + "\n";

    std::cout << str;

    if (direxists("log")) {
        CFile log("log/log.log", "a");
        log.wfile(str);
    }
    else {
        if (creatdir("log") == 0) {
            CFile log("log/log.log", "a");
            log.wfile(str);
        }
    }
}
