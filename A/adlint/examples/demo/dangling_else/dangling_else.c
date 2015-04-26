static void foo(const int i, const int j)
{
    if (i < 0)
        if (j > 0) {
            return 0;
        }
    else {
        return 1;
    }

    if (i > 0)
        if (j < 0) {
            return 2;
        }
        else {
            return 3;
        }

    return 4;
}
