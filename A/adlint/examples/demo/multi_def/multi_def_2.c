#include "multi_def_2.h"

int g1;
struct Point g2;

int foo(void)
{
    return 0;
}

struct Point *bar(int i)
{
    static struct Point p;
    p.x = i;
    p.y = i + 1;
    return &p;
}

int baz(void)
{
    return foo();
}
