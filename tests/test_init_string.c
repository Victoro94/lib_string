#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../src/string/string.h"

TestSuite(init_string);
TestSuite(init_string_from_str);

//=====================================INIT_STRING=============================

Test(init_string, init_string)
{
    String *string = init_string();

    size_t actual_capacity = string->capacity;
    size_t expected_capacity = 1;
    cr_expect(actual_capacity == expected_capacity);

    size_t actual_size = string->size;
    size_t expected_size = 0;
    cr_expect(actual_size == expected_size);

    char actual_data = (string->data)[0];
    char expected_data = 0;
    cr_expect(actual_data == expected_data);
    free_string(string);
}

//=====================================INIT_STRING_FROM_STR====================

Test(init_string_from_str, normal)
{
    String *string = init_string_from_str("Hello world!");

    size_t actual_capacity = string->capacity;
    size_t expected_capacity = 13;
    cr_expect(actual_capacity == expected_capacity);

    size_t actual_size = string->size;
    size_t expected_size = 12;
    cr_expect(actual_size == expected_size);

    free_string(string);
}

Test(init_string_from_str, init_null)
{
    String *string = init_string_from_str(NULL);
    cr_expect(string->capacity == 1);
    cr_expect(string->size == 0);
    cr_expect(string->data[0] == 0);
    free_string(string);
}
