extern void exit(int);
extern int rand(void);

static int foo(const int i, int);
static int bar(const int i, int j);
static int baz(const int, int);
static int baz(const int j, int i);

static int foo(const int i, int)
{
    if (i == 0) {
        return 0;
    }
    else if (i == 1) {
        exit(1);
    }
    else {
        return 2;
    }
    return rand();
}

static int bar(const int i, int j)
{
    if (i < 0) {
        unsigned short j = foo(1);
        if (j < i) {
            abort();
        }
        if (i == 0) {
            abort();
        }
        exit(1);
    }
    else {
        if (i == -2) {
            abort();
        }
    }
    /* i >= 0 */

    if (i < 2) {
        j = 3 / i;  /* i == 0..1 */
    }

    if (i < 1) {
        j = 3 / i;  /* i == 0 */
        return j;
    }

    return 3 / i; /* i == 1 */
}

static int baz(const int i, int j)
{
    if (i < 0) {
        unsigned short j = foo(1, 2, 3);
        if (j < i) {
            abort();
        }
        if (i == 0) {
            abort();
        }
        exit(1);
    }
    else {
        if (i == -2) {
            abort();
        }
    }
    /* i >= 0 */

    if (i < -3) {
        abort();
    }

    if (i != 0) {
        i = 1;
    }
    else {
        return 0;
    }
    /* i == 1 */

    if (i < 2) {
        j = 3 / i;
    }

    if (i < 1) {
        j = 3 / i;
        return j;
    }

    return 3 / i;
}

static int qux(void)
{
    int i = foo(0);
    int j;

    if (i < 0) {
        unsigned short j = foo(1);
        if (j < i) {
            abort();
        }
        if (i == 0) {
            abort();
        }
        exit(1);
    }
    else {
        if (i == -2) {
            abort();
        }
    }
    /* i >= 0 */

    if (i == 0) {
        i = 1;
    }
    else if (i == 1) {
        i = 2;
    }
    /* i >= 1 */

    if (i < 2) {
        j = 3 / i;
    }

    if (i < 1) {
        j = 3 / i;
        return j;
    }

    return 3 / i;
}

static int foobar(void)
{
    int i;

    if (1) {
        i = foo(0);
    }

    if (0) {
        return i;
    }

    if (1) {
        i = foo(0);
    }
    else {
        __adlint__eval("puts 'NOTREACHED'");
        return 0;
    }

    if (0) {
        __adlint__eval("puts 'NOTREACHED'");
        return 0;
    }
    else {
        i = foo(0);
    }

    do {
        i = 0;
    } while(0);

    switch (i) {
    case 0:
        for (;;) {
            i = 0;
        }
        break;
    default:
        i = 1;
    }

    return 3 / i;
}

int (*p)(const int j, int i) = &foo;

int main(void)
{
    int i = foo(0);
    int j;
    int (*p)(const int x, int y) = bar;

    p = baz;

    if (i < 0) {
        return 0;
    }

    if (i != 0) {
        i = 1;
    }
    else {
        return 0;
    }
    /* i == 1 */

    if (i < 2) {
        j = 3 / i;
    }

    if (i < 1) {
        return 3 / i;
    }

    i = foo(0);

    switch (i) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
    case 3:
        return 3;
    default:
        return 4;
        break;
    }

    if (i == 4) {
        return 5;
    }
    else {
        return 6;
    }

    return 0;
}
