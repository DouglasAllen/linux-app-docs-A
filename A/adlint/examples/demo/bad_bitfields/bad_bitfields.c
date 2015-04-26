struct foo {
    signed int b1:1;
    signed int   :1;
    int b2:1;
    int   :1;
};

struct bar {
    int a:5;
    unsigned int b:4;
    signed int c:3;
    int d:4;
    struct baz {
        int a:5;
        unsigned int b:4;
        signed int c:3;
        int d:4;
    } baz;
};

enum color { R = 0, G, B };

struct hoge {
    signed int a:3;
    unsigned int b:4;
    unsigned char c:6;
    unsigned short d:5;
    enum color e:2;
};

#define NBITS 3
enum { FOUR = 4 };

struct hage {
    unsigned int a:1;
    unsigned int b:2;
    unsigned int c:NBITS;
    unsigned int d:FOUR;
    struct hage *p;
};

void foo()
{
    struct foo f;
    f.b1 = 0;
    f.b1 = -1;
    f.b1 = 1;
}

void bar()
{
    const struct foo f;
    const int i = sizeof(f.b1);
}

void baz()
{
    const int i = { 0 };
    const int a1[] = { { 0, 0, 0 } };
    const int a2[][3] = { { 0, 0, 0 } };
    const struct bar b1 = { 0, 0, 0, 0, { 0, 0, 0, 0 } };
    const struct bar b2 = { { 0, 0, 0, 0, { 0, 0, 0, 0 } } };
    const struct bar b3[] = { { 0, 0, 0, 0, { 0, 0, 0, 0 } } };

    const int a3[4] = { 0 };
    const int a4[4] = { 1, 2, 3, 4 };
    const int a5[4] = { 1, 2, 3 };
    const int aa1[3][3] = { { 0 }, { 1, 2, 3 }, { 4, 5, 6 } };
    const int aa2[3][3] = { { 1 }, { 1, 2, 3 }, { 4, 5, 6 } };
    const int aa3[3][3] = { { 0, 1 }, { 1, 2, 3 }, { 4, 5, 6 } };
    const int aa4[3][3] = { { 0 + 1, 2 }, { 1, 2, 3 }, { 4, 5, 6 } };
    const int aa5[3][3] = { { 1, 2, 3 } };
    const int aa6[3][3] = { { { 0 } }, { 1, 2, 3 }, { 4, 5, 6 } };
}
