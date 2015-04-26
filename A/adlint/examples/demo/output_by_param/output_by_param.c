void foo(int *p, char *buf)
{
    if (p && buf) {
        *p = 0;
        buf[0] = 0;
    }
}

int bar(void)
{
    int i = 0;
    char buf[100] = { 0 };

    foo(&i, buf);

    return buf[i];
}
