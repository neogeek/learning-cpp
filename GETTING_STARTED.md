# Getting Started

## Simple Hello World

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, world!\n";
}
```

### Using Namespace

```cpp
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello, world!\n";
}
```

### Using `endl`

_Using `std::endl` results in a performance hit because it not only returns a new line but flushes the output buffer._

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, world!" << std::endl;
}
```

## Compile and Run

```shell
$ g++ HelloWorld/main.cpp -o out && ./out
```

#### C++ 11

```bash
$ g++ -std=c++11 HelloWorld/main.cpp -o out && ./out
```

#### C++ 14

```bash
$ g++ -std=c++14 HelloWorld/main.cpp -o out && ./out
```

#### C++ 17

```bash
$ g++ -std=c++17 HelloWorld/main.cpp -o out && ./out
```
