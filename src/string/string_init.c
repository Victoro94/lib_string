#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <string.h>

#include "string.h"

/**
 *   @brief Allocate a new empty String.
 *   @return A pointer to the newly allocated String, or NULL on failure.
 *   @details Allocates a String with data set to a single NUL byte,
 *   size 0 and capacity 1.
 **/
String *string_init(void)
{
    String *string = calloc(1, sizeof(String));
    if (!string)
        return NULL;
    string->data = calloc(1, sizeof(char));
    if (!string->data)
    {
        free(string);
        return NULL;
    }
    string->capacity = 1;
    return string;
}

/**
 *   @brief Allocate a new String initialized from a C string.
 *   @param str The source C string (may be NULL).
 *   @return A pointer to the newly allocated String, or NULL on failure.
 *   @details If @p str is NULL, the result is equivalent to string_init().
 **/
String *string_from_cstr(const char *str)
{
    if (!str)
        return string_init();
    size_t len = strlen(str);
    String *string = calloc(1, sizeof(String));
    if (!string)
        return NULL;
    string->data = calloc(len + 1, sizeof(char));
    if (!string->data)
    {
        free(string);
        return NULL;
    }
    memcpy(string->data, str, len + 1);
    string->size = len;
    string->capacity = len + 1;
    return string;
}

/**
 *   @brief Reset a String to an empty state.
 *   @param string The String to reset.
 *   @return The same pointer @p string, or NULL on failure.
 *   @details Resets size to 0, capacity to 1, and reallocates data.
 **/
String *string_reset(String *string)
{
    if (!string)
        return NULL;
    char *tmp = realloc(string->data, 1);
    if (!tmp)
        return NULL;
    string->data = tmp;
    string->data[0] = '\0';
    string->size = 0;
    string->capacity = 1;
    return string;
}

/**
 *   @brief Free a String and its internal buffer.
 *   @param string The String to free. Safe to call with NULL.
 **/
void string_free(String *string)
{
    if (!string)
        return;
    free(string->data);
    free(string);
}
