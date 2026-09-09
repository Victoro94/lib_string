#include <stdio.h>

#include "string/string.h"

int main(void)
{
    String *string = string_init();
    string_debug(string);
    string_free(string);

    string = string_from_cstr("test string");
    string_debug(string);
    string_free(string);
    return 0;
}
