static int fact(const int n)
{
    return (n == 1) ? 1 : (n * fact(n - 1));
}

extern int printf();

int main(void)
{
    const int i = fact(5);

    printf("%d", i);

    return 0;
}
