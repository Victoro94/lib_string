#include <stdlib.h>
#include <string.h>

#include "string.h"

// COMPARISON

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

// duplication

/**
 *   return a duplicate of the given string (newly allocated)
 **/
String *dup_string(String *string)
{
    if (string)
        return init_string_from_str(string->data);
    return NULL;
}

/**
 *   return a duplicate of the first n char of the given string
 **/
String *dupn_string(String *string, size_t n)
{
    if (!string)
        return NULL;
    char *tmp = strndup(string->data, n);
    String *res = init_string_from_str(tmp);
    free(tmp);
    return res;
}
