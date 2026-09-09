#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../src/string/string.h"

TestSuite(string_cmp);
TestSuite(string_cmp_cstr);
TestSuite(string_ncmp);
TestSuite(string_ncmp_cstr);

// ==================================== string_cmp
// ==============================

int test_string_cmp(String *string1, String *string2)
{
    int res = string_cmp(string1, string2);
    string_free(string1);
    string_free(string2);
    return res;
}

Test(string_cmp, simple)
{
    int actual = test_string_cmp(string_init(), string_init());
    int expected = 0;
    cr_expect(actual == expected);
}

Test(string_cmp, left_null)
{
    int actual = test_string_cmp(NULL, string_from_cstr("a"));
    int expected = -97;
    cr_expect(actual == expected);
}

Test(string_cmp, right_null)
{
    int actual = test_string_cmp(string_from_cstr("a"), NULL);
    int expected = 97;
    cr_expect(actual == expected);
}

Test(string_cmp, negative)
{
    int actual =
        test_string_cmp(string_from_cstr("Hello "), string_from_cstr("world!"));
    int expected = 0;
    cr_expect(actual < expected);
}

Test(string_cmp, positive)
{
    int actual =
        test_string_cmp(string_from_cstr("world!"), string_from_cstr("Hello "));
    int expected = 0;
    cr_expect(actual > expected);
}

Test(string_cmp, equal)
{
    int actual =
        test_string_cmp(string_from_cstr("Hello"), string_from_cstr("Hello"));
    int expected = 0;
    cr_expect(actual == expected);
}

Test(string_cmp, double_null)
{
    int actual = string_cmp(NULL, NULL);
    int expected = 0;
    cr_expect(actual == expected);
}

// ==================================== string_cmp_cstr
// =========================

int test_string_cmp_cstr(String *string, const char *str)
{
    int res = string_cmp_cstr(string, str);
    string_free(string);
    return res;
}

Test(string_cmp_cstr, simple)
{
    int actual = test_string_cmp_cstr(string_init(), "");
    int expected = 0;
    cr_expect(actual == expected);
}

Test(string_cmp_cstr, right_null)
{
    int actual = test_string_cmp_cstr(string_from_cstr("a"), NULL);
    int expected = 'a';
    cr_expect(actual == expected);
}

Test(string_cmp_cstr, left_null)
{
    int actual = string_cmp_cstr(NULL, "a");
    int expected = -('a');
    cr_expect(actual == expected);
}

Test(string_cmp_cstr, double_null)
{
    int actual = string_cmp_cstr(NULL, NULL);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(string_cmp_cstr, equal)
{
    int actual = test_string_cmp_cstr(string_from_cstr("Hello"), "Hello");
    int expected = 0;
    cr_expect(actual == expected);
}

Test(string_cmp_cstr, positive)
{
    int actual = test_string_cmp_cstr(string_from_cstr("Hello"), "Hell");
    int expected = 0;
    cr_expect(actual > expected);
}

Test(string_cmp_cstr, negative)
{
    int actual = test_string_cmp_cstr(string_from_cstr("Hell"), "Hello");
    int expected = 0;
    cr_expect(actual < expected);
}

// ==================================== string_ncmp
// =============================

int test_string_ncmp(String *string1, String *string2, size_t n)
{
    int res = string_ncmp(string1, string2, n);
    string_free(string1);
    string_free(string2);
    return res;
}

Test(string_ncmp, simple)
{
    String *string1 = string_from_cstr("hello");
    String *string2 = string_from_cstr("hello");

    int actual = test_string_ncmp(string1, string2, 3);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(string_ncmp, left_null)
{
    String *string = string_from_cstr("hello");

    int actual = test_string_ncmp(NULL, string, 5);
    int expected = -('h');
    cr_expect(actual == expected);
}

Test(string_ncmp, right_null)
{
    String *string = string_from_cstr("hello");

    int actual = test_string_ncmp(string, NULL, 5);
    int expected = 'h';
    cr_expect(actual == expected);
}

Test(string_ncmp, double_null)
{
    int actual = string_ncmp(NULL, NULL, 5);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(string_ncmp, n_zero)
{
    String *string1 = string_from_cstr("hello");
    String *string2 = string_from_cstr("hello");

    int actual = test_string_ncmp(string1, string2, 0);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(string_ncmp, all_null_or_zero)
{
    int actual = test_string_ncmp(NULL, NULL, 0);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(string_ncmp, equal)
{
    String *string1 = string_from_cstr("hello");
    String *string2 = string_from_cstr("hello");

    int actual = test_string_ncmp(string1, string2, 5);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(string_ncmp, n_out_of_bound)
{
    String *string1 = string_from_cstr("hello");
    String *string2 = string_from_cstr("hello");

    int actual = test_string_ncmp(string1, string2, 100);
    int expected = 0;
    cr_expect(actual == expected);
}

// ==================================== string_ncmp_cstr
// ========================

int test_string_ncmp_cstr(String *string, const char *str, size_t n)
{
    int res = string_ncmp_cstr(string, str, n);
    string_free(string);
    return res;
}

Test(string_ncmp_cstr, simple)
{
    String *string = string_from_cstr("hello");
    int actual = test_string_ncmp_cstr(string, "hello", 3);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(string_ncmp_cstr, left_null)
{
    int actual = test_string_ncmp_cstr(NULL, "hello", 3);
    int expected = -'h';
    cr_expect(actual == expected);
}

Test(string_ncmp_cstr, right_null)
{
    String *string = string_from_cstr("hello");
    int actual = test_string_ncmp_cstr(string, NULL, 3);
    int expected = 'h';
    cr_expect(actual == expected);
}

Test(string_ncmp_cstr, double_null)
{
    int actual = test_string_ncmp_cstr(NULL, NULL, 3);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(string_ncmp_cstr, n_zero)
{
    String *string = string_from_cstr("hello");
    int actual = test_string_ncmp_cstr(string, "hello", 0);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(string_ncmp_cstr, n_out_of_bound)
{
    String *string = string_from_cstr("hello");
    int actual = test_string_ncmp_cstr(string, "hello", 100);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(string_ncmp_cstr, all_null_or_zero)
{
    int actual = test_string_ncmp_cstr(NULL, NULL, 0);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(string_ncmp_cstr, equal)
{
    String *string = string_from_cstr("hello");
    int actual = test_string_ncmp_cstr(string, "hello", 5);
    int expected = 0;
    cr_expect(actual == expected);
}
