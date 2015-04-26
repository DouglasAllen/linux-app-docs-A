int foo(const int i1, const int i2, const int i3, const int i4)
{
    int r;

    r = (i1 + i2) < (i3 == i4);
    r = i1 - i2 > (i3 != i4);
    r = (i1 * i2) <= (i3 < i4);
    r = i1 / i2 >= (i3 > i4);
    r = (i1 % i2) < (i3 <= i4);
    r = i1 & i2 > (i3 >= i4);
    r = (i1 | i2) <= !i3;
    r = i1 ^ i2 >= !(i3 + i4);
    r = (i1 << i2) > (!i3 < (i4 + i1));

    r = (i3 == i4) < (i1 + i2);
    r = (i3 != i4) > i1 - i2;
    r = (i3 < i4) <= (i1 * i2);
    r = (i3 > i4) >= i1 / i2;
    r = (i3 <= i4) < (i1 % i2);
    r = (i3 >= i4) > i1 & i2;
    r = !i3 <= (i1 | i2);
    r = !(i3 + i4) >= i1 ^ i2;
    r = (!i3 < (i4 + i1)) > (i1 << i2);

    r = (!i3 < (i4 + i1)) < (i3 == i4);
    r = !(i3 + i4) > (i3 != i4);
    r = !i3 <= (i3 < i4);
    r = (i3 >= i4) >= (i3 > i4);
    r = (i3 <= i4) < (i3 <= i4);
    r = (i3 > i4) > (i3 >= i4);
    r = (i3 < i4) <= !i3;
    r = (i3 != i4) >= !(i3 + i4);
    r = (i3 == i4) > (!i3 < (i4 + i1));

    return r;
}

int bar(const int i1, const int i2, const int i3, const int i4)
{
    int r;

    r = (i1 + i2) & (i3 == i4);
    r = i1 - i2 | (i3 != i4);
    r = (i1 * i2) & (i3 < i4);
    r = i1 / i2 | (i3 > i4);
    r = (i1 % i2) & (i3 <= i4);
    r = i1 & i2 | (i3 >= i4);
    r = (i1 | i2) & !i3;
    r = i1 ^ i2 | !(i3 + i4);
    r = (i1 << i2) & (!i3 < (i4 + i1));

    r = (i3 == i4) | (i1 + i2);
    r = (i3 != i4) & i1 - i2;
    r = (i3 < i4) | (i1 * i2);
    r = (i3 > i4) & i1 / i2;
    r = (i3 <= i4) | (i1 % i2);
    r = (i3 >= i4) & i1 & i2;
    r = !i3 | (i1 | i2);
    r = !(i3 + i4) & i1 ^ i2;
    r = (!i3 < (i4 + i1)) | (i1 << i2);

    r = (!i3 < (i4 + i1)) & (i3 == i4);
    r = !(i3 + i4) | (i3 != i4);
    r = !i3 & (i3 < i4);
    r = (i3 >= i4) | (i3 > i4);
    r = (i3 <= i4) & (i3 <= i4);
    r = (i3 > i4) | (i3 >= i4);
    r = (i3 < i4) & !i3;
    r = (i3 != i4) | !(i3 + i4);
    r = (i3 == i4) & (!i3 < (i4 + i1));

    return r;
}
