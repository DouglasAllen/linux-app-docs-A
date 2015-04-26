extern int foo(void);

static inline void bar(const int x, int y)
{
    if ((x == 0) && (y == 0)) {
    }

    if ((x > 0) && (y++ < 0)) {
    }

    if ((x < 0) && foo()) {
    }

    {
        int i;

        i = !(x || y);
        i = !(x | b);

        i = !(x && b);
        i = !(x & b);
    }

    {
        int i;

        i = ~((x > y) && (x > 5));
        i = !((x > b) && (x > 5));
    }
}

static int baz(const int x, const int y)
{
    (x && y) || 0;
    return 0;
}
