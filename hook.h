#ifndef HOOK_H
#define HOOK_H
#include <stdio.h>
#ifdef __cplusplus
extern "C"
{
#endif
    typedef size_t (*fread_type)(void *__restrict ptr, size_t size, size_t n,
                                 FILE *__restrict stream);
    typedef size_t (*fwrite_type)(const void *__restrict __ptr, size_t __size,
                                  size_t __n, FILE *__restrict __s);
    typedef FILE *(*fopen_type)(const char *__restrict __filename,
                                const char *__restrict __modes);
    typedef int (*fclose_type)(FILE *__stream);
    typedef int (*fseek_type)(FILE *__stream, long int __off, int __whence);
    typedef long int (*ftell_type)(FILE *__stream);

    struct io_helper
    {
        fread_type fread;
        fwrite_type fwrite;
        fopen_type fopen;
        fclose_type fclose;
        fseek_type fseek;
        ftell_type ftell;
    };
    extern struct io_helper g_io_helper;

#define fread g_io_helper.fread
#define fwrite g_io_helper.fwrite
#define fopen g_io_helper.fopen
#define fclose g_io_helper.fclose
#define fseek g_io_helper.fseek
#define ftell g_io_helper.ftell

    typedef void *(*malloc_type)(size_t __size);
    extern malloc_type g_my_malloc;
#define malloc g_my_malloc
    typedef int (*posix_memalign_type)(void **__memptr, size_t __alignment,
                                       size_t __size);
    extern posix_memalign_type g_my_posix_memalign;
#define posix_memalign g_my_posix_memalign
    typedef void (*free_type)(void *__ptr);
    extern free_type g_my_free;
#define free g_my_free
    typedef void *(*calloc_type)(size_t, size_t);
    extern calloc_type g_my_calloc;
#define calloc g_my_calloc
#ifdef __cplusplus
}
#endif
#endif
