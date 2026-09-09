# lib_string

A high-level `String` type for C: a `typedef struct String` with its lifecycle,
comparison, duplication and display functions, all `NULL`-safe.

## Structure

`String` is a heap-allocated buffer with its length and capacity tracked:

- `data` — the NUL-terminated character buffer
- `size` — current length, excluding the NUL byte
- `capacity` — allocated size, including the NUL byte

## Quick example

```c
#include "string/string.h"

String *s = string_from_cstr("hello");
string_debug(s);          /* String : "hello"  size: 5  capacity: 6 */
string_free(s);
```

## API

| Category    | Functions                                       |
|-------------|-------------------------------------------------|
| Lifecycle   | `string_init` `string_from_cstr` `string_reset` `string_free` |
| Accessors   | `string_len`                                    |
| Display     | `string_display` `string_debug`                 |
| Compare     | `string_cmp` `string_cmp_cstr` `string_ncmp` `string_ncmp_cstr` |
| Duplicate   | `string_dup` `string_ndup`                      |

- [all defined functions](globals_func.html)

## Build & test

```bash
make        # build the library and the demo
make check  # build and run the test suite
```

## License

MIT © 2026 Victor Tang