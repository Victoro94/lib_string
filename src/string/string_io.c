#include <stdio.h>

#include "string.h"

/**
 *   @brief Print a String to stdout without a trailing newline.
 *   @param string The String to display.
 *   @details Prints "(empty string)" if size is 0, or "(null)" if @p string
 *   is NULL.
 **/
void string_display(const String *string)
{
    if (!string)
        return;
    if (string->size == 0)
        printf("(empty string)");
    else
        printf("%s", string->data);
    fflush(stdout);
}

/**
 *   @brief Print a String with its size and capacity (debug format).
 *   @param string The String to display, or NULL.
 *   @details Prints the content between quotes, followed by size and capacity
 *   on separate lines. Prints "(null)" if @p string is NULL.
 **/
void string_debug(const String *string)
{
    if (!string)
    {
        printf("(null)\n");
        return;
    }
    printf("String : \"");
    string_display(string);
    printf("\"\n");
    printf("size: %zu\n", string->size);
    printf("capacity: %zu\n", string->capacity);
}
