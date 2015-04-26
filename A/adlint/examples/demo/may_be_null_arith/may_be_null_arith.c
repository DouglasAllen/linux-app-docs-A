int main(void)
{
    int c;
    int *p = NULL;

    if (rand() == 1) {
        p = &c;
    }

    *p = 0;
    p = p + 1;
    *p = 2;

    return 0;
}
