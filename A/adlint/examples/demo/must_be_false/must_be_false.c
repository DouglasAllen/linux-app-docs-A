int main(void)
{
    const int i = rand();
    const unsigned short us = (unsigned short) rand();

    if (i < 0) {
        if (i > us) {
            return 0;
        }
    }
    else {
        for (int j = -1; j > i; j++) {
            puts("hoge\n");
        }
        while (i == -5) {
            return 1;
        }
        do {
            puts("hoge\n");
        } while (i == -10);
    }

#define A (1)
#define B (1)

    if (A - B) {
        puts("hoge\n");
    }

    if (A - B) {
        puts("hoge\n");
    }
    else {
        puts("hoge\n");
    }

    while (A - B) {
        puts("hoge\n");
    }

    {
        int k;
        for (k = 0; A - B; k++) {
            puts("hoge\n");
        }
    }

    for (int k = 0; A - B; k++) {
        puts("hoge\n");
    }

    return 0;
}
