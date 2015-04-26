static void foo(const int i, const unsigned int ui)
{
    {
        int r;

        if (i > 2000000000) {
            r = i * 5;
            r = i + i;
        }
    }

    {
        unsigned int r;

        if (ui > 3000000000U) {
            r = ui * 5U;
            r = ui + ui;
        }
        else {
            r = ui - 4000000000U;
        }
    }
}

static void bar(const int i, const unsigned int ui)
{
    {
        int r;

        if (i > 1000) {
            r = i * 5;
            r = i + i;
        }
    }

    {
        unsigned int r;

        if (ui > 1000U) {
            r = ui * 5U;
            r = ui + ui;
        }
        else {
            r = ui - 1000U;
        }
    }
}

static void baz(const signed char c, const unsigned char uc)
{
    {
        signed char r;

        if (c > 125) {
            r = c * 5;
            r = c + c;
        }
    }

    {
        unsigned char r;

        if (uc > 128U) {
            r = uc * 5U;
            r = uc + uc;
        }
        else {
            r = uc - 128U;
        }
    }
}

static void qux(const unsigned int ui)
{
    {
        const unsigned int ui1 = 3U - 1U;
        const unsigned int ui2 = 3U - 3U;
        const unsigned int ui3 = 3U - 5U;

        unsigned int ui4;

        ui4 = 3U - 1U;
        ui4 = 3U - 3U;
        ui4 = 3U - 5U;

        ui4 = ui - 1U;
    }

    {
        const unsigned int ui1 = 4294967294U + 1U;
        const unsigned int ui2 = 4294967295U + 1U;

        unsigned int ui3;

        ui3 = 4294967294U + 1U;
        ui3 = 4294967295U + 1U;

        ui3 = ui + 1U;
    }

    {
        const unsigned int ui1 = 2000000000U * 2U;
        const unsigned int ui2 = 3000000000U * 2U;

        unsigned int ui3;

        ui3 = 2000000000U * 2U;
        ui3 = 3000000000U * 2U;

        ui3 = ui * 2U;
    }
}

static void quux(const int i)
{
    unsigned int ui;

    if (i < 10) {
	ui1 = (unsigned int) (i - 5);
	ui1 = (unsigned int) (i - 9);
	ui1 = (unsigned int) (i - 10);
    }

    if (i >= 0 && i < 10) {
	ui1 = (unsigned int) (i - 5);
	ui1 = (unsigned int) (i - 9);
	ui1 = (unsigned int) (i - 10);
    }
}
