dotenv
======

Example:

```c++
#include "dotenv.h"

int main() {
    dotenv::load(".env");

    auto var = dotenv::get("VAR");
    std::cout << var << std::endl;

    // Also works with C standard library:
    var = getenv("VAR");
    std::cout << var << std::endl;
}
```
