static int foo(const int n)
{
    int i;
    int j = 0;

    for (i = 0; i < n; i++);
    {
        j += n;
    }

    return j;
}

static int bar(const int n)
{
    int i = n;

    return i++;;
}
