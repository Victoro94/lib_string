#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../src/string/string.h"

TestSuite(string_init);
TestSuite(string_from_cstr);

// ==================================== string_init
// =============================

Test(string_init, string_init)
{
    String *string = string_init();

    size_t actual_capacity = string->capacity;
    size_t expected_capacity = 1;
    cr_expect(actual_capacity == expected_capacity);

    size_t actual_size = string->size;
    size_t expected_size = 0;
    cr_expect(actual_size == expected_size);

    char actual_data = (string->data)[0];
    char expected_data = 0;
    cr_expect(actual_data == expected_data);
    string_free(string);
}

// ==================================== string_from_cstr
// ========================

Test(string_from_cstr, normal)
{
    String *string = string_from_cstr("Hello world!");

    size_t actual_capacity = string->capacity;
    size_t expected_capacity = 13;
    cr_expect(actual_capacity == expected_capacity);

    size_t actual_size = string->size;
    size_t expected_size = 12;
    cr_expect(actual_size == expected_size);

    string_free(string);
}

Test(string_from_cstr, from_cstr_null)
{
    String *string = string_from_cstr(NULL);
    cr_expect(string->capacity == 1);
    cr_expect(string->size == 0);
    cr_expect(string->data[0] == 0);
    string_free(string);
}
