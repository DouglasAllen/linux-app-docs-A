int *foo(int i)
{
    int n = i;
    return &n;
}

int *bar(int i)
{
    static int n;
    return &n;
}

void baz(int **pp)
{
    int i = 0;
    *pp = &i;
}

void qux(void)
{
    int *p;
    {
        int i;
        p = &i;
    }
}

int *gpi;
char *gpc;

void hoge(long ** p)
{
    int i = 0;
    static const char s[] = "aaa";
    static const long l = 1;

    gpi = &i;
    gpc = s;
    gpc = &s[0];
    *p = &l;
}

void hogehoge(int i)
{
    static int *p;
    p = &i;
}
