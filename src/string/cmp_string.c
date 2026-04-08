#include "string.h"

#include <string.h>

/**
 *   compare the two given strings
 **/
int cmp_string(String *string1, String *string2)
{
    if (!string1 && !string2)
        return 0;
    if (!string1)
        return -(string2->data[0]);
    if (!string2)
        return string1->data[0];
    return strcmp(string1->data, string2->data);
}

/**
 *   compare a string with a char*
 **/
int cmp_string_with_str(String *string, char *str)
{
    if (!string && !str)
        return 0;
    if (!string)
        return -(str[0]);
    if (!str)
        return string->data[0];
    return strcmp(string->data, str);
}

/**
 *   compare the n first char of the two given string
 **/
int cmpn_string(String *string1, String *string2, size_t n)
{
    if (!string1 && !string2)
        return 0;
    if (!string1)
        return -(string2->data[0]);
    if (!string2)
        return string1->data[0];
    return strncmp(string1->data, string2->data, n);
}

/**
 *   compare the n first char between a string and a char*
 **/
int cmpn_string_with_str(String *string, char *str, size_t n)
{
    if (!string && !str)
        return 0;
    if (!string)
        return -(str[0]);
    if (!str)
        return string->data[0];
    return strncmp(string->data, str, n);
}