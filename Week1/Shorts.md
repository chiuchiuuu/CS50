Data types

- int
  - the int data type is used for variables that will store integers
  - integer always take up 4 bytes of memory(32 bits). This means the range of values they can store is necessarily limited to 32 bits worth of information
  - range: $-2^{31} \to  2^{31}-1$
- unsigned int
  - range: $0 \to 2^{32}-1$
- char
  - single character
  - take up 1 byte of memory (8 bits)
  - range: $-128 \to 127$
- float
  - real number
  - take up 4 bytes (32 bits)
  - not precise
- double
  - real number
  - take up 8 bytes(64 bits)
  - with addition 32 bits of precision
- void
  - is a type, but not a data type
  - void return type
  - void parameter list

two additional types that cs50 provide

- bool
  - boolean value
  - true or false
- string
  - series of character

using variable

- declaration
- assignment
- initialization
  - simultaneously delaring and setting the value of a variable

conditional statement

- if else block
  - boolean expression
- switch statement
  - discrete case
  - break
- `?:` statement
  - (expr) ? \<statement1> : \<statement2>
  - ternary operator



loops

- while
  - loop unknown number of times
- do...while
  - loop unknown number of times but at least time
- for (start; expr; increment)
  - loop a discrete number of time
