#include "multi_typedef_1.h"

typedef struct { int x, y; } Point;

#include "multi_typedef_2.h"

int main(void)
{
    Point p = { 1, 2 };
    return p.x;
}
