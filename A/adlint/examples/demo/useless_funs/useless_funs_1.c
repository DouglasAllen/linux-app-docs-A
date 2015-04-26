#include "useless_funs_1.h"

int foo(void)
{
    return 0;
}

int bar(const int i) /* no caller of bar() in this project */
{
    if (i < 100) {
        return i + 1;
    }
    else {
        return 0;
    }
}

int baz(const int i) /* no caller of baz() in this project */
{
    if (i < 100) {
        return i + 2;
    }
    else {
        return 1;
    }
}

static int qux(void) /* no caller of qux() in this translation unit */
{
    return 2;
}
