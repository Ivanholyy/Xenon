#ifndef ENGINE_H
#define ENGINE_H 1

#include "window/gui/gui.h"

class CEngine {

public:
    int Init();
    int Run();

private:
    CWindow m_window;
    CGUI gui;
};

#endif
