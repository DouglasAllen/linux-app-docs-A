// line comment

/*
// block comment
 */

extern int foo(int, /* hoge */ long); // line comment

int main(void)
{
    return foo(0, 1L); // line comment
} // end of main
