#include "multi_decl_1.h"

int g1;
struct Point g2;
double g3;

int foo(void)
{
    extern int g3;
    extern int func1(void);
    typedef long g3;

    return 0;
}

enum E1 { A, B, C };

struct Point *bar(int i)
{
    extern long g3;
    extern int func1(int);

    enum E2 { A, B, C };
    typedef int A;

    {
	extern short g3;
	extern int g3;
	extern void func1(int);
	extern int func1(int);
    }

    {
	extern char g3;
	extern short g3;
	extern void func1(int, ...);
	extern void func1(int);
    }

    static struct Point p;
    p.x = i;
    p.y = i * 2;

    return &p;
}

typedef int A;
