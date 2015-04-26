extern int g;

void foo(void)
{
    int * const p = &g;
    *p = 0;
}

typedef struct {
    int i;
} type;

type buf[3];
type *p = &buf[1];

void bar(void)
{
    type t = *p;
    (*p).i = 1;
    p->i += p->i;
}
