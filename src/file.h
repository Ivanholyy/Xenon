#ifndef FILE_H
#define FILE_H 1

#include <iostream>

class CFile {

public:
    CFile(const std::string &filename, const std::string &mode)
         : m_filename(filename), m_mode(mode) {
        m_file = fopen(m_filename.c_str(), m_mode.c_str());
        if (m_file == NULL)
            std::cout << "Error in opening file!" << std::endl;
    }

    ~CFile() {
        if (m_file != NULL) {
            fclose(m_file);
        }
    }

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
