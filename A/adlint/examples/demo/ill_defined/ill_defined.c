#define FOO 1

#if defined(FOO)
int i;
#endif

#if defined FOO
int ii;
#endif

#if defined "FOO"
int iii;
#endif
