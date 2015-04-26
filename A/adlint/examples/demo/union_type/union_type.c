struct event {
    int type;
    union {
        void *p;
        int i;
    } body;
};

union foo {
    int i;
    unsigned short s;
};

union bar {
    unsigned int a;
    float b;
};

struct baz {
    union {
	unsigned long a;
	double b;
    } u;
    unsigned long a;
};

int main(void)
{
    struct event e1;
    const struct event e2 = {0, 0};
    union foo u1;

    e1.body.i = 0;

    return e2.body.i;
}
