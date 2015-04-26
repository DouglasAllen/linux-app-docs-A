int main(void)
{
    int *p = may_return_null();

    if (p) {
        *p = 1;
    }
    else {
        *p = 2;
    }

    return 0;
}
