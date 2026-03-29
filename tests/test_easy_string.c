#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "../src/string/string.h"

TestSuite(cmp_string);
TestSuite(cmp_string_with_str);
TestSuite(cmpn_string);
TestSuite(cmpn_string_with_str);

TestSuite(dup_string);
TestSuite(dupn_string);

//=====================================CMP_STRING==============================

int test_cmp_string(String* string1, String* string2)
{
    int res = cmp_string(string1,string2);
    free_string(string1);
    free_string(string2);
    return res;
}

Test(cmp_string, simple)
{
    int actual = test_cmp_string(init_string(),init_string());
    int expected = 0;
    cr_expect(actual == expected);
}

Test(cmp_string, left_null)
{
    int actual = test_cmp_string(NULL,init_string_from_str("a"));
    int expected = -97;
    cr_expect(actual == expected);
}

Test(cmp_string, right_null)
{

    int actual = test_cmp_string(init_string_from_str("a"),NULL);
    int expected = 97;
    cr_expect(actual == expected);
}

Test(cmp_string, negative)
{
    int actual = test_cmp_string(init_string_from_str("Hello "),
                                    init_string_from_str("world!"));
    int expected = 0;
    cr_expect(actual < expected);
}


Test(cmp_string, positive)
{
    int actual = test_cmp_string(init_string_from_str("world!"),
                                    init_string_from_str("Hello "));
    int expected = 0;
    cr_expect(actual > expected);
}


Test(cmp_string, equal)
{ 
    int actual = test_cmp_string(init_string_from_str("Hello"),
                                    init_string_from_str("Hello"));
    int expected = 0;
    cr_expect(actual == expected);
}

Test(cmp_string,double_null)
{ 
    int actual = cmp_string(NULL,NULL);
    int expected = 0;
    cr_expect(actual == expected);
}

//=====================================CMP_STRING_WITH_STR=====================

int test_cmp_string_with_str(String* string, char* str)
{
    int res = cmp_string_with_str(string, str);
    free_string(string);
    return res;
}

Test(cmp_string_with_str, simple)
{
    int actual = test_cmp_string_with_str(init_string(),"");
    int expected = 0;

    cr_expect(actual == expected);
}

Test(cmp_string_with_str,right_null)
{
    int actual = test_cmp_string_with_str(init_string_from_str("a"),NULL);
    int expected = 'a';

    cr_expect(actual == expected);
}

Test(cmp_string_with_str,left_null)
{
    int actual = cmp_string_with_str(NULL,"a");
    int expected = -('a');

    cr_expect(actual == expected);
}

Test(cmp_string_with_str,double_null)
{
    int actual = cmp_string_with_str(NULL, NULL);
    int expected = 0;

    cr_expect(actual == expected);
}

Test(cmp_string_with_str,equal)
{
    int actual = test_cmp_string_with_str(init_string_from_str("Hello"),
                                            "Hello");
    int expected = 0;

    cr_expect(actual == expected);
}

Test(cmp_string_with_str,positive)
{
    int actual = test_cmp_string_with_str(init_string_from_str("Hello"),
                                            "Hell");
    int expected = 0;

    cr_expect(actual > expected);
}

Test(cmp_string_with_str,negative)
{
    int actual = test_cmp_string_with_str(init_string_from_str("Hell"),
                                            "Hello");
    int expected = 0;

    cr_expect(actual < expected);
}

//=====================================CMPN_STRING=============================

int test_cmpn_string(String* string1, String* string2, size_t n)
{
    int res = cmpn_string(string1,string2,n);
    free_string(string1);
    free_string(string2);
    return res;
}

