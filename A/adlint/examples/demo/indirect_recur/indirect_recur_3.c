#include "indirect_recur_1.h"

int func_3(const int i)
{
    return func_1(i + 1); /* ADLINT::[-W0723] */
}
