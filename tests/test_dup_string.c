#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../src/string/string.h"

TestSuite(dup_string);
TestSuite(dupn_string);

//=====================================DUP_STRING==============================

Test(dup_string, simple)
{
    String *string1 = init_string();
    String *string2 = dup_string(string1);

    int actual = cmp_string(string1, string2);
    int expected = 0;

    cr_expect(actual == expected);

    free_string(string1);
    free_string(string2);
}

Test(dup_string, normal)
{
    String *string1 = init_string_from_str("hello");
    String *string2 = dup_string(string1);

    int actual = cmp_string(string1, string2);
    int expected = 0;

    cr_expect(actual == expected);

    free_string(string1);
    free_string(string2);
}

Test(dup_string, null)
{
    String *string = dup_string(NULL);
    cr_expect(string == NULL);
}

//=====================================DUPN_STRING=============================

Test(dupn_string, simple)
{
    String *string1 = init_string_from_str("hello");
    String *string2 = dupn_string(string1, 3);

    int actual = cmpn_string(string1, string2, 3);
    int expected = 0;
    cr_expect(actual == expected);

    free_string(string1);
    free_string(string2);
}

Test(dupn_string, normal)
{
    String *string1 = init_string_from_str("hello");
    String *string2 = dupn_string(string1, 3);

    int actual = cmpn_string(string1, string2, 3);
    int expected = 0;
    cr_expect(actual == expected);
    actual = cmp_string(string1, string2);
    expected = 0;
    cr_expect(actual > expected);

    free_string(string1);
    free_string(string2);
}

Test(dupn_string, n_out_of_bound)
{
    String *string1 = init_string_from_str("hello");
    String *string2 = dupn_string(string1, 100);

    int actual = cmpn_string(string1, string2, 3);
    int expected = 0;
    cr_expect(actual == expected);
    actual = cmp_string(string1, string2);
    expected = 0;
    cr_expect(actual == expected);

    free_string(string1);
    free_string(string2);
}

Test(dupn_string, n_zero)
{
    String *string1 = init_string_from_str("hello");
    String *string2 = dupn_string(string1, 0);

    int actual = cmpn_string(string1, string2, 3);
    int expected = 0;
    cr_expect(actual > expected);
    actual = cmp_string(string1, string2);
    expected = 0;
    cr_expect(actual > expected);

    free_string(string1);
    free_string(string2);
}

Test(dupn_string, null)
{
    String *string = dup_string(NULL);
    cr_expect(string == NULL);
}
