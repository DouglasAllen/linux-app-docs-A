int main(void)
{
    int i = rand();

    if (i == 0) {
        if (i > 0) {
            i = 1;
        }
    }

    if (i < 0) {
        if (i > 3) {
            i = 2;
        }
    }

    switch (i) {
    case 0:
        if (i < 0) {
            i = 3;
        }
        break;
    case 1:
        if (5 < i) {
            i = 4;
        }
        break;
    }

    for (int ii = 0; ii < i; ii++) {
    }

    return 0;
}
