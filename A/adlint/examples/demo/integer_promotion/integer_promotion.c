/* ADLINT:TUNIT:[-W0118,-W0414,-W0425,-W0947,-W0948] */

#define EOF (-1)

extern int getchar(void);
extern int printf(const char *, ...);

int main(void)
{
    unsigned char c; /* ADLINT::[-W0100] */

    while ((c = getchar()) != EOF) {
	if ((int) c != '\n') printf("%d\n", (int) c);
    }

    return 0;
}
