int baz(i, a)
    const int i;
    const char a[];
{
    return i;
}

int main(void)
{
    const short s = 0;
    const int i = 0;
    const char a[3];

    foo(s);
    foo(i);
    foo(s, i);

    bar(s);
    bar(i);
    bar(s, i);

    baz(s, a);
    baz(i, a);
    baz(s, a, i);

    qux();

    return 0;
}

extern int foo(int);

static int bar(const int i)
{
    char str[] = "hello\n";

    printf(str);
    printf("hello world\n");

    return i;
}

static int qux(void)
{
}
