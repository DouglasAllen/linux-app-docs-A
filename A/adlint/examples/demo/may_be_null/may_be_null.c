#define NULL (0)

extern int *may_return_null(void);
extern int rand(void);

int main(void)
{
    int i;
    int *p = NULL;

    i = *(int *)(NULL);

    *p = 1; /* p is obviously NULL */

    p = may_return_null();

    *p = 2; /* p is NULL when may_return_null() returns NULL */

    if (rand() == 1) {
        p = &i;
        *p = 3; /* p points to i in this path */
    }

    *p = 4; /* p is NULL when rand() returns != 1 */

    switch (rand()) {
    case 0:
        p = &i;
        break;
    case 1:
        p = NULL;
        break;
    default:
        return 0;
    }

    *p = 5; /* p is NULL when rand() returns 1 */

    for (i = 0; i < rand(); ++i) {
        p = &i;
    }

    *p = 6; /* p is NULL when rand() returns 0 */

    while (rand() < 1) {
        p = &i;
    }

    *p = 7; /* p is NULL when rand() returns >= 1 */

    return *p;
}
