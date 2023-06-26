# Libft

This project was completed as part of the curriculum at École 42. The goal of the project is to implement a library of standard C functions, as well as additional useful functions that are not part of the standard library. 

## Installation

To use the library in your own projects, follow these steps:

1. Clone the repository to your local machine.
2. Open a terminal window and navigate to the root directory of the project.
3. Run the command `make` to compile the library.
4. Include the header file `libft.h` in your source code.

## Usage

The library includes a variety of functions for working with strings, memory, lists, and more. All functions are named according to the convention `ft_<function_name>`. For a full list of functions and their descriptions, see the `libft.h` header file.

In addition to the standard library functions, the library includes a number of useful functions that are not part of the standard library. These include:

- `ft_strjoin`: Concatenates two strings into a new string.
- `ft_split`: Splits a string into an array of substrings using a specified delimiter.
- `ft_lstadd_back`: Adds a new element to the end of a linked list.
- `ft_lstsize`: Returns the number of elements in a linked list.

## Example

Here's an example of how to use the library to concatenate two strings:

```c
#include "libft.h"

int main()
{
    char *s1 = "Hello, ";
    char *s2 = "world!";
    char *result = ft_strjoin(s1, s2);
    ft_putstr(result);
    ft_putchar('\n');
    return 0;
}
```

In this example, the `ft_strjoin` function is used to concatenate two strings, which are then printed to the screen using the `ft_putstr` and `ft_putchar` functions.

## Credits

This project was completed by Léon Pupier (lpupier) as part of the curriculum at École 42.