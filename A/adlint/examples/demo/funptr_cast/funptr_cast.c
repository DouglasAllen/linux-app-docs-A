#pragma once
#pragma twice
#pragma omp parallel

typedef int (*compatible_funptr)();

typedef int (*incompatible_funptr1)(int);
typedef void (*incompatible_funptr2)();
typedef long (*incompatible_funptr3)(char *);

int main(void)
{
    compatible_funptr p1 = (compatible_funptr) &main;
    const int i = 0;

    incompatible_funptr1 p2 = (incompatible_funptr1) &main;
    incompatible_funptr2 p3 = (incompatible_funptr2) &main;
    incompatible_funptr3 p4 = (incompatible_funptr3) main;

    void (*p5)(int) = (void (*)(int)) &main;

    void (*p6)() = (void (*)()) i;
    const int j = (int) &main;

    return 0;
}
