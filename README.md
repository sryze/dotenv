dotenv
======

Example code:

```sh
FOO=hello
BAR=world
```

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
