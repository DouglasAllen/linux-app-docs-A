static int foo(const int i)
{
    return i * 2;
}

static int bar(i)
    const int i;
{
    return i * 2;
}

static
int
baz
(const int i)
{
    return i * 2;
}

inline
static
struct
hoge
{
    int i;
}
*
qux
(
 const
 int
 i
 )
{
    return (struct hoge *) i;
}

extern const int ansi_qualified_func_1(const int);
const int ansi_qualified_func_1(const int i)
{
    return i * 2;
}

extern const int kandr_qualified_func_1();
const int kandr_qualified_func_1(i)
    const int i;
{
    return i * 2;
}

static volatile ansi_qualified_func_2(const int);
static volatile ansi_qualified_func_2(const int i)
{
    return i * 2;
}

static volatile kandr_qualified_func_2();
static volatile kandr_qualified_func_2(i)
    const int i;
{
    return i * 2;
}

const int *ansi_func(const int);
const int *ansi_func(const int i)
{
    static int j;
    j = i;
    return &j;
}

const int *kandr_func();
const int *kandr_func(i)
    const int i;
{
    static int j;
    j = i;
    return &j;
}
