#include "indirect_recur_1.h"
#include "indirect_recur_2.h"

int g;

static int foo(void)
{
    return g;
}

int func_1(const int i)
{
    return func_2(g + i + foo()); /* ADLINT::[-W0723] */
}
