struct Foo {
    int i;
    int j;
};

union Bar {
    int i;
    long j;
};

static void foo(void)
{
    const struct Foo foo1 = { 1, 2 };
    const struct Foo foo2 = 1;

    const union Bar bar1 = { 1 };
    const union Bar bar2 = 1;
}

struct Baz {
    int i;
    int a[3];
};

struct Qux {
    int i;
    union Bar u;
};

static void bar(void)
{
    const struct Foo foo1[2] = { { 1, 2 }, { 3, 4 } };
    const struct Foo foo2[2] = { 1, 2, 3, 4 };

    const union Bar bar1 = { 1 };
    const union Bar bar2 = bar1;
    const union Bar bar3 = foo1[0];

    const struct Baz baz1 = { 1, { 2, 3 } };
    const struct Baz baz2 = { 1, 2, 3 };
    const struct Baz baz3 = baz1;
    const struct Baz baz4 = foo1[0];

    const struct Qux qux1 = { 1, { 2 } };
    const struct Qux qux2 = { 1, 2 };

    const int a1[2][2] = { { 1, 2 }, { 3, 4 } };
    const int a2[2][2] = { 1, 2, 3, 4 };
}
