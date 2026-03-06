#include "string/string.h"
#include <stdio.h>


int main(void)
{
    String* string = init_string();    
    debug_string(string);
    free_string(string);


    string = init_string_from_str("test string");    
    debug_string(string);
    free_string(string);
    return 0;
}
