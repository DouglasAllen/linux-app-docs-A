int main(void)
{
    int i = rand();

    if (i == 1) {
        goto Label1;
    }

    if (i < 0) {
        int j = 3 / i;
Label1:
Label2:
        return j;
    }

    goto Label2;

    return 0;
}
