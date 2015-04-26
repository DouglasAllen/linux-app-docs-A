struct Point {
    int x;
    int y;
};

typedef struct {
    int r;
    int g;
    int b;
} Color;

extern void foo(struct Point);
extern void bar(int, struct Point);
extern void baz(int, Color, int);

int main(void)
{
    struct Point point = { 1, 2 };
    Color color = { 0, 1, 2 };

    foo(point);
    bar(0, point);
    baz(0, color, 1);

    return 0;
}
