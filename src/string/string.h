#ifndef STRING_H
#define STRING_H
#include <stddef.h>

typedef struct String
{
    char *data;
    size_t size;
    size_t capacity;
} String;

//  init_string.c
String *init_string();
String *init_string_from_str(char *str);
String *reset_string(String *string);
void free_string(String *string);

//  print_string.c
void display_string(String *string);
void debug_string(String *string);

//  cmp_string.c
int cmp_string(String *string1, String *string2);
int cmp_string_with_str(String *string1, char *str);
int cmpn_string(String *string1, String *string2, size_t size);
int cmpn_string_with_str(String *string1, char *str, size_t size);

//  dup_string.c
String *dup_string(String *string);
String *dupn_string(String *string, size_t n);

#endif /* ! STRING_H */
