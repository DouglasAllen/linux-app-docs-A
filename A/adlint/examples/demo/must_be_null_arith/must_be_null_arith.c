int main(void)
{
    int *p = may_return_null();

    if (p) {
        *p = 1;
    }
    else {
        p = p + 1;
        *p = 0;
    }

    return 0;
}
