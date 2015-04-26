#include "intro_demo.h"
#include "useless_header.h"

static int foo(void)
{
    int i = rand();

    if (i < 0) {
        unsigned * const p = (unsigned *) malloc(sizeof(unsigned));
        unsigned int ui;

        if (p != NULL) {
            *p = 0U;
        }
        /* No malloc() error handling in the else branch */

        ui = *p;  /* Dereferencing a NULL pointer when malloc() failed */

        switch (i) {
        case -5:
            i = -1;
            ui = 0U;
            break;
        /* Control never reaches to this "case 10:" clause because "i" is less
           than 0 at this point */
        case 10:
            ui = 100U;
            break;
        default:
            ui = 0U;
            break;
        }

        /* Control never reaches to this if-body-statement because
         * usual-arithmetic-conversion makes "i < ui" into
         * "(unsigned int) i < ui" and then the value of "i" which is less than
         * 0 will be converted into a new value which is greater than 0 because
         * of the wrap-around.
         * So, the expression ("a value greater than 0" < 0) makes always false
         */
        if (i < ui) {
            /* exit() standard function terminates this execution path */
            exit(0);
        }
    }
    else {
        /* "i" is greater than or equal to 0 at this point */
        unsigned j = 10 / i;

        if (i < 1) {
            j = 3 / i;  /* "i" is equal to 0 at this point */
        }

        if (i <= 0x0FFFFFFF) {
            i <<= 3;
        }
        else {
            i = i << 1;  /* "i" is greater than or equal to 0x10000000 */
        }

        /* abort() standard function terminates this execution path */
        abort();
    }

    /* Control never reaches to this if-body-statement because "i" is less than
       0 and not equal to -5 at this point */
    if (i == -5) {
        abort();
    }

    return i;
}

static inline int bar(void) { return 0; }

int main(void) { return foo(); }
