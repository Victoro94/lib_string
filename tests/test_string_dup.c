#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../src/string/string.h"

TestSuite(string_dup);
TestSuite(string_ndup);

// ==================================== string_dup
// ==============================

Test(string_dup, simple)
{
    String *string1 = string_init();
    String *string2 = string_dup(string1);

    int actual = string_cmp(string1, string2);
    int expected = 0;
    cr_expect(actual == expected);

    string_free(string1);
    string_free(string2);
}

Test(string_dup, normal)
{
    String *string1 = string_from_cstr("hello");
    String *string2 = string_dup(string1);

    int actual = string_cmp(string1, string2);
    int expected = 0;
    cr_expect(actual == expected);

    string_free(string1);
    string_free(string2);
}

Test(string_dup, null)
{
    String *string = string_dup(NULL);
    cr_expect(string == NULL);
}

// ==================================== string_ndup
// =============================

Test(string_ndup, simple)
{
    String *string1 = string_from_cstr("hello");
    String *string2 = string_ndup(string1, 3);

    int actual = string_ncmp(string1, string2, 3);
    int expected = 0;
    cr_expect(actual == expected);

    string_free(string1);
    string_free(string2);
}

Test(string_ndup, normal)
{
    String *string1 = string_from_cstr("hello");
    String *string2 = string_ndup(string1, 3);

    int actual = string_ncmp(string1, string2, 3);
    int expected = 0;
    cr_expect(actual == expected);
    actual = string_cmp(string1, string2);
    expected = 0;
    cr_expect(actual > expected);

    string_free(string1);
    string_free(string2);
}

Test(string_ndup, n_out_of_bound)
{
    String *string1 = string_from_cstr("hello");
    String *string2 = string_ndup(string1, 100);

    int actual = string_ncmp(string1, string2, 3);
    int expected = 0;
    cr_expect(actual == expected);
    actual = string_cmp(string1, string2);
    expected = 0;
    cr_expect(actual == expected);

    string_free(string1);
    string_free(string2);
}

Test(string_ndup, n_zero)
{
    String *string1 = string_from_cstr("hello");
    String *string2 = string_ndup(string1, 0);

    int actual = string_ncmp(string1, string2, 3);
    int expected = 0;
    cr_expect(actual > expected);
    actual = string_cmp(string1, string2);
    expected = 0;
    cr_expect(actual > expected);

    string_free(string1);
    string_free(string2);
}

Test(string_ndup, null)
{
    String *string = string_ndup(NULL, 5);
    cr_expect(string == NULL);
}
