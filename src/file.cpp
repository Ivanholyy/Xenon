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
            Log("Can't use this mode with read function!", __LINE__, __FILE__, __PRETTY_FUNCTION__, __DATE__, __TIME__);
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

int CFile::open() {

    m_file = fopen(m_filename.c_str(), m_mode.c_str());
    if (m_file == NULL)
        return -1;

    return 0;
}

int CFile::wfile(const std::string &_buf) {

    for (int i = 0; i < 5; i++) {
        if (m_mode == sym1[i]) {
            Log("Can't use this mode with write function!", __LINE__, __FILE__, __PRETTY_FUNCTION__, __DATE__, __TIME__);
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
        Log("Error in opening file!", __LINE__, __FILE__, __PRETTY_FUNCTION__, __DATE__, __TIME__);
        return -1;
    }

    m_file = newf;

    return 0;
}

bool isdirectory(const std::string &name)
{

    struct stat s;
    if (stat(name.c_str(), &s) == 0)
        return S_ISDIR(s.st_mode);

    return false;
}

bool isimage(const std::string &name)
{

    const std::string &ext = strrchr(name.c_str(), '.');
    if (!ext.c_str()) return false;

    if (strcasecmp(ext.c_str(), ".png") == 0) return true;
    if (strcasecmp(ext.c_str(), ".jpg") == 0) return true;
    if (strcasecmp(ext.c_str(), ".jpeg") == 0) return true;
    if (strcasecmp(ext.c_str(), ".bmp") == 0) return true;
    if (strcasecmp(ext.c_str(), ".tga") == 0) return true;
    if (strcasecmp(ext.c_str(), ".psd") == 0) return true;
    if (strcasecmp(ext.c_str(), ".hdr") == 0) return true;
    if (strcasecmp(ext.c_str(), ".pic") == 0) return true;
    if (strcasecmp(ext.c_str(), ".pnm") == 0) return true;

    return false;
}

bool direxists(const std::string &path) {

    struct stat info;

    if (stat(path.c_str(), &info) != 0)
        return false;

    return (info.st_mode & S_IFDIR);
}

bool fileexists(const std::string &path) {

    struct stat info;
    return stat(path.c_str(), &info) == 0 && S_ISREG(info.st_mode);
}

int creatdir(const std::string &path) {

    if (mkdir(path.c_str(), 0755) == 0)
        return 0;
    else {
        if (errno == EEXIST)
            return 0;
        std::cout << "Error in creating directory: " << strerror(errno) << std::endl;
        return -1;
    }
}
