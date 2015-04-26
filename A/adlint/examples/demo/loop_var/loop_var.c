int foo(void)
{
    int i;
    int ii;

    for (i = 0; i < 10; i++)
        ;
    for (ii = 0; i < 10; i++)
        ;
    for (i = 0, ii = 0; ii < 10; ii++)
        ;

    return i;
}

void bar(void)
{
    int i;
    int j;
    int k = 0;

    for (i = 0; i < 10; k = k + 1) {
        i++;
    }

    for (i = 0; i < 10; i++) {
        i++;
    }

    for (j = 0; j < 10; j++) {
        if (j == 5) {
            j++;
        }
        if (j == 15) {
            j++;
        }
        if (j == -15) {
            j++;
        }
    }

    for (j = 0; ; j++) {
        if (j < 0) {
            j++;
        }
        if (j == 3) {
            j++;
        }
        if (j == 5) {
LABEL:
            break;
        }
    }
}

void baz(void)
{
    int i;
    int j = 0;

    for (i = 0; i < 5; ) {
        ++i;
    }

    for (i = 0; i < 5; j++) {
        i++;
    }

    for (i = 0; i < 5; ++j) {
        i++;
    }

    for (i = 0; i < 5; j--) {
        i++;
    }

    for (i = 0; i < 5; --j) {
        i++;
    }

    for (i = 0; i < 5; j = i + j) {
        ++i;
    }

    for (i = 0; i < 5; j += 2) {
        i++;
    }

    for (i = 0; i < 5; j -= 2) {
        ++i;
    }
}
