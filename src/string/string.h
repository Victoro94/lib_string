#ifndef STRING_H
#define STRING_H
#include <stddef.h>

typedef struct String 
{
    char* data;
    size_t size;
    size_t capacity;
} String;

// basic_string.c
String* init_string();
String* init_string_from_str(char* str);
void display_string(String* string);
void debug_string(String* string);
void free_string();

//easy_string.c
int cmp_string(String* string1, String* string2);
int cmp_string_with_char(String* string1, char* str);
int cmpn_string(String* string1, String* string2, size_t size);
int cmpn_string_with_char(String* string1, char* str, size_t size);



#endif /* ! STRING_H */
