#define MESG "hello world\n"
#define CHAR 'C'
#define SIZE (10)

extern void foo(void)
{
    const unsigned int ui = 0x80000000;
    const long l = 2147483648;
    const int i = 50;
    const char * const str = "hoge";
    const char ch = 'A';
    const int a1[3];
    const int a2[3 + 1];
    const int a3[SIZE];
    const int a4[SIZE + 1];

    puts(MESG);
    printf("%c\n", CHAR);
}
