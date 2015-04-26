static void foo(const int i1, const int i2,
        const unsigned char uc1, const unsigned char uc2)
{
    int i;

    i = (int) (uc1 & uc2);
    i = (int) (uc1 | uc2);
    i = (int) (uc1 ^ uc2);
    i = (int) ~uc1;
    i = (int) (uc1 << 1);
    i = (int) (uc1 >> 1);

    i = i1 & i2;
    i = i1 | i2;
    i = i1 ^ i2;
    i = ~i1;
    i = i1 << i2;
    i = i1 >> i2;
}
