#include "string.h"

#include <stdlib.h>
#include <string.h>

/**
 *   @brief Init a struct String and return it.
 *   @param void The function take no parameter.
 *   @details The function create a new struct string with an allocated data of
 *   size 1.\n Sets size to 0 and capacity to 1.
 *   @return String *
 *   @see Check on String implementation for more information.
 **/
String *init_string(void)
{
    String *string = calloc(1, sizeof(String));
    if (!string)
        return NULL;
    string->data = calloc(1, sizeof(char)); // \0 only never null
    if (!string->data)
        return NULL;
    string->capacity = 1;
    return string;
}

/**
 *   @brief Init a struct String from a char * and return it.
 *   @param char * The str to init with.
 *   @details If the param str is NULL, the call is equivalent to init_string().\n 
 *   Sets the size to strlen(str) and capacity to size + 1.
 *   @see Check on String implementation for more information.
 **/
String *init_string_from_str(char *str)
{
    if (!str)
        return init_string();
    String *string = calloc(1, sizeof(String));
    if (!string)
        return NULL;
    string->size = strlen(str);
    string->capacity = strlen(str) + 1;
    string->data = calloc(string->capacity, sizeof(char));
    if (!string->data)
        return NULL;
    string->data = strcpy(string->data, str);
    return string;
}

/**
 *   @brief Reset the string given.
 *   @details Set the size to 0, the capacity to 1 and data is reallocated.\n \n 
 *   The call is equivalent of free_string and init_string().
 *   @return String * The reseted String.
 **/
String *reset_string(String *string)
{
    if (string)
    {
        string->size = 0;
        string->capacity = 1;
        string->data = realloc(string->data, 1 * sizeof(char));
        string->data[0] = '\0';
    }
    return string;
}

/**
 *   @brief Free the struct string.
 *   @details Deallocate the given string.
 *   @param String * the string to deallocate.
 *   @return void this function returns nothing.
 **/
void free_string(String *string)
{
    if (!string)
        return;
    free(string->data);
    free(string);
}
