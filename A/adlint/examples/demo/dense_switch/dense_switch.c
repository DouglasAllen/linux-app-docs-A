int main(void)
{
    const int i = rand();
    int j;

    switch (i) {
    case 0:
        j = 3 / i;
    case 1:
        j = 3 / i;
        if (i == 0)
            case 3: j = 3 / i;
        if (i == 0 || i == 1) {
            case 2: j = 3 / i;
        }
        else {
            __adlint__inspect(i);
            j = 3 / i;
        }
        switch (i) {
        default:
            j = 3 / i;
            break;
        case 0:
            j = 3 / i;
        case 1:
            j = 3 / i;
        }
        break;
    default:
        j = 3 / i;
    }

    switch (i) {
    case 0:
        if (i < j) {
            break;
        }
        while (i > j) {
            break;
        }
        j += i;
        break;
    default:
        switch (i) {
        default:
            j = 3 / i;
            break;
        case 1:
            if (i < j) {
                break;
            }
            if (i < j + 1) {
                break;
            }
            j += i;
            break;
        }
    }

    return j;
}
