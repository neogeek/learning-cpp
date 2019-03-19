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
- [Structs](#structs)
    - [Methods](#methods)
    - [Arithmetic Operators](#arithmetic-operators)

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
std::string message = "Hello, world";
```

### Booleans

```cpp
bool enabled = false;
```

### Dynamic Types

> C++ 11

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
int main() {

    for (int i = 0; i < 10; i += 1) {

        std::cout << std::to_string(i) << " Hello, world." << std::endl;

    }

}
```

### While

```cpp
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
void displayMessage(std::string message) {
    std::cout << message << std::endl;
};

int main() {
    displayMessage("Hello, world!");
}
```

```cpp
int addNumbers(int a, int b) {
    return a + b;
}

int main() {
    std::cout << addNumbers(1, 2) << std::endl;
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
