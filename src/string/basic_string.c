#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string.h"

/**
 *   @brief init a struct String and return it.
 *   @param void the function take no parameter.
 *   @details the function create a new struct string with an allocated data of
 *   size 1. sets size to 0 and capacity to 1.
 *   @return String *
 *   @see check on String for more information.
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
 *   @brief init a struct String from a char* and return it.
 *   @param char * the str to init with.
 *   @details if the param str is NULL the call is equivalent to init_string();
 *   sets the size to strlen(str) and capacity to size + 1.
 *   @see check on String for more information.
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
 *   @brief return the size of a string
 *   @param String * the string which length will be returned.
 *   @return size_t the length in size_t form.
 **/
size_t string_len(String *string)
{
    size_t result = 0;
    if (string)
        result = string->size;
    return result;
}

/**
 *   @brief reset the string given
 *   @details set the size to 0, the capacity to 1 and data is reallocated.
 *   the call is equivalent of free_string and init_string()
 *   @return String * the reseted String
 **/
String *reset_string(String *string)
{
    string->size = 0;
    string->capacity = 1;
    string->data = realloc(string->data, 1 * sizeof(char));
    string->data[0] = '\0';
    return string;
}

/**
 *   @brief display the string on stdout
 *   @details display the given string to stdout without a newline
 *   @param String * the string which will be displayed
 *   @return this function returns nothing
 **/
void display_string(String *string)
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
 *   @brief display all the information on stdout
 *   @details display the given string on stdout
 *   @return this function returns nothing
 *   @param String * the string which will be displayed
 **/
void debug_string(String *string)
{
    if (string)
    {
        printf("String : \"");
        display_string(string);
        printf("\"\n");
        printf("size: %lu\n", string->size);
        printf("capacity: %lu\n", string->capacity);
    }
    else
        printf("(null)\n");
}

/**
 *   @brief free the struct string
 *   @details deallocate the given string
 *   @param String * the string to deallocate
 *   @return this function returns nothing
 **/
void free_string(String *string)
{
    if (!string)
        return;
    free(string->data);
    free(string);
}
