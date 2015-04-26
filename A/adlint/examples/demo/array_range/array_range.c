static int foo(const int i)
{
    int array[10] = { 0 };
    int j;

    j = array[5];
    j = array[10];

    if (i < 5) {
        j = array[i];
    }

    if (i > 5) {
        j = array[i];
    }

    if (i < 0) {
        j = array[i];
    }

    if (i > 9) {
        j = array[i];
    }

    j = array[i];


    for (j = 0; j < 10; j++) {
        array[j] = 0;
        array[j + 1] = 0;
        if (j == 10) {
            break;
        }
        if (j < 0) {
            break;
        }
    }

    for (j = 9; j >= 0; j--) {
        array[j] = 0;
        array[j - 1] = 0;
        if (j < 0) {
            break;
        }
        if (j > 9) {
            break;
        }
    }

    for (j = 0; j != 10; j++) {
        array[j] = 0;
        array[j + 1] = 0; /* ADLINT::[-W0723] */
        if (j == 10) {
            break;
        }
        if (j < 0) {
            break;
        }
    }

    return j;
}
