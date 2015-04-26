int foo(const int i)
{
    if (i == 0) {
label:
        return 0;
    }

    if (i < 0) {
        goto label;
    }

label:
    return 1;
}

int bar(const int i)
{
    if (i == 0) {
        goto label;
    }

    i = 0;

label:
    return i;
}
