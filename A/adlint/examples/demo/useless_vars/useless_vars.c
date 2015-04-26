int foo(int i)
{
    return 0;
}

int main(void)
{
    int i = foo(0);
    int ii;
    int iii = 0;

    if (i == 0) {
        ii = foo(ii);
    }

    return foo(iii);
}
