int foo()
{
    return 0;
}

int (*bar())()
{
    return 0;
}

int baz(int (*p)())
{
    return p(0);
}
