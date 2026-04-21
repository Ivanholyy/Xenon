#include "log.h"
#include "../file.h"
#include <dirent.h>
#include <vector>

std::vector<std::string> logbuf;

void Log(const std::string &buf, const int line, const std::string &file, const std::string &func, const std::string &date, const std::string &time) {

    std::string str = "(" + date + " " + time + ") An error in function (" + func + ") occured on line " + std::to_string(line) +
                      " in file (" + file + "): " +
                      buf + "\n";

    std::cout << "\e[1;91m" << str << "\e[0m";

    logbuf.push_back(str);

    if (logbuf.size() > 1000)
    {
        logbuf.erase(logbuf.begin());
    }

    if (direxists("log")) {
        CFile log("log/log.log", "a");
        if (log.open() == -1) {
            std::cout << "Error while opening log file!" << std::endl;
            return;
        }
        log.wfile(str);
    }
    else {
        if (creatdir("log") == 0) {
            CFile log("log/log.log", "a");
            if (log.open() == -1) {
                std::cout << "Error while opening log file!" << std::endl;
                return;
            }
            log.wfile(str);
        }
    }
}

void InfoLog(const std::string &buf, const std::string &func, const std::string &date, const std::string &time) {

    std::string str = "(" + date + " " + time + ")" + func +
                      ": " + buf + "\n";

    std::cout << "\e[1;94m" << str << "\e[0m";

    logbuf.push_back(str);

    if (logbuf.size() > 1000)
    {
        logbuf.erase(logbuf.begin());
    }

    if (direxists("log")) {
        CFile log("log/log.log", "a");
        if (log.open() == -1) {
            std::cout << "Error while opening log file!" << std::endl;
            return;
        }
        log.wfile(str);
    }
    else {
        if (creatdir("log") == 0) {
            CFile log("log/log.log", "a");
            if (log.open() == -1) {
                std::cout << "Error while opening log file!" << std::endl;
                return;
            }
            log.wfile(str);
        }
    }
}
