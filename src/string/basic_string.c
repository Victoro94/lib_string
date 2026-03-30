#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string.h"

/**
 *   init a struct String from nothing
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
 *   init a struct String from a char*
 *   if str is NULL the call is equivalent to init_string();
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
 *   reset the string given (equivalent of free_string and init_string())
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
 *   display the string on stdout
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
 *   print all the information on stdout
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
 *   free the struct string
 **/
void free_string(String *string)
{
    if (!string)
        return;
    free(string->data);
    free(string);
}
