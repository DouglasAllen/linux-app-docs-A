int main(void)
{
    const int i = rand();
    const unsigned short us = (unsigned short) rand();

    if (i < 0) {
        if (i < us) {
            return 0;
        }
    }
    else {
        for (int j = 0; j < i; j++) {
            puts("hoge\n");
        }
        while (i != -5) {
            return 1;
        }
    }

    return 0;
}
