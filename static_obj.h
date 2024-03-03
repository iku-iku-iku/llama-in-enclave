#define STATIC_OBJ_DEF_BEGIN(TYPE, NAME) \
static TYPE& NAME ## _() { \
    static char NAME ## MEM[sizeof(TYPE)]; \
    static bool __inited_ ## NAME = false; \
    static TYPE* NAME = 0; \
    if (__inited_ ## NAME == false) { \
        NAME = new (NAME ## MEM) TYPE; \
        __inited_ ## NAME = true; \
        *NAME =
#define STATIC_OBJ_DEF_END(TYPE, NAME) \
    } \
    return *NAME; \
}

