void foo(int arg1, int *arg2, int arg3)
{
    asm("movl %ecx, %eax");

    __asm__("movl %ecx, (%eax)");

    asm {
        xorl eax, eax
    }

    __asm__ volatile (
            "int $0x80"
            : "=a" (r)
              "+b" (arg1),
              "+c" (arg2),
              "+d" (arg3)
            : "a" (128)
            : "memory", "cc");
}

#define ASM1 asm("movl %ecx, %eax");

#define ASM2 __asm__("movl %ecx, (%eax)");

#define ASM3 asm { xorl eax, eax }

#define ASM4(arg1, arg2, arg3)   \
    __asm__ volatile (           \
	"int $0x80"              \
            : "=a" (r)           \
              "+b" (arg1),       \
              "+c" (arg2),       \
              "+d" (arg3)        \
            : "a" (128)          \
            : "memory", "cc");

void bar(int arg1, int *arg2, int arg3)
{
    ASM1;
    ASM2;
    ASM3;
    ASM4(arg1, arg2, arg3);
}
