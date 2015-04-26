extern struct Foo ga1[3];
extern union Bar ga2[3];
extern void ga3[3];
extern int ga4[3][];
extern int ga5[][3];

extern int ga6[3]();
extern int ga7[3](int);
extern int (*ga8[3])(long);

static struct Foo a1[3];
static union Bar a2[3];
static void a3[3];
static int a4[3][];
static int a5[][3];

static int a6[3]();
static int a7[3](int);
static int (*a8[3])(long);

extern enum Baz baz1;

void foo(const union Bar *p1, const union Bar * const p2)
{
    *p1 = *p2;
    p1[0] = p2[0];
    p1->i = p2->i;
    p1 = p2;
}

void bar(const struct Foo *p1, const struct Foo * const p2)
{
    *p1 = *p2;
    p1[0] = p2[0];
    p1->i = p2->i;
    p1 = p2;
}

void baz(void)
{
    int a9[];
    const int a10[];
    struct Foo f1;
    const struct Foo f2;
    union Bar b1;
    const union Bar b2;
    void v1;
    const void v2;
    int i1;
    const int i2;
    const enum Baz baz2;
}
