struct struct_tag {
    int i;
    int j;
};

union union_tag {
    int i;
    int j;
};

enum enum_tag { ONE = 1, TWO, THREE };

static void foo(void)
{
    struct struct_tag {};
    union union_tag {};
    enum enum_tag { A, B, C };
}
