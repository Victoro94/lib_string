#include "string.h"

/**
 *   @brief Return the length of a string.
 *   @param String * The string which length will be returned.
 *   @return size_t The length in size_t form.
 **/
size_t string_len(String *string)
{
    size_t result = 0;
    if (string)
        result = string->size;
    return result;
}