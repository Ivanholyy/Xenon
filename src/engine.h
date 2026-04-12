#ifndef ENGINE_H
#define ENGINE_H 1

#include "window/window.h"

class CEngine {

public:
    int Init();
    int Run();

private:
    CWindow m_window;
};

#endif
