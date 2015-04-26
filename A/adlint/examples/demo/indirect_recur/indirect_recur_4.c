#include "indirect_recur_1.h"

extern void exit(int);
extern void (*signal(int, void (*)(int)))(int);
#define SIGINT (1)

static void handler(int signo)
{
    exit(1);
}

/*
 * main(indirect_recur_4.c)
 *   -> *func_1(indirect_recur_1.c) <-------+-------+
 *        -> foo(indirect_recur_1.c)        |       |
 *        -> *func_2(indirect_recur_2.c)    |       |
 *             -> *foo(indirect_recur_2.c)--+       |
 *                  -> *func_3(indirect_recur_3.c)--+
 */

int main(void)
{
    signal(SIGINT, handler);
    return func_1(g);
}
