enum Foo { FOO_A, FOO_B, FOO_C };
enum Bar { BAR_A = 1, BAR_B, BAR_C };
enum Baz { BAZ_A = 2, BAZ_B = 4, BAZ_C = 8 };

extern void func1(enum Foo f);
int func3(int i)
{
    const enum Foo foo = FOO_A;

    foo1(i);
    foo = i;
    foo = FOO_A + i;

    switch (i) {
    case FOO_A:
        return foo;
    case FOO_B:
        return FOO_B;
    case FOO_C:
        return i;
    default:
        return (int) BAR_A;
    }
}

enum Foo func2(const enum Foo param, const int i)
{
    enum Foo foo = BAR_A;
    enum Bar bar = BAZ_A;
    enum Baz baz = FOO_A;

    foo = FOO_A;
    bar = BAR_A;
    baz = BAZ_A;

    func3(foo);
    func3(BAR_A);
    func3((int) BAZ_C);

    switch (param) {
    case FOO_A:
        foo = BAR_A;
        func1(BAR_A);
        func1(1);
        func1(baz);
        foo = 1;
        foo = bar;
        return BAR_B;
    case BAR_B:
    case 5:
        foo = BAZ_C;
        func1(BAZ_C);
        func1(0x2);
        baz = BAZ_C;
        func1(baz);
        foo = 0x2;
        foo = baz;
        return BAZ_C;
    case 6:
        return FOO_A + 10;
    case 7:
        return FOO_A + i;
    case 8:
        return bar;
    case 9:
        baz = BAZ_C;
        return baz;
    case 10:
        return i;
    }

    return FOO_C;
}
