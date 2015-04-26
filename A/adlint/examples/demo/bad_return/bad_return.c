int ansi_int_func_1(const int i)
{
    if (i == 0) {
        return;
    }
    else {
        return i * 2;
    }
}

int kandr_int_func_1(i)
    const int i;
{
    if (i == 0) {
        return;
    }
    else {
        return i * 2;
    }
}

static void ansi_void_func(const int i)
{
    if (i == 0) {
        return;
    }
    else {
        return i * 2;
    }
}

static void kandr_void_func(i)
    const int i;
{
    if (i == 0) {
        return;
    }
    else {
        return i * 2;
    }
}

ansi_int_func_2(const i)
{
    if (i == 0) {
        return;
    }
    else {
        return i * 2;
    }
}

kandr_int_func2(i)
    const i;
{
    if (i == 0) {
        return;
    }
    else {
        return i * 2;
    }
}

const void ansi_qualified_void_func_1(const int i)
{
    if (i == 0) {
        return;
    }
    else {
        return i * 2;
    }
}

volatile void kandr_qualified_void_func_1(i)
    const int i;
{
    if (i == 0) {
        return;
    }
    else {
        return i * 2;
    }
}
