#include "file.h"
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include "log/log.h"

int CFile::rfile(std::string &_buf) {

    for (int i = 0; i < 10; i++) {
        if (m_mode == sym[i]) {
            Log("Can't use this mode with read function!", __LINE__, __FILE__, __PRETTY_FUNCTION__);
            return -1;
        }
    }

    fseek(m_file, 0, SEEK_END);
    int sz = ftell(m_file);
    fseek(m_file, 0, SEEK_SET);

    std::string buf(sz, '\0');

    int cnt = fread(buf.data(), sizeof(char), sz, m_file);

    if (cnt < sz)
        return -1;

    _buf = buf;

    return 0;
}

int CFile::wfile(const std::string &_buf) {

    for (int i = 0; i < 5; i++) {
        if (m_mode == sym1[i]) {
            Log("Can't use this mode with write function!", __LINE__, __FILE__, __PRETTY_FUNCTION__);
            return -1;
        }
    }

    int cnt = fwrite(_buf.data(), sizeof(char), _buf.size(), m_file);

    if (cnt < _buf.size())
        return -1;

    return 0;
}

int CFile::reopen(const std::string &mode) {

    FILE *newf = freopen(m_filename.c_str(), mode.c_str(), m_file);

    if (newf == NULL) {
        Log("Error in opening file!", __LINE__, __FILE__, __PRETTY_FUNCTION__);
        return -1;
    }

    m_file = newf;

    return 0;
}

bool direxists(const std::string &path) {

    DIR *dir = opendir(path.c_str());

    if (dir)
        return true;

    return false;
}

bool fileexists(const std::string &path) {

    FILE *f = fopen(path.c_str(), "r");

    if (f)
        return true;

    return false;
}

int creatdir(const std::string &path) {

    if (mkdir(path.c_str(), 755) == 0)
        return 0;
    else {
        std::cout << "Error in creating directory: " << strerror(errno) << std::endl;
        return -1;
    }

}
