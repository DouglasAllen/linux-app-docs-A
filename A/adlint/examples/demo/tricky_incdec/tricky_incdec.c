extern int foo(int);

void bar(int n, int *p)
{
    int r;

    ++n;
    (*p)--;

    r = ++n;
    foo(r++);
}
