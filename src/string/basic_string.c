#include "string.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/** 
*   return the nearest higher power of 2
**/   
static size_t get_new_size(size_t size)
{
    size_t result = 2;
    while (result<=size)
        result*=2;
    return result;
}

/**
*   init a struct String from nothing
**/
String* init_string(void)
{
    String* string = calloc(1,sizeof(String));
    if (! string)
        return NULL;
    string -> data = calloc(1, sizeof(char)); // \0 only never null
    if (! string -> data)
        return NULL;
    string -> capacity = 1;
    return string;
}

/** 
*   init a struct String from a char*
**/ 
String* init_string_from_str(char* str)
{
    if(!str)
        return NULL;
    String* string = calloc(1,sizeof(String));
    if (! string)
        return NULL;
    string -> size = strlen(str);
    string -> capacity = get_new_size(strlen(str));
    string -> data = calloc(string->capacity, sizeof(char));
    if (! string -> data)
        return NULL;
    string -> data = strcpy(string -> data, str);
    return string;
}


/**
*   display the string on stdout
**/
void display_string(String* string)
{
    if (!string)
        return;
    if (string->size == 0)
        printf("(empty string)");
    else 
        printf("%s",string-> data);
    fflush(stdout);
}

/**
*   print all the information on stdout
**/
void debug_string(String* string)
{   
    if (string)
    {
        printf("String : \"");
        display_string(string);
        printf("\"\n");
        printf("size: %lu\n",string -> size);
        printf("capacity: %lu\n",string -> capacity);
    }
    else
        printf("(null)\n");
}
/**
*   free the struct string
**/
void free_string(String* string)
{
    if (!string)
        return;
    free(string -> data);
    free(string);
}
