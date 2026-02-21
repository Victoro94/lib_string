#include "string/string.h"
#include <stdio.h>


int main(void)
{
    struct String* string = init_string();    
    printf("struct String :%s\n",string->data);
    free_string(string);


    struct String* str = init_string_from_str("test string");    
    printf("struct String :%s\n",str->data);
    free_string(str);
    return 0;
}
