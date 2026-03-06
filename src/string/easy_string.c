#include "string.h"
#include <string.h>

int cmp_string(String* string1, String* string2)
{
    if (!string1 && !string2)
        return 0;
    if (!string1)
        return string2 -> data[0];
    if (!string2)
        return string1 -> data[0];
    return strcmp(string1 -> data, string2 -> data);
}

int cmp_string_with_char(String* string, char* str)
{
    if (!string && !str)
        return 0;
    if (!string)
        return str[0];
    if (!str)
        return string -> data[0];
    return strcmp(string -> data, str);
}

int cmpn_string(String* string1, String* string2, size_t size)
{ 
    if (!string1 && !string2)
        return 0;
    if (!string1)
        return string2 -> data[0];
    if (!string2)
        return string1 -> data[0];
    return strncmp(string1 -> data, string2 -> data, size);
}

int cmpn_string_with_char(String* string, char* str, size_t size)
{
    if (!string && !str)
        return 0;
    if (!string)
        return str[0];
    if (!string)
        return string -> data[0];
    return strncmp(string -> data, str, size);
}
