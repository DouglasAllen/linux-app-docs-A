extern int rand(void);

static void foo(void)
{
    const int i = rand();

    if (i > 127) {
        const signed char c = (signed char) i;
    }
    /* __adlint__inspect(i); // 2 -> 1 */
    if (i < -128) {
        const signed char c = (signed char) i;
    }
    /* __adlint__inspect(i); // 4 -> 1 */

    if (i > 100) {
        const signed char c = (signed char) i;
    }
    /* __adlint__inspect(i); // 5 -> 1 */
    if (i < -100) {
        const signed char c = (signed char) i;
    }
    /* __adlint__inspect(i); // 5 -> 1 */

    if (i > -129 && i < 128) {
        const signed char c = (signed char) i;
    }
}

extern void *alloc(void);

static void bar(void)
{
    const signed char sc1 = (signed char) 127.5;
    const signed char sc2 = (signed char) 128.5;

    const signed char sc3 = (signed char) -128.5;
    const signed char sc4 = (signed char) -129.5;

    const unsigned char uc1 = (unsigned char) 255.5;
    const unsigned char uc2 = (unsigned char) 256.5;

    const unsigned char uc3 = (unsigned char) 0.5;
    const unsigned char uc4 = (unsigned char) -1.5;

    const int si1 = (int) 1.5e9;
    const int si2 = (int) 1.5e10;

    const int si3 = (int) -1.5e9;
    const int si4 = (int) -1.5e10;

    int *data_ptr = (int *) alloc();
    int (*func_ptr)(void) = (int (*)(void)) alloc();

    const unsigned char uc5 = (unsigned char) data_ptr;
    const unsigned char uc6 = (unsigned char) func_ptr;

    const unsigned short us1 = (unsigned short) data_ptr;
    const unsigned short us2 = (unsigned short) func_ptr;

    const unsigned int ui1 = (unsigned int) data_ptr;
    const unsigned int ui2 = (unsigned int) func_ptr;

    const unsigned long ul1 = (unsigned long) data_ptr;
    const unsigned long ul2 = (unsigned long) func_ptr;

    const unsigned char uc7 = 255;
    const unsigned char uc8 = 256;

    const unsigned int ui3 = 4294967295;
    const unsigned int ui4 = 4294967296;

    const unsigned char a[] = { 255, 256 };

    const signed char sc5 = 127;
    const signed char sc6 = 128;

    const int si5 = 2147483647;
    const int si6 = 2147483648;
}

extern long baz(void);
extern unsigned long qux(void);

int main(void)
{
    const long l = baz();
    const unsigned long ul = qux();
    long r;

    r = 0x1FFFFFFFL << 1;
    r = 0x1FFFFFFFL << 2;
    r = 0x1FFFFFFFL << 3;
    r = 0x1FFFFFFFL << 4;

    if (l >= 0x1FFFFFFFL) {
        r = l << 1;
        r = l << 2;
        r = l << 3;
        r = l << 4;
    }

    if (l < 500) {
        r = l << 1;
        r = l << 2;
    }

    if ((l > 0) && (l < 500)) {
        r = l << 1;
        r = l << 2;
    }

    r = l << 1;

    if (ul < 500) {
        r = ul << 1;
        r = ul << 2;
    }

    if (ul <= 0x1FFFFFFFUL) {
        r = ul << 1;
        r = ul << 2;
        r = ul << 3;
        r = ul << 4;
    }

    return 0;
}
