#include "unmatch_decl_2.h"

long g1;
struct Color g2;

struct Color *bar(void)
{
    static struct Color c;
    return &c;
}
