extern int bar(int *p);
extern int baz(const int *p);

void foo(int a, int b, int *c)
{
    {
        a = b * a++;
        a = bar(&a) * a++;
        b = bar(&a) * (a++ + --a);
    }

    {
        b = bar(&a) * a++;
        b = bar(&a) + baz(&a);
        b = baz(&a) - baz(&a);
    }

    {
        b = (a + 1) + a++;
        b = c[a] + c[++a];
        foo(a, a++, c);
        foo(a++, a, c);
        a = a + b;
        c[a] = a++ + b;
    }

    {
        b = bar(&a) * a;
        b = baz(&a) * a;
    }
}
