#ifndef SYSGRAPHICS_H
#define SYSGRAPHICS_H

#include "GlobalDef.h"

namespace ox
{
class SysGraphics
{
public:
    SysGraphics();
    ~SysGraphics();
    static bool init();
    static bool dispose();
    static void getGlInfo();
    // Sys interface
private:
};
}
#endif // SYSGRAPHICS_H