Test(cmpn_string, simple)
{
    String* string1 = init_string_from_str("hello");
    String* string2 = init_string_from_str("hello");

    int actual = test_cmpn_string(string1,string2,3);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(cmpn_string, left_null)
{
    String* string = init_string_from_str("hello");

    int actual = test_cmpn_string(NULL,string,5);
    int expected = -('h');
    cr_expect(actual == expected);
}

Test(cmpn_string, right_null)
{
    String* string = init_string_from_str("hello");

    int actual = test_cmpn_string(string,NULL,5);
    int expected = 'h';
    cr_expect(actual == expected);
}

Test(cmpn_string, double_null)
{
    int actual = cmpn_string(NULL,NULL,5);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(cmpn_string, n_zero)
{
    String* string1 = init_string_from_str("hello");
    String* string2 = init_string_from_str("hello");

    int actual = test_cmpn_string(string1,string2,0);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(cmpn_string, all_null_or_zero)
{
    int actual = test_cmpn_string(NULL,NULL,0);
    int expected = 0;
    cr_expect(actual == expected);
}


Test(cmpn_string, equal)
{
    String* string1 = init_string_from_str("hello");
    String* string2 = init_string_from_str("hello");

    int actual = test_cmpn_string(string1,string2,5);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(cmpn_string, n_out_of_bound)
{
    String* string1 = init_string_from_str("hello");
    String* string2 = init_string_from_str("hello");

    int actual = test_cmpn_string(string1,string2,100);
    int expected = 0;
    cr_expect(actual == expected);
}


//=====================================CMPN_STRING_WITH_STR====================


int test_cmpn_string_with_str(String* string, char* str, size_t n)
{
    int res = cmpn_string_with_str(string,str,n);
    free_string(string);
    return res;
}

Test(cmpn_string_with_str, simple)
{
    String* string = init_string_from_str("hello");
    int actual = test_cmpn_string_with_str(string,"hello",3);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(cmpn_string_with_str, left_null)
{
    int actual = test_cmpn_string_with_str(NULL,"hello",3);
    int expected = -'h';
    cr_expect(actual == expected);
}

Test(cmpn_string_with_str, right_null)
{
    String* string = init_string_from_str("hello");
    int actual = test_cmpn_string_with_str(string,NULL,3);
    int expected = 'h';
    cr_expect(actual == expected);
}

Test(cmpn_string_with_str, double_null)
{
    int actual = test_cmpn_string_with_str(NULL,NULL,3);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(cmpn_string_with_str, n_zero)
{
    String* string = init_string_from_str("hello");
    int actual = test_cmpn_string_with_str(string,"hello",0);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(cmpn_string_with_str, n_out_of_bound)
{
    String* string = init_string_from_str("hello");
    int actual = test_cmpn_string_with_str(string,"hello",100);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(cmpn_string_with_str, all_null_or_zero)
{
    int actual = test_cmpn_string_with_str(NULL,NULL,0);
    int expected = 0;
    cr_expect(actual == expected);
}

Test(cmpn_string_with_str, equal)
{
    String* string = init_string_from_str("hello");
    int actual = test_cmpn_string_with_str(string,"hello",5);
    int expected = 0;
    cr_expect(actual == expected);
}


//=====================================DUP_STRING==============================

Test(dup_string, simple)
{
    String* string1 = init_string();
    String* string2 = dup_string(string1);

    int actual = cmp_string(string1,string2);
    int expected = 0;

    cr_expect(actual == expected);

    free_string(string1);
    free_string(string2);
}

Test(dup_string, normal)
{
    String* string1 = init_string_from_str("hello");
    String* string2 = dup_string(string1);

    int actual = cmp_string(string1,string2);
    int expected = 0;

    cr_expect(actual == expected);

    free_string(string1);
    free_string(string2);
}

Test(dup_string, null)
{
    String* string = dup_string(NULL);
    cr_expect(string == NULL);
}

//=====================================DUPN_STRING=============================

Test(dupn_string, simple)
{
    String* string1 = init_string_from_str("hello");
    String* string2 = dupn_string(string1,3);

    int actual = cmpn_string(string1,string2,3);
    int expected = 0;
    cr_expect(actual == expected);

    free_string(string1);
    free_string(string2);
}

Test(dupn_string, normal)
{
    String* string1 = init_string_from_str("hello");
    String* string2 = dupn_string(string1,3);

    int actual = cmpn_string(string1,string2,3);
    int expected = 0;
    cr_expect(actual == expected);
    actual = cmp_string(string1,string2);
    expected = 0;
    cr_expect(actual > expected);

    free_string(string1);
    free_string(string2);
}

Test(dupn_string, n_out_of_bound)
{
    String* string1 = init_string_from_str("hello");
    String* string2 = dupn_string(string1,100);

    int actual = cmpn_string(string1,string2,3);
    int expected = 0;
    cr_expect(actual == expected);
    actual = cmp_string(string1,string2);
    expected = 0;
    cr_expect(actual == expected);

    free_string(string1);
    free_string(string2);
}

Test(dupn_string, n_zero)
{
    String* string1 = init_string_from_str("hello");
    String* string2 = dupn_string(string1,0);

    int actual = cmpn_string(string1,string2,3);
    int expected = 0;
    cr_expect(actual > expected);
    actual = cmp_string(string1,string2);
    expected = 0;
    cr_expect(actual > expected);

    free_string(string1);
    free_string(string2);
}

Test(dupn_string, null)
{
    String* string = dup_string(NULL);
    cr_expect(string == NULL);
}
