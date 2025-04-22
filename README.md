# ft_printf @ 42 School
![42 Badge](https://img.shields.io/badge/42-Ft_printf-5CB3FF?style=for-the-badge) ![Score](https://img.shields.io/badge/Score-125%2F100-brightgreen?style=for-the-badge)

This project is part of the **42 School** curriculum. The goal of `ft_printf` is to recreate the well-known `printf` function from the C standard library. It teaches variadic arguments, formatting mechanics, and the use of structs and modular code organization for flags and specifiers.

---

## 📖 Table of Contents
- [Status](#-status)
- [Mandatory Features](#-mandatory-features)
- [Bonus Features](#-bonus-features)
- [Usage](#-usage)
- [Examples](#-examples)
- [Format Specifiers](#-format-specifiers)
- [42 School Requirements](#-42-school-requirements)

---

## ✅ Status
**Finished**: *2024-11-27*  
**Grade**: *125/100*

---

## 🌟 Mandatory Features

### Conversions
- `%` — Print a literal `%`
- `c` — Character
- `s` — String
- `p` — Pointer address
- `i` / `d` — Signed integers
- `u` — Unsigned integers
- `x` / `X` — Hexadecimal (lower/uppercase)

### Flags
- `#` — Alternative form (`0x`, `0X`)
- `+` — Always show sign
- `(space)` — Leading space for positive numbers
- `-` — Left-justify
- `0` — Zero-padding

### Width/Precision
- `.` — Precision control
- Static width/precision: `%10s`, `%.5d`
- Dynamic width/precision: `%*s`, `%.*d`, `%*.*d` (from arguments)

---

## 🏆 Bonus Features
- Full flag combinations support
- Advanced edge-case handling
- Optimized parsing architecture
- Extended format validation
- Modular code structure

---

## 🛠️ Usage
Build the project using:
```bash
# For mandatory part
make

# For bonus features
make bonus
```

Include in your project:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello from ft_printf!\n");
    return (0);
}
```

Compile with:
```bash
gcc main.c -L. -lftprintf -o printf_test
./printf_test
```

---

## 📝 Examples

### Basic Example
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Testing ft_printf!\n");
    return (0);
}
```

Output:
```
Testing ft_printf!
```

### Advanced Example (Flags & Width)
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("String: %-10s | Num: %+05d\n", "42", 42);
    ft_printf("Pointer: %#20p | Hex: %#X\n", &var, 255);
    return (0);
}
```

Output:
```
String: 42        | Num: +0042
Pointer:   0x7ffeeb39a4b4 | Hex: 0XFF
```

---

## 🔍 Format Specifiers

### Format Syntax
```
%[flags][width][.precision]specifier
```

### ⚑ Flags
| Flag  | Description |
|-------|-------------|
| `-`   | Left-align output |
| `+`   | Precede positive numbers with `+` |
| ` `   | Precede positive numbers with space |
| `#`   | Adds `0x`, `0X` for hex values |
| `0`   | Pads with zeros |

### 📏 Width
| Symbol | Description |
|--------|-------------|
| number | Minimum width of output |
| `*`    | Width passed as function argument |

### 🎯 Precision
| Symbol | Description |
|--------|-------------|
| `.n`   | Minimum number of digits or max string chars |
| `.*`   | Precision from argument |

### 🔣 Specifiers
| Specifier | Output |
|-----------|--------|
| `%`       | Literal percent sign |
| `c`       | Character |
| `s`       | String |
| `p`       | Pointer |
| `d`, `i`  | Signed integer |
| `u`       | Unsigned integer |
| `x`, `X`  | Hexadecimal (lower/upper) |

### Flag Combinations
| Combination | Example     | Output          |
|-------------|-------------|-----------------|
| `%-10.5s`   | "Hello"     | `Hello     `    |
| `%+08.2d`   | 42          | `+00042.00`     |
| `%#10x`     | 255         | `     0xff`     |

---
```

---

## 📜 42 School Requirements
- **No memory leaks**
- **Norminette-compliant**
- **Static library (`libftprintf.a`)**
- **Full test coverage**

---

Feel free to clone this project and experiment with different formatting combinations!
