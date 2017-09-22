functions

- aka procedures, methods, subroutines
- why use functions:
  - organization
  - simplification
  - reusability
- declarations
  - should always go atop `main()`
  - `return-type name(argument-list);`
- definitions
- calls
  - simply pass it appropriate arguments



Variables and Scope

- **Scope** is a characteristic of a variable that defines from which functions that variable may be accessed
  - **Local variables** can only be accessed with in the functions in which they are created.
  - **Global variables** can be accessed by any function in the program
    - declare outside of all functions
- **Local variables** in C are **passed by value** in functions calls 
  - when a variable is passed by value, the **callee**(function) receives a copy of the passed variable, not the variable itself
  - that means that the variable in the **caller**(function that calling a function) is unchanged unless overwritten.



Arrays

- Arrays are a fundamental **data structure**
- use to hold values of the same type at contiguous memory locations
- declaration: `type name[size]`
  - instantiation: `type name[siza] = { element1, element2, ... };`
  - multi-dimensional arrays `type name[size][size]...`
- can't not assign one array to another, instead, we must use a loop to copy over the elements one at a time
- Arrays are **passed by reference.** The callee receives the actual array, NOT a copy of it.



Command Line Arguments

- used to provide data to program before the program starts running 

- declaration:

  - ```c
    int main(int argc, string argv[]):
    {
      
    }
    ```

- argc (argument count)

  - integer type variable
  - store the number of command-line arguments the user typed

- argv (argument vector)

  - array of strings stores the actual text the user typed at the command-line



Magic Numbers

- Directly writing constants into our code is sometimes referred to as using **magic numbers**

- C provides a **preprocessor directive** (aka **macro** ) for creating symbolic constants.

  `#define NAME REPLACEMENT`

  At the time program is compiled, `#define` goes through your code and replaces `NAME` with `REPLACEMENT`