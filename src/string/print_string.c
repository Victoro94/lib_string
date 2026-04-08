#include <stdio.h>

#include "string.h"

/**
 *   @brief Display the string on stdout.
 *   @details Display the given string to stdout without a newline.
 *   @param String * The string which will be displayed.
 *   @return void This function returns nothing.
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
 *   @brief Display all the information on stdout.
 *   @details Display the given string on stdout in a debug form. \n
 *   Displays the content, size and capacity.
 *   @return void This function returns nothing.
 *   @param String * The string which will be displayed.
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