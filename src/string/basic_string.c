#include "string.h"
#include <string.h>
#include <stdlib.h>

/** 
*   return the nearest higher power of 2
**/   
size_t get_new_size(size_t size)
{
    size_t result = 2;
    while (result<=size)
        result*=2;
    return result;
}

/**
*   init a struct String from nothing
**/
struct String* init_string(void)
{
    struct String* string = calloc(1,sizeof(struct String));
    string -> data = calloc(1, sizeof(char)); // \0 only never null
    string -> capacity = 1;
    return string;
}

/** 
*   init a struct String from a char*
**/ 
struct String* init_string_from_str(char* str)
{
    if(!str)
        return NULL;
    struct String* string = calloc(1,sizeof(struct String));
    string -> size = strlen(str);
    string -> capacity = get_new_size(strlen(str));
    string -> data = calloc(string->capacity, sizeof(char));
    string -> data = strcpy(string -> data, str);
    return string;
}


/**
*   free the struct string
**/
void free_string(struct String* string)
{
    if (!string)
        return;
    free(string -> data);
    free(string);
}
