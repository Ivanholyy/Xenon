#include "engine.h"
#include <GLFW/glfw3.h>

int main()
{
    CEngine engine;

    if (engine.Init() == -1)
        return -1;

    engine.Run();

    return 0;
}
