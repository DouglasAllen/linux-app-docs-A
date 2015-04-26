extern int printf(const char *, ...);
extern int scanf(const char *, ...);

int main(void)
{
    int i = 0;
    int ii = 1;

    printf();

    printf("%509d\n", i);
    printf("%510d\n", i);

    printf("%3d %5t\n", i, ii);

    printf("%3ld %xd\n", i);
    printf("%3to %fo\n", i, ii, 0);
    printf("%3tu %fu\n");
    printf("%3tx %fx\n", i, ii);
    printf("%3tX %fX\n", i, ii);
    printf("%3lf %Lf\n", i, ii);
    printf("%3le %Le\n", i, ii);
    printf("%3lE %LE\n", i, ii);
    printf("%3lg %Lg\n", i, ii);
    printf("%3lG %LG\n", i, ii);
    printf("%lc %Lc\n", i, ii);
    printf("%%lc % %Z\n", i, ii);
    printf("%ls %Ls\n", i, ii);
    printf("%ln %Ln\n", i, ii);
    printf("%p %lp\n", i, ii);
    printf("%#x %#\n", i, ii);

    scanf("%3d %5t\n", &i, &ii);

    scanf("%3ld %xd\n", &i, &ii);
    scanf("%3to %fo\n", i, &ii);
    scanf("%3tu %fu\n", &i, ii);
    scanf("%3tx %fx\n", &i, &ii);
    scanf("%3tf %lf\n", &i, &ii);
    scanf("%3lls %fs\n", &i, &ii);
    scanf("%3p %lp\n", &i, &ii);
    scanf("%%lc % %Z\n", &i, &ii);
    scanf("%l[a-z] %ll[a-z]\n", &i, &ii);
    scanf("%3llc %fc\n", &i, &ii);
    scanf("%3llz %c\n", &i, &ii);

    scanf("%[z-a]\n", &i);
    scanf("%[abcd]\n", &i);
    scanf("%[abca]\n", &i);

    return 0;
}

static void foo(void)
{
    char buf[256];

    printf("%s", buf);
    scanf("%s", buf);
}
