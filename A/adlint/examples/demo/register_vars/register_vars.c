extern int puts(const char *);

void foo(void)
{
    register char a[3];
    char *p = a;

    p = &a[0];
    p = &a[1];

    puts(a);
}
