#include <string.h>

#include "string.h"

/**
 *   @brief Compare two Strings lexicographically.
 *   @return Negative if s1 < s2, 0 if equal, positive if s1 > s2.
 *   @details Both NULL returns 0. One NULL returns the signed value of the
 *   first character of the other.
 **/
int string_cmp(const String *string1, const String *string2)
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
 *   @brief Compare a String with a C string.
 *   @return Negative if s < str, 0 if equal, positive if s > str.
 **/
int string_cmp_cstr(const String *string, const char *str)
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
 *   @brief Compare the first n characters of two Strings.
 *   @return Negative, 0, or positive like strncmp.
 *   @details Returns 0 immediately if n == 0.
 **/
int string_ncmp(const String *string1, const String *string2, size_t n)
{
    if (n == 0)
        return 0;
    if (!string1 && !string2)
        return 0;
    if (!string1)
        return -(string2->data[0]);
    if (!string2)
        return string1->data[0];
    return strncmp(string1->data, string2->data, n);
}

/**
 *   @brief Compare the first n characters of a String with a C string.
 *   @return Negative, 0, or positive like strncmp.
 *   @details Returns 0 immediately if n == 0.
 **/
int string_ncmp_cstr(const String *string, const char *str, size_t n)
{
    if (n == 0)
        return 0;
    if (!string && !str)
        return 0;
    if (!string)
        return -(str[0]);
    if (!str)
        return string->data[0];
    return strncmp(string->data, str, n);
}
