int main(void)
{
    for (int i = 0; i < 10; i++) {
        if (i == 1) {
            break;
        }
        switch (i) {
        case 5:
            break;
        default:
            break;
        }
        if (i == 6) {
            break;
        }
    }

    while (1) {
        if (rand() == 1) {
            break;
        }
        do {
            if (rand() == 2) {
                break;
            }
        } while (1);
        if (rand() == 3) {
            break;
        }
    }

    return 0;
}
