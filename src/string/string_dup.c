#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <string.h>

#include "string.h"

/**
 *   @brief Duplicate a String.
 *   @param string The String to duplicate.
 *   @return A newly allocated deep copy, or NULL if @p string is NULL.
 **/
String *string_dup(const String *string)
{
    if (!string)
        return NULL;
    return string_from_cstr(string->data);
}

/**
 *   @brief Duplicate the first n characters of a String.
 *   @param string The String to duplicate.
 *   @param n Maximum number of characters to copy.
 *   @return A newly allocated truncated copy, or NULL on failure.
 *   @details Uses strndup internally. If @p n exceeds the string length,
 *   the full string is duplicated.
 **/
String *string_ndup(const String *string, size_t n)
{
    if (!string)
        return NULL;
    char *tmp = strndup(string->data, n);
    if (!tmp)
        return NULL;
    String *result = string_from_cstr(tmp);
    free(tmp);
    return result;
}
