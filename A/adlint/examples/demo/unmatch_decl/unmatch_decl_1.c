#include "unmatch_decl_1.h"

int g1;
struct Point g2;

struct Point *bar(int i)
{
    static struct Point p;
    p.x = i;
    p.y = i * 2;
    return &p;
}
