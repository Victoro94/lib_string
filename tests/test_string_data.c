#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../src/string/string.h"

TestSuite(string_len);
TestSuite(string_reset);

// ==================================== string_len
// ==============================

Test(string_len, normal)
{
    String *string = string_from_cstr("hello");
    cr_expect(string_len(string) == 5);
    string_free(string);
}

Test(string_len, empty)
{
    String *string = string_init();
    cr_expect(string_len(string) == 0);
    string_free(string);
}

Test(string_len, null)
{
    cr_expect(string_len(NULL) == 0);
}

Test(string_len, long_string)
{
    String *string = string_from_cstr("a very long string indeed");
    cr_expect(string_len(string) == 25);
    string_free(string);
}

// ==================================== string_reset
// ============================

Test(string_reset, normal)
{
    String *string = string_from_cstr("hello");
    cr_expect(string_len(string) == 5);
    String *result = string_reset(string);
    cr_expect(result == string);
    cr_expect(string_len(string) == 0);
    cr_expect(string->capacity == 1);
    cr_expect(string->data[0] == '\0');
    string_free(string);
}

Test(string_reset, null)
{
    String *result = string_reset(NULL);
    cr_expect(result == NULL);
}

Test(string_reset, already_empty)
{
    String *string = string_init();
    String *result = string_reset(string);
    cr_expect(result == string);
    cr_expect(string_len(string) == 0);
    cr_expect(string->capacity == 1);
    string_free(string);
}

Test(string_reset, reuse_after_reset)
{
    String *string = string_from_cstr("hello");
    string_reset(string);
    String *new_string = string_from_cstr("world");
    string->data = realloc(string->data, 6);
    string->size = 5;
    string->capacity = 6;
    memcpy(string->data, "world", 6);
    cr_expect(string_cmp(string, new_string) == 0);
    string_free(string);
    string_free(new_string);
}
