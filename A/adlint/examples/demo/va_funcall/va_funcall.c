typedef int FILE;

extern FILE *stdout;

extern int printf(const char *format, ...);
extern int fprintf(FILE* stream, const char *format, ...);

extern void foo(int i, long l, double d, ...);

int main(void)
{
    printf("%d\n", 10);
    fprintf(stdout, "%d\n", 10);

    printf();
    fprintf(stdout);

    foo();
    foo(1);
    foo(1, 2);
    foo(1, 2, 3.0);
    foo(1, 2, 3.0, 4);

    return 0;
}
