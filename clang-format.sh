#!/bin/sh

ref_out=/tmp/ref_out.out
my_out=/tmp/my_out.out
good=0

is_clang_format() {
    clang-format "$1" >"$ref_out" 2>/dev/null
    cat "$1" >"$my_out" 2>/dev/null
    diff "$ref_out" "$my_out" >/tmp/null
    if [ $? -ne 0 ]; then
        echo "$1" "is not formatted"
        good=1
    fi
}

check_files() {
    cd "$1"
    for file in *; do
        if [ -d "$file" ]; then
            check_files "$file"
        elif test "${file##*.}" = "c" || test "${file##*.}" = "h"; then
            is_clang_format "$file"
        fi
    done
    cd ../
}

correct_files() {
    cd "$1"
    for file in *; do
        if [ -d "$file" ]; then
            correct_files "$file"
        elif test "${file##*.}" = "c" || test "${file##*.}" = "h" ; then
            clang-format -i "$file"
        fi
    done
    cd ../
}

if [ "$1" = "check" ]; then
    check_files .
    if [ $good -eq 0 ]; then 
        echo "All files are already formatted"
    fi
    exit "$good"
elif [ "$1" = "correct" ]; then
    correct_files .
    echo "All .c and .h files formatted !"
else 
    echo "usage: \n\t./clang-format check (to check files)\n\t./clang-format correct (to format files)"
fi
exit 0
