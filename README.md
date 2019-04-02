# Learning C++

## TOC

- [Variables](#variables)
    - [Initialization](#initialization)
    - [Integers](#integers)
    - [Floats](#floats)
    - [Strings](#strings)
    - [Booleans](#booleans)
    - [Dynamic Types](#dynamic-types)
    - [Auto Types](#auto-types)
    - [Typedefs](#typedefs)
    - [Type Casting](#type-casting)
    - [Constants](#constants)
    - [Compile Time Constant Expressions](#compile-time-constant-expressions)
    - [Symbolic Constants](#symbolic-constants)
    - [Enums](#enums)
- [Conditional Statements](#conditional-statements)
    - [If](#if)
    - [For](#for)
    - [While](#while)
    - [Switch](#switch)
- [Functions](#functions)
    - [Templates](#templates)
- [Structs](#structs)
    - [Methods](#methods)
    - [Arithmetic Operators](#arithmetic-operators)
- [Arrays](#arrays)
- [IO](#io)
    - [Output](#output)
    - [Input](#input)

## Variables

### Initialization

```cpp
int i = 1; // copy initialization,
int j(2); // direct initialization, improved performance
int k{3}; // uniform initialization, best performance (C++ 11 and up)
```

```cpp
int i = 1, j = 2, k = 3;
```

```cpp
int i(1), j(2), k(3);
```

> C++ 11

```cpp
int i{1}, j{2}, k{3};
```

### Integers

```cpp
int i = 1; // 16 bit
long j = 2; // 32 bit
```

### Floats

> Make sure that float values end in `f` to prevent loss of precision as it's converting a double to a float.

```cpp
float k = 3.14f; // 32 bit
double l = 3.14f; // 64 bit
```

### Strings

```cpp
#include <iostream>

std::string message = "Hello, world";
```

### Booleans

```cpp
bool enabled = false;
```

### Dynamic Types

> `decltype` requires C++ 11

```cpp
float k = 3.14f;
decltype(k) a{k};
```

### Auto Types

```cpp
auto i = 1;
auto j = 3.14f;
auto message = "Hello, world";
```

### Typedefs

```cpp
#include <iostream>

typedef float distance;

int main() {
    distance metersFromTarget = 25;
    std::cout << typeid(metersFromTarget).name() << std::endl; // f
}
```

### Type Casting

```cpp
int i = (int)42;
int j = static_cast<int>(42);
```

```cpp
float i = (float)3.14;
float j = static_cast<float>(3.14);
```

```cpp
#include <iostream>

int main() {
    std::cout << "Pie is " + std::to_string(3.14) << std::endl;
}
```

### Constants

```cpp
const float p = 3.14f;
```

### Compile Time Constant Expressions

The value of `p2` is calculated at compile time and then stored in `p2` as a constant.

```cpp
constexpr float p2 = 3.14f * 2;
```

### Symbolic Constants

```cpp
#define MAX_NUM_HTTP_RETRIES 5
```

### Enums

Basic enum values are accessible without prefix.

```cpp
#include <iostream>

enum COLOR {
    RED,
    GREEN,
    BLUE
};

int main() {
    std::cout << GREEN << std::endl;
}
```

Class-based enum values require the prefix. These are preferred.

```cpp
#include <iostream>

enum class COLOR {
    RED,
    GREEN,
    BLUE
};

int main() {
    std::cout << (int)COLOR::GREEN << std::endl;
}
```

Class-based enum class with custom int values.

```cpp
enum class EXIT_CODES {
    SUCCESS = 0,
    GENERAL_ERROR = 1,
    MISSUSE_OF_SHELL_BUILTIN = 2,
    COMMAND_CANNOT_BE_EXECUTUED = 126,
    COMMAND_NOT_FOUND = 127,
    INVALID_ARGUMENT = 128,
    SCRIPT_TERMINATED = 130,
    EXIT_STATUS_OUT_OF_RANGE = 255
};

int main() {
    return (int)EXIT_CODES::SCRIPT_TERMINATED;
}
```

## Conditional Statements

### If

```cpp
#include <iostream>

int main() {

    bool activeStatus = false;

    if (activeStatus == true) {

        std::cout << "The device is active." << std::endl;

    } else {

        std::cout << "The device is inactive." << std::endl;

    }

}
```

### For

```cpp
#include <iostream>

int main() {

    for (int i = 0; i < 10; i += 1) {

        std::cout << std::to_string(i) << " Hello, world." << std::endl;

    }

}
```

### While

```cpp
#include <iostream>

int main() {

    int i = 0;

    while (i < 10) {

        std::cout << std::to_string(i) << " Hello, world" << std::endl;

        i++;

    }

}
```

### Switch

```cpp
#include <iostream>

int main() {

    int status = 0;

    switch (status) {
        case 0:
            std::cout << "Success." << std::endl;
            break;

        case 1:
            std::cout << "Unknown error." << std::endl;
            break;

        case 130:
            std::cout << "Script terminated." << std::endl;
            break;

        default:
            break;
    }

}
```

## Functions

```cpp
#include <iostream>

void displayMessage(std::string message) {
    std::cout << message << std::endl;
};

int main() {
    displayMessage("Hello, world!");
}
```

```cpp
#include <iostream>

int addNumbers(int a, int b) {
    return a + b;
}

int main() {
    std::cout << addNumbers(1, 2) << std::endl;
}
```

### Templates

```cpp
#include <iostream>

template<typename T, size_t N>
void printArray(T (&array)[N]) {

    int length = std::size(array);

    std::string output = "";

    for (int i = 0; i < length; i += 1) {

        output += std::to_string(array[i]) + " ";

    }

    std::cout << output << std::endl;

}
```

```cpp
#include <iostream>

template<typename T, size_t N>
void sortArray(T (&array)[N]) {

    int length = std::size(array);

    for (int i = 0; i < length; i += 1) {

        int lowestValueIndex = i;

        for (int j = i; j < length; j += 1) {

            if (array[j] < array[lowestValueIndex]) {

                lowestValueIndex = j;

            }

        }

        std::swap(array[i], array[lowestValueIndex]);

    }

}
```

## Structs

```cpp
struct Vector2 {
    float x;
    float y;
};

int main() {
    Vector2 position{1,2};
}
```

### Methods

```cpp
struct Vector2 {
    float x;
    float y;
    Vector2 add(Vector2 other) {
        return {
            this->x + other.x,
            this->y + other.y
        };
    };
};

int main() {
    Vector2 position{1,2};
    Vector2 newPosition = position.add(Vector2{1,1});
}
```

### Arithmetic Operators

```cpp
struct Vector2 {
    float x;
    float y;
    friend Vector2 operator+(Vector2 a, Vector2 b);
};

Vector2 operator+(Vector2 a, Vector2 b) {
    return {
        a.x + b.x,
        a.y + b.y
    };
}

int main() {
    Vector2 position{1,2};
    Vector2 newPosition = position + Vector2{1,1};
}
```

## Arrays

> `std::size` requires C++ 17

```cpp
int main()
{
    int array[5];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
}
```

```cpp
#include <iostream>

int main()
{
    int array[5]{1, 2, 3, 4, 5};
    std::cout << std::size(array) << std::endl;
}
```

## IO

### Output

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, world!\n";
}
```

### Input

```cpp
#include <iostream>

int main()
{
    int test;
    std::cout << "Enter integer: ";
    std::cin >> test;
    std::cout << "You entered " << test << "\n";
}
```
