extern int rand(void);

int foo(void)
{
    int i;
    const int r = rand();

    if (r == 0) {
        i = 1;
    }
    else if (r == 1) {
        i = 2;
    }

    return 3 / i; /* i is not set when rand() returns !(0 or 1) */
}

int bar(int n)
{
    int i;
    int c;

    for (c = 0; c < n; c++) {
        i = c;
    }

    return 3 / i; /* i is not set when n < 1 */
}
