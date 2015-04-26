extern const g_int;

extern foo(void);

static bar(const *p)
{
    return *p;
}

extern baz(void)
{
    const i = 0;
    return i;
}
