#ifndef STRING_H
#define STRING_H
#include <stddef.h>

struct String 
{
    char* data;
    size_t size;
    size_t capacity;
};

struct String* init_string();
struct String* init_string_from_str(char* str);
void free_string();






#endif /* ! STRING_H */
