#include "multi_decl_2.h"

extern int g1;
extern struct Point { int x, y; } g2;

extern int foo(void);
extern struct Point *bar(int);
extern int baz(void);

static int baz(void)
{
    return foo() + bar(0)->x;
}
