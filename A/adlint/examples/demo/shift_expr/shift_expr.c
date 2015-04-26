int main(void)
{
    const int i = -1;
    int j;
    const unsigned int ui = 1;

    j = i >> 3;
    j = (int) (ui >> 3);

    j = i << 3;
    j = (int) (ui << 3);

    return 0;
}
