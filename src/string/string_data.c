#include "string.h"

/**
 *   @brief Return the length of a String.
 *   @param string The String to measure.
 *   @return The number of characters (excluding NUL), or 0 if @p string is
 *NULL.
 **/
size_t string_len(const String *string)
{
    if (!string)
        return 0;
    return string->size;
}
