extern void *malloc(int);

int main(void)
{
    char *p;

    p = (char *) malloc(10);
    if (p == NULL) {
        return 2;
    }
    *p = (char) 1;

    p = (char *) malloc(10);
    if (p == NULL) {
        return 2;
    }
    else {
        *p = (char) 1;
    }

    p = (char *) malloc(10);
    if (p == NULL) {
        return 2;
    }
    else if (p == NULL) {
        *p = (char) 0;
    }
    else {
        *p = (char) 1;
    }

    *p = (char) 3;

    p = (char *) malloc(10);
    switch (p) {
    case NULL:
        return 4;
    default:
        *p = (char) 5;
    }

    return *p;
}
