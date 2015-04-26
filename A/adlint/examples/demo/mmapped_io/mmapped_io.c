extern volatile unsigned char *vptr;
extern unsigned char *ptr;

int main(void)
{
    unsigned short us;
    unsigned long ul;
    unsigned char *puc;

    vptr = (volatile unsigned char *) 0x1111U;
    ptr = (unsigned char *) 0x1111U;

    us = (unsigned short) vptr;
    ul = (unsigned long) vptr;
    us = (unsigned short) ptr;
    ul = (unsigned long) ptr;

    puc = (unsigned char *) 0x1111U;
    us = (unsigned short) puc;
    ul = (unsigned long) puc;

    return 0;
}
