#include <math.h>
#include <stdlib.h>

static int CalledRecursively(void);

static int Function(void)
{
    return CalledRecursively();
}

static void OutputByParam(int **param)
{
    int result = Function() + rand();
    *param = &result;
}

static int CalledRecursively(void)
{
    int *result;
    OutputByParam(&result);
    return *result;
}

int main(int argc, char *argv[])
{
    int i;
    int *ptr = NULL;

    if (argc < 2) {
        return *ptr;
    }

    if (rand() == 1) {
        ptr = &i;
        *ptr = CalledRecursively();
    }
    *ptr = 2;

    return 0;
}
