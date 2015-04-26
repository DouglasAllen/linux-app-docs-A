#include "indirect_recur_3.h"

static int foo(const int i)
{
    extern int func_1(const int);
    return func_3(i + 1) + func_1(i + 1); /* ADLINT::[-W0723] */
}

int func_2(const int i)
{
    return foo(i + 1); /* ADLINT::[-W0723] */
}
