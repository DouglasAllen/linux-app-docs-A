void foo(const unsigned int ui1, const unsigned int ui2,
         const unsigned char uc1, const unsigned char uc2)
{
    unsigned long ul;

    ul = ~ui1;

    ul = ui1 * ui2;
    ul = ui1 / ui2;
    ul = ui1 % ui2;

    ul = ui1 + ui2;
    ul = ui1 - ui2;

    ul = ui1 & uib;
    ul = ui1 | uib;
    ul = ui1 ^ ui2;

    ul = ui1 << 1;
    ul = ui1 >> 1;

    ul = ~uc1;

    ul = uc1 * uc2;
    ul = uc1 / uc2;
    ul = uc1 % uc2;

    ul = uc1 + uc2;
    ul = uc1 - uc2;

    ul = uc1 & ucb;
    ul = uc1 | ucb;
    ul = uc1 ^ uc2;

    ul = uc1 << 1;
    ul = uc1 >> 1;

    ul = (unsigned long) (~uc1);
    ul = (unsigned long) ~uc1;

    ul = (unsigned long) (uc1 * uc2);
    ul = (unsigned long) (uc1 / uc2);
    ul = (unsigned long) (uc1 % uc2);

    ul = (unsigned long) (uc1 + uc2);
    ul = (unsigned long) (uc1 - uc2);

    ul = (unsigned long) (uc1 & uc2);
    ul = (unsigned long) (uc1 | uc2);
    ul = (unsigned long) (uc1 ^ uc2);

    ul = (unsigned long) (uc1 << 1);
    ul = (unsigned long) (uc1 >> 1);
}

void bar(void)
{
    unsigned char uc = -1;

    uc = -2;
}
