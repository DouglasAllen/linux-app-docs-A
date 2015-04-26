#line

#line 35000 "bad_line.c"

#line 35 * 100

#line 35 * 100 "bad_line.c"

#line 35 L"あいう.c"

#line __LINE__ __FILE__

#define THIS_FILE __FILE__
#define LINE 35

#line LINE THIS_FILE

#undef LINE
#define LINE 35000

#line LINE THIS_FILE

#line __FILE__ 35

#line LINE1000

#pragma
