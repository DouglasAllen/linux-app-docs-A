void __fundecl(void);
extern void _FUNDECL(void);
static void _fundecl(void);

extern int __vardecl;
extern int _VARDECL;
static int _vardecl;

int __vardef = 0;
extern int _VARDEF = 0;
static int _vardef = 0;

int __ansi_fundef(const int __param, const int _PARAM, const int _param)
{
    return __param + _PARAM + _param;
}

int _ANSI_FUNDEF(const int __param, const int _PARAM, const int _param)
{
    return __param + _PARAM + _param;
}

static _ansi_fundef(const int __param, const int _PARAM, const int _param)
{
    return __param + _PARAM + _param;
}

int __kandr_fundef(__param, _PARAM, _param)
    const int __param;
    const int _PARAM;
    const int _param;
{
    return __param + _PARAM + _param;
}

int _KANDR_FUNDEF(__param, _PARAM, _param)
    const int __param;
    const int _PARAM;
    const int _param;
{
    return __param + _PARAM + _param;
}

static int _kandr_fundef(__param, _PARAM, _param)
    const int __param;
    const int _PARAM;
    const int _param;
{
    return __param + _PARAM + _param;
}

typedef int __typedef;
typedef int _TYPEDEF;
typedef int _typedef;

struct __struct_tag {
    int i;
};
struct _STRUCT_TAG {
    int i;
};
struct _struct_tag {
    int i;
};

union __union_tag {
    int i;
};
union _UNION_TAG {
    int i;
};
union _union_tag {
    int i;
};

enum __enum_tag { __enum, _ENUM, _enum };
enum _ENUM_TAG { __enum, _ENUM, _enum };
enum _enum_tag { __enum, _ENUM, _enum };

typedef struct __struct_tag_ {
    int i;
} __struct_tag_t;
typedef struct _STRUCT_TAG_ {
    int i;
} _STRUCT_TAG_t;
typedef struct _struct_tag_ {
    int i;
} _struct_tag_t;

typedef struct {
    int i;
} __unnamed_t;
typedef struct {
    int i;
} _UNNAMED_T;
typedef struct {
    int i;
} _unnamed_t;
