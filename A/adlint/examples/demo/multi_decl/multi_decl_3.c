#include "multi_decl_1.h"
#include "multi_decl_2.h"

extern int Hoge;

struct Hoge {
    int i;
    int HogeHoge;
};

typedef struct HogeHoge {
    int Hoge;
    int HogeHoge;
} HogeHoge;

static int Hoge;

int main(void)
{
Hoge:
    return baz();
}
