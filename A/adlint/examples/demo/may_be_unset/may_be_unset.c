static int j;

int func(int *p)
{
    int i;
    int k;

    if (p != NULL && *p < 0) {
        i = *p;
    }

    if (NULL != p && *p > 5) {
        i = *p;
    }

    if (p == NULL && *p == 0) {
        i = 0;
    }

    if (p && *p == rand()) {
        i = *p;
    }

    {
        struct Foo { int val; } *p = may_return_null();
        if (p && p->val == 0) {
            p->val = 1;
        }
    }

    k = j;

    return i * k;
}
