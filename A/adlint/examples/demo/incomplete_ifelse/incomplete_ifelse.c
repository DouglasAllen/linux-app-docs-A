int foo(const int i)
{
    int j;

    if (i == 0) {
        j = 0;
    }

    if (i == 1) {
        j = 1;
    }
    else if (i == 2) {
        j = 2;
    }

    if (i > 2) {
        if (i == 5) {
            j = 5;
        }
        else if (i == 6) {
            j = 6;
        }
    }
    else if (i < 0) {
        j = -1;
    }

    return j;
}
