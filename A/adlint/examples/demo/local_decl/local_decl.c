int main(void)
{
    extern int i;
    extern int foo(int);
    extern int bar();
    static int baz(void);

    return bar(foo(i));
}
