#ifndef FILE_H
#define FILE_H 1

#include <iostream>

const std::string sym[10] = { "a", "w", "w+", "a+", "wb", "ab", "w+b", "a+b", "wb+", "ab+" };
const std::string sym1[5] = { "r", "r+", "rb", "r+b", "rb+" };

class CFile {

public:
    CFile(const std::string &filename, const std::string &mode)
         : m_filename(filename), m_mode(mode) {}

    ~CFile() {
        if (m_file != NULL)
            fclose(m_file);
    }

    int open();
    int rfile(std::string &_buf);
    int wfile(const std::string &_buf);
    int reopen(const std::string &mode);
private:
    std::string m_filename;
    std::string m_mode;
    FILE *m_file;
};

bool direxists(const std::string &path);
int creatdir(const std::string &path);
bool fileexists(const std::string &path);

#endif
