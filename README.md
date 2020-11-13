dotenv
======

[![Build Status][build_status]][build]

Example code:

```c++
#include <iostream>
#include "dotenv.h"

int main() {
    dotenv::load();

    auto foo = dotenv::get("FOO");
    std::cout << "FOO = " << foo << std::endl;

    // It also works with getenv() from the standard library:
    auto bar = getenv("BAR");
    if (bar != nullptr) {
        std::cout << "BAR = " << bar << std::endl;
    }
}
```

In your .env file:

```sh
FOO=hello
BAR=world
```

[build]: https://travis-ci.org/sryze/dotenv
[build_status]: https://travis-ci.org/sryze/dotenv.svg?branch=master
