#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdio.h>
#include <stddef.h>

#include "../src/string/string.h"

TestSuite(init_string);

//=====================================INIT_STRING=============================

Test(init_string, init_simple)
{
    struct String* string = init_string();

    size_t actual_capacity = string -> capacity;
    size_t expected_capacity = 1;
    cr_expect(actual_capacity == expected_capacity);

    size_t actual_size = string -> size;
    size_t expected_size = 0;
    cr_expect(actual_size == expected_size);

    char actual_data = (string -> data)[0];
    char expected_data = 0;
    cr_expect(actual_data == expected_data);
    free_string(string);
}

