#ifndef LOG_H
#define LOG_H 1

#include <iostream>

void Log(const std::string &buf, const int line, const std::string &file, const std::string &func, const std::string &date, const std::string &time);
void InfoLog(const std::string &buf, const std::string &func, const std::string &date, const std::string &time);

#endif
