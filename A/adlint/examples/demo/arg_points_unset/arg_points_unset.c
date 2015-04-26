extern int printf(const char *, ...);
extern int rand(void);

static void foo(const int *p) { }

static void bar(char *str, const long *p)
{
    printf(str, *p);
}

static void baz(void)
{
    int i;

    for (int j = 0; j < rand(); ++j) {
        i = 0;
    }

    foo(&i);
}

int main(void)
{
    int i;
    long l;

    foo(&i);
    bar("%l", &l);

    if (rand() == 0) {
        i = 1;
    }

    foo(&i);

    return i;
}
