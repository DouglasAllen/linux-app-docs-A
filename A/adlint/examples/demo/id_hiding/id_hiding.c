extern int i;

static int foo(const int i)
{
    return i;
}

static int bar(void)
{
    const int i = foo(0);
    return i;
}

static int baz(void)
{
    typedef int foo;
    const foo f = 0;
    return f;
}
