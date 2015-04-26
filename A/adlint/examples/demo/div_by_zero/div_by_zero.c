extern int rand(void);

int foo(void)
{
    const int i = rand();

    return 3 / i; /* div by 0 when rand() returns 0 */
}

int bar(const int n)
{
    int c;
    int i = 1;

    for (c = 0; c < n; ++c) {
        i = c;
    }

    i = 3 / i; /* div by zero when 1 is passed as parameter n */

    for (c = 0; c < n; ++c) {
        if (c % 2 == 0) {
            i = 0;
        }
    }

    i = 3 / i; /* div by zero when 1 is passed as parameter n */

    if (i == 0) {
        return 0;
    }
    else {
        return 3 / i; /* i must not be 0 in this path */
    }
}
