int foo(const int i)
{
    if (i > 5) {
        switch (i) {
        case 0:
            return 1;
        case 5:
            return 2;
        default:
            return 3;
        }
    }

    switch (i) {
    case 0:
        return 4;
    default:
        switch (i) {
        case 10:
            return 5;
        default:
            return 6;
        }
    }
}
