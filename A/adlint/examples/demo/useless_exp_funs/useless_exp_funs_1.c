int bar(int i)
{
    return i + 1;
}

int baz(int i)
{
    return i * 2;
}

int foo(void)
{
    return bar(1) + baz(2);
}
