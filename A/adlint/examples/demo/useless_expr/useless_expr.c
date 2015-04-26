int main(void)
{
    int *p = (int *) malloc(sizeof(int));

    if (p) {
        *p = 0;
    }
    else {
        return 1;
    }

    *p;
    *p++;
    (*p)++;

    return 0;
}
