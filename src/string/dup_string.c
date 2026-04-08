#include <stdlib.h>
#include <string.h>

#include "string.h"

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