#ifndef STRING_H
#define STRING_H
#include <stddef.h>

typedef struct String
{
    char *data;
    size_t size;
    size_t capacity;
} String;

// string_init.c
String *string_init(void);
String *string_from_cstr(const char *str);
String *string_reset(String *string);
void string_free(String *string);

// string_data.c
size_t string_len(const String *string);

// string_io.c
void string_display(const String *string);
void string_debug(const String *string);

// string_cmp.c
int string_cmp(const String *string1, const String *string2);
int string_cmp_cstr(const String *string, const char *str);
int string_ncmp(const String *string1, const String *string2, size_t n);
int string_ncmp_cstr(const String *string, const char *str, size_t n);

// string_dup.c
String *string_dup(const String *string);
String *string_ndup(const String *string, size_t n);

#endif /* ! STRING_H */
