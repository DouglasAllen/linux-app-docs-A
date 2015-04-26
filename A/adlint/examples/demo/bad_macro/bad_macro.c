#define FUNC1(x, y) x + y
#define FUNC2(x) (x * x)
#define FUNC3(x, y) x##y
#define FUNC4(x) #x

#define MANY_PARAMS1(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee)  1

#define MANY_PARAMS2(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff)  1

int main(void)
{
    const int i = FUNC1(1, 2);
    const int j = FUNC2(2);
    const int k = FUNC3(1, 2);
    const char * const str = FUNC4(foo);

    const int l = MANY_PARAMS1(1,1,1,1,1,1,1,1,1,1,
                               1,1,1,1,1,1,1,1,1,1,
                               1,1,1,1,1,1,1,1,1,1,
                               1);

    return MANY_PARAMS2(1,1,1,1,1,1,1,1,1,1,
                        1,1,1,1,1,1,1,1,1,1,
                        1,1,1,1,1,1,1,1,1,1,
                        1,1);
}

static int foo(void)
{
#define FOO (1)
    const int i = FOO;
#undef FOO
    return i;
}

#define MACRO1 { 0, 1, i }

#define MACRO2(x) { 0, x, x + 1 }

#define MACRO3(a, n) {                      \
    int j;                                  \
    for (j = 0; j < n; j++) {               \
        a[j] = j;                           \
    }                                       \
}

#define MACRO4(foo)                         \
    do {                                    \
        foo(0);                             \
    } while (0)

#define MACRO5 static const

#define MACRO6 if (hoge) perror("hoge");

#define MACRO7 {                            \
    for (int i = 0; i < 10; i++) {          \
        puts("hello world\n");              \
    }                                       \
}

static void bar(int i)
{
    int a1[] = MACRO1;
    int a2[] = MACRO2(3);

    MACRO3;

    if (i == 0)
        MACRO4(bar);

    {
        MACRO5 int hoge;
        MACRO6
    }

    MACRO7;
}

#define ADD +
#define SUB -
#define MUL *
#define DIV /
#define MOD %

#define WHILE while
#define DO do
#define FOR for
#define IF if
#define ELSE else
#define SWITCH switch
#define CASE case
#define DEFAULT default
#define GOTO goto
#define RETURN return
#define BREAK break
#define CONTINUE continue

#undef assert
#define defined !defined
#undef defined

#undef __STDC__
#define __FILE__ "foo.c"
