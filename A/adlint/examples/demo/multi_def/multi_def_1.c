#include "multi_def_1.h"

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

int g1 = 0;

int foo(void)
{
    return 1;
}

int foo = 1;

int g1(void)
{
    return 0;
}
