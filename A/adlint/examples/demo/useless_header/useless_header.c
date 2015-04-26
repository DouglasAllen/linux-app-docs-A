#include "useless_header_1.h"
#include "useless_header_3.h"
#include "useless_header_4.h" /* contents never referred in this file */

int main(void)
{
    const Color color = { 0xFFU, 0x55U, 0xAAU };
    return (int) (color.r | color.g | color.b);
}
