static int i = 0;
static int ii = 0;
static int iii = 0;

void foo(void)
{
    i = 1;
}

int bar(void)
{
    return i;
}

static void baz(void)
{
    ii = 1;
}

static int qux(void)
{
    static int ii = 0;
    return ii;
}

static int a[];
static int a[3];

static struct Foo s1;
static struct Foo s2[];
static struct Foo s3[3];

static union Bar u1;
static union Bar u2[];
static union Bar u3[3];

static enum Baz e1;
static enum Baz e2[];
static enum Baz e3[3];
